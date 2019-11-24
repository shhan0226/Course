/* 
 * symbol table definitions
 */

/* 
   variables come in one of four categories
         lvar  -  local variables
                  position is offset in activation record
         gvar  -  golobal variables
                  position is offset within static data space
         pvar  -  parameter variables
                  position is offset in activation record
         ivar  -  name internal to a structure
                  position is relative to start of structure
*/

enum varcategories { lvar, gvar, pvar, ivar, };

struct sym {
   char *v_name;
   enum varcategories v_cat;
   int v_position;               /* position unused in struct names */
   struct typestruct *v_type;
   struct sym *v_next;
};

#define NILVAR ((struct sym *) 0)

struct varlist {
    struct sym *symp;
    struct varlist *next;
};

struct varlist *buildlist();

#define NILLIST ((struct varlist *) 0)

/* 
type come in one of five categories
   inttype - integer type
   strtype - struct type
   arrtype - array type
   ptrtype - pointer type
   funtype - function type

in all cases, size is size of the object ( in words )
*/

enum tcategories {
   inttype, strtype, arrtype, ptrtype, funtype,
};

struct typestruct {
   enum tcategories t_cat;
   int t_size;
   union {
      /* if arrtype, ptrtype, funtype, t_base points to base type */
      struct typestruct *t_base;
      /* if strtype, t_first points to variable representing first field */
      struct sym *t_first;
   } tt;
   /* for structure types, t_first points to a reverse linked list of 
    * the field names. if the structure is named, the last entry on
    * this list is the sym type representing the name of structure.
    * otherwise, the list is null-terminated.
    */
};

#define NILTYPE (struct typestruct *) 0

extern struct sym *lookup(), *vinstall(), *struct_lookup(), *struct_install();
extern struct typestruct *tinstall();
