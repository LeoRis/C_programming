#include <stdio.h>
#include <limits.h>

unsigned int rightrot(unsigned int x, unsigned int n){

   size_t s = sizeof(x) * CHAR_BIT;
   size_t p;

   if(n < s){
       p = n;
   }else{
       p = n % s;
   }

   if((0 == x) || (0 == p)){
       return x;
   }

   return (x >> p) | (x << (s - p));
}


int main(void){

   unsigned int val, pos, x, n;

   unsigned int max = sizeof (pos) * CHAR_BIT + 1;

   for(val = 0; val < 700; val += 49){
      for(pos = 0; pos < max; ++pos){
         printf("%u, %d: %u\n", x, n, rightrot(val, pos));
      }
   }
}
