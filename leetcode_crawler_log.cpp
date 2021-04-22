#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
int minOperations(vector<string>& logs){
	stack<int> s;
	for(int i=0;i<logs.size();i++){
		if(logs[i]=="./"){
			continue;
		}
		else if(logs[i]=="../"){
			if(!s.empty()){
				s.pop();
			}
			continue;
		}
		else{
			s.push(1);
		}
	}
	return s.size();
}
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	vector<string> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<minOperations(arr)<<endl;
	return 0;
}