#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void *mycalloc(size_t nmemb, size_t size)
{
  void *Result = NULL;

  /* use malloc to get the memory */
  Result = malloc(nmemb * size);

  /* and clear the memory on successful allocation */
  if(NULL != Result)
  {
    memset(Result, 0x00, nmemb * size);
  }

  /* and return the result */
  return Result;
}

int main(void)
{
  int *p = NULL;
  int i = 0;

  p = mycalloc(100, sizeof *p);
  if(NULL == p)
  {
    printf("mycalloc returned NULL.\n");
  }
  else
  {
    for(i = 0; i < 100; i++)
    {
      printf("%08X ", p[i]);
      if(i % 8 == 7)
      {
	printf("\n");
      }
    }
    printf("\n");
    free(p);
  }

  return 0;
}
