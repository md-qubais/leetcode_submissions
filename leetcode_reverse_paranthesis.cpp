class Solution {
public:
    string reverseParentheses(string str){
	stack<char> s;
	for(int i=0;i<str.length();i++){
		if(str[i]!=')'){
			s.push(str[i]);
			continue;
		}
		string temp="";
		while(!s.empty() and s.top()!='('){
			temp+=s.top();
			s.pop();
		}
		if(!s.empty()){
			s.pop();
		}
		for(int j=0;j<temp.length();j++){
			s.push(temp[j]);
		}
	}
	string ans="";
	while(!s.empty()){
		ans=s.top()+ans;
        s.pop();
	}
	return ans;
}
};