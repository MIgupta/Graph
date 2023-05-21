class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &vis,queue<pair<int,int>> &q)
    {
        int n= grid.size();
        vis[r][c]=1;
        int d_row[]={-1,0,+1,0};
        int d_col[]={0,+1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nr=r+d_row[i];
            int nc=c+d_col[i];
            
            if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1 && vis[nr][nc]==0)
            {
                dfs(nr,nc,grid,vis,q);
            }
            else if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && vis[nr][nc]==0)
            {
                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }
       
return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n= grid.size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        int flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    flag=1;
                    dfs(i,j,grid,vis,q);
                        break;
                }
            }
            if(flag)
            break;
        }
        int d_row[]={-1,0,+1,0};
        int d_col[]={0,+1,0,-1};
        int level=0;
        while(q.size())
        {
            int size=q.size();
            while(size--)
            {
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if(grid[r][c]==1)return level;
                for(int i=0;i<4;i++)
                {
                    int nr=r+d_row[i];
                    int nc=c+d_col[i];
                    
                    if(nr>=0 && nr<n && nc<n && nc>=0 && vis[nr][nc]==0)
                    {
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
            level++;
        }
        return level;
    }
};