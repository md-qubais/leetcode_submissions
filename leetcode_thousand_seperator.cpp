class Solution {
public:
    string thousandSeparator(int n){
    	string temp=to_string(n);
    	string ans="";
    	int count=0;
    	for(int i=temp.length()-1;i>=0;i--){
    		if(count>3){
    			count=0;
    			ans=temp[i]+'.'+ans;
    		}else{
    			ans=temp[i]+ans;
    		}
    		count++;
    	}
    	return ans;
    }
};