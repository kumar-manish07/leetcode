class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int right=0,left=0,best=0;
        int i=0,j=n-k;
        for(int i=n-1;i>=n-k;i--)   right+=cardPoints[i];
        while(k--){
            int takeLeft=right-cardPoints[j]+left+cardPoints[i];
            int takeRight=left+right;
            left+=cardPoints[i++];
            right-=cardPoints[j++];
            best=max({best,takeLeft,takeRight});
        }
        return best;
    }
};