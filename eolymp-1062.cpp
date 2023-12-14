#include <bits/stdc++.h>
using namespace std;

// Struct of matrix element.
// i - row number, j - column number.
typedef struct 
{
    int i;
    int j;
} element;

vector<vector<char>> matr;
vector<vector<bool>> visited;
vector<vector<element>> paths;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // Resize vectors.
    matr.resize(n, vector<char> (n));
    visited.resize(n, vector<bool> (n));
    paths.resize(n);
    
    // Get input and fill array visited.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matr[i][j];
            visited[i][j] = false;
        }
    }


    // Find starting point.
    int x = 0, y = 0;
    bool found = false;
    for (x = 0; x < n && !found; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (matr[x][y] == '@')
            {
                found = true;
                break;
            }
        }
    }
    x--;
    
    // Find shortest path to X (DFS).
    queue<element> q;
    // Set the starting point as visited.
    visited[x][y] = true;
    q.push({x, y});
    // Traverse a graph.
    element u = q.front();
    while (!q.empty() && matr[u.i][u.j] != 'X')
    {
        // Iterate through every adjacent vertex (.).
        u = q.front();
        q.pop();
        // Check the top point.
        if (u.i - 1 >= 0 && matr[u.i - 1][u.j] != 'O' && !visited[u.i - 1][u.j])
        {
            // Add current point to the queue.
            q.push({u.i - 1, u.j});
            visited[u.i - 1][u.j] = true;
            paths[0].push_back({u.i - 1, u.j});
            //cout << "pushed " << u.i - 1 << ' ' << u.j << '\n';
        }
        // Check the bottom point.
        if (u.i + 1 < n && matr[u.i + 1][u.j] != 'O' && !visited[u.i + 1][u.j])
        {
            q.push({u.i + 1, u.j});
            visited[u.i + 1][u.j] = true;
            paths[0].push_back({u.i + 1, u.j});
            //cout << "pushed " << u.i + 1 << ' ' << u.j << '\n';
        }
        // Check the left point.
        if (u.j - 1 >= 0 && matr[u.i][u.j - 1] != 'O' && !visited[u.i][u.j - 1])
        {
            q.push({u.i, u.j - 1});
            visited[u.i][u.j - 1] = true;
            paths[0].push_back({u.i, u.j - 1});
            //cout << "pushed " << u.i << ' ' << u.j - 1 << '\n';
        }
        // Check the right point.
        if (u.j + 1 < n && matr[u.i][u.j + 1] != 'O' && !visited[u.i][u.j + 1])
        {
            q.push({u.i, u.j + 1});
            visited[u.i][u.j + 1] = true;
            paths[0].push_back({u.i, u.j + 1});
            //cout << "pushed " << u.i << ' ' << u.j + 1 << '\n';
        }
        //cout << "M[" << u.i << "][" << u.j << "] = \'" << matr[u.i][u.j] << "\'\n";
        //cout << q.empty() << '\n';
    }
    /*
    TODO:
    (+) recognize X.
    - dead end.
    - store path to X in vector<element>.
    - change input matrix based on path vector.
    */
    //cout << "M[" << u.i << "][" << u.j << "] = \'" << matr[u.i][u.j] << "\'\n";

    // Modify input matrix.
    for (element u : paths[0])
    {
        matr[u.i][u.j] = '+';
    }

    // Show output.
    if (paths[0].empty())
    {
        cout << "N\n";
    }
    else
    {
        cout << "Y\n";
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matr[i][j];
        cout << '\n';
    }
}
