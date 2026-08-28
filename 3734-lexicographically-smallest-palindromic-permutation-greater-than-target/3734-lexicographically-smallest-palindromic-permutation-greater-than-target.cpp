class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        // Count characters in s
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check if palindrome is possible
        int odd = 0;
        int midChar = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                midChar = i;
            }
        }

        if (odd > n % 2) {
            return "";
        }

        int m = n / 2;

        // Characters available in the left half
        vector<int> half(26);
        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        string ans = "";

        // Try every position where our palindrome becomes
        // strictly greater than target.
        for (int pos = 0; pos < m; pos++) {

            vector<int> rem = half;
            string left;
            bool possible = true;

            // Keep prefix equal to target
            for (int i = 0; i < pos; i++) {
                int c = target[i] - 'a';

                if (rem[c] == 0) {
                    possible = false;
                    break;
                }

                left += target[i];
                rem[c]--;
            }

            if (!possible)
                continue;

            // At pos, choose smallest character > target[pos]
            int chosen = -1;

            for (int c = target[pos] - 'a' + 1; c < 26; c++) {
                if (rem[c] > 0) {
                    chosen = c;
                    break;
                }
            }

            if (chosen == -1)
                continue;

            left += char('a' + chosen);
            rem[chosen]--;

            // Fill remaining left half with smallest characters
            for (int c = 0; c < 26; c++) {
                while (rem[c] > 0) {
                    left += char('a' + c);
                    rem[c]--;
                }
            }

            // Build palindrome
            string cur = left;

            if (n % 2) {
                cur += char('a' + midChar);
            }

            string rev = left;
            reverse(rev.begin(), rev.end());

            cur += rev;

            // Keep smallest valid answer
            if (cur > target && (ans.empty() || cur < ans)) {
                ans = cur;
            }
        }

        // Case where the entire left half equals target's left half
        {
            vector<int> rem = half;
            string left;
            bool possible = true;

            for (int i = 0; i < m; i++) {
                int c = target[i] - 'a';

                if (rem[c] == 0) {
                    possible = false;
                    break;
                }

                left += target[i];
                rem[c]--;
            }

            if (possible) {
                string cur = left;

                if (n % 2) {
                    cur += char('a' + midChar);
                }

                string rev = left;
                reverse(rev.begin(), rev.end());

                cur += rev;

                if (cur > target && (ans.empty() || cur < ans)) {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};