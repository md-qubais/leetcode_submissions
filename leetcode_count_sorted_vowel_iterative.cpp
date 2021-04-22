class Solution {
public:
    int countVowelStrings(int n) {
    	int dp[5]={0};
    	for(int i=0;i<5;i++){
    		dp[i]=1;
    	}
    	for(int i=2;i<=n;i++){
    		for(int j=0;j<5;j++){
    			int sum=0;
    			for(int k=j;k<5;k++){
    				sum+=dp[k];
    			}
    			dp[j]=sum;
    		}
    	}
    	int ans=0;
    	for(int i=0;i<5;i++){
    		ans+=dp[i];
    	}

    	return ans;
    }
};