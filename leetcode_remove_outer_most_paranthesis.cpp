class Solution {
public:
    string removeOuterParentheses(string str){
    	string ans="";
    	stack<char> s;
    	string temp="";
    	int count=0;
    	for(int i=0;i<str.length();i++){
    		if(str[i]=='('){
    			s.push(str[i]);
    			ans+=temp;
    			temp="";
                count=0;
    		}else{
    			count++;
    			while(!s.empty() and s.top()!=')'){
    				temp="("+temp+")";
                    s.pop();
    			}
    			if(count==2){
    				continue;
    			}
    		}
    	}
    	return ans;
    }
};