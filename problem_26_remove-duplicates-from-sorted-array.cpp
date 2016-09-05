class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if (nums.size() == 0) return 0;

        int cur_max = nums[0];
        int cur_idx = 1;
        for (int i = 1; i < nums.size(); i++) {
        	if (cur_max >= nums[i]) {
        		continue;
        	} else {
        		nums[cur_idx] = nums[i];
        		cur_max = nums[i];
                cur_idx++;
        	}
        }
        return cur_idx;
    }
};