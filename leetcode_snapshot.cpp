class SnapshotArray {
public:
	vector<int> arr;
	int snap_shot;
    SnapshotArray(int length) {
    	arr.resize(length);
    	snap_shot=0;
    }
    
    void set(int index, int val) {
    	arr.insert(arr.begin()+index,val);
    }
    int snap(){
    	snap_shot++;
    	return snap_shot-1;
    }
    
    int get(int index, int snap_id) {
    	
    }
};