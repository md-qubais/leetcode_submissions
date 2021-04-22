
#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
int dp[1000][1000]={0};
	int get_ans(vector<vector<int>>&mat,int i,int j){
		if(i>=mat.size()){
			return INT_MAX;
		}
		if(j>=mat[i].size() or j<0){
			return INT_MAX;
		}
		if(i==mat.size()-1){
			return mat[i][j];
		}
		if(dp[i][j]!=0){
			return dp[i][j];
		}
		int ans=INT_MAX;
		for(int k=0;k<mat[i].size();k++){
			if(k==j){
				continue;
			}
			ans=min(ans,get_ans(mat,i+1,k));
		}
		dp[i][j]=mat[i][j]+ans;
		return dp[i][j];
	}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        for(int i=0;i<matrix[0].size();i++){
        	ans=min(ans,get_ans(matrix,0,i));
        }
        return ans;
    }

int32_t main(){
	qubais_judge;
	IOS;
	int rows,cols;
	cin>>rows>>cols;
	vector<vector<int>> mat;
	for(int i=0;i<rows;i++){
		vector<int> col(cols);
		for(int j=0;j<cols;j++){
			cin>>col[j];
		}
		mat.push_back(col);
	}
	cout<<minFallingPathSum(mat)<<endl;
	return 0;
}