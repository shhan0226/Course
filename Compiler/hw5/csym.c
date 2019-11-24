#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "sym.h"

#define False        0
#define True         1

#define HASH_SIZE    17

static fix_size();

static struct sym
   *stable[HASH_SIZE],         /* symbol table uses hashing */
   *structable[HASH_SIZE],     /* symbol table for structure names */
   *fvars = NULL;              /* free list */

/* create a new symobl structure with fields initalized according
 * to the values of name, vcat, and type.
 */
struct sym *symcreate(name,vcat,type)
   register char *name;
   enum varcategories vcat;
   struct typestruct *type;
{
   register struct sym *vp;
   char *slookup();

   vp = fvars;
   if (vp == NULL) {
      if ((vp = (struct sym *) malloc(sizeof(struct sym))) == NULL) {
        fprintf(stderr, "out of malloc space\n");
        exit(1);
      }
   }
   else
      fvars = vp->v_next;

   vp->v_name = slookup(name, 1);
   vp->v_cat = vcat;
   vp->v_type = type;
   return vp;
}

/* reclaim the storage allocated to *symp */
freesym(symp)
   register struct sym *symp;
{
   symp->v_next = fvars;
   fvars = symp;     /* free the allocated storage for later using */
}

static struct sym *xlookup(), *xinstall();
static xremove(), xforeach();

/* lookup the specified variable name, returning a pointer to the
 * symbol or null if not found
 */
struct sym *lookup(name)
   register char *name;
{
   return xlookup(stable, name);
}

/* install *symp in the symbol table, returning its value */
struct sym *vinstall(symp)
   register struct sym *symp;
{
   return xinstall(stable,symp);
}

/* remove the symbol table entry for the variable rmvp and free it */
remove2(rmvp)
   register struct sym *rmvp;
{
   return xremove(stable,rmvp);
}

/* perform the specified function on each entry in the symbol table
 * of specified category -- note: function may be remove.
 */
foreach(vcat, func)
   enum varcategories vcat;
   int (*func)();
{
   xforeach(stable,vcat,func);
}

/* lookup the specified variable name, returning a pointer to the
 * symbol or null if not found
 */
struct sym *struct_lookup(name)
   register char *name;
{
   return xlookup(structable,name);
}

/* install *symp in the symbol table, returning its value. */
struct sym *struct_install(symp)
   struct sym *symp;
{
   return xinstall(structable,symp);
}

/* remove the symbol table entry for the variable name */
struct_remove(rmvp)
   register struct sym *rmvp;
{
   xremove(structable, rmvp);
}

/* perform the specified function on each entry in the symbol table
 * of specified category -- note: function may be remove.
 */
struct_foreach(vcat, func)
   enum varcategories vcat;
   int (*func)();
{
   xforeach(structable,vcat,func);
}

/* internal lookup routine, does the work of lookup and struct_lookup */
static struct sym *xlookup(table,name)
   struct sym *table[];
   char *name;
{
   char *slookup();

   if (name = slookup(name, 0)) {
      register int hash;
      register struct sym *vp;

      hash = ((int) name) % HASH_SIZE;
      for(vp=table[hash]; vp; vp = vp->v_next)
         if (vp->v_name == name) return vp;
   }
   return NULL;
}

/* internal install routine, does the work of install and struct_install */
static struct sym *xinstall(table,vp)
   struct sym *table[], *vp;
{
   register int hash;

   hash = ((int) vp->v_name) % HASH_SIZE;
   vp->v_next = table[hash];
   table[hash] = vp;
   return vp;
}

/* internal remove routine, does the work of remove and struct_remove */
static xremove(table,rmvp)
   struct sym *table[], *rmvp;
{
   register int hash = 0;
   register struct sym *oldvp, *vp;

   hash = ((int) rmvp->v_name) % HASH_SIZE;
   oldvp = NULL;
   for (vp = table[hash]; vp; vp = vp->v_next) {
      if (vp == rmvp) {
         if (oldvp)
            oldvp->v_next = vp->v_next;
         else
            table[hash] = vp->v_next;
         vp->v_next = fvars;
         fvars = vp;
         return;
      }
      oldvp = vp;
   }
}

/* internal foreach routine, does the work of remove and struct_remove */
static xforeach(table,vcat,func)
   struct sym *table[];
   enum varcategories vcat;
   int (*func)();
{
   register int i = 0;
   register struct sym *vp, *nextvp;

    for (i = 0; i < HASH_SIZE; i++) {
       for (vp = table[i]; vp; vp = nextvp) {
          nextvp = vp->v_next;
          if (vp->v_cat == vcat)
             (*func)(vp);
       }
    }
}

/* create a new typestruct and initialize as specified
 * Note:
 *      typestructures may be shared and are not garbage collected.
 */
struct typestruct *tinstall(tcat, size, base)
   enum tcategories tcat;
   int size;
   struct typestruct *base;
{
   register struct typestruct *tp;

