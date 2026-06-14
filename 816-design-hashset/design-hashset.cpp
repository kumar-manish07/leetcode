class MyHashSet {
public:

    vector<int> box=vector<int>(1e6+1);

    MyHashSet() {
        
    }
    
    void add(int key) {
        box[key]=1;
    }
    
    void remove(int key) {
        if(box[key]==1)    box[key]=0;
    }
    
    bool contains(int key) {
        if(box[key]==1)  return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */