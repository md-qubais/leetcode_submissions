#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
void get(vector<int> in,vector<int> out,vector<vector<int>>&ans,int i,int sum,int k){
	if(sum==k){
		ans.push_back(out);
		return;
	}
	if(i==in.size()){
		return;
	}
	if(sum>k){
		return;
	}
	for(int j=i;j<in.size();j++){
		out.push_back(in[j]);
		get(in,out,ans,j,sum+in[j],k);
		out.pop_back();
	}
	return;
}

vector<vector<int>> combinationSum(vector<int>& v, int k){
	vector<vector<int>> ans;
	vector<int> res;
	get(v,res,ans,0,0,k);
	return ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int k;
	cin>>k;
	vector<vector<int>> ans=combinationSum(v,k);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;   
}

