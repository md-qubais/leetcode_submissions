class Solution {
public:
    int sumOfUnique(vector<int>& nums){
    	map<int,int> m;
    	for(auto it:nums){
    		m[it]++;
    	}
    	int ans=0;
    	for(auto it:m){
    		if(m[it.first]==1){
    			ans+=it.first;
    		}
    	}
    	return ans;
    }
};