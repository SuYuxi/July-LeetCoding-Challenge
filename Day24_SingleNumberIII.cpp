class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xOr = 0;
        for(int& num : nums)
        {
            xOr ^= num;
        }
        int lastBit = xOr & ~(xOr - 1);
        int a = xOr, b = xOr;
        for(int& num : nums)
        {
            if(num & lastBit)
            {
                a ^= num;
            }
            else
            {
                b ^= num;
            }
        }
        return {a, b};
    }
};
