#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define fori(n) for(int i=0;i<n;i++)
#define ford(n) for(int i=n-1;i>=0;i--)
#define fl(x,n) for(int i=x;i<n;i++)
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
//class Solution {
//public:
    bool can_place(vector<int>&arr,int k,int dis){
    	int i=1;
    	int prev=arr[0];
    	k--;
    	while(i<arr.size()){
    		if(arr[i]>=prev+dis){
    			k--;
    			prev=arr[i];
    		}
    		i++;
    	}
    	if(k<=0){
    		return true;
    	}
    	return false;
    }
    int maxDistance(vector<int>&arr, int m){
    	sort(arr.begin(),arr.end());
    	int ans=0;
    	int s=0;
    	int e=*max_element(arr.begin(),arr.end());
    	while(s<=e){
    		int mid=(s+e)/2;
    		if(can_place(arr,m,mid)){
    			ans=mid;
    			s=mid+1;
    		}else{
    			e=mid-1;
    		}
    	}
    	return ans;
    }
//};
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	vector<int> arr(n);
	fori(n) cin>>arr[i];
	int m;
	cin>>m;
	cout<<maxDistance(arr,m)<<endl;
	return 0;
}