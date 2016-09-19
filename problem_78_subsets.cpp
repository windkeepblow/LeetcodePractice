class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> buf;
        subsets_helper(res, buf, nums, 0, nums.size());
        return res;
    }

    void subsets_helper(vector<vector<int>>& res, vector<int>& buf, vector<int>& nums, int start, int size) {
        res.push_back(buf);
        for (int i = start; i < size; i++) {
        	buf.push_back(nums[i]);
        	subsets_helper(res, buf, nums, i + 1, size);
        	buf.pop_back();
        }
    }
};