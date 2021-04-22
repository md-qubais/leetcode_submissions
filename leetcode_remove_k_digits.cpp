class Solution {
public:
    string removeKdigits(string num, int k) {
	stack<char> s;
        if(k==0){
            return num;
        }
	if(num.length()==k){
		return "0";
	}
	int i=0;
	for( ;i<num.length();i++){
		if(k==0){
			break;
		}
		if(s.empty()){
			s.push(num[i]);
		}else{
			while(!s.empty() and s.top()>num[i]){
				k--;
				s.pop();
				if(k==0){
					break;
				}
			}
  			s.push(num[i]);
		}
	}
        string ans="";
	while(i<num.length()){
		ans+=num[i++];
	}

	while(!s.empty()){
      ans=s.top()+ans;
		s.pop();
	}
	string t="";
	if(k>0){
		for(int i=0;i<ans.length()-k;i++){
			t+=ans[i];
		}
	}
	ans=t;
	while(ans.length()>1){
		if(ans[0]!='0'){
			break;
		}
		ans=ans.substr(1);
	}
	return ans;
}
};