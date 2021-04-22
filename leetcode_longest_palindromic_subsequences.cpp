class Solution {
public:
	int dp[1000][1000]={0};
	int lps(string s,int start,int end){
		if(start>end){
			return 0;
		}
		if(dp[start][end]!=0){
			return dp[start][end];
		}
        if(start==end){
            return dp[start][end]=1;
        }
		if(s[start]==s[end]){
			return dp[start][end]=2+lps(s,start+1,end-1);
		}
		return dp[start][end]=max(lps(s,start+1,end),lps(s,start,end-1));
	}
    int longestPalindromeSubseq(string s){
    	return lps(s,0,s.length());
    }
};