#include <stdio.h>
#define NUMBER '0'


/* getop: get next operator or numeric operand */
int getop(char s[]){
  int i;
  static int c = ' ';

  while(c == ' ' || c == '\t'){
      c = getchar();
  }

  s[0] = c;
  s[1] = '\0';
  if(!isdigit(c) && c != '.'){
      int res = c;
      c = ' '; /* default behavior is to "unget" at end by using last read character (saved in static c) as first read character on the next call, but in this case we don't want to do so, since no extra character was read */
      return res; /* not a number */
  }

  i = 0;
  if(isdigit(c)){ /* collect integer part */
    while(isdigit(s[++i] = c = getch())){
      ;
    }
  }

  if(c == '.'){
    while(isdigit(s[++i] = c = getch())){
      ;
    }
  }

  s[i] = '\0';

  return NUMBER;
}
