#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Union-Find (Disjoint Set) structure
struct DSU
{
    vector<int> parent;
    DSU(int n)
    {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            parent[rootY] = rootX;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Uncomment the line below if testing with input.txt specifically
    // freopen("input.txt", "r", stdin);

    int N, M;
    if (!(cin >> N)) return 0;
    cin >> M;

    DSU dsu(N);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++) {
            int connected;
            cin >> connected;
            if (connected == 1) {
                dsu.unite(i, j);
            }
        }
    }

    int start_node = -1;
    bool possible = true;
    
    for (int i = 0; i < M; i++)
    {
        int city;
        cin >> city;
        
        if (i == 0)
        {
            start_node = dsu.find(city);
        }
        else
        {
            if (dsu.find(city) != start_node)
            {
                possible = false;
            }
        }
    }

    if (possible) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
