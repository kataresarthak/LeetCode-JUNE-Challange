#include <vector>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long) m * k > bloomDay.size())
            return -1;

        int low = 1, high = 1e9;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (isPossibleBouquets(bloomDay, m, k, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

private:
    bool isPossibleBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int total = 0, count = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= day)
            {
                count++;
                if (count == k) {
                    total++;
                    count = 0;
                }
            }
            else 
                count = 0;
            if (total >= m)
                return true;
        }
        return false;
    }
};
