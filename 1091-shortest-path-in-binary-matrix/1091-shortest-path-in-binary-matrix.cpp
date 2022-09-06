class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
               int n = grid.size(), m = grid[0].size();
        if (!n || !m || grid[0][0]) return -1;
        if (n == 1 && m == 1) return 1;
        queue<pair<pair<int,int>,int>>pathQ;
        vector<pair<int,int>>dir = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
        int i, j;
        pathQ.push({{0, 0}, 1});
        while (!pathQ.empty()) {
            auto currCoord = pathQ.front();
            pathQ.pop();
            for (auto x : dir) {
                i = currCoord.first.first + x.first;
                j = currCoord.first.second + x.second;
                if (i >= 0 && j >= 0 && i < n && j < m && !grid[i][j]) {
                    if (i == n - 1 && j == m - 1) {
                        return currCoord.second + 1;
                    } else {
                        grid[i][j] = 1;
                        pathQ.push({{i, j}, currCoord.second + 1});
                    }
                }
            }
        }
        return -1;
    }
};