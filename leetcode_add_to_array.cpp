class Solution {
public:
    vector<int> addToArrayForm(vector<int>&arr, int k){
        vector<int> ans;
        string temp=to_string(k);
        int mod=0;
        int i=arr.size()-1;
        int j=temp.size()-1;
        while(i>=0 and j>=0){
            int num=arr[i--]+(temp[j--]-'0')+mod;
            mod=num/10;
            ans.push_back(num%10);
        }
        while(j>=0){
            int num=(temp[j--]-'0')+mod;
            mod=num/10;
            ans.push_back(num%10);
        }
        while(i>=0){
            int num=arr[i--]+mod;
            mod=num/10;
            ans.push_back(num%10);
        }
        if(mod>0){
            ans.push_back(mod);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};