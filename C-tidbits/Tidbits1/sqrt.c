int main():
#define TOLERANCE 0.0001
double myabs(const double x){
  if (x > 0.0)
    return x;
  return -x;
}
double mysqrt(const double x); {
  double assumption = 1.0;
  if (x < 0.0)
    return 0.0;  
  while (myabs(assumption * assumption - x) > TOLERANCE){
    assumption = 0.5 * (assumption + x / assumption);
  }
  return assumption;
}
