#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
int calculate(string str){
	stack<pair<int,int>> st;
	stack<char> op;
	stack<char> sign;
	for(int i=0;i<str.length();i++){
		if(str[i]==' '){
			continue;
		}
	}
	while(!st.empty() and st.size()>1){
		int n1=st.top().first;
		char sign1=st.top().second;
		st.pop();
		int n2=st.top().first;
		char sign2=st.top().second;
		st.top();
		if(sign1=='-'){
			n1=-n1;
		}
		if(sign2=='-'){
			n2=-n2;
		}
		int ans=n2+n1;
		char ans_sign='+';
		if(ans<0){
			ans_sign='-';
		}
		st.push(make_pair(ans,ans_sign));
	}
	return st.top().second=='+'?+(st.top().first):-(st.top().first);
}

int32_t main(){
	qubais_judge;
	IOS;
	string s;
	getline(cin,s);
	cout<<calculate(s)<<endl;
	return 0;
}