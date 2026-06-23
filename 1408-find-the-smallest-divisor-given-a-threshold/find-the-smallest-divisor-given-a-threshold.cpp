class Solution {
public:

    int count(vector<int>& nums,int mid){
        int cnt=0;
        for(auto it:nums){
            cnt+=(it/mid);
            if(it%mid!=0)   cnt++;
        }
        return cnt;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            int cnt=count(nums,mid);
            if(cnt<=threshold){
                ans=mid;
                h=mid-1;
            }
            else   l=mid+1;
        }
        return ans;
    }
};