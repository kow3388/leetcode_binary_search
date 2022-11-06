#include <bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    
    if(nums[l] == target)
        return l;
    if(nums[r] == target)
        return r;

    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] > nums[r])
            l = mid + 1;
        else
            r= mid;
    }

    if(l == 0)
        r = nums.size() - 1;
    else
    {
        if(target > nums[0])
        {
            r = l - 1;
            l = 0;
        }
        else if(target < nums.back())
            r = nums.size() - 1;
        else
            return -1;
    }

    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(target > nums[mid])
            l = mid + 1;
        else
            r = mid;
    }

    return nums[l]== target? l : -1;
}

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 6;
    int ans = search(nums, target);

    cout << ans << endl;

    return 0;
}