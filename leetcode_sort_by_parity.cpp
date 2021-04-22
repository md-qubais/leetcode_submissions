#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
vector<int> sortArrayByParity(vector<int>&arr){
	int i=0;
	int j=arr.size()-1;
	while(i<j){
		if(arr[i]%2==0){
			i++;
			continue;
		}
		if(arr[i]%2!=0){
			swap(arr[i],arr[j]);
			j--;
			continue;
		}
	}
	return arr;
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
	vector<int> ans=sortArrayByParity(arr);
	for(auto it: ans){
		cout<<it<<" ";
	}
	cout<<endl;
    return 0;
}