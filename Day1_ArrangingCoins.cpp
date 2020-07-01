class Solution {
public:
    int arrangeCoins(int n) {
        return int(-0.5 + 0.5 * sqrt(1 + 8 * (long)n));
    }
};
