class Solution{
  public:
 
    int minJumps(int arr[], int n){
        // Your code here
        if(n==1) return 0;
        else if(arr[0]==0) return -1;
        
        int furthest=arr[0];
        int step=arr[0];
        int jump=1;
        int idx=0;
        
        for(int x=1;x<n;x++){
            if(x==n-1) return jump;
            step--;
            
            furthest=max(furthest,arr[x]+x);
            
            if(step==0){
             jump++;
             if(x>=furthest){
                 return -1;
             }
             step=furthest-x;
            }
        }
        
        return jump;
            
            
    }
};
