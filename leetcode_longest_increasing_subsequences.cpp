class Solution {
public:
    int longestCommonSubsequence(string a, string b){
	int dp[1000][1000]={0};
	if(a.length()<b.length()){
		swap(a,b);
	}
	a=" "+a;
	b=" "+b;
	
	for(int i=1;i<a.length();i++){
		for(int j=1;j<b.length();j++){
				//it matches
			if(a[i]==b[j]){
				dp[i][j]=1+dp[i-1][j-1];
			}
				//else not matches
			else{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	return dp[a.length()-1][b.length()-1];
}
};