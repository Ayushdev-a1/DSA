class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool findFirst) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            ans = mid;

            if (findFirst)
                high = mid - 1;  
            else
                low = mid + 1;   
        }
        else if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
       return {
        binarySearch(nums, target, true),
        binarySearch(nums, target, false)
    };
    }
};