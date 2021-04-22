#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
int dp[100]={0};
char ch[]={
	' ','a','b','c','d','e','f','g','h','i','j',
	'k','l','m','n','o','p','q','r','s','t',
	'u','v','w','x','y','z'
};

int printEncoding(string str, string asf){
    if(str.length()==0){
		return 1;
	}
	int ans=0;
	int num=0;
	for(int i=0;i<str.length();i++){
	    num=0;
		string temp=str.substr(0,i+1);
		if(temp[0]=='0'){
			return ans+dp[num];
		}
		for(int j=0;j<temp.length();j++){
			num=num*10+(temp[j]-'0');
		}
		if(num>26){
			return ans;
		}
		if(dp[num]!=0){
			return dp[num];
		}
	ans+=printEncoding(str.substr(i+1),asf+ch[num]);
	}
	dp[num]+=ans;
	return dp[num];
}

int numDecodings(string s){
	return printEncoding(s,"");
}


int32_t main(){
	qubais_judge;
	IOS;
    string str;
    cin>>str;
    if(str[0]=='0'){
		cout<<0<<endl;
		return 0;
	}
    cout<<printEncoding(str,"");
}