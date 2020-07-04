class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglys(n);
        uglys[0] = 1;
        int inx2 = 0, inx3 = 0, inx5 = 0;
        for(int i = 1; i < n; ++i)
        {
            int ugly = min(2 * uglys[inx2], min(3 * uglys[inx3], 5 * uglys[inx5]));
            uglys[i] = ugly;
            if(ugly == 2 * uglys[inx2])
            {
                inx2 += 1;
            }
            if(ugly == 3 * uglys[inx3])
            {
                inx3 += 1;
            }
            if(ugly == 5 * uglys[inx5])
            {
                inx5 += 1;
            }
        }
        return uglys[n - 1];
        
    }
};
