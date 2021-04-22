#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
int visited[100]={0};
int burst(vector<int>&arr,int i){
		if(i<0 or i>=arr.size()){
			return 1;
		}
		if(visited[i]!=0){
			return 1;
		}
		visited[i]=1;
		int ans1=burst(arr,i-1);
		int ans2=burst(arr,i+1);
		visited[i]=0;
		return arr[i]*ans1*ans2;
	}
int maxCoins(vector<int>& nums) {
    	int ans=0;
    	for(int i=0;i<nums.size();i++){
    		ans=burst(nums,i);
    		cout<<ans<<endl;
    	}
    	return ans;
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
	cout<<maxCoins(arr)<<endl;
	return 0;
}