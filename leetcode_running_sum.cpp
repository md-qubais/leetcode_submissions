class Solution {
public:
    vector<int> runningSum(vector<int>& nums){
    	int tot=0;
    	for(auto&it:nums){
    		it+=tot;
    		tot=it;
    	}
    	return nums;
    }
};