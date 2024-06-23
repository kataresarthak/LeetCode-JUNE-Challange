class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0, right = 0, max_len = 0;
        deque<int> max_deque, min_deque;
        
        while (right < nums.size())
        {
            while (!max_deque.empty() && max_deque.back() < nums[right])
                max_deque.pop_back();
            while (!min_deque.empty() && min_deque.back() > nums[right])
                min_deque.pop_back();
            max_deque.push_back(nums[right]);
            min_deque.push_back(nums[right]);
            
            while (max_deque.front() - min_deque.front() > limit) {
                if (max_deque.front() == nums[left])
                    max_deque.pop_front();
                if (min_deque.front() == nums[left])
                    min_deque.pop_front();
                left++;
            }
            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;
    }
};