
#include <iostream>

using namespace std;

#define MAX 10

int N, M;
int arr[MAX];

void input()
{
  freopen("input.txt", "r", stdin);
  cin >> N >> M;
}

void printCases()
{
  for(int i=0; i<M; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void DFS(int dep, int start)
{
  if(dep == M)
  {
    printCases();
    return;
  }
  for(int i=start; i<=N; i++)
  {
    arr[dep] = i;
    DFS(dep+1, i);
  }
}

int main(void)
{
  input();
  // cout << N << M << endl;
  DFS(0, 1);
  return 0;
}
