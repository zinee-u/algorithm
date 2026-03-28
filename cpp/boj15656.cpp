// https://www.acmicpc.net/problem/15656

#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX (7+3)

int N, M;

int num_of_cases[MAX];
int number[MAX];

void input(void)
{
  cin >> N >> M;
  for(int i=1; i<N+1; i++)
  {
    cin >> number[i];
  }
}

void printCases()
{
  for(int i=0; i<M; i++)
  {
    cout << num_of_cases[i] << endl;
  }
}


void DFS(int dep)
{
  if(dep==M)
  {
    printCases();
    return;
  }

  for(int i=1; i<=N; i++)
  {
    num_of_cases[dep] = number[i];
    DFS(dep+1);
  }
}


int main(void)
{
  freopen("input.txt","r",stdin);
  input();
  for(int i=1; i<=N-1; i++)
  {
    for(int k=i+1; k<=N; k++)
    {
      if(number[i]>number[k])
      {
        int tmp = number[i];
        number[i] = number[k];
        number[k] = tmp;
      }
    }
  }
  DFS(0);
  return 0;
}
