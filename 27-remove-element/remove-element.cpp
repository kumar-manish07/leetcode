class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        if(n==0)   return 0;
        int l=0,r=n-1;
        while(l<=r){
            if(nums[l]!=val)  l++;
            else{
                if(nums[r]==val)   r--;
                else{
                    swap(nums[l],nums[r]);
                    l++;
                    r--;
                }
            }
        }
        return l;
    }
};