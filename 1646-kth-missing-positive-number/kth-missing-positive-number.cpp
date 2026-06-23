class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int missing=arr[0]+k;
        if(arr[0]>k)    return k;
        else    missing-=(arr[0]-1);
        for(int i=1;i<n;i++){
            if(arr[i]>missing)   return missing;
            missing++;
        }
        return missing;
    }
};