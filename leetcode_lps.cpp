class Solution {
public:
    int longestPalindromeSubseq(string s){
        int dp[1001][1001]={0};
        for(int i=0;i<s.length();i++){
            dp[i][i]=1;
        }
        for(int i=s.length()-2;i>=0;i--){
            for(int j=i+1;j<s.length();j++){
                //if they are equal
                if(s[i]==s[j]){
                    dp[i][j]=2+dp[i+1][j-1];
                }
                //they are not equal
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][s.length()-1];
    }
};