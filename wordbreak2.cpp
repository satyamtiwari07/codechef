class Solution {
public:
    
    unordered_map<string,bool>mpp;
    
    void dfs(string &s , int idx , vector<string>&ans ,string &temp){
        
        if(idx==s.size()){
            temp.pop_back();
            ans.push_back(temp);
            temp.push_back(' ');
            return;
        }
        
        for(int x=idx;x<s.length();x++){
            if(mpp[s.substr(idx,x-idx+1)]){
                temp+=s.substr(idx,x-idx+1)+' ';
                dfs(s,x+1,ans,temp);
                temp.pop_back();
                for(int z=0;z<x-idx+1 ; z++){
                    temp.pop_back();
                }
                
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        vector<string>ans;
        for(auto &it:wordDict){
            mpp[it]=true;
        }
        string temp;
        dfs(s,0,ans,temp);
        return ans;
    
    }
};
