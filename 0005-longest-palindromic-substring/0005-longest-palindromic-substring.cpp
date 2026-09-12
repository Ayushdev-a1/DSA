class Solution {
public:
    // Expand outward from a chosen center and return the palindrome length.
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() &&
               s[left] == s[right]) {
            left--;
            right++;
        }

        return right - left - 1;
    }

    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int start = 0;
        int bestLength = 1;

        // Check odd- and even-length palindromes for every position.
        for (int center = 0; center < s.length(); center++) {
            int oddLength = expandAroundCenter(s, center, center);
            int evenLength = expandAroundCenter(s, center, center + 1);
            int currentLength = max(oddLength, evenLength);

            // Update the best palindrome when the current one is longer.
            if (currentLength > bestLength) {
                bestLength = currentLength;
                start = center - (currentLength - 1) / 2;
            }
        }

        return s.substr(start, bestLength);
    }
};