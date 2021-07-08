class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n=arr.size(),k;
        bool vis[n+1];
        for(int i=0; i<n; i++){
            vis[i]=false;
        }
        
        stack<int>q;
        q.push(start);
        vis[start]=true;
        
        while(!q.empty()){
            int p=q.top();
            q.pop();
            k=p-arr[p];
            if(k >= 0){
                int k=p-arr[p];
                if(!vis[k]){
                    q.push(k);
                    vis[k]=true;
                }
            }
            k=p+arr[p];
             if(k<n){
                if(!vis[k]){
                    q.push(k);
                    vis[k]=true;
                }
            }
            
        }
       for(int i=0; i<n; i++){
           if(arr[i]==0 && vis[i]){
               return true;
           }
       }
        return false;
    }
};