class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> lps(n);
        int pre=0,suf=1;
        while(suf<n){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
        int maxi=lps[n-1];
        string ans=s.substr(0,maxi);
        return ans;
    }
};