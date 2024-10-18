class Solution {
public:
    string longestPalindrome(string s) {
        // Return an empty string if the input is empty.
        if (s.empty()) return "";

        int start = 0;  // Start index of the longest palindrome found.
        int end = 0;    // End index of the longest palindrome found.

        // Iterate through each character in the string.
        for (int i = 0; i < s.length(); i++) {
            // Check for the longest odd-length palindrome centered at i.
            int odd = centerFunc(s, i, i);
            // Check for the longest even-length palindrome centered between i and i+1.
            int even = centerFunc(s, i, i + 1);
            // Determine the maximum length between the two found palindromes.
            int max_len = max(odd, even);

            // Update start and end indices if a longer palindrome is found.
            if (max_len > end - start) {
                start = i - (max_len - 1) / 2; // Adjust start index.
                end = i + max_len / 2;         // Adjust end index.
            }
        }
        // Return the longest palindrome substring.
        return s.substr(start, end - start + 1);
    }

private:
    // Helper function to expand around the center and find the length of the palindrome.
    int centerFunc(string s, int left, int right) {
        // Expand outwards as long as the characters match.
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;   // Move left pointer outwards.
            right++;  // Move right pointer outwards.
        }
        // Return the length of the palindrome found.
        return (right - left - 1);
    }
};
