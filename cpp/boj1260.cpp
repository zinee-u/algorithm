// https://www.acmicpc.net/problem/1260
#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX (1000+100)

int N, M, V;
int ARR[MAX][MAX] = {0,};
int visit[MAX] = {0,};
int visit_dfs[MAX];
int q[MAX];

void input(void)
{
    //freopen("input.txt","r",stdin);
    cin >> N >> M >> V;
    for(int i=0; i<M; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        ARR[n1][n2] = 1;
        ARR[n2][n1] = 1;
    }
}

void printMap(void)
{
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<M; c++)
        {
            cout << ARR[r][c];
        }
        cout << endl;
    }
}

void DFS(int node)
{
    visit_dfs[node] = 1;
    cout << node << " ";
    
    for(int i=1; i<=N; i++)
    {
        if(ARR[node][i]==0||ARR[i][node]==0||visit_dfs[i]==1) continue;
        DFS(i);
    }
}


void BFS(int node)
{
    int pw, pr;
    pw = pr = 0;
    q[pw++] = node;
    visit[node] = 1;
    while(pw > pr)
    {
        int out = q[pr++];
        for(int i=1; i<=N; i++)
        {
            if(ARR[out][i]==0 || ARR[i][out]==0 || visit[i]==1) continue;
            visit[i] = 1;
            q[pw++] = i;
        }
    }
    for(int j=0; j<pr; j++)
    {
        cout << q[j] << " ";
    }
}

int main(void)
{
    input();
    // printMap();
    DFS(V);
    cout << endl;
    BFS(V);
}