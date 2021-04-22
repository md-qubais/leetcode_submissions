class Solution {
public:
	int dp[1000]={0};
	int get_ans(vector<int>&arr,int i){
		if(i==arr.size()){
			return 0;
		}
		if(i==arr.size()-1){
			return arr[i];
		}
		if(dp[i]!=0){
			return dp[i];
		}
		dp[i]=arr[i]+min(get_ans(arr,i+1),get_ans(arr,i+2));
		return dp[i];
	}
    int minCostClimbingStairs(vector<int>& cost){
    	int ans1=get_ans(cost,0);
    	int ans2=get_ans(cost,1);
    	cout<<ans1<<" "<<ans2<<endl;
    	return min(ans1,ans2);
    }
};