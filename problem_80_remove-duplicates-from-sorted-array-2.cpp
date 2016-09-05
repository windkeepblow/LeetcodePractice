class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int cur_max = nums[0];
        int cur_idx = 1;
        int last_num = nums[0];
        int bonus = 1;
        for (int i = cur_idx; i < nums.size(); i++) {
        	if (cur_max >= nums[i] && bonus <= 0) {
        		continue;
        	} else {
        		nums[cur_idx] = nums[i];
        		cur_max = nums[i];
        		cur_idx++;

        		if (nums[i] == last_num) {
        			bonus--;
        		} else {
        			last_num = nums[i];
        			bonus = 1;
        		}
        	}
        }

        return cur_idx;
    }
};