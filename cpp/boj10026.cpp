#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N;
vector<string> arr;
vector<vector<bool>> visited;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void bfs(int r, int c, bool is_cblind)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    char color = arr[r][c];

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
                        
            if(nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc])
            {
                char next_color = arr[nr][nc];
                bool target = false;

                if(is_cblind)
                {
                    if (color == 'B')
                    {
                        target = (next_color == 'B');
                    }
                    else
                    {
                        target = (next_color == 'R' || next_color == 'G');
                
                    }
                }
                else
                {
                    target = (color == next_color);
                }

                if(target)
                {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
}

int count_areas(bool is_cblind)
{
    visited.assign(N, vector<bool>(N, false));
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (!visited[i][j])
            {
                bfs(i, j, is_cblind);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    freopen("input.txt","r",stdin);
    
    if (!(cin >> N)) return 0;
    arr.resize(N);
    
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int nonblind = count_areas(false);
    int blind = count_areas(true);

    cout << nonblind << " " << blind << endl;

    return 0;
}
