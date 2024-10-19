class Solution {

private:
    // Helper function for backtracking
    // It generates all possible combinations of letters by recursively adding characters
    // from the current digit's corresponding letter mapping.
    void backtrack(string digits, string output, int i, vector<string>& ans, string mapping[]) {
        // Base case: if we have processed all the digits, add the current combination to the result
        if (i >= digits.size()) {
            ans.push_back(output);
            return;
        }

        // Get the digit at index 'i' and map it to its corresponding string of letters
        int num = digits[i] - '0';      // Convert the character to an integer
        string value = mapping[num];    // Get the letters corresponding to this digit

        // Loop through each letter in the current digit's mapping
        for (int j = 0; j < value.size(); j++) {
            output.push_back(value[j]); // Add the current letter to the output
            backtrack(digits, output, i + 1, ans, mapping); // Recurse for the next digit
            output.pop_back();           // Remove the letter (backtrack) and try the next one
        }
    }

public:
    // Main function to return all possible letter combinations for a given string of digits
    vector<string> letterCombinations(string digits) {
        // Mapping of digits to corresponding letters (like on a phone keypad)
        string mapping[10] = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans; // Vector to store all the letter combinations

        // Edge case: If the input is empty, return an empty result
        if (digits.empty()) return ans;

        // Start the backtracking process
        int i = 0;
        string output;  // Variable to store the current combination of letters
        backtrack(digits, output, i, ans, mapping); // Begin the backtracking from index 0

        return ans;  // Return all the generated combinations
    }
};
