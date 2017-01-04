#include<stdio.h>
#include<stdlib.h>

void root(int n){
  int guess = n/2;

  while (1){
    int j;
    int count = 4;
    count += 1;

    if (guess*guess < n) {
      guess+= 0.001;
    }

    else {
       guess-= 0.001;
    }

    if (abs(guess*guess - n)) <= 0.001{
      break;
    }
  }
  printf("The square root of %d is:  ", guess);
 }

int main() {
  int n;
  printf("Type a number: ");
  scanf("%d", &n);
  root(n);
  return 0;
}
