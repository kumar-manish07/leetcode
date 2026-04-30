class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0)    return false;
        unordered_map<int,int> freq;
        for(auto num:nums)   freq[num]++;
        sort(nums.begin(),nums.end());
        for(auto num:nums){
            if(freq[num]==0)   continue;
            for(int i=num;i<=num+k-1;i++){
                if(freq[i]==0)  return false;
                freq[i]--;
            }
        }
        return true;
    }
};