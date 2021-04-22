class Solution {
public:
   
 int secondHighest(string str){
        unordered_map<int,int> m;
        int ans=-1;
        for(int i=0;i<str.length();i++){
            if(str[i]>='0' and str[i]<='9'){
                m[(str[i]-'0')]=1;
            }
        }
        vector<int> arr;
        for(auto it:m){
            arr.push_back(it.first);
        }
        sort(arr.begin(),arr.end());
        if(arr.size()>1){
            ans=arr[arr.size()-2];
        }
        return ans;
    }
};