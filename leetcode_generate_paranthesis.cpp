class Solution {
public:
    vector<string> generateParenthesis(int n,string ans="",int open=0,int close=0){
    	vector<string> res;
    	
    	if(ans.length()==2*n){
    		res.push_back(ans);
    		return res;
    	}

    	vector<string> op1;
    	if(open>close){
    		op1=generateParenthesis(n,ans+")",open,close+1);
    	}
    	vector<string> op2;
    	if(open<n){
    		op2=generateParenthesis(n,ans+"(",open+1,close);
    	}
    	for(auto it:op1){
    		res.push_back(it);
    	}
    	for(auto it:op2){
    		res.push_back(it);
    	}
    	return res;
    }
};