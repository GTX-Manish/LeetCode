class Solution {
public:
    int romanToInt(string s) {
        // Map to store the integer values for each Roman numeral character
        unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                        {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int ans = 0; // Variable to store the final integer result

        // Loop through the Roman numeral string
        for (int i = 0; i < s.length(); i++) {
            // If the current Roman numeral is smaller than the next, subtract it (special case)
            // This handles cases like IV (4), IX (9), etc.
            if (i < s.length() - 1 && map[s[i]] < map[s[i+1]]) {
                ans -= map[s[i]];  // Subtract the current value
            } 
            // Otherwise, just add the current value to the result
            else {
                ans += map[s[i]];  // Add the current value
            }
        }
        return ans;  // Return the final computed integer value
    }
};
