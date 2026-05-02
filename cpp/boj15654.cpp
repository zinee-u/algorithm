#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 10

int N, M;
int arr[MAX];
int arr_ans[MAX];
int visited[MAX];

void input(void)
{
  freopen("input.txt", "r", stdin);
}

void printArr(void)
{
  for(int i=0; i<M; i++)
  {
    cout << arr_ans[i] << " ";
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
  for(int i=0; i<N; i++)
  {
    if(visited[i]==1) continue;
    arr_ans[dep] = arr[i];
    visited[i] = 1;
    DFS(dep+1);
    visited[i] = 0;
  }
}

int main(void)
{
  input();
  cin >> N >> M;
  
  for(int i=0; i<N; i++)
  {
    cin >> arr[i];
  }
  sort(arr, arr+N);
  DFS(0);
  return 0;
}