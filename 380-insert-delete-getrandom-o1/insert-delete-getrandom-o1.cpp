class RandomizedSet {
public:
    
    vector<int> box;
    unordered_map<int,int> mp;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        int idx=box.size();
        box.push_back(val);
        mp[val]=idx;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        int idx=mp[val];
        int lastElement=box.back();
        box.back()=val;
        box[idx]=lastElement;
        box.pop_back();
        mp[lastElement]=idx;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n=box.size();
        int idx=rand()%n;
        return box[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */