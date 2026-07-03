class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int curr=0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                curr++;
                cnt+=curr;
            }else{
                curr=0;
            }
        }
        return cnt;
    }
};