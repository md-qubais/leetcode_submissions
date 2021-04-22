#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
string countOfAtoms(string str){
	stack<string> symb;
	stack<int> num;
	map<string,int> m;
	for(int i=0;i<str.length();i++){
		if(str[i]>='0' and str[i]<='9'){
			int n=0;
			while(str[i]>='0' and str[i]<='9'){
				n=n*10+(str[i]-'0');
				i++;
			}
			num.push(n);
			i--;
			continue;
		}
		if(str[i]==')'){
			int n=0;
			i++;
			while(i<str.length() and str[i]>='0' and str[i]<='9'){
				n=n*10+(str[i]-'0');
				i++;
			}
			stack<int> temp;
			while(!num.empty() and num.top()!=-1){
				if(n==0){
					if(num.top()!=-1){
						temp.push(num.top());
					}
					else temp.push(1);
				}
				else temp.push(num.top()*n);
				num.pop();
			}
			num.pop();
			while(!temp.empty()){
				num.push(temp.top());
				temp.pop();
			}
			i--;
			continue;
		}
		if(str[i]=='('){
			num.push(-1);
			continue;
		}
		else{
			string temp="";
			temp+=str[i];
			i++;
			while((str[i]>='a'  and str[i]<='z')){
				temp+=str[i];
				i++;
			}
			symb.push(temp);
			if(i<str.length() and (str[i]>='0' and str[i]<='9')){
				i--;
				continue;
			}else{
				num.push(1);
			}
			i--;
			continue;
		}
	}
	string ans=""; 
	while(!num.empty() and !symb.empty()){
		string temp=symb.top();
		int n=num.top();
		m[temp]+=n;
		symb.pop();
		num.pop();
	}
	for(auto it:m){
		if(m[it.first]==1){
			ans+=it.first;
			continue;
		}
		ans+=it.first+to_string(m[it.first]);
	}
	return ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	string s;
	cin>>s;
	cout<<countOfAtoms(s)<<endl;
	return 0;
}