class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0;
        int p2 = 0;
        int step1 = 1
        int step2 = 1;
        bool reverse = false;

        if (nums1 != NULL && nums1[0] > nums1[m - 1]) {
        	p1 = m;
        	step1 = -1;
        }

        if (nums2 != NULL && nums2[0] > nums2[n - 1]) {
            p2 = n;
            step2 = -1;
        }
        
        while (p1 >= 0 && p1 <= m || p2 >= 0 && p2 <= n) {
            if (nums1[p1] < nums2[p2]) {
                p1 += step1;
            } else {
                nums1.insert(nums1.begin() + p1, nums2[p2]);
                p1 += step;
                p2 += step;
            }
        }

        return nums1;
    }
};