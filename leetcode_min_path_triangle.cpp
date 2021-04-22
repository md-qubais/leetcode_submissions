//i or i+1
int dp[1000][1000]={0};
class Solution {
public:
	int get_ans(vector<vector<int>>&arr,int i,int j){
		if(i>=arr.size()){
			return 0;
		}
		if(j>=arr[i].size()){
			return 0;
		}
		if(dp[i][j]!=0){
			return dp[i][j];
		}
		dp[i][j]=arr[i][j]+min(get_ans(arr,i+1,j),get_ans(arr,i+1,j+1));
		return dp[i][j];
	}
    int minimumTotal(vector<vector<int>>&arr){
    	return get_ans(arr,0,0);
    }
};