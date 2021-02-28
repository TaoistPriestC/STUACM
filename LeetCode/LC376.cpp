class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2){
            return nums.size();
        }
        int up = 1,dn = 1;
        for(int i = 1;i<nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                up = dn + 1;
            }
            if(nums[i] < nums[i - 1]){
                dn = up + 1;
            }
        }
        return max(up,dn);
    }
};
