//First Memorization Approach
class Solution {
public:
    int solve(vector<int>&arr,int k,int i,vector<int>&dp){
        int n=arr.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int len=0;
        int maxn=INT_MIN;
        int ans=INT_MIN;
        for(int j=i;j<min(i+k,n);j++){
            len=len+1;  
            maxn=max(maxn,arr[j]);
            ans=max(ans,maxn*len+solve(arr,k,j+1,dp));

        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(arr,k,0,dp);
    }
};