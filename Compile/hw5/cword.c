#include <stdio.h>

#define MaxWords   509
#define BufSize   2048

/* treat wptr as a hash table :
 * all entries are initially NULL
 * entries that are in use are non-NULL
 * on collisions, search forward from the desired array entry to
 * an empty entry.
 */
static char *wptr[MaxWords];
static char buf[BufSize], *nxtfree = buf;

/* hash function for word pointer table */
static unsigned hash(s)
   register unsigned char *s;
{
   register int i = 0;

   while (*s)
      i = i * 16 + *s++;
   return i;
}

/* 
 *  slookup looks up searches the table of existing words for the
 *  null-terminated strings.
 *
 *  if this string is found, slookup returns a pointer to it.
 *  else
 *     if install is non-zero, insert the string into table and return
 *         its new location
 *     else return NULL;
 */
char *slookup(s, install)
   char *s;
   int install;
{
   int h;

   h = hash(s) % MaxWords;
   while (wptr[h] && strcmp(s, wptr[h]))
      h = (h + 1) % MaxWords;
   if (!wptr[h] && install) {
      wptr[h] = nxtfree;

      /* still need to check for overflow */
      while(*nxtfree++ = *s++) ;
   }
   return wptr[h];
}
