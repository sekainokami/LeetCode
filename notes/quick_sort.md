```c++
#include <iostream>
#include <vector>

using namespace std;

// Regular swap function
inline void swap(int& a, int & b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

// Puts all elements in v smaller or equal to the v[stop] before
// those greater elements
int partition(vector<int>& v, int start, int stop)
{
  int pivot = stop;
  int slow = start;
  for (int fast = start; fast < stop; ++fast)
  {
    if (v[fast] <= v[pivot])
      swap(v[fast],v[slow++]);
  }
  // Swap the pivot element to its correct position
  swap(v[slow],v[pivot]);
  return slow;
}

void qs(vector<int>& v, int start, int stop)
{
  if (start < stop)
  {
    int pi = partition(v,start,stop);
    qs(v,start,pi-1);
    qs(v,pi+1,stop);
  }
}

int main()
{
  vector<int> v = {7,2,1,6,8,5,3,4};
  qs(v,0,v.size()-1);
  for (auto & x : v)
    cout << x << " ";
}
```
