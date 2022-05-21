class Solution {
public:
    vector<vector<long>> a;
    int n, m;
    
    bool good(long mn) {
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        vis[0][0] = 1;
        
        queue<array<long, 3>> q;
        q.push({0, 0, mn});
        
        while(!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            long dis = q.front()[2];
            
            q.pop();
            
            if(x == n - 1 and y == m - 1) {
                return 1;
            }
            if(a[x][y] <= dis) {
                continue;
            }
            
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            // DURL
            for(int t = 0; t < 4; ++t) {
                int i = x + dx[t];
                int j = y + dy[t];
                
                if(min(i, j) >= 0 and i < n and j < m and !vis[i][j] and a[x][y] != -1 and dis + 1 <= a[i][j]) {
                    q.push({i, j, dis + 1});
                    vis[i][j] = 1;
                }
            }
        }
        
        return 0;
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        a.resize(n, vector<long> (m, 1e10));
        
        queue<pair<int, int>> q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 1) {
                    a[i][j] = 0;
                    q.push({i, j});
                } else if(grid[i][j] == 2) {
                    a[i][j] = -1;
                }
            }
        }
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            
            for(int t = 0; t < 4; ++t) {
                int i = x + dx[t];
                int j = y + dy[t];
                
                if(min(i, j) >= 0 and i < n and j < m and a[i][j] != -1 
                   and a[x][y] + 1 < a[i][j]) {
                    a[i][j] = a[x][y] + 1;
                    q.push({i, j});
                }
            }
        }
        /*
        
        
        
        */
        // cout<<" printing size is "<<q.size()<<endl;
        // for(auto arr:a){
        //     for(auto it:arr)
        //         cout<< it<<" "; cout<<endl;
        // }
        long l = 0, r = 1e9, best = -1;
        // r=7;
        while(l <= r) {
            long mid = l + (r - l) / 2;
            
            if(good(mid)) {
                best = mid,
                l = mid + 1;
            } else {
                r = mid - 1;
            }
            cout<< " best is "<<best<<" "<<mid <<endl;
        }
        
        return best;
    }
};
/*

Clues:
If man reaches erly to end position, then return some digits
If fire reaces end position early then return -1
If fire doesnt reaches end position ten return 10^9


0 2 0 0 0 0 0
0 0 0 2 2 1 0
0 2 0 0 1 2 0
0 0 2 2 2 0 2
0 0 0 0 0 0 0

t=1
M 2 0 0 0 1 0
0 0 0 2 2 1 1
0 2 0 1 1 2 0
0 0 2 2 2 0 2
0 0 0 0 0 0 0

t=2
M 2 0 0 1 1 1
0 0 0 2 2 1 1
0 2 1 1 1 2 1
0 0 2 2 2 0 2
0 0 0 0 0 0 0

t=3
M 2 0 1 1 1 1
0 0 1 2 2 1 1
0 2 1 1 1 2 1
0 0 2 2 2 0 2
0 0 0 0 0 0 0

t=4
0 2 1 1 1 1 1
1 1 1 2 2 1 1
1 2 1 1 1 2 1
1 1 2 2 2 0 2
1 M 0 0 0 0 0


Some stiff problem is thrown at me, im feeling overwhelming
let me do facewash first then ill feel fresh

*/
