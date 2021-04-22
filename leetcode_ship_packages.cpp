class Solution {
public:
    bool capacity(vector<int>&arr,int d,int capacity){
        int i=0;
        int tot=0;
        while(i<arr.size()){
            if(tot+arr[i]<=capacity){
                tot+=arr[i];
                i++;
            }else{
                d--;
                tot=0;
            }
            if(d<=0){
                return false;
            }
        }
        if(d<0){
            return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int D){
        int tot=0;
        for(auto it:weights){
            tot+=it;
        }
        int s=0;
        int e=tot;
        int ans=0;
        while(s<=e){
            int mid=(s+e)/2;
            cout<<mid<<endl;
            if(capacity(weights,D,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};