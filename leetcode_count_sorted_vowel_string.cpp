class Solution {
public:
	string s="aeiou";
	int dp[1000][1000]={0};
	int count(int n,string temp,int i){
		if(n==0){
			return 1;
		}
		if(dp[temp[temp.size()-1]][n]!=0){
			return dp[temp[temp.size()-1]][n]!=0;
		}
		int ans=0;
		for(int j=i;j<s.length();j++){
			if(temp.size()>0 and temp[temp.size()-1]>s[j]){
				continue;
			}
			ans+=count(n-1,temp+s[j],j);
		}
		dp[temp[temp.size()-1]][n]=ans;
		return dp[temp[temp.size()-1]][n];
	}
    int countVowelStrings(int n){
    	int ans=0;
    	for(int i=0;i<5;i++){
    		string temp="";
    		temp+=s[i];
    		ans+=count(n-1,temp,i);
    	}
        for(int i=0;i<5;i++){
            cout<<s[i]<<" "<<dp[s[i]][n-1]<<endl;
        }
    	return ans;
    }
};
