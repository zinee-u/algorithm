//https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/?envType=daily-question&envId=2026-03-07
#include <iostream>
#include <string>

using namespace std;

string s = "1110";

int minFlips(string s)
{
        // PatternA : 010101...
        int pAodd0s = 0;
        int pAeven1s = 0;

        // PatternB : 101010...
        int pBodd1s = 0;
        int pBeven0s = 0;

        int n = s.size();

        // 1. 현재 문자열 기준 mismatch 개수 세기
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0) // even index
            {
                if (s[i] == '0')
                {
                    pBeven0s++;   // PatternB에서 틀림
                }
                else
                {
                    pAeven1s++;   // PatternA에서 틀림
                }
            }
            else // odd index
            {
                if (s[i] == '0')
                {
                    pAodd0s++;    // PatternA에서 틀림
                }
                else
                {
                    pBodd1s++;    // PatternB에서 틀림
                }
            }
        }

        int cnt = min(pAodd0s + pAeven1s, pBodd1s + pBeven0s);

        // 2. 홀수 길이일 때만 rotation 확인
        if ((s.size() % 2) != 0)
        {
            for (int i = 0; i < s.size(); i++)
            {
                /* even index */
                if (i % 2 == 0)
                {
                    if (s[i] == '0')
                    {
                        pAodd0s++;
                        pBeven0s--;
                    }
                    else
                    {
                        pAeven1s--;
                        pBodd1s++;
                    }
                }
                /* odd index */
                else
                {
                    if (s[i] == '0')
                    {
                        pAodd0s--;
                        pBeven0s++;
                    }
                    else
                    {
                        pAeven1s++;
                        pBodd1s--;
                    }
                }

                int tmp = min(pAodd0s + pAeven1s, pBodd1s + pBeven0s);
                cnt = min(cnt, tmp);
            }
        }

        return cnt;
}

int main(void)
{
    cout << minFlips(s) << endl;
    return 0;
}