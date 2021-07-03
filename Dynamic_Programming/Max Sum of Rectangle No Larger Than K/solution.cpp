class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& ma, int k) {

        int ans=-99999;
        int n=ma.size();
        int m=ma[0].size();
        int matrix[n+2][m+2];

        for(int i=0; i<=n; i++){
            matrix[i][0]=0;
        }
        for(int j=0; j<=m; j++){
            matrix[0][j]=0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
               matrix[i][j]=ma[i-1][j-1];
            }
        }
        for(int i=0; i<=n; i++){
            for(int j=1; j<=m; j++){
               matrix[i][j] += matrix[i][j-1];
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<=m; j++){
               matrix[i][j] += matrix[i-1][j];
            }
        }



        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                for(int i1=0; i1<=n; i1++){
                    for(int j1=0; j1<=m; j1++){
                        int tmp;
                        if((i>i1 && j>j1 )|| (i==i1 && j>j1) || (i>i1 && j==j1)){
                            if(j1>0 && i1>0){
                         tmp = matrix[i][j] - matrix[i][j1-1]-matrix[i1-1][j]+matrix[i1-1][j1-1];
                            }else if(j1>0 && i1==0){
                             tmp = matrix[i][j] - matrix[i][j1-1];
                            }else if(j1==0 && i1>0){
                         tmp = matrix[i][j] -matrix[i1-1][j];
                            }else if(i1==0 && j1==0){
                                tmp=matrix[i][j];
                            }

                            if(tmp<=k){
                                ans=max(ans,tmp);
                            }
                        }

                    }
                }
            }
        }


        return ans;
    }
};
