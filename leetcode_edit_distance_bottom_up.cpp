class Solution {
public:
    int minDistance(string s1, string s2){
    	s1=" "+s1;
    	s2=" "+s2;
    	int dp[1000][1000]={0};
    	dp[0][0]=0;
    	for(int i=1;i<s1.length();i++){
    		dp[i][0]=i;
    	}
    	for(int i=1;i<s2.length();i++){
    		dp[0][i]=i;
    	}
    	for(int i=1;i<s1.length();i++){
    		for(int j=1;j<s2.length();j++){
    			if(s1[i]==s2[j]){
    				dp[i][j]=dp[i-1][j-1];
    			}else{
    				dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
    			}
    		}
    	}
    	return dp[s1.length()-1][s2.length()-1];
    }
};