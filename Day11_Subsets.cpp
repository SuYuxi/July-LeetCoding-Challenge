class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets = {{}};
        for(int& num : nums)
        {
            int size = sets.size();
            for(int i = 0; i < size; ++i)
            {
                sets.emplace_back(sets[i]);
                sets.back().emplace_back(num);
            }
        }
        return sets;
    }
};
