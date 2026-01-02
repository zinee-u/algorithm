#include <stdio.h>
#include <iostream>

using namespace std;

int count;

void DFS(int depth, int arr[5])
{
  count++;
  cout << "depth = " << depth << " count = " << count << endl;

  if(depth==5)
    return;
  
  cout << "DFS starts " << depth << endl;
  
  arr[depth] = 100;
  
  for(int i=0; i<5; ++i)
  {
    cout << arr[i] << endl;
  }

  DFS(depth+1, arr);

  for(int i=0; i<5; ++i)
  {
    cout << arr[i] << endl;
  }
  cout << "DFS ends " << depth << endl;
}

int main()
{
  int a[5] = {0,};
  for(int i=0; i<5; ++i) a[i] = i+1;  

  cout << "main starts" << endl;
  cout << "count " << count << endl;
  
  for(int i=0; i<5; ++i) cout << a[i] << endl;

  DFS(1,a);

  cout << "main ends" << endl;
  cout << "cout " << count << endl;

  for(int i=0; i<5; ++i) cout << a[i] << endl;

  return 0;
}