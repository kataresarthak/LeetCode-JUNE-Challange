class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int total = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                total += customers[i];
        }
        int max_extra = 0;
        int window_sum = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 1)
                window_sum += customers[i];
            if (i >= minutes && grumpy[i - minutes] == 1)
                window_sum -= customers[i - minutes];
            max_extra = max(max_extra, window_sum);
        }
        return total + max_extra;
    }
};