#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
string simplifyPath(string str){
	stack<string> s;
	for(int i=0;i<str.length();i++){
		if(str[i]=='/'){
			if(!s.empty() and s.top()=="/"){
				continue;
			}
			string temp="";
			temp+=str[i];
			s.push(temp);
		}else if(str[i]=='.'){
			string temp="";
			int j=i;
			while(j<str.length() and str[j]!='/'){
				temp+=str[j++];
			}
			if(temp=="."){
				continue;
			}else if(temp==".."){
				int count=0;
				while(!s.empty() and count<2 ){
					if(s.top()=="/"){
						count++;
					}
					s.pop();
				}
			}else if(temp=="..."){
				s.push(temp);
			}else{
				s.push(temp);
			}
			i=j-1;
		}else{
			string temp="";
			int j=i;
			while(j<str.length() and str[j]!='/'){
				temp+=str[j++];
			}
			i=j-1;
			s.push(temp);
		}
	}
	string ans="";
	while(!s.empty()){
		ans=s.top()+ans;
		s.pop();
	}
	if(ans.length()==0){
		return "/";
	}
	reverse(ans.begin(),ans.end());
	if(ans.length()>1){
		while(ans.length()>1 and ans[0]=='/'){
			ans=ans.substr(1);
		}
	}
	reverse(ans.begin(),ans.end());
	if(ans[0]!='/'){
		ans="/"+ans;
	}
	return ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	string s;
	cin>>s;
	cout<<simplifyPath(s)<<endl;
	return 0;
}