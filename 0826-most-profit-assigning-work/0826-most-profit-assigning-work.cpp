class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        int n = difficulty.size();
        int m = worker.size();
        vector< pair<int, int>> jobs(n);
        
        for (int i = 0; i < n; i++)
            jobs[i] = {difficulty[i], profit[i]};
        
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        
        int max = 0;
        int j = 0;
        int total = 0;
        
        for (int i = 0; i < m; i++)
        {
            while (j < n && jobs[j].first <= worker[i]) {
                max = std::max(max, jobs[j].second);
                j++;
            }
            total += max;
        }
        return total;
    }
};
