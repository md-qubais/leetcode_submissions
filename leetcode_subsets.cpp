#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
void sub(vector<int> in,vector<int> out,int i,vector<vector<int>>&ans){
	if(i==in.size()){
		ans.push_back(out);
		return;
	}

	out.push_back(in[i]);
	sub(in,out,i+1,ans);
	out.pop_back();
	sub(in,out,i+1,ans);
}

vector<vector<int>> subsets(vector<int>& nums){
	vector<vector<int>> ans;
	vector<int> res;
	sub(nums,res,0,ans);
	return ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	vector<int> ans(n);
	for(int i=0;i<n;i++){
		cin>>ans[i];

	}
	vector<vector<int>> res=subsets(ans);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;   
}