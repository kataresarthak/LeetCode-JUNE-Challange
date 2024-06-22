class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1; 
        
        int count = 0;
        int result = 0;
        
        for (int num : nums)
        {
            count += num % 2;
            if (map.find(count - k) != map.end())
                result += map[count - k];
            map[count]++;
        }
        return result;
    }
};