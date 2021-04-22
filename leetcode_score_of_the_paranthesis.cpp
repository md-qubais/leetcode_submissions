#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
int scoreOfParentheses(string str){
	stack<int> num;
	stack<char> paran;
	for(int i=0;i<str.length();i++){
		if(str[i]=='('){
			paran.push(str[i]);
			num.push(-1);
		}
		else{
			int n=0;
			int number=0;
			while(i<str.length() and str[i]==')'){
			i++;
			n++;
			int tot=0;
			while(!num.empty() and num.top()!=-1){
				tot+=num.top();
				num.pop();
			}
			num.pop();
			if(n>2){
				n=2;
			}
			if(tot==0) num.push(1);
			else num.push(n*tot);
		}
		i--;
	}
}
	int ans=0;
	while(!num.empty()){
		ans+=num.top();
		num.pop();
	}
	return ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	string s;
	cin>>s;
	cout<<scoreOfParentheses(s)<<endl;
	return 0;
}