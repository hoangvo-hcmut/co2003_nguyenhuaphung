#include <vector>
#include <cmath>
#include <string>
using namespace std;

template <typename T>
vector<vector<T>> powerSet(vector<T> arr)
{
  vector<vector<T>> result;
  // for a set arr of n element, there will be 2^n elements
  const int powerSetSize = pow(2, arr.size());
  // we can use a binary count from 000 -> binary of powerSetSize
  // to represent the power set. eg. for a set ò 3 elements: 000 -> [], 001 -> [a], 111, [a,b,c]
  // -> represent all sets

  // [1] the complexity of this outer loop is O(2^n) because it goes from 0 -> 2^n -1
  for (int i = 0; i < powerSetSize; i += 1)
  {
    vector<T> set;
    // [2] the complexity of this inner loop is O(n)
    for (unsigned int j = 0; j < arr.size(); j += 1)
    {
      // check if j-th bit in binary representation of i is 0 or 1
      // if it is 1 we use the element from set
      // reference: https://www.geeksforgeeks.org/check-whether-k-th-bit-set-not/
      if (i & (1 << j))
      {
        set.push_back(arr[j]);
      }
    }

    result.push_back(set);
  }

  // From [1] and [2], the complexity of the function is O(2^n) * O(n) = O(n*2^n)
  return result;
}
