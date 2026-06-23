class Solution {
public:

    int count(vector<int>& bloomDay,int mid,int k){
        int cnt=0,flower=0;
        for(auto it:bloomDay){
            if(it<=mid)  cnt++;
            else{
                flower+=(cnt/k);
                cnt=0;
            }
        }
        flower+=(cnt/k);
        return flower;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if (((long)m*k)>n) return -1;
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int bouquet=count(bloomDay,mid,k);
            if(bouquet>=m){
                ans=mid;
                h=mid-1;
            }
            else   l=mid+1;
        }
        return ans;
    }
};