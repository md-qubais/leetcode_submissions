class Solution {
public:
	int dp[1000][1000]={0};
    int minDistance(string s1, string s2,int i=0,int j=0){
    	if((i==s1.length() and j==s2.length())){
    		return dp[i][j]=0;
    	}
    	if(dp[i][j]!=0){
    		return dp[i][j];
    	}
    	if(i==s1.length()){
    		return dp[i][j]=s2.length()-j;
    	}
    	if(j==s2.length()){
    		return dp[i][j]=s1.length()-i;
    	}
    	if(s1[i]==s2[j]){
    		return dp[i][j]=minDistance(s1,s2,i+1,j+1);
    	}
    	return dp[i][j]=1+min(minDistance(s1,s2,i,j+1),min(minDistance(s1,s2,i+1,j+1),minDistance(s1,s2,i+1,j)));
    }
};