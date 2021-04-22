class Solution {
public:
	int dp[100][100]={0};
	int longest(string s1,string s2,int i,int j){
		if(i==s1.length() or j==s2.length()){
			return 0;
		}
		if(dp[i][j]!=0){
			return dp[i][j];
		}
		if(s1[i]==s2[j]){
			return dp[i][j]=1+longest(s1,s2,i+1,j+1);
		}
		return dp[i][j]=max(longest(s1,s2,i+1,j),longest(s1,s2,i,j+1));
	}
    int longestPalindromeSubseq(string s){
    	string s1;
    	s1=s;
    	reverse(s1.begin(),s1.end());
    	return longest(s,s1,0,0);
    }
};