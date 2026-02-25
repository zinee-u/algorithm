//https://www.acmicpc.net/problem/15651

#include <iostream>

#define MAX_NUM 14

using namespace std;

int N, M;
int arr[MAX_NUM];

void input()
{
    freopen("input.txt","r",stdin);
    cin >> N >> M;
}

void DFS(int dep)
{
    if(dep==M)
    {
        for(int i=0; i<M; i++)
        {
            cout << arr[i] << endl;
        }
        return;
    }
    for(int i=1; i<=N; i++)
    {
        arr[dep] = i;
        DFS(dep+1);
    }
}

int main(void)
{
    input();
    DFS(0);
    return 0;
}