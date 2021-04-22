class Solution{
public:
    int numDifferentIntegers(string word) {
        map<string,int> m;
        string temp="";
        for(int i=0;i<word.length();i++){
            if(word[i]<'0' or word[i]>'9'){
                if(temp.length()>0){
                    
                    while(temp.length()>1 and temp[0]=='0'){
                        temp=temp.substr(1);
                        
                    }
                    if(temp.length()>0)
                    m[temp]++;
                }
                temp="";
            }
            else temp+=word[i];
        }
        if(temp.length()>0){
        
                    while(temp.length()>1 and temp[0]=='0'){
                        temp=temp.substr(1);
                        
                    }
                    if(temp.length()>0)
                    m[temp]++;
                }
                   for(auto it:m){
            cout<<it.first<<" ";
        }
     cout<<endl;
        return m.size();
    }
};