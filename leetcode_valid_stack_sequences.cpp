#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
bool validateStackSequences(vector<int>& push, vector<int>& pop){
	if(push.size()==0 or pop.size()==0){
		return true;
	}
	stack<int> s;
	int i=0;
	int j=0;
	while(i<push.size() and j<pop.size()){
		if(s.empty()){
			s.push(push[i++]);
		}
		else if(s.top()==pop[j]){
			j++;
			s.pop();
		}else{
			s.push(push[i++]);
		}
	}
	while(i<push.size()){
		s.push(push[i++]);
	}
	while(j<pop.size()){
		if(!s.empty() and s.top()==pop[j]){
			j++;
			s.pop();
		}else{
			break;
		}
	}
	if(i<=push.size()-1){
		return false;
	}
	if(j<=pop.size()-1){
		return false;
	}
	if(!s.empty()){
		return false;
	}
	return true;
}

int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	vector<int> push(n);
	vector<int> pop(n);
	for(int i=0;i<n;i++){
		cin>>push[i];
	}
	for(int i=0;i<n;i++){
		cin>>pop[i];
	}
	cout<<validateStackSequences(push,pop)<<endl;
	return 0;
}