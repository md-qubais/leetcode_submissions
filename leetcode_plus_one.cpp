class Solution {
public:
    vector<int> plusOne(vector<int>& digits){
    	vector<int> ans;
    	int num=digits[digits.size()-1]+1;
    	ans.push_back(num%10);
    	int mod=num/10;
    	for(int i=digits.size()-2;i>=0;i--){
    		num=digits[i]+mod;
    		mod=num/10;
    		ans.push_back(num%10);
    	}
    	if(mod>0){
    		ans.push_back(mod);
    	}
    	reverse(ans.begin(),ans.end());
    	return ans;
    }
};