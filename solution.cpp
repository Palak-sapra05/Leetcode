#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector <int> seg;

    SegmentTree(int n)
    {
        seg.resize(4 * n);
    }

    void build(int nodeIndex, int left, int right, vector <int> &nums)
    {
        if (left == right)
        {
            seg[nodeIndex] = nums[left];
            return;
        }

        int mid = ((left + right) >> 1);

        int leftChildIndex = ((nodeIndex * 2) + 1);
        int rightChildIndex = ((nodeIndex * 2) + 2);

        build(leftChildIndex, left, mid, nums);
        build(rightChildIndex, mid+1, right, nums);

        seg[nodeIndex] = (seg[leftChildIndex] + seg[rightChildIndex]);
    }

    int query(int nodeIndex, int queryLeft, int queryRight, int numsLeft, int numsRight)
    {
        /* completely inside */
        if (numsLeft >= queryLeft and numsRight <= queryRight) return seg[nodeIndex];

        /* completely outside */
        if (numsRight < queryLeft or numsLeft > queryRight) return 0;

        int mid = ((numsLeft + numsRight) >> 1);

        int leftQueryRes = query((nodeIndex * 2) + 1, queryLeft, queryRight, numsLeft, mid);
        int rightQueryRes = query((nodeIndex * 2) + 2, queryLeft, queryRight, mid + 1, numsRight);

        return (leftQueryRes + rightQueryRes);
    }

    void update(int nodeIndex, int updateIndex, int updateValue, int numsLeft, int numsRight)
    {
        if (numsLeft == numsRight)
        {
            seg[nodeIndex] = updateValue;
            return;
        }

        int mid = ((numsLeft + numsRight) >> 1);

        if (updateIndex <= mid) update((nodeIndex * 2) + 1, updateIndex, updateValue, numsLeft, mid);
        else update((nodeIndex * 2) + 2, updateIndex, updateValue, mid + 1, numsRight);

        seg[nodeIndex] = (seg[(nodeIndex * 2) + 1] + seg[(nodeIndex * 2) + 1]);
    }
};

int main()
{
    vector <int> nums = {5, -1, 3, 2, -4};

    int n = nums.size();

    SegmentTree *st = new SegmentTree(n);

    st->build(0, 0, n-1, nums);

    cout << "Sum of values from 2 to 4 is -: " << st->query(0, 2, 4, 0, n-1) << "\n";

    /* updating index 2 with value 5 */

    st->update(0, 2, 5, 0, n-1);

    return 0;
}