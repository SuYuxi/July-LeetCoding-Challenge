class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        auto cmp = [](pair<int, int>& a, pair<int, int>& b){ return a.second > b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);
        vector<int> ans;
        for(int& num : nums)
        {
          counter[num] += 1;
        }
        for(pair<const int, int> p : counter)
        {
            heap.emplace(make_pair(p.first, p.second));
            if(heap.size() > k) heap.pop();
        }
        for(int i = 0; i < k; ++i)
        {
            ans.emplace_back(heap.top().first);
            heap.pop();
        }
        return ans;
    }
};
