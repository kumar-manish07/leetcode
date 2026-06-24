class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int l=2,r=2;
        if(n<=2)    return n;
        while(r<n){
            if(nums[l-2]!=nums[r]){
                nums[l]=nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};