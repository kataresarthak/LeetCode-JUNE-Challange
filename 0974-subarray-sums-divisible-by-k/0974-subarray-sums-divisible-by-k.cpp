class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int> map;
        map[0]=1; 
        
        int prefixSum=0;
        int count=0;
        
        for (int num : nums)
        {
            prefixSum += num;
            int mod=((prefixSum % k)+k) % k;
            
            if (map.find(mod) != map.end())
            {
                count += map[mod];
            }
            map[mod]++;
        }
        return count;
    }
};