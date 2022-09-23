#include<bits/stdc++.h>

using namespace std;

struct trie{
  struct trie * children[26];
  bool isend;
};

struct trie* getnode(){

   struct trie *g=new trie;

   for(int x=0;x<25;x++){
      g->children[x]=NULL;
   }
   g->isend=false;
   return g;
}

void insert(struct trie*root , string str){

 struct trie* temp=root;

 for(int x=0;x<str.size();x++){
    int idx=str[x]-'a';
    //if it is null
    if(temp->children[idx]==NULL){
        temp->children[idx]=getnode();
    }
    temp=temp->children[idx];
 }

 temp->isend=true;
}

bool search(struct trie*root , string str){

 struct trie* temp=root;

 for(int x=0;x<str.size();x++){
    int idx=str[x]-'a';
    //if it is null
    if(temp->children[idx]==NULL){
        return false;
    }
    temp=temp->children[idx];
 }

 return temp->isend;
}

int main(){

 struct trie*root=getnode();
 insert(root,"apple");
 insert(root,"apps");
 insert(root,"apxl");
 insert(root,"bac");
 insert(root,"bat");

 cout<<search(root,"satyam");cout<<endl;
 cout<<search(root,"app");cout<<endl;
 cout<<search(root,"apps");cout<<endl;
 cout<<search(root,"name");cout<<endl;
 cout<<search(root,"apple");cout<<endl;

  return 0;
}

