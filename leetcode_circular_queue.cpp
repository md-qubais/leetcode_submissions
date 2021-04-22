#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;

class MyCircularQueue {
public:
    int max_size;
    int *arr;
    int front;
    int rear;
    int curr;
    MyCircularQueue(int k) {
        max_size=k;
        arr=new int[max_size];
        front=-1;
        rear=-1;
        curr=0;
    }
    
    bool enQueue(int value) {
        if(curr>=max_size){
            return false;
        }
        if(curr==0){
            front=0;
            rear=0;
            arr[front]=value;
        }else{
            front=(front+1)%max_size;
            arr[front]=value;
        }
        curr++;
        return true;
    }
    
    bool deQueue() {
        if(curr<=0){
            return false;
        }
        rear=(rear+1)%max_size;
        curr--;
        return true;
    }
    
    int Front() {
        if(curr<=0){
            return -1;
        }
        return arr[rear];
    }
    
    int Rear() {
        if(curr<=0){
            return -1;
        }
        return arr[front];
    }
    
    bool isEmpty() {
        if(curr<=0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(curr>=max_size){
            return true;
        }
        return false;
    }
};
int32_t main(){
    qubais_judge;
    IOS;
    MyCircularQueue myCircularQueue(3);
cout<<myCircularQueue.enQueue(1)<<endl; // return True
cout<<myCircularQueue.enQueue(2)<<endl; // return True
cout<<myCircularQueue.enQueue(3)<<endl; // return True
cout<<myCircularQueue.enQueue(4)<<endl; // return False
cout<<myCircularQueue.Rear()<<endl;     // return 3
cout<<myCircularQueue.isFull()<<endl;   // return True
cout<<myCircularQueue.deQueue()<<endl;  // return True
cout<<myCircularQueue.enQueue(4)<<endl; // return True
cout<<myCircularQueue.Rear()<<endl;     // return 4
    return 0;
}