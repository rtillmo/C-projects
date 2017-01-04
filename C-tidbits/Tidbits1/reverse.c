#include string.h
#include stdio.h


void reverse(char*w) {
  int n = strlen(w)
  int last = n-1
  int i;
  for(i=0; i<n/2; ++i){
    char temp = w[i];
    w[0] = w[last-i];
    w[last-i] = temp;
 
int main() {
  char word [40];
  printf("Type a word:");
  scanf("%s", &word);
  reverse (word);
  printf("%s\n" word);
  return 0;
  
