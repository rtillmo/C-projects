#include <stdio.h>
#include "tree.h"
#include "ascii.h"
#include "dec2bin.h"
#include "divisors.h"



int main() {
  tree(7);
  printInitials();
  binary();
  divisors();
  return 0;
}

void loop(int n) {
int choice;

choice = printf("Type your choice: ");
scanf("%d" , &n);

while (choice !=0) {
  
  if (choice == 0) {
    break;
  }

  if (choice == 1) {
    tree(7);
  }

  if (choice == 2) {
    binary();
  }

  if (choice == 3) {
    divisor();
  }

  if (choice == 4) {
    root();
  }

  if (choice == 5) {
    printInitials();
  }
  printf("\n");
} 

