class Solution {
public:
    string convert(string s, int numRows) {
        // Create a vector of strings to store characters for each row.
        vector<string> v(numRows);
        int i = 0;  // Index to track position in the input string.

        // Iterate through the input string until the end is reached.
        while (i < s.length()) {
            // Traverse downwards across the rows.
            for (int j = 0; j < numRows && i < s.length(); j++) {
                v[j] += s[i++];  // Add character to the current row.
            }
            // Traverse upwards across the rows (except the first and last rows).
            for (int j = numRows - 2; j > 0 && i < s.length(); j--) {
                v[j] += s[i++];  // Add character to the current row.
            }
        }

        // Construct the final output string by concatenating all rows.
        string ans = "";
        for (int i = 0; i < numRows; i++) {
            ans += v[i];  // Append each row's string to the result.
        }
        
        return ans;  // Return the final zigzag converted string.
    }
};
