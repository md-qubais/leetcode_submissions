#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
void get(vector<int>&in,int j,set<vector<int>>&ans){
	if(j==in.size()){
		ans.insert(in);
		return;
	}
	for(int i=j;i<in.size();i++){
		swap(in[i],in[j]);
		get(in,j+1,ans);
		swap(in[i],in[j]);

	}
}


vector<vector<int>> permute(vector<int>& nums){
	vector<vector<int>> ans;
	set<vector<int>> s;
	get(nums,0,s);
	for(auto it:s){
		ans.push_back(it);
	}
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
	vector<vector<int>> ans=permute(v);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}