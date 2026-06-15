class SnapshotArray {
public:

    int snapId;
    vector<vector<pair<int,int>>> history;

    SnapshotArray(int length) {
        snapId=0;
        history.resize(length);
        for(int i=0;i<length;i++){
            history[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        if(history[index].back().first==snapId){
            history[index].back().second=val;
        }
        else{
            history[index].push_back({snapId,val});
        }
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto &v=history[index];
        int l=0,r=v.size()-1;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(v[mid].first<=snap_id){
                ans=mid;
                l=mid+1;
            }
            else   r=mid-1;
        }
        return v[ans].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */