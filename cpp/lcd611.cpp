// https://leetcode.com/problems/valid-triangle-number/?envType=daily-question&envId=2026-02-21
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int triangleNumer(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int n = (int)nums.size();
    long long ans = 0;
    for(int k=n-1; k>=2; --k)
    {
        int i=0, j=k-1;
        while(j>i)
        {
            if(nums[i]+nums[j]>nums[k])
            {
                ans+=(j-i);
                --j;
            }
            else
            {
                ++i;
            }
        }
    }
    return (int)ans;
}

int main()
{
    vector<int> testNums(1000);
    int res;
    // freopen("./input.txt","r",stdin);
    // cin >> testNums;
    testNums[0] = 4;
    testNums[1] = 2;
    testNums[2] = 3;
    testNums[3] = 4;
    res = triangleNumer(testNums);
    cout << res << endl;
    return 0;
}