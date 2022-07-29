#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+10;
int parent[N];
int size[N];

void make(int a){
  parent[a]=a;
  size[a]=1;
}

int find(int a){
  if(a==parent[a]) return a;

  //path compression
  return parent[a]=find(parent[a]);

} 
void Union(int a,int b){

  a=find(a);//find parent of a
  b=find(b);//find parent of b

  if(a==b) return ;
  
  //union by size
  else{
    if(size[a]>size[b]){
        parent[b]=a;
        size[a]+=size[b];
      }
      else{
        parent[a]=b;
        size[b]+=size[a];
      }
    }

}

void solve(){
  int n,m;
  cin>>n>>m;
  
  for(int x=1;x<=n;x++){
    make(x);
  }

              //wt     //u  v
  vector<pair<int,pair<int,int>>>edges;

  for(int x=0;x<m;x++){
    int u,v,wt;
    cin >> u >> v >> wt;
    edges.push_back({wt,{u,v}});
  }

  sort(edges.begin(),edges.end());

  int count=0;
  for(auto &edge:edges){
    int wt=edge.first;
    int u =edge.second.first;
    int v= edge.second.second;
    if(find(u)==find(v)) continue;

    Union(u,v);
    count+=wt;
  }

  cout<<count;

}

signed main()
{
   FAST_IO 
   
   int t=1;
   //cin>>t;
   while(t--){ 
      solve();
   }
    return 0; 
}
