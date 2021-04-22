#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
int evalRPN(vector<string>&arr){
	stack<int> nums;
	for(int i=0;i<arr.size();i++){
		if(arr[i].length()==1 and (arr[i]=="+" or arr[i]=="-" or arr[i]=="/" or arr[i]=="*")){
			//here we have to calculate
			int n2=nums.top();
			nums.pop();
			int n1=nums.top();
			nums.pop();
			if(arr[i]=="+"){
				nums.push(n1+n2);
			}else if(arr[i]=="-"){
				nums.push(n1-n2);
			}else if(arr[i]=="/"){
				nums.push(n1/n2);
			}else if(arr[i]=="*"){
				nums.push(n1*n2);
			}
		}else{
			int n=0;
			int sign='+';
			string temp=arr[i];
			if(temp[0]=='-'){
				sign='-';
				for(int i=1;i<temp.length();i++){
					n=n*10+(temp[i]-'0');
				}
				if(sign=='-'){
					n=-n;
				}
				nums.push(n);
				continue;
			}
				for(int i=0;i<temp.length();i++){
					n=n*10+(temp[i]-'0');
				}
				nums.push(n);
		}
	}
	return nums.top();
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
	cout<<evalRPN(arr)<<endl;
    return 0;
}