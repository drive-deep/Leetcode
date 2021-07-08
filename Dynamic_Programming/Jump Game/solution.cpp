class Solution {
public:
   
    
    bool canJump(vector<int>& nums) {
       int n=nums.size();
        int tmp[n+1];
        memset(tmp,0,sizeof(tmp));
        
        for(int i=0; i<n; i++){
            tmp[min(nums[i]+i,n-1)]+=nums[i];
            tmp[i]-= nums[i];
      
        }
        for(int i=1; i<n; i++){
            tmp[i]+=tmp[i-1];
        }
        
         for(int j=0; j<n-1; j++){
            if(tmp[j]==0){
                return false;
            }
        }
       
        return true;
    }
};