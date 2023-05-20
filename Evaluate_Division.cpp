class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> graph;
   
    vector<double> res;
    bool dfs(string start,string end,unordered_map<string,vector<pair<string,double>>> &graph,double val, unordered_map<string,int> &vis)
    {
        if(start==end && graph.find(start)!=graph.end())
        {
            res.push_back(val);
            return true;
        }
        vis[start]=1;
        for(int i=0;i<graph[start].size();i++)
        {
            if(vis[graph[start][i].first]!=1)
            {
                if(dfs(graph[start][i].first,end,graph,val*graph[start][i].second,vis))return true;
            }
        }
        // vis[start]=false;
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++)
        {
            string st=equations[i][0];
            string end=equations[i][1];
            graph[st].push_back({end,values[i]});
            graph[end].push_back({st,1/values[i]}); 
            // vis[st]=false;
            // vis[end]=false;
        }
        for(int i=0;i<queries.size();i++)
        {
            double val=1;
             unordered_map<string,int> vis;
            string st=queries[i][0];
            string end=queries[i][1];
            bool b=dfs(st,end,graph,val,vis);
            if(b==false)res.push_back(-1);
        }
        return res;
    }
};


