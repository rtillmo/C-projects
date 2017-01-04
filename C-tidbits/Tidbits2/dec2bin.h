#include <stdio.h>
 
void binary()
{
  int n, c, k;
 
  printf("Enter an integer\n");
  scanf("%d", &n);
 
  printf("the binary equivalent of %d is:\n", n);
 
  for (c = 9; c >= 0; c--)
  {
    k = n >> c;
 
    if (k & 1)
      printf("1");
    else
      printf("0");
  }
 
  printf("\n");
 
}
