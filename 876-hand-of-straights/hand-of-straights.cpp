class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)    return false;
        sort(hand.begin(),hand.end());
        unordered_map<int,int> freq;
        for(auto it:hand)   freq[it]++;
        for(int i=0;i<n;i++){
            int num=hand[i];
            if(freq[num]==0)    continue;
            for(int j=num;j<=num+groupSize-1;j++){
                if(freq[j]==0)     return false;
                freq[j]--;
            }
        }
        return true;
    }
};