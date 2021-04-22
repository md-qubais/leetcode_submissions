class Solution {
public:
    int searchInsert(vector<int>& nums, int target){
    	int s=0;
    	int e=nums.size()-1;
    	int ans=0;
    	while(s<=e){
    		int mid=(s+e)/2;
    		if(nums[mid]==target){
    			return mid;
    		}
    		if(nums[mid]>target){
    			ans=mid;
    			e=mid-1;
    		}else{
    			ans=mid;
    			s=mid+1;
    		}
    	}
        if(target<nums[ans] and ans==0){
            return ans;
        }
        if(target>nums[ans] and ans==nums.size()-1){
            return nums.size();
        }
        
    	return ans;
    }
};