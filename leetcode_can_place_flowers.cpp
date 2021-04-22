class Solution {
public:
    
    bool canPlaceFlowers(vector<int>&arr, int n){
        if(arr.size()==1){
            if(arr[0]==0){
                n--;
            }
            if(n<=0){
                return true;
            }
            return false;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1){
                continue;
            }
            if(i==0 and arr[i+1]!=1){
                n--;
                arr[i]=1;
                continue;
            }
            if(i==arr.size()-1  and arr[i-1]!=1){
                n--;
                arr[i]=1;
                continue;
            }
            if(i>0 and arr[i-1]!=1 and arr[i+1]!=1){
                n--;
                arr[i]=1;
                continue;

            }
        }
        if(n<=0){
            return true;
        }
        return false;
    }
};