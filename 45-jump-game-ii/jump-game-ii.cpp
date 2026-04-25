class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dist(n,1e9);
        dist[0]=0;
        for(int i=0;i<n-1;i++){
            int maxDist=min(nums[i],n-i-1);
            for(int j=1;j<=maxDist;j++){
                int idx=i+j;
                dist[idx]=min(dist[idx],dist[i]+1);
            }
        }
        return dist[n-1];
    }
};