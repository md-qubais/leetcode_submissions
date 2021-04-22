class Solution {
public:
    bool checkIfPangram(string sentence){
    	int arr[26]={0};
    	for(auto&it:sentence){
    		arr[it-'a']=1;
    	}
    	for(int i=0;i<26;i++){
            if(arr[i]==0) return false;
    	}
    	return true;
    }
};