class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int bits = 0;
        for(int& cell : cells)
        {
            bits = (bits << 1) | cell;
        }
        map<int, int> visited = {{bits, 0}};
        vector<int> order = {bits};
        int i = 1;
        int mask = 127;
        for(; i <= N; ++i)
        {
            bits = (~((bits << 1) ^ (bits >> 1)));
            bits &= ~1 & ~(1 << 7);
            bits &= mask;
            if(visited.count(bits)) break;
            visited.insert(make_pair(bits, i));
            order.emplace_back(bits);
        }
        int k = visited[bits];
        int period = i - k;
        bits = order[(N - k) % period + k];
        vector<int> res;
        for(int i = 7; i >= 0; --i)
        {
            res.emplace_back((bits & (1 << i)) >> i);
        }
        return res;
    }
};
