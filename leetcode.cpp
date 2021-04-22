#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
int lengthOfLongestSubstring(string str){
	unordered_map<char,int> m;
	int sum=0;
	char ch;
	int j=0;
	int i=0;
	while(j<str.length()){
		m[str[j]]++;
		char ch=str[j];
		if(m[ch]>1){
			//cout<<j<<endl;
			sum=max(sum,j-i);
			//cout<<i<<" "<<j<<endl;
			while(m[ch]>1){
				m[str[i]]--;
				i++;
			}
		}
		j++;
	}
	sum=max(sum,j-i);
	return sum;
}
int32_t main(){
	qubais_judge;
	IOS;
	string str;
	cin>>str;
	cout<<lengthOfLongestSubstring(str)<<endl;
	return 0;   
}