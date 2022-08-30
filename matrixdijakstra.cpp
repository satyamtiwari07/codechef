//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    
    bool isvalid(int r,int c, int ro , int col ){
        if(ro<0 || col<0 || ro>=r || col>=c) 
            return false;
        
        return true;
    }
    
    
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        vector<pair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dist(r,vector<int>(c,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        //        distance   x-y coordinats
        pq.push({grid[0][0],{0,0}});
        dist[0][0]=grid[0][0];
        
        while(!pq.empty()){
           
           int distance=pq.top().first;
           int ro=pq.top().second.first;
           int col=pq.top().second.second;
           pq.pop();
           
           for(int x=0;x<4;x++){
               int nr=ro+dir[x].first;
               int nc=col+dir[x].second;
               
               if(isvalid(r,c,nr,nc) and dist[nr][nc]>distance+grid[nr][nc]){
                   dist[nr][nc]=distance+grid[nr][nc];
                   pq.push({dist[nr][nc],{nr,nc}});
               }
           }
        }
        
        // if(dist[r-1][c-1]==INT_MAX)
        //     return -1;
        
        return dist[r-1][c-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
