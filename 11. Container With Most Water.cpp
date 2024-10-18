class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;                         // Left pointer
        int j = height.size() - 1;        // Right pointer
        int k = j;                         // Width between the two pointers
        int max_area = 0;                  // Variable to store the maximum area

        // Use a two-pointer approach to find the maximum area.
        while (i < j) {
            // Calculate the area with the current left and right boundaries.
            max_area = max(max_area, (min(height[i], height[j])) * k);

            // Move the pointer pointing to the shorter line to try to find a taller line.
            if (height[i] < height[j]) {
                i++;        // Increment left pointer.
                k--;        // Decrease width since left pointer has moved.
            } else {
                j--;        // Decrement right pointer.
                k--;        // Decrease width since right pointer has moved.
            }
        }
        return max_area;  // Return the maximum area found.
    }
};
