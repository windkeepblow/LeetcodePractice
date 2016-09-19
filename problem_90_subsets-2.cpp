class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> buf;
        subsets_helper(buf, res, nums, 0, nums.size());
        return res;
    }
    
private:
    void subsets_helper(vector<int>& buf, vector<vector<int>>& res, vector<int>& nums, int start, int size) {
        res.push_back(buf);
        for (int i = start; i < size; i++) {
        	buf.push_back(nums[i]);
        	subsets_helper(buf, res, nums, i + 1, size);
        	buf.pop_back();
        	while (i + 1 < size && nums[i] == nums[i + 1]) i++;
        }
    }
};