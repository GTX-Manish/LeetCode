class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the input array to make it easier to use the two-pointer technique
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> v;  
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate elements to avoid duplicate triplets in the result
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int j = i + 1; 
            int k = nums.size() - 1;

            // Two-pointer approach to find valid triplets
            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];  // Calculate the sum of the triplet
                
                // If the sum is greater than 0, decrement the third pointer to reduce the sum
                if (total > 0) k--;
                // If the sum is less than 0, increment the second pointer to increase the sum
                else if (total < 0) j++;
                // If the sum is exactly 0, a valid triplet is found
                else {
                    // Add the current triplet to the result
                    v.push_back({nums[i], nums[j], nums[k]});
                    
                    j++;  // Move the second pointer forward to find other potential triplets

                    // Skip duplicate values to avoid duplicate triplets
                    while (j < k && nums[j] == nums[j-1]) j++;
                }
            }
        }

        // Return the vector containing all unique triplets
        return v;
    }
};
