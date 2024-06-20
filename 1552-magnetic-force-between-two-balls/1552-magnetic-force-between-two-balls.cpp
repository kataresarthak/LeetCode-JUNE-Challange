class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
         sort(position.begin(), position.end());
        int start = 1;
        int n = position.size();
        int end = position[n-1];
        int ans = 0;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            int count = 1; 
            int previous = position[0];
            for(int i = 1; i < position.size(); i++) {
                if((position[i] - previous) >= mid) {
                    count++;
                    previous = position[i];
                }
            }
            if(count >= m) {
                start = mid + 1;
                ans = mid;
            } 
            else
                end = mid - 1;
        }
        return ans;
    }
};