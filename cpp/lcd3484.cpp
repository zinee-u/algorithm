//https://leetcode.com/problems/design-spreadsheet/?envType=daily-question&envId=2026-02-14
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

#define MAX_COL 26

class Spreadsheet
{
private:
    vector<vector<int>> sheet;

    int getCol(string s)
    {
        char c = s[0];
        return c - 'A';
    }
    int getRow(string s)
    {
        string s1 = s.substr(1);
        return stoi(s1);
    }

public:
    Spreadsheet(int rows)
    {
        sheet = vector<vector<int>>(rows+1, vector<int>(MAX_COL, 0));
    }
    
    void setCell(string cell, int value)
    {
        sheet[getRow(cell)][getCol(cell)] = value;
    }
    
    void resetCell(string cell)
    {
        sheet[getRow(cell)][getCol(cell)] = 0;   
    }
    
    int getValue(string formula)
    {
        string s1, s2;
        bool seenPlus = false;
        for(int i = 0; i<formula.size(); i++)
        {
            char c = formula[i];
            if(c=='=')
            {/*do nothing*/}
            else if(c=='+')
            {
                seenPlus = true;
            }
            else if(seenPlus)
            {
                s2 += c;
            }
            else
            {
                s1+=c;
            }
        }
        int n1, n2;
        if(isdigit(s1[0]))
        {
            n1 = stoi(s1);
        }
        else
        {
            n1 = sheet[getRow(s1)][getCol(s1)];
        }
        if(isdigit(s2[0]))
        {
            n2 = stoi(s2);
        }
        else
        {
            n2 = sheet[getRow(s2)][getCol(s2)];
        }
        return n1+n2;
    }
};

int main(void)
{
    return 0;
}