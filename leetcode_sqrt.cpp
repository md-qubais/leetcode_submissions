class Solution {
public:
    int mySqrt(int x){
    	int s=0;
    	int e=x/2;
    	int ans=0;
    	while(s<=e){
    		int mid=(s+e)/2;
    		if(mid*mid==x){
    			return mid;
    		}
    		if(mid*mid>x){
    			e=mid-1;
    		}else {
    			ans=mid;
    			s=mid+1;
    		}
    	}
    	return ans;
    }
};