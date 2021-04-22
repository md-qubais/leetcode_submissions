#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
int calPoints(vector<string>& arr){
	int ans=0;
	stack<int> s;
	for(int i=0;i<arr.size();i++){
		if(arr[i]!="D" and arr[i]!="+" and arr[i]!="C"){
			s.push(stoi(arr[i]));
			continue;
		}
		if(arr[i]=="+"){
			int n1=s.top();
			s.pop();
			int n2=s.top();
			s.pop();
			s.push(n2);
			s.push(n1);
			s.push(n1+n2);
		}else if(arr[i]=="C"){
			s.pop();
		}else{
			s.push(2*s.top());
		}
	}

	while(!s.empty()){
		ans+=s.top();
		s.pop();
	}
	return ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	return 0;
}