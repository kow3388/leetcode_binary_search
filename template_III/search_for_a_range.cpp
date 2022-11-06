#include <bits/stdc++.h>

using namespace std;

//using binary tree implement by my self
vector<int> searchRange1(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    vector<int> ans = {-1, -1};

    if(nums.empty())
        return ans;

    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(nums[mid] >= target)
            r = mid;
        else
            l = mid + 1;
    }

    if(nums[l] == target)
        ans[0] = l;
    else
        return ans;

    r = nums.size() - 1;

    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(nums[mid] > target)
            r = mid;
        else
            l = mid + 1;
    }

    if(nums[l] == target)
        ans[1] = l;
    else
        ans[1] = l - 1;

    return ans;
}

//using binary tree implement by STL
vector<int> searchRange(vector<int> &nums, int target)
{
    auto l = lower_bound(nums.begin(), nums.end(), target);
    auto r = upper_bound(nums.begin(), nums.end(), target);

    if(l == nums.end() or *l != target)
        return {-1, -1};
    
    int low = l - nums.begin();
    int up = r - nums.begin() - 1;

    return {low, up};
}

int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> ans = searchRange(nums, target);

    for(int a : ans)
        cout << a <<endl;

    return 0;
}