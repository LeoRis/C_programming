#include <stdio.h>

int main()
{
     int lastlastc, lastc, c, nextc;
     int incomment, inquote;

     lastlastc = lastc = nextc = incomment = inquote = 0;
     c = getchar();

     while(c != EOF){
          nextc = getchar();

          if(!incomment){
               if(!inquote){
                    if(c == '"' && lastc != '\'')
                         inquote = 1;
               }else{
                    // Look out for escape characters
                    if(c == '"' && (lastc != '\\' || lastc == '\\' && lastlastc == '\\'))
                         inquote = 0;
               }
          }

          if(!inquote){
               if(c == '/' && nextc == '*'){
                    incomment = 1;
               }
          }

          if(incomment){
               if(c == '*' && nextc == '/'){
                    // It was a comment anyway, chars captured don't matter
                    lastlastc = lastc = nextc = incomment = inquote = 0;
                    c = getchar();
                    continue;
               }
          }else{
               putchar(c);
          }

          lastlastc = lastc;
          lastc = c;
          c = nextc;
     }

     return 0;
}
