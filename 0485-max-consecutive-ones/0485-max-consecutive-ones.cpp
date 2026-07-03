class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0 ;
    int ans = 0 ;
    for (int x : nums){
          if(x== 1){
            count++;
            ans = max(count , ans);
          }
          else{
            count = 0 ;
          }

         
    }
      return ans ;
}
};