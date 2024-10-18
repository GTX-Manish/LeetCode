class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;  // Merged vector to store elements from both arrays.

        // Add elements from nums1 to the merged vector.
        for (auto k : nums1) {
            v.push_back(k);
        }
        // Add elements from nums2 to the merged vector.
        for (auto k : nums2) {
            v.push_back(k);
        }

        // Sort the merged vector.
        sort(v.begin(), v.end());
        int n = v.size();  // Total size of the merged vector.

        // If size is odd, return the middle element; if even, return the average of two middle elements.
        return n % 2 ? v[n / 2] : (v[n / 2 - 1] + v[n / 2]) / 2.0;
    }
};
