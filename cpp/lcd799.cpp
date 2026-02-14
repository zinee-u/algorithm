//https://leetcode.com/problems/champagne-tower/?envType=daily-question&envId=2026-02-14

#include <iostream>
#include <vector>

using namespace std;

double champagneTower(int poured, int query_row, int query_glass)
{
    vector<vector<double>> tower(102, vector<double>(102, 0.0));
    tower[0][0] = poured;
    for(int i=0;i<=query_row;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(tower[i][j]>1.0)
            {
                double overflow = (tower[i][j]-1.0)/2.0;
                tower[i+1][j] += overflow;
                tower[i+1][j+1] += overflow;
            }
        }
    }
    return min(1.0, tower[query_row][query_glass]);
}

int main(void)
{
    double ans;
    int poured, query_row, query_glass;

    freopen("input.txt","r",stdin);
    cin >> poured >> query_row >> query_glass;
    ans = champagneTower(poured, query_row, query_glass);
    cout << ans << endl;
}