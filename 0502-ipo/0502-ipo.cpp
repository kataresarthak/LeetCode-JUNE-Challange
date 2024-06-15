class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); i++) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        
        priority_queue<int> pq;
        int i = 0;
        for (int j = 0; j < k; j++) {
            while (i < projects.size() && projects[i].first <= w) {
                pq.push(projects[i].second);
                i++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
            else
                break;
        }
        return w;
    }
};