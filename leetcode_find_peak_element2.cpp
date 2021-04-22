class Solution {
public:
    int findPeakElement(vector<int>&nums){
    	int mid=0;
    	if(nums.size()==0 or nums.size()==1) return mid;
    	vector<int> arr;
    	arr.push_back(INT_MIN);
    	for(auto it:nums) arr.push_back(it);
    	arr.push_back(INT_MAX);
    	int s=1;
    	int e=arr.size()-2;
    	while(s<=e){
    		mid=(s+e)/2;
    		if(mid==1 and arr[mid+1]<arr[mid]) return mid-1;
    		if(mid==arr.size()-2 and arr[mid-1]<arr[mid]) return mid-1;
    		if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]) return mid-1;
    		if(arr[mid]<arr[mid+1]) s=mid+1;
    		if(arr[mid]>arr[mid+1]) e=mid-1;
    	}	
    	return mid-1;
    }
};