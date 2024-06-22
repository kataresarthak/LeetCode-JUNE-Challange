class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return  func(nums, k) - func(nums, k - 1);
    }
     int func(vector<int>& nums, int goal){
        if(goal < 0)
            return 0;
        int r = 0, l = 0, count = 0, sum = 0;
        while(r < nums.size())
        {
            sum += nums[r] % 2;
            while(sum > goal) {
                sum = sum - nums[l] % 2;
                l++;
            }
            count = count + (r - l + 1);
            r++;
        }
        return count;
    }
};