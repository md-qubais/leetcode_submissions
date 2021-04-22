class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs){
    	int dp[10000]={0};
    	int ans=0;
        sort(pairs.begin(),pairs.end());
    	dp[0]=1;
    	for(int i=0;i<pairs.size();i++){
    		int n=0;
    		for(int j=i-1;j>=0;j--){
    			if(pairs[i][0]>pairs[j][1]){
    				n=max(n,dp[j]);
    			}
    		}
    		dp[i]=n+1;
    	}
    	for(int i=0;i<pairs.size();i++){
    		cout<<dp[i]<<" ";
    		ans=max(ans,dp[i]);
    	}
    	return ans;
    }
};