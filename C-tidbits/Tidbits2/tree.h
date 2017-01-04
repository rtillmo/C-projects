#include <stdio.h>

void tree(int n){
  int i = 1;
  int stars = 1;

  while ( i <= n ){
    int j;
    
    for ( j = 0; j < (n-i); ++j ) {
      printf(" ");
    }
    
    for ( j = 0; j < stars; ++j ) {
      printf("*");
    }
    
    printf("\n");
    i += 1;
    stars += 2;
   }
int j;   
for ( j=0; j < (n/2+2); ++j){
  printf(" ");
   }
for ( j=0; j < (n/2-1); ++j){
  printf("*");
   }
    printf("\n");
}

int main() {
  int n;
  printf("Type number of rows: ");
  scanf("%d",&n);
  tree(n);
  return 0;
}
