class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n=nums.size();
        int maxfreq=0;
        int ans=0;
        for(int x: nums){
            freq[x]++;
        }
        for(auto x: freq){
            maxfreq=max(maxfreq, x.second);
        }
        for(auto x : freq){
            if(x.second==maxfreq){
                ans+=x.second;
            }
        }
        return ans;
    }
};