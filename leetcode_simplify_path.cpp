#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
    string simplifyPath(string str){
	stack<char> s;
	for(int i=0;i<str.length();i++){
		if(str[i]=='/'){
			if(!s.empty() and s.top()=='/'){
				continue;
			}
			s.push(str[i]);
		}else if(str[i]=='.'){
            if(i+2<str.length() and str[i]=='.' and str[i+1]=='.' and str[i+2]=='.'){
                cout<<str[i]<<" "<<i<<" "<<i+1<<" "<<i+2<<endl;
                for(int i=0;i<3;i++){
                    s.push('.');
                }
                i=i+3;
            }else  
			if(str[i]=='.' and str[i+1]=='.'){
				int count=0;
				while(!s.empty() and count<2 ){
					if(s.top()=='/'){
						count++;
					}
					s.pop();
				}
				i++;
			}
            else{
				while(!s.empty() and s.top()!='/'){
					s.pop();
				}
				if(!s.empty()){
					s.pop();
				}
			}
		}else{
			/*
			int j=i;
			string temp="";
			while(str[j]!='/' and str[j]!='.'){
				temp+=str[j++];
			}
			i=j-1;
			for(int k=0;k<temp.length();k++){
				s.push(temp[k]);
			}*/
			s.push(str[i]);
		}
	}
	string ans="";
	while(!s.empty() ){
		ans=s.top()+ans;
		s.pop();
	}
        if(ans.length()==0){
            return "/";
        }
	reverse(ans.begin(),ans.end());
	if(ans.length()>1){
		int j=0;
		while(ans[j]=='/'){
			ans=ans.substr(1);
		}
	}
	reverse(ans.begin(),ans.end());
	if(ans[0]!='/'){
		ans="/"+ans;
	}
	return ans;
}
int32_t main(){
	qubais_judge;
	IOS;
	string s;
	cin>>s;
	cout<<simplifyPath(s)<<endl;
	return 0;
}