int dir[5] = {0, 1, 0, -1, 0};
class Solution {
    void paint(vector<vector<int>>& A, int i, int j, queue<pair<int, int>> &q) {
    if (min(i, j) >= 0 && max(i, j) < A.size() && A[i][j] == 1) {
        A[i][j] = 2;
        q.push({i, j});
        for (int d = 0; d < 4; ++d)
            paint(A, i + dir[d], j + dir[d + 1], q);
    }
}
public:
    int shortestBridge(vector<vector<int>>& A) {
    queue<pair<int, int>> q;
    for (int i = 0; q.size() == 0 && i < A.size(); ++i)
        for (int j = 0; q.size() == 0 && j < A[0].size(); ++j)
            paint(A, i, j, q);
    
    while (!q.empty()) {
        int sz=q.size();
        for (;sz--;) {
            int i=q.front().first,
                j=q.front().second;
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int x = i + dir[d], y = j + dir[d + 1];
                if (min(x, y) >= 0 && max(x, y) < A.size()) {
                    if (A[x][y] == 1){
                        /*printing the matrix */
    // for(auto i:A){
    //     for(auto j:i)
    //         cout<<j<<" ";
    //     cout<<endl;
    // }
                        return A[i][j] - 2;
                    }
                    if (A[x][y] == 0) {
                        A[x][y] = A[i][j] + 1;
                        q.push({x, y});
                    }
                }
            }
        }
        cout<<"before swap "<<q.size() <<endl;
        // // swap(q, q1);
        // cout<<"after swap "<<q.size() <<q1.size()<<endl;
    }
    return 0;
}
};