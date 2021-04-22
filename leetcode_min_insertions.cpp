#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
int minInsertions(string str){
	stack<char> s;
	int ans=0;
	for(int i=str.length()-1;i>=0;i--){
		if(str[i]==')'){
			s.push(str[i]);
			continue;
		}else {
			int count=2;
			while(!s.empty() and (s.top()==')' and count>0)){
				s.pop();
				count--;
			}
			ans+=count;
		}
	}
	while(!s.empty()){
		int count=2;
		while(!s.empty() and (s.top()==')' and count>0)){
			count--;
			s.pop();
		}
		if(count==0){
			ans+=1;
		}
		else{
			ans+=2;
		}
	}
	return ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	string s;
	cin>>s;
	cout<<minInsertions(s)<<endl;
	return 0;
}