class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else {
                mat[i][j]=INT_MAX; 
            }
            }
        }
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!q.empty()){
            auto[r,c]=q.front();q.pop();
            for(int d=0;d<4;d++){
                int nr=r+dr[d],nc=c+dc[d];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&mat[nr][nc]==INT_MAX){
                    mat[nr][nc]=mat[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return mat;
    }
};