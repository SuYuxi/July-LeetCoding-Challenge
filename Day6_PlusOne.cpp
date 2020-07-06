class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits);
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            res[i] = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
        }
        if(carry) res.insert(res.begin(), carry);
        return res;
    }
};
