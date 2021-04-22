class Solution {
public:
    int maxEnvelopes(vector<vector<int>>&arr){
    	sort(arr.begin(),arr.end());
    	int dp[1000]={0};
        for(int i=0;i<arr.size();i++){
            dp[i]=1;
        }
     	for(int i=0;i<arr.size();i++){
    		int h=arr[i][0];
    		int w=arr[i][1];
    		for(int j=i+1;j<arr.size();j++){
    			if(h<arr[j][0] and w<arr[j][1]){
    				dp[j]=max(dp[j],dp[i]+1)
    			}
    		}
    	}
    	int ans=0;
    	for(int i=0;i<arr.size();i++){
    		ans=max(ans,dp[i]);
    	}
    	return ans;
    }
};