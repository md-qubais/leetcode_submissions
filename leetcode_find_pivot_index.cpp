class Solution {
public:
    int pivotIndex(vector<int>& nums){
    	vector<int> left_sum(nums.size());
    	vector<int> right_sum(nums.size());
    	left_sum[0]=nums[0];
    	for(int i=1;i<nums.size();i++){
    		left_sum[i]=left_sum[i-1]+nums[i];
    	}
    	right_sum[nums.size()-1]=nums[nums.size()-1];
    	for(int i=nums.size()-2;i>=0;i--){
    		right_sum[i]=right_sum[i+1]+nums[i];
    	}
    	int ans=-1;
    	for(int i=0;i<nums.size();i++){
    		if(left_sum[i]-nums[i]==right_sum[i]-nums[i]){
    			return i;
    		}
    	}
    	return ans;
    }
};