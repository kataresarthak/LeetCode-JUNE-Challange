class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_set<int> set;
        int prev_sum = 0;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum = (sum + nums[i]) % k;
            if(set.find(sum) != set.end())
                return true;
            set.insert(prev_sum);
            prev_sum = sum;
        }
        return false;
    }
};
