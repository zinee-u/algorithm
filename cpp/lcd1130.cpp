#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        // Monotonic stack approach
        // We maintain a decreasing stack.
        // When we encounter a value 'x' larger than the stack top,
        // it means the stack top is a local minimum.
        // It should be paired with the smaller of its two neighbors (previous in stack, or 'x').
        
        stack<int> st;
        st.push(INT_MAX); // Sentinel to simplify boundary checks
        int cost = 0;

        for(int i=0; i<arr.size(); ++i)
        {
          int x = arr[i];
          while(st.top()<(x+1))
          {
            int mid = st.top();
            st.pop();
            cost += mid * min(st.top(), x);
          }
          st.push(x);
        }

        // Process remaining elements in the stack
        // The stack is now strictly decreasing (except for INT_MAX)
        // e.g., [INT_MAX, 6, 4, ...]
        // We combine elements from the top (smallest) with their left neighbor.
        while (st.size() > 2) {
            int right = st.top();
            st.pop();
            int left = st.top(); 
            cost += right * left;
        }

        return cost;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> arr1 = {6, 2, 4};
    cout << "Test Case 1: " << sol.mctFromLeafValues(arr1) << " (Expected: 32)" << endl;

    // Test case 2
    vector<int> arr2 = {4, 11};
    cout << "Test Case 2: " << sol.mctFromLeafValues(arr2) << " (Expected: 44)" << endl;
    
    return 0;
}
