#include<stdio.h>

int main()   
{   
 int i, n ; 
     
 printf("Enter the number: ");   
 scanf("%d", &n);   

 printf("\nThe divisors are:\n") ;   

 for(i = 1 ; i <= n ; i++)   
   if(n % i == 0)   
     printf("%d\t", i) ;     
}  
