class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h=(hour*30)+(minutes*0.5);
        double m=(minutes*6);
        double diff=abs(h-m);
        return min(diff, 360-diff);
    }
};