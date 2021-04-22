class Solution {
public:
    int arrangeCoins(int n){
    	int ans=0;
    	int coins=1;
    	while(true){
    		if(n-coins<0){
    			break;
    		}
    		ans++;
    		n=n-coins;
    		coins+=1;
    	}

    	return ans;
    }
};