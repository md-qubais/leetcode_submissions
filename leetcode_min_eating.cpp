class Solution {
public:
	int can_eat(vector<int>&arr,int h,int k){
		for(int i=0;i<arr.size();i++){
			int num=arr[i];
			if(num>k){
				while(num>0){
					num=num-k;
					if(h-1<0){
                        return false;
                    }
                    h--;
				}
			}else{
				h--;
			}
			if(h<0){
				return false;
			}
		}
		if(h<0){
			return false;
		}
		cout<<h<<" "<<k<<endl;
		return true;
	}
    int minEatingSpeed(vector<int>&arr, int h){
    	int Max=0;
        for(int i=0;i<arr.size();i++){
            Max=max(Max,arr[i]);
        }
    	int ans=0;
    	int s=0;
    	int e=Max;
    	while(s<=e){
    		int mid=(s+e)/2;
    		if(can_eat(arr,h,mid)){
    			ans=mid;
    			e=mid-1;
    		}else{
    			s=mid+1;
    		}
    	}
    	return ans;
    }
};