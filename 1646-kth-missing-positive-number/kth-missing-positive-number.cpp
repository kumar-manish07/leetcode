class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k<arr[0])   return k;
        int l=0,h=arr.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int missing=arr[mid]-mid-1;
            if(missing<k)    l=mid+1;
            else    h=mid-1;
        }
        int missing=arr[h]-h-1;
        int more=k-missing;
        int ans=arr[h]+more;
        return ans;
    }
};