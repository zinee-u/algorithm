// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        for(int i=0; i<nums.size(); i++)
        {
            indices[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for(auto& [value, v]: indices)
        {
            if(v.size()<3) continue;
            for(int i =0; i+2<v.size(); i++)
            {
                ans = min(ans, 2*(v[i+2]-v[i])); /* |i-j| + |j-k| + |k-i| = 2 * (k - i) */
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums = {1,2,1,1,3};
    // vector<int> nums = {1,1,2,3,2,1,2};
    // vector<int> nums = {1};
    cout << sol.minimumDistance(nums) << endl;
    return 0;
}