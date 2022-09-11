template <typename T>
int findMax(T arr[],int n) {
  int index = 0;
  for (int i = 0; i < n; i += 1) {
    if (arr[i] >= arr[index]) {
      index = i;
    }  
  }
  return index;
}
