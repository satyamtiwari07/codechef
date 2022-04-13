#include<bits/stdc++.h>

using namespace std;

void solve(){
 string text1 = "abc", text2 = "abc"; 
 
 int n=text1.size();
 int m=text2.size();
        
 vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
 
  //base case of tabulation
  for(int idx2=0;idx2<m+1;idx2++) dp[0][idx2]=0;
        
  for(int idx1=0;idx1<n+1;idx1++) dp[idx1][0]=0;
        
   //recurence     
  for(int idx1=1 ; idx1<n+1 ; idx1++){
    for(int idx2=1 ; idx2<m+1 ; idx2++){
      //if matching 
      if(text1[idx1-1]==text2[idx2-1]) dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
        
      //not matching
      else dp[idx1][idx2]=0+max( dp[idx1][idx2-1] , dp[idx1-1][idx2] );
    }
  }
        
  //printing dp table
  for(int x=0;x<=n;x++){
    for(int y=0;y<=m;y++){
      cout<<dp[x][y]<<' ';
    }
    cout<<endl;
  }
  
  //printing longest common subsequence
  string s="";
  int i=n,j=m;

  while(i>0 && j>0){
    cerr<<i<<" "<<j;
    if(text1[i-1]==text2[j-1]){
      
      s.push_back(text1[i-1]);
      //digonal move
      i--;
      j--;
    
    }
    else if(dp[i][j-1]>dp[i-1][j]){
      j--;
    }
    else{
      i--;
    }
  }

    reverse(s.begin(),s.end());
    cout<<s;
} 
 
signed main(){
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int t=1;
  // cin>>t;
  while(t--){
      solve();
  }
 
  return 0;
}
