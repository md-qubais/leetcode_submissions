#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
int maximalRectangle(vector<vector<char>>& matrix){
	int ans=INT_MIN;
	return ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	int rows,cols;
	cin>>rows>>cols;
	vector<vector<char>> mat;
	for(int i=0;i<rows;i++){
		vector<char> col(cols);
		for(int j=0;j<cols;j++){
			cin>>col[j];
		}
		mat.push_back(col);
	}
	cout<<maximalRectangle(mat)<<endl;
    return 0;
}