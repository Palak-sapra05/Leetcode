class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> l(n+1,0);
        for(auto& booking: bookings){
            l[booking[0]-1]+=booking[2];
            l[booking[1]]-=booking[2];
        }
        l.pop_back();
        for(int i=1;i<n;i++) l[i]+=l[i-1];
        return l;
    }
};