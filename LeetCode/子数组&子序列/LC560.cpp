class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, prefix = 0;
        map<int,int> prefixCnt{{0,1}};
        for(int i = 0; i<nums.size(); i++){
            prefix += nums[i];
            ans += prefixCnt[prefix - k];
            prefixCnt[prefix]++;
        }
        return ans;
    }
};

