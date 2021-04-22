class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target){
    	if(letters[letters.size()-1]==target or letters[letters.size()-1]<target){
    		return letters[0];
    	}
    	int s=0;
    	int e=letters.size()-1;
    	int ans=-1;
    	while(s<=e){
    		int mid=(s+e)/2;
    		if(letters[mid]>target){
    			ans=mid;
    			e=mid-1;
    		}else{
    			s=mid+1;
    		}
    	}
    	return letters[ans];
    }
};