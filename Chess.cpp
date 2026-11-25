#include <bits/stdc++.h>
using namespace std;

int digitValue(char ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    return ch - 'A';
}

int main() {
    int n;
    cin >> n;

    vector<string> grid(8);

    vector<int> dc = {1, 1, -1, -1};
    vector<int> dr = {1, -1, 1, -1};

    while(n--) {
        int sr, sc, er, ec;

        for(int i = 0; i < n; i++) {
            char x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            x1 = digitValue(sr);
            y1 = digitValue(sc);
        
            x2 = digitValue(er);
            y2 = digitValue(ec);

        }

        vector<vector<int>> dist(8, vector<int>(8, -1));  // -1 = unvisited
        queue<pair<int, int>> q;

    
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= 8 || nc < 0 || nc >= 8) continue; // off the grid;
                if (grid[nr][nc] == '#') continue; // wall
                if (dist[nr][nc] != -1) continue; // already visited
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }

        if(dist[er][ec] < 0) cout << "impossible\n";
        else cout << dist[er][ec] << "\n";
    }
}