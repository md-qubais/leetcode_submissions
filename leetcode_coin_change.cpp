#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;

int dp[10000]={0};
int helper(vector<int>&coins,int amt){
	if(amt==0){
		return 0;
	}
	if(dp[amt]!=0){
		return dp[amt];
	}
	dp[amt]=INT_MAX;
	for(int i=0;i<coins.size();i++){
		if(amt-coins[i]>=0){
			int small_ans=helper(coins,amt-coins[i]);
            if(small_ans!=INT_MAX){
                dp[amt]=min(dp[amt],small_ans+1);
            }
		}
	}
	return dp[amt];
}

int coinChange(vector<int>& coins,int amount){
	int ans=helper(coins,amount);
	if(ans==INT_MAX){
		return -1;
	}
	return ans;
}





int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	vector<int> coins(n);
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	int amount;
	cin>>amount;
	cout<<coinChange(coins,amount)<<endl;
	return 0;   
}