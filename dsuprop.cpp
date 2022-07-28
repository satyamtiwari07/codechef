// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/

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
  
  int n , q;
  cin >> n >> q;
  for(int x=1;x<=n;x++){
    make(x);
  }

  while(q--){
    int u,v;
    cin>>u >> v;
    Union(u,v);
  }

  int cnt=0;
  for(int i=1;i<=n;i++){
    if(parent[i]==i) cnt++;
  }

  cout<<cnt;
}

int main()
{  
   int t=1;
   while(t--){ 
      solve();
   }
    return 0; 
}
