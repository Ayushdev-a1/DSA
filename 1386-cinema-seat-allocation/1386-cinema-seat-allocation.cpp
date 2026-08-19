class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

           
            if (s >= 2 && s <= 9) {
                rows[row] |= (1 << (s - 2));
            }
        }

       
        long long ans = 2LL * n;

        int left   = 15;  
        int middle = 60;   
        int right  = 240;  

        for (auto &[row, mask] : rows) {

            bool canLeft   = (mask & left) == 0;
            bool canMiddle = (mask & middle) == 0;
            bool canRight  = (mask & right) == 0;

            int families;

            if (canLeft && canRight) {
                families = 2;
            }
            else if (canLeft || canMiddle || canRight) {
                families = 1;
            }
            else {
                families = 0;
            }
            ans -= 2;
            ans += families;
        }

        return ans;
    }
};