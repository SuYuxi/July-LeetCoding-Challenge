class Solution {
public:
    int hammingDistance(int x, int y) {
        int h = x ^ y;
        int res = 0;
        for(int i = 0; i < 31; ++i)
        {
            res += (h & 1);
            h >>= 1;
        }
        return res;
    }
};
