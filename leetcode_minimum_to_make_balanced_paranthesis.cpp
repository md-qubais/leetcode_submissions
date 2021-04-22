#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
string minRemoveToMakeValid(string str){
	stack<string> s;
	for(int i=0;i<str.length();i++){
		if(str[i]==')'){
			string temp="";
			while(!s.empty() and s.top()!="("){
				temp=s.top()+temp;
				s.pop();
			}
			if(s.empty()){
				s.push(temp);
			}else{
				s.pop();
				s.push("("+temp+")");
			}
			continue;
		}else{
			string temp="";
			temp+=str[i];
			s.push(temp);
		}
	}
	string ans="";
	while(!s.empty()){
		if(s.top()=="(" or s.top()==")"){
			s.pop();
			continue;
		}else{
			ans=s.top()+ans;
			s.pop();
		}
	}
	return ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	string s;
	cin>>s;
	cout<<minRemoveToMakeValid(s)<<endl;
	return 0;
}