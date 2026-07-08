class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> a;
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                a.push_back(nums1[i]);
                i++;
            } else {
                a.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            a.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            a.push_back(nums2[j]);
            j++;
        }

        for (int k = 0; k < m + n; k++) {
            nums1[k] = a[k];
        }
    }
};