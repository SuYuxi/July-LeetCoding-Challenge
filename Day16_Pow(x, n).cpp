class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        double cur = x;
        for(long long i = N; i != 0; i /= 2)
        {
            if(i & 1 == 1) ans *= cur;
            cur = cur * cur;
        }
        return ans;
    }
};
