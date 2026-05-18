#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10

int N, M;
int arrIn[MAX]={0};
int arrOut[MAX] = {0};


void printArr(void)
{
  for(int i=0; i<M; i++)
  {
    cout << arrOut[i];
  }
  cout << endl;
}

void input(void)
{
  freopen("input.txt", "r", stdin);
  cin >> N >> M;
  for(int i=0; i<N; i++)
  {
    cin >> arrIn[i];
  }
  sort(arrIn, arrIn+N);
}

void DFS(int dep, int start)
{
  if(dep == M)
  {
    printArr();
    return;
  }

  for(int i=start; i<N; i++)
  {
    arrOut[dep] = arrIn[i];
    DFS(dep+1, i+1);
  }
}

int main(void)
{
  input();
  DFS(0, 0);
  return 0;
}