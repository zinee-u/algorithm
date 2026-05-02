// https://www.acmicpc.net/problem/15649

#include <iostream>
using namespace std;

#define MAX 10

int N, M;
int arr[MAX];
int visited[MAX];

void input(void)
{
  freopen("input.txt", "r", stdin);
  cin >> N >> M;
}

void printArr(void)
{
  for(int i=0; i<M; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void DFS(int dep)
{
  if(dep == M)
  {
    printArr();
    return;
  }
  for(int i=1; i<=N; i++)
  {
    if(visited[i]==1) continue;

      arr[dep] = i;
      visited[i] = 1;
      DFS(dep+1);
      visited[i] = 0;

  }
}

int main(void)
{
  input();
  DFS(0);
  return 0;
}