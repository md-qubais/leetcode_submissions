class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
    	int ans=INT_MIN;
    	int max_so_far=nums[0];
    	for(int i=1;i<nums.size();i++){
    		if(nums[i]>nums[i-1]){
    			max_so_far+=nums[i];
    		}
    		else{
    			ans=max(ans,max_so_far);
    			max_so_far=nums[i];
    		}
    	}
    	ans=max(ans,max_so_far);
    	return ans;
    }
};