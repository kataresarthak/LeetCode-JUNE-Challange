class Solution {
public:
    int heightChecker(vector<int>& heights) {
        std::vector<int> expected = heights;
        
        std::sort(expected.begin(),expected.end());
        
        int count = 0;
        for (int i=0; i < heights.size(); i++)
        {
            if (heights[i] != expected[i])
                count++;
        }
        return count;
    }
};