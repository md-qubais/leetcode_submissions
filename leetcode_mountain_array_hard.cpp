class Solution {
public:

    int findInMountainArray(int target, MountainArray&arr){
        int s=0;
        int e=arr.length()-1;
        //first find the peak element
        int mid;
        while(s<e){
            mid=(s+e)/2;
            //then the fist part is sorted
            int num=arr.get(mid);
            int start=arr.get(s);
            int end=arr.get(e);
            //the below (AND) condition is the core condition
            //to find the peak element if the array
            //is very large
            if(start<num and num>arr.get(mid-1)){
                s=mid;
            }else{
                e=mid;
            }
        }
      //here we got the peak index 
        if(arr.get(mid)==target){
            return mid;
        }
        //if we got the value at the first that is our answer
        s=0;
        e=mid;
        while(s<=e){
            int mid=(s+e)/2;
            int num=arr.get(mid);
            cout<<num<<endl;
            if(num==target){
                return mid;
            }
            if(num>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        //if we got the value at the second half that is our answer
        s=mid;
        e=arr.length()-1;
        while(s<=e){
            int mid=(s+e)/2;
            int num=arr.get(mid);
            if(num==target){
                return mid;
            }
            if(num>target){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return -1;
    }
};