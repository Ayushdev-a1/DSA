class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int interval = 0;

        for (int i = 0; i < n; i++) {
            int tiring = 0;
            int non_tiring = 0;
            int current = 0;
            for (int j = i; j < n; j++) {
                if (hours[j] > 8) {
                    tiring++;
                } else {
                    non_tiring++;
                }

                if (tiring > non_tiring) {
                    current = j - i + 1;
                }

                interval = max(current, interval);
            }
        }

        return interval;
    }
};