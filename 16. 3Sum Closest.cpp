class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Initialize closestSum to a very large number (half of INT_MAX to avoid overflow)
        int closestSum = INT_MAX / 2;

        // Sort the array
        sort(nums.begin(), nums.end());

        // Iterate through the array, treating nums[k] as the first element of the triplet
        for (int k = 0; k < nums.size() - 2; k++) {
            int i = k + 1;
            int j = nums.size() - 1;

            // Use two-pointer technique to find the closest sum
            while (i < j) {
                int sum = nums[i] + nums[j] + nums[k];  // Calculate the sum of the current triplet

                // If the current sum is closer to the target, update closestSum
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                // Adjust pointers based on the comparison of sum and target
                if (sum > target) {
                    j--;  // If sum is greater than the target, move the third pointer left to reduce sum
                }
                else if (sum < target) {
                    i++;  // If sum is less than the target, move the second pointer right to increase sum
                }
                else {
                    // If sum is exactly equal to the target, return it immediately (it's the closest possible sum)
                    return sum;
                }
            }
        }

        // Return the sum that is closest to the target
        return closestSum;
    }
};
