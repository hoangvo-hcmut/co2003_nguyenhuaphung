unsigned int fibo(int n)
{
  int a = 0, b = 1, c = 1;
  for (int i = 0; i < n; i += 1)
  {
    a = b;
    b = c;
    c = a + b;
  }
  return a;
}
