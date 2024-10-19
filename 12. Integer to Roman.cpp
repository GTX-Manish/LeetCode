class Solution {
public:
    // Function to convert an integer to its corresponding Roman numeral
    string intToRoman(int num) {
        // Map of integer values to their respective Roman numeral representations
        map<int, string> map;
        map[1] = "I";
        map[4] = "IV";   // Special case: 4 represented as IV (5 - 1)
        map[5] = "V";
        map[9] = "IX";   // Special case: 9 represented as IX (10 - 1)
        map[10] = "X";
        map[40] = "XL";  // Special case: 40 represented as XL (50 - 10)
        map[50] = "L";
        map[90] = "XC";  // Special case: 90 represented as XC (100 - 10)
        map[100] = "C";
        map[400] = "CD"; // Special case: 400 represented as CD (500 - 100)
        map[500] = "D";
        map[900] = "CM"; // Special case: 900 represented as CM (1000 - 100)
        map[1000] = "M";

        string ans = "";  // Variable to store the final Roman numeral string

        // Iterate over the map in reverse order (starting from the largest values)
        for (auto i = map.rbegin(); i != map.rend(); ++i) {
            int a = i->first;      // Integer value
            string b = i->second;  // Corresponding Roman numeral

            // Append the Roman numeral to the result while reducing num by the value
            while (num >= a) {
                ans += b;          // Add the Roman numeral to the result string
                num -= a;          // Subtract the integer value from num
            }
        }
        return ans;  // Return the final Roman numeral string
    }
};
