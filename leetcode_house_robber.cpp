class Solution {
public:
	int dp[1000]={0};
	int rob(vector<int>&arr,int i){
		int ans=0;
		if(i>=arr.size()){
			return ans;
		}
		if(dp[i]!=-1){
			return dp[i];
		}
		for(int j=i+1;j<arr.size();j++){
			ans=max(ans,rob(arr,j+1));
		}
		dp[i]=ans+arr[i];
		return dp[i];
	}
    int rob(vector<int>& nums) {
    	int ans=0;
    	memset(dp,-1,1000);
    	for(int i=0;i<nums.size();i++){
    		ans=max(ans,rob(nums,i));
    	}
        return ans;
    }
};