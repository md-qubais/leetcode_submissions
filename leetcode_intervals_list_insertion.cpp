class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>&arr1,vector<vector<int>>&arr2){
        vector<vector<int>> ans;
        int i=0;
        int j=0;
        vector<pair<int,int>> temp;
        while(i<arr1.size() and j<arr2.size()){
            if(((arr1[i][1]>=arr2[j][0] and arr1[i][1]<=arr2[j][1]) or (arr2[j][1]>=arr1[i][0] and arr2[j][1]<=arr1[i][1])) ){
                temp.push_back(make_pair(max(arr1[i][0],arr2[j][0]),min(arr1[i][1],arr2[j][1])));
            }
            if(arr1[i][1]<arr2[j][1]){
                i++;
                continue;
            }
            if(arr1[i][1]>arr2[j][1]){
                j++;
                continue;
            }
            if(arr1[i][1]==arr2[j][1]){
                if(arr1[i][0]>arr2[j][0]) j++;
                else i++;
            }
        }
        for(auto&it:temp){
            vector<int> arr;
            arr.push_back(it.first);
            arr.push_back(it.second);
            ans.push_back(arr);
        }
        return ans;
    } 
};