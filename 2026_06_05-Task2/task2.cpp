#include <iostream>
#include <vector>
#include <climits>
using namespace std;
//MEDIUM (Shortest Path in Binary Maze)

//Cheking a cell can be visited or not
bool isSafe(vector<vector<int>>& mat,
            vector<vector<bool>>& visited,
            int x,
            int y)
{
    return (x >= 0 &&
            x < mat.size() &&
            y >= 0 &&
            y < mat[0].size() &&
            mat[x][y] == 1 &&
            !visited[x][y]);
}

// Recursive DFS + Backtracking
void shortPath(vector<vector<int>>& mat,
               vector<vector<bool>>& visited,
               int i,
               int j,
               int x,
               int y,
               int& min_dist,
               int dist)
{
    // Destination reached
    if(i == x && j == y)
    {
        min_dist = min(min_dist, dist);
        return;
    }

    // Mark current cell visited
    visited[i][j] = true;

    // Move Down
    if(isSafe(mat, visited, i + 1, j))
        shortPath(mat, visited,
                  i + 1, j,
                  x, y,
                  min_dist,
                  dist + 1);

    // Move Right
    if(isSafe(mat, visited, i, j + 1))
        shortPath(mat, visited,
                  i, j + 1,
                  x, y,
                  min_dist,
                  dist + 1);

    // Move Up
    if(isSafe(mat, visited, i - 1, j))
        shortPath(mat, visited,
                  i - 1, j,
                  x, y,
                  min_dist,
                  dist + 1);

    // Move Left
    if(isSafe(mat, visited, i, j - 1))
        shortPath(mat, visited,
                  i, j - 1,
                  x, y,
                  min_dist,
                  dist + 1);

    // Backtrack
    visited[i][j] = false;
}

int shortPathLength(vector<vector<int>>& mat,
                    pair<int,int>& src,
                    pair<int,int>& dest)
{
    if(mat.empty() ||
       mat[src.first][src.second] == 0 ||
       mat[dest.first][dest.second] == 0)
    {
        return -1;
    }

    int rows = mat.size();
    int cols = mat[0].size();

    vector<vector<bool>> visited(
        rows,
        vector<bool>(cols, false)
    );

    int min_dist = INT_MAX;

    shortPath(mat,
              visited,
              src.first,
              src.second,
              dest.first,
              dest.second,
              min_dist,
              0);

    return (min_dist == INT_MAX) ? -1 : min_dist;
}
int main()
{
    vector<vector<int>> mat =
    {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 1}
    };

    pair<int, int> src = {0, 0};
    pair<int, int> dest = {3, 4};

    int dist = shortPathLength(mat, src, dest);

    cout << "Shortest Distance = " << dist << endl;

    return 0;
}
