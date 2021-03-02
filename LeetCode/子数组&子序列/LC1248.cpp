class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int prefix = 0, ans = 0;
        vector<int> prefixCnt;
        prefixCnt.resize(nums.size()+1,0);
        prefixCnt[0] = 1;
        for(int i = 0;  i < nums.size(); i++){
            prefix += (nums[i] & 1);
            if(prefix >= k){
                ans += prefixCnt[prefix - k]; 
            }
            prefixCnt[prefix]++;
        }
        return ans;
    }
};
