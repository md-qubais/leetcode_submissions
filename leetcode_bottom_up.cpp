class Solution {
public:
	int longest(string s1,string s2){
		int dp[1001][1001]={0};
		s1=" "+s1;
		s2=" "+s2;
		for(int i=1;i<s1.length();i++){
			for(int j=1;j<s2.length();j++){
				if(s1[i]==s2[j]){
					dp[i][j]=1+dp[i-1][j-1];
				}else{
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				}
			}
		}
		
		return dp[s1.length()-1][s2.length()-1];
	}
    int longestPalindromeSubseq(string s){
    	string s1;
    	s1=s;
    	reverse(s1.begin(),s1.end());
    	return longest(s,s1);
    }
};