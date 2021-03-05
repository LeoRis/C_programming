#include <stdio.h>
#include <string.h>

void myreverse(char s[]){
    static int start = 0;
    static int end;

    int temp;

    if(start == 0){
        end = strlen(s) - 1; /* initialize end only when no recursive calls have been made */
    }
    if(end - start > 2){
        start++;
        end--;
        myreverse(s);
        start--; /* Unwind start and end to start reversing from middle of string. */
        end++;   /* Start will eventually wind back to 0 to get ready for next string.*/
    }
    /* Swap letters */
    temp = s[start];
    s[start] = s[end];
    s[end] = temp;
}

int main(){
    char test1[] = "Hello World!";
    char test2[] = "abcd";
    char test3[] = "ab";
    char test4[] = "";

    printf("input: \"%s\"\n", test1);
    myreverse(test1);

    printf("reversed: \"%s\"\n", test1);
    myreverse(test1);

    printf("twice reversed: \"%s\"\n", test1);
    printf("input: \"%s\"\n", test2);
    myreverse(test2);

    printf("reversed: \"%s\"\n", test2);
    myreverse(test2);

    printf("twice reversed: \"%s\"\n", test2);
    printf("input: \"%s\"\n", test3);
    myreverse(test3);

    printf("reversed: \"%s\"\n", test3);
    myreverse(test3);

    printf("twice reversed: \"%s\"\n", test3);
    printf("input: \"%s\"\n", test4);
    myreverse(test4);

    printf("reversed: \"%s\"\n", test4);
    myreverse(test4);

    printf("twice reversed: \"%s\"\n", test4);

    return 0;
}
