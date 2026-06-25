class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> temp(n,0);
        for(int i=0;i<n;i++){
            if(citations[i]==0)  continue;
            int idx=min(n-1,citations[i]-1);
            temp[idx]++;
        }
        if(temp[n-1]==n)   return n;
        for(int i=n-2;i>=0;i--){
            int paper=temp[i]+temp[i+1];
            temp[i]=paper;
            if(paper>=i+1)   return i+1;
        }
        return 0;
    }
};