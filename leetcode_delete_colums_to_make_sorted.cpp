class Solution {
public:
    int minDeletionSize(vector<string>&mat){
    	int ans=0;
    	for(int i=0;i<mat[0].size();i++){
    		int j=0;
    		while(j<mat.size()-1){
    			if(mat[j][i]>mat[j+1][i]){
    				ans++;
    				cout<<i<<" "<<j<<endl;
    				break;
    			}
    			j++;
    		}
    	}
    	return ans;
    }
};