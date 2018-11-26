/*
 * Complete the function below.
 */
#include <bits/stdc++.h>
using namespace std;

bool valid(int rows, int cols, int i, int j) {
    return (i >= 0 && j >= 0 && i < rows && j < cols);
}
vector<pair<int, int>> neighbors(int rows, int cols, pair<int, int> p) {
    vector<pair<int, int>> result;
    vector<pair<int, int>> v = {{2, 1}, {2, -1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}};
    for (auto c : v) {
        if (valid(rows, cols, p.first + c.first, p.second + c.second))
            result.push_back({p.first + c.first, p.second + c.second});
    }
    return result;
}
int find_minimum_number_of_moves(int rows, int cols, int start_row, int start_col, int end_row, int end_col) {
    // Write your code here.
    vector<vector<bool>> visited(rows, vector<bool> (cols, false));
    queue<pair<int, int>> q;
    int i = start_row, j = start_col;
    visited[i][j] = true;
    q.push({i, j});
    int result = 0, old = 1, new_count = 0;
    while (!q.empty()) {
        pair <int, int> p = q.front();
        if (p.first == end_row && p.second == end_col)
            return result;
        q.pop();
        old--;
        for (auto n : neighbors(rows, cols, p))
            if (!visited[n.first][n.second]) {
                visited[n.first][n.second] = true;
                q.push(n);
                new_count++;
            }
        
        if (old == 0) {
            result++;
            old = new_count;
            new_count = 0;
        }
    }
    return -1;
}

