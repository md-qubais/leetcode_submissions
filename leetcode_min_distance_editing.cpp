class Solution {
public:
	int dp[1000][1000]={0};
    int minDistance(string word1, string word2,int i=0,int j=0){
    	if(i==word1.length() and j==word2.length()){
    		return dp[i][j]=0;
    	}
    	if(dp[i][j]!=0){
    		return dp[i][j];
    	}
    	if(i==word1.length()){
    		//return something
    		return dp[i][j]=word2.length()-j;
    	}
    	if(j==word2.length()){
    		//return something
    		return dp[i][j]=word1.length()-i;
    	}
    	if(word1[i]==word2[j]){
    		return dp[i][j]=minDistance(word1,word2,i+1,j+1);
    	}
    	return dp[i][j]=1+min(minDistance(word1,word2,i+1,j),minDistance(word1,word2,i,j+1));
    }
};