class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count =0 ;
        
        unordered_map<int ,int>mp ;
        mp[0] =1 ;
        int prefix_sum =0 ;
        for(int i =0 ; i<n ; i++){
            prefix_sum += nums[i] ; 
            int remain = prefix_sum - k ; 
            if(mp.find(remain) != mp.end()){
                count += mp[remain];
            }

            mp[prefix_sum] ++ ; 
        }

        return count ; 
    }
};