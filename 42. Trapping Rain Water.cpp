class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;   // Initialize two pointers, left and right
        int res = 0;            // Variable to store the total amount of trapped water
        int lmax = 0, rmax = 0; // Variables to store the maximum heights on the left and right sides

        while (l <= r) {
            if (height[l] <= height[r]) {
                // Update left maximum height if current height is greater than or equal to left maximum
                if (height[l] >= lmax) {
                    lmax = height[l];
                }
                // Otherwise, calculate the trapped water based on the difference between left maximum and current height
                else {
                    res += lmax - height[l];
                }
                l++;
            }
            else {
                // Update right maximum height if current height is greater than or equal to right maximum
                if (height[r] >= rmax) {
                    rmax = height[r];
                }
                // Otherwise, calculate the trapped water based on the difference between right maximum and current height
                else {
                    res += rmax - height[r];
                }
                r--;
            }
        }
        return res;
    }
};
