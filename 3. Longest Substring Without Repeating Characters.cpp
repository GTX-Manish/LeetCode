class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0, cmax = INT_MIN; // Track current and max lengths.
        int l = 0, r = 0; // Sliding window pointers.
        unordered_map<char, int> map; // Store the latest index of characters.

        if (s == "") return 0; // Handle empty string.

        while (r < s.length()) {
            // If character is new or its previous occurrence is outside the current window.
            if (map.find(s[r]) == map.end() || map[s[r]] < l) {
                map[s[r]] = r; // Update character's latest index.
                count = r - l + 1; // Calculate current window length.
                cmax = max(count, cmax); // Update max length.
                r++; // Expand window.
            } else {
                l = map[s[r]] + 1; // Move left pointer past duplicate.
            }
        }
        return cmax; // Return max length found.
    }
};
