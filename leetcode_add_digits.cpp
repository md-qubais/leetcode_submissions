class Solution {
public:
    int addDigits(int num) {
        int ans=0;
        string temp=to_string(num);
        for(int i=0;i<temp.size();i++){
        	ans+=((temp[i]-'0'));
        }
        if(ans/10==0){
        	return ans;
        }
        return addDigits(ans);
    }
};