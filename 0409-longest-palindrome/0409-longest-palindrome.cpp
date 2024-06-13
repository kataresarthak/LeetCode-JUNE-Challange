class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for(auto x: s)
            mp[x]++;
        
        int ans = 0, count = 0;
        for(auto x: mp) 
        {
            ans += x.second;
            if((x.second % 2) && count)
                ans--;
            if(count == 0 && x.second % 2)
                count = 1;
        }
        return ans;
    }
};
