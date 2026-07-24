class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> pairXor;
        unordered_set<int> result;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        for (int x : pairXor) {
            for (int num : nums) {
                result.insert(x ^ num);
            }
        }

        return result.size();
    }
};