#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
string decodeString(string str){
	stack<int> s;
	stack<char> ch;
	for(int i=0;i<str.length();i++){
		if(str[i]>='0' and str[i]<='9'){
			int temp=0;
			while(str[i]>='0' and str[i]<='9'){
				temp=temp*10+(str[i]-'0');
				i++;
			}
			i--;
			s.push(temp);
			continue;
		}
		if((str[i]>='a' and str[i]<='z') or str[i]=='['){
			ch.push(str[i]);
			continue;
		}
		if(str[i]==']'){
			string temp="";
			while(!ch.empty() and ch.top()!='['){
				temp=ch.top()+temp;
				ch.pop();
			}
			ch.pop();
			int num=0;
			if(!s.empty()){
				num=s.top();
				s.pop();
			}
			string t=temp;
			for(int j=1;j<num;j++){
				temp=temp+t;
			}
			//cout<<temp<<endl;
			for(int j=0;j<temp.length();j++){
				ch.push(temp[j]);
			}
		}
	}
	string ans="";
	while(!ch.empty()){
		ans=ch.top()+ans;
		ch.pop();
	}
	return ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	string s;
	cin>>s;
	cout<<decodeString(s)<<endl;
    return 0;
}