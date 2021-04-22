#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
vector<int> dailyTemperatures(vector<int>&arr){
	vector<int> res(arr.size());
	stack<int> s;
	for(int i=arr.size()-1;i>=0;i--){
		while(!s.empty() and arr[s.top()]<=arr[i]){
			s.pop();
		}
		if(s.empty()){
			res[i]=0;
		}else{
			res[i]=s.top()-i;
		}
		s.push(i);
	}
	return res;
}
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> ans=dailyTemperatures(arr);
	for(auto it:ans){
		cout<<it<<" ";
	}
	cout<<endl;
    return 0;
}