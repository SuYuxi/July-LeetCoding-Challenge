class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        int carry = 0;
        int sum = 0;
        string res = "";
        while(m > 0 || n > 0)
        {
            sum = carry;
            if(m > 0) sum += (a[--m] - '0');
            if(n > 0) sum += (b[--n] - '0');
            carry = sum / 2;
            sum = sum % 2;
            res += '0' + sum;
        }
        if(carry != 0) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
