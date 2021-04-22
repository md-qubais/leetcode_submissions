class Solution {
public:
    int findPeakElement(vector<int>&arr){
  
        int s=0;
        int h=arr.size()-1;
        while(s<h){
            int mid=(s+h)/2;
            if(mid==0){
                if(arr[mid]>arr[mid+1]){
                    return mid;
                }
                s=mid+1;
                continue;
            }
            if(mid==arr.size()-1){
                if(arr[mid]>arr[mid-1]){
                    return mid;
                }
                h=mid-1;
                continue;
            }
            if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1]){
                return mid;
            }
            if(arr[mid+1]>arr[mid]){
                s=mid+1;
            }else{
                h=mid-1;
            }
        }
        return s;
    }
};