class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<int, int> map;
        for (int num : arr1)
        {
            map[num]++;
        }
        vector<int> result;
        for (int num : arr2)
        {
            while (map[num] > 0)
            {
                result.push_back(num);
                map[num]--;
            }
        }
        vector<int> element;
        for (const auto& entry : map)
        {
            int num = entry.first;
            int count = entry.second;
            while (count>0)
            {
                element.push_back(num);
                count--;
            }
        }
        sort(element.begin(), element.end());
        result.insert(result.end(), element.begin(), element.end());
        return result;
    }
};