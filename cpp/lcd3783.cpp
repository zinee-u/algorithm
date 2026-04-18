// https://leetcode.com/problems/mirror-distance-of-an-integer/submissions/1981373482/?envType=daily-question&envId=2026-04-18
#include <stdio.h>
#include <iostream>

using namespace std;

int mirrorDistance(int n)
{
  int rev = 0;
  int x = n;
  while(x)
  {
    rev = (rev*10) + (x%10);
    x/=10; 
  }
  return abs(n - rev);
}

int main(void)
{
  int n = 10;
  cout << mirrorDistance(n) << endl;
}