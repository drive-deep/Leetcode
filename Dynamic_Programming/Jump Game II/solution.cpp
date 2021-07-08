class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1];
        for(int i=0; i<n; i++){
            dp[i]=999999;
        }
        dp[0]=0;
        queue<int>s;
        s.push(0);
        bool visited[n+1];
        memset(visited,false,sizeof(visited));
        visited[0]=true;
        
        while(!s.empty()){
            int p=s.front();
            s.pop();
            for(int i=p+1; i<=min(p+nums[p],n-1); i++){
                if(!visited[i]){
                    s.push(i);
                    visited[i]=true;
                    dp[i]=min(dp[i],dp[p]+1);  
                }
            }
        }
        
        return dp[n-1];
    }
};