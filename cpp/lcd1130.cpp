#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int MAX_INTEGER = 0xffffffff/2;

class Solution {
public:
  int mctFromLeafValues(vector<int> &arr)
  {
    stack<int> st;
    
    st.push(MAX_INTEGER);
    int cost = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
      int x = arr[i];
      /*leaf 중 가장 작은 곱셈 결과를 반환하는 값 찾기*/
      while (st.top() < (x + 1))
      {
        int mid = st.top();
        st.pop();
        cost += mid * min(st.top(), x);
        cout << "first while" << endl;
        /* cout << "[DBG] cost = " << cost << endl;*/
      }
      st.push(x);
    }

    while (st.size() > 2)
    {
      int left = st.top();
      st.pop();
      int right = st.top();
      cost += left * right;
      cout << "second while" << endl;
      /*cout << "[DBG] cost = " << cost << endl;*/
    }
    return cost;
  }
};

int main() {
  Solution sol;

  // Test case 1
  vector<int> arr1 = {6, 2, 4};
  cout << "Test Case 1: " << sol.mctFromLeafValues(arr1) << " (Expected: 32)"
       << endl;

  // Test case 2
  vector<int> arr2 = {4, 11};
  cout << "Test Case 2: " << sol.mctFromLeafValues(arr2) << " (Expected: 44)"
       << endl;

  // cout << "MAX_INTEGER=" << MAX_INTEGER << endl;
  return 0;
}
