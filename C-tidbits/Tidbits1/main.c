#include <stdio.h>

/*
 * User enters the number of days. This program
 * computes the amount of pennies, given that the
 * pennies double every day.
 */

int main() {
  int numberOfDays;
  int total = 0;
  int pennies = 1;
  int count = 1;

  printf("How many days: ");
  scanf("%d", &numberOfDays); /* get number of days from user */
  while ( count <= numberOfDays ) {  // start of while loop
    total = total + pennies;
    // pennies = pennies * 2;
    pennies *= 2;
    // count += 1;
    ++count;
  }
  printf("You have earned $ %.2f dollars\n", total*0.01);
  return 0;
}
