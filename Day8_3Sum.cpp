class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n - 2; i++)
        {
            if(i == 0 || nums[i] != nums[i - 1])
            {
                int sum = nums[i];
                int lo = i + 1;
                int hi = n - 1;
                while(lo < hi)
                {

                    if(nums[lo] + nums[hi] + sum == 0)
                    {
                        ans.emplace_back(vector<int>({sum, nums[lo], nums[hi]}));
                        while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi - 1]) hi--;
                        lo++;
                        hi--;
                    }
                    else if(nums[lo] + nums[hi] + sum > 0)
                    {
                        hi--;
                    }
                    else
                    {
                        lo++;
                    }
                }
            }
        }
        return ans;
    }
};
