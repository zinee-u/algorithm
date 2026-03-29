#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX (7+3)

int N, M;

int nums[MAX];
int ans[MAX];


void input(void)
{
  freopen("input.txt","r",stdin);
  
  cin >> N >> M;

  for(int i=1; i<N+1; i++)
  {
    cin >> nums[i];  
  }
}


void printOutput(void)
{
  for(int i=0; i<M; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}


void DFS(int dep, int start)
{
  if(dep == M)
  {
    printOutput();
    return;
  }
  for(int i=start; i<=N; i++)
  {
    ans[dep] = nums[i];
    //cout << ans[dep] << endl;
    DFS(dep+1, i);
  }
}


int main(void)
{
  input();
  //cout << N << M << endl;
  for(int i=1; i<N; i++)
  {
    for(int k=i+1; k<=N; k++)
    {
      if(nums[i] > nums[k])
      {
        int tmp = nums[i];
        nums[i] = nums[k];
        nums[k] = tmp;
      }
    }
  }
  DFS(0,1);
  return 0;
}
