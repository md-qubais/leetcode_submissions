#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
class CustomStack {
public:
    int *s;
    int i=0;
    int maxSize;
CustomStack(int maxSize){
    this->maxSize=maxSize;
	s=new int[maxSize];
}
void push(int x){
	if(i<maxSize){
		s[i++]=x;
	}
}
int pop(){
	if(i<=0){
		return -1;
	}
	return s[--i];
}

void increment(int k, int val){

	for(int j=0;j<k and j<i ;j++){
		s[j]+=val;
	}
}
};

int32_t main(){
	qubais_judge;
	IOS;
	CustomStack customStack(3);// = new CustomStack(3); // Stack is Empty []
customStack.push(1);                          // stack becomes [1]
customStack.push(2);                          // stack becomes [1, 2]
cout<<customStack.pop()<<endl;                            // return 2 --> Return top of the stack 2, stack becomes [1]
customStack.push(2);                          // stack becomes [1, 2]
customStack.push(3);                          // stack becomes [1, 2, 3]
customStack.push(4);                          // stack still [1, 2, 3], Don't add another elements as size is 4
customStack.increment(5, 100);                // stack becomes [101, 102, 103]
customStack.increment(2, 100);                // stack becomes [201, 202, 103]
cout<<customStack.pop()<<endl;                            // return 2 --> Return top of the stack 2, stack becomes [1]
cout<<customStack.pop()<<endl;                            // return 2 --> Return top of the stack 2, stack becomes [1]
cout<<customStack.pop()<<endl;                            // return 2 --> Return top of the stack 2, stack becomes [1]
cout<<customStack.pop()<<endl;                            // return 2 --> Return top of the stack 2, stack becomes [1]

	return 0;
}