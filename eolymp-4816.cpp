#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjacency;
vector<bool> visited;
vector<int> st;
vector<vector<int>> components;

void dfs(int u)
{
    // Set current vertex as visited.
    visited[u] = true;
    // Loop through every adjacent vertex.
    for (int v : adjacency[u])
        // If adjacent vertex is not visited, run dfs recursively.
        if (!visited[v])
        {
            dfs(v);
            st.push_back(v);
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

    int counter = 0;
    // Loop through all unvisited vertices.
    for (v = 1; v < visited.size(); v++)
        if (!visited[v])
        {
            // Traverse a graph component.
            dfs(v);
            st.push_back(v);
            // Save vertices of a component.
            components.push_back(st);
            st.clear();
            counter++;
        }
    
    // Show output.
    cout << counter << '\n';
    for (int i = 0; i < components.size(); i++)
    {
        cout << components[i].size() << '\n';
        for (int j = 0; j < components[i].size(); j++)
            cout << components[i][j] << ' ';
        cout << '\n';
    }
}
