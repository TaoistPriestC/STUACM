class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() < 2){
            return arr.size();
        }
        int up = 1, dn = 1, ans = 0;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > arr[i - 1]){
                up = dn + 1; dn = 1;
            }else if(arr[i] < arr[i - 1]){
                dn = up + 1; up = 1;
            }else{
                up = dn = 1;
            }
            ans = max(ans,max(up,dn));
        }
        return ans;
    }
};
