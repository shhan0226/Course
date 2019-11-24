char *replace(char *s, char *olds, char *news) {  // stirng replace function 
  char *result, *str;                             // character pointer
  int i, count = 0;                               // vairable initialization     
  int oldlen = strlen(olds);                      // find string length initialization
  int  newlen = strlen(news);

  if (oldlen < 1) return s;                     //when old word not be return stirng 

  if (newlen != oldlen) {                  //when old word and new word not equal then
    for (i = 0; s[i] != '\0';) {
      if (memcmp(&s[i], olds, oldlen) == 0){    //when find old word
          count++;                              //number of string lncrase counter +1
          i += oldlen;
      }
      else i++;
    }
  } else i = strlen(s);      //when old word and new word equal return nubmer of sting
                             //result string dynamic allocation, number of new stirng
  result = (char *) malloc(i + 1 + count * (newlen - oldlen));
  if (result == NULL) return NULL;

  str = result;                            //str pointer allocation result stirng

  while (*s) {                             //until input stirng find EOF
    if (memcmp(s, olds, oldlen) == 0) {    //find old word in stirng then
      memcpy(str, news, newlen);           //copy new word to stirng
      str += newlen;                       //stirng length increase
      s  += oldlen;
    } else *str++ = *s++;
  }
  *str = '\0';                              //end input '\0'

  return result;
}
