#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjacency;
vector<int> lengths;

// Calculate path lengths by using BFS.
void findPaths(int s)
{
    queue<int> q;

    // Set start vertex as visited with path length 0.
    lengths[s] = 0;
    q.push(s);
    // Traverse a graph.
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // Iterate through every adjacent vertex.
        for (int v = 0; v < adjacency.size(); v++)
        {
            // If adjacent and not visited,
            // set as visited and increment path length.
            if (adjacency[u][v] && lengths[v] == -1)
            {
                lengths[v] = lengths[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    
    // Resize adjacency matrix of a graph.
    adjacency.resize(n, vector<int>(n));
    // Resize matrix of path lengths.
    lengths.resize(n, -1);

    // Fill adjacency matrix.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adjacency[i][j];

    // Traverse a graph from vertex x.
    findPaths(x - 1);

    // Show output.
    for (int v = 0; v < n; v++)
        cout << lengths[v] << ' ';
}
