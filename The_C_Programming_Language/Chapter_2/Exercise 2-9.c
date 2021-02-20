/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a faster
 * version of "bitcount". */

/* Let's suppose (char)x = 86. The expression x &= (x - 1) is the same as
 * x = x & (x - 1). Then:
 *  01010110	<- this is x (86)
 * +11111111	<- this is -1 (two's complement of 1).
 *  01010101	<- this is the result of x - 1 (or, better, x + (-1)) (85)
 * &01010110 	<- this is x (86) again, for the & operation
 *  01010100	<- this is x & (x - 1), i.e., the new value of x. (84)
 *
 * Notice that the last 1 has been deleted. When you subtract 1 from a number
 * (or, in this case, adds -1), you are always going to flip the last 1 from
 * that number (i.e., it becomes 0) and the remaining rightmost bits all become
 * 1 - the oposite of the original number. When you perform an & operation
 * between that number and the result, from the last 1 on, the result will
 * always be 0. Notice also that x will never assume an odd value after the
 * first time you run the operation, because the rightmost bits will always
 * assume a value of 0 (even if you start with an even number) and the only way
 * to have an odd number is by setting the rightmost bit to 1.
 *
 * It means that the amount of 1 digits in the number equals the amount of times
 * you have to run the operation until x == 0. And it is faster because it
 * doesn't need to examine every single bit of the number. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLEN 10	/* maximum length of the input number */

unsigned getuint();
unsigned bitcount(unsigned x);

int main(){

	unsigned x;

	printf("Type any positive number: ");
	x = getuint();

	printf("The number %u has %u ones.\n", x, bitcount(x));
	exit(0);
}

unsigned getuint(){

	int i, c;
	char s[MAXLEN + 1];
	unsigned uint;

	uint = i = 0;
	while((c = getchar()) != EOF && c != '\n' && i < MAXLEN){
		if(isdigit(c)){
			s[i++] = c;
		}else{
			printf("Error: \"%c\" is not a valid number!\n", c);
			exit(1);
		}
	}

	s[i] = '\0';

	for(i = 0; s[i] != '\0'; i++){
		uint = uint * 10 + (s[i] - '0');
	}

	return uint;
}

unsigned bitcount(unsigned x){

	int i = 0;

	if(x == 0){
		return 0;
	}

	while((x &= (x-1)) > 0){
		++i;
	}

	return ++i;
}
