#include <bits/stdc++.h>

using namespace std;

//只想到不是linear的解法
//解答是用binary search
int findPeakElement(vector<int> &nums)
{
    int l = 0;
    int r = nums.size()-1;

    //可以直接用binary search解的原因是因為
    //我要馬找到一個increase要馬找的一個decrease
    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(nums[mid] < nums[mid+1])
            l = mid + 1;
        else
            r = mid;
    }

    return l;
}

int main()
{
    vector<int> nums = {1,2,1,3,5,6,4};
    int ans = findPeakElement(nums);

    cout << ans << endl;

    return 0;
}