   if ((tp = (struct typestruct *)
      malloc(sizeof(struct typestruct))) == NULL) {
      fprintf(stderr, "out of malloc space\n");
      exit(1);
   }
   tp->t_cat = tcat;
   tp->t_size = size;
   tp->tt.t_base = base;
   return tp;
}

/* append type struct to the end of vp->v_next */
struct typestruct *append_type(basep, newp)
   struct typestruct *basep;
   struct typestruct *newp;
{
   register struct typestruct *oldbase;

   if (basep) {
      oldbase = basep;
      while (basep->tt.t_base) {
         if (basep->t_size < 0)
            fix_size(basep, newp);
         basep = basep->tt.t_base;
      }
      if (basep->t_size < 0)
         fix_size(basep, newp);
      if (newp->t_cat == arrtype && newp->t_size == 0)
         yyerror("Null dimension");
      basep->tt.t_base = newp;
      return oldbase;
   }
   else
      return newp;
}

static struct varlist *flelem = NILLIST;

struct varlist *buildlist(vp, listp)
   struct sym *vp;
   struct varlist *listp;
{
   register struct varlist *lhead;
   if (lhead = flelem)
      flelem = lhead->next;
   else if (!(lhead = (struct varlist *) malloc(sizeof(struct varlist)))) {
      fprintf(stderr, "out of malloc in buildlist");
      exit(1);
   }

   lhead->next = listp;
   lhead->symp = vp;
   return lhead;
}

freelist(listp)
   register struct varlist *listp;
{
   listp->next = flelem;
   flelem = listp;
}

/* Given that a particular symbol has been declared multiple times
 * (presumably through the use of the "extern" storage class), ensure
 * that the current symbol table information, represented by type t2 is
 * consistent with the current declaration, which is represented by t1.

 * Since array dimensions may be incompletely specified in the extern
 * declarations, it may be necessary to augment the symbol table information
 * if the current declaration provides array dimensions that were previously
 * unspecified.  This also done by typecmp().
 *
 * Finally, typecmp() assumes that the types represented by t1 and t2 are 
 * meaningful.  It allows other routines to complain about constructs
 * like list[5][].
 *
 * typecmp() returns 0 if the types compatible, 1 otherwise.
 */
typecmp(t1, t2)
   register struct typestruct *t1, *t2;
{
   if (t1 == t2)
      return 0;
   else if (t1->t_cat != t2->t_cat)
      return 1;
   else {
      switch (t1->t_cat) {
         case arrtype:
            if (t1->t_size == 0)
               t1->t_size = t2->t_size;
            else if (t2->t_size != 0 && t1->t_size != t2->t_size)
               return 1;
         /* note: this may fall through to the following code */
         case ptrtype:
         case funtype:
            return typecmp(t1->tt.t_base, t2->tt.t_base);
         case strtype:
            return (t1->tt.t_first != t2->tt.t_first);
         default:
            return 0;
      }
   }
}

/* return non-zero if two types are assignment compatible */
/* structure types use name equivalence */
sametype(tp1, tp2)
   struct typestruct *tp1, *tp2;
{
   if (tp1->t_cat != tp2->t_cat)
      return False;
   else if (tp1 == tp2)
      return True;
   else {
      switch (tp1->t_cat) {
         case inttype:
            return True;
         case strtype:
            return False;    /* because tp1 != tp2 above */
         case arrtype:
         case ptrtype:
         case funtype:
            return sametype(tp1->tt.t_base, tp2->tt.t_base);
      }
   }
}

/* Given that *rtp is an array type whose basic entry size has not yet
 * been determined, and that *tp represents part of the type of the basic
 * entry, adjust the size of *rtp by multiplying it by the size of *tp.
 * If *tp represents the fundamental type of the array (such as an integer,
 * pointer, or structure), then change the sign of the array size to positive, 
 * indicating that the size of the area is now known.  However, if *tp
 * represents a nested array, keep the size negative, because the size
 * of the array cannot be determined until we know that this nested array
 * contains.  If *tp representes an array, its size will be negative.
 */
static fix_size(rtp, tp)
   register struct typestruct *tp, *rtp;
{
   switch (tp->t_cat) {
      default:
         yyerror("Array of functions");
      case inttype:
      case strtype:
      case ptrtype:
      /* for all of the above cases, tp->t_size is positive */
      /* for array type, tp->t_size is negative */
      case arrtype:
         rtp->t_size *= -tp->t_size;
      break;
   }
}

/* look up the field named name in flist, returning Null if the field
 * is not found
 */
struct sym *fieldlook(flist, name)
   register struct sym *flist;
   register char *name;
{
   while (flist && flist->v_cat == ivar && flist->v_name != name)
      flist = flist->v_next;

   return (flist->v_cat == ivar)? flist: NILVAR;
}

/* given that tp points to an object, return the type corresponding to
 * address of this object.
 */
struct typestruct *addrtype(tp)
   register struct typestruct *tp;
{
   if (tp->t_cat == arrtype)
      return tinstall(ptrtype, 1, tp->tt.t_base);
   else
      return tinstall(ptrtype, 1, tp);
}
