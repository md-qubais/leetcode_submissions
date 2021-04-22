class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr){
    	int s=0;
    	int h=arr.size()-1;
    	while(s<=h){
    		int mid=(s+h)/2;
    		if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]){
    			return mid;
    		}
    		if(arr[s]<=arr[mid] and arr[h]<=arr[mid]){
    			h=mid;
    		}else{
    			s=mid;
    		}
    	}
    	return -1;
    }
};