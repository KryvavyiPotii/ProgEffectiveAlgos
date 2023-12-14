#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjacency;
vector<bool> visited;
vector<int> st;

void dfs(int u)
{
    // Set current vertex as visited.
    visited[u] = true;
    // Loop through every adjacent vertex.
    for (int v : adjacency[u])
    {
        // If adjacent vertex is not visited, run dfs recursively.
        if (!visited[v])
        {
            dfs(v);
            st.push_back(v);
            // Print edge.
            cout << u << ' ' << v << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;
    // Resize adjacency matrix of a graph.
    adjacency.resize(n + 1);
    // Resize matrix of visited elements.
    visited.resize(n + 1, false);

    int u, v;
    // Fill adjacency matrix.
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }

    if (m)
    {
        // Traverse a graph.
        dfs(v);
    }
}
