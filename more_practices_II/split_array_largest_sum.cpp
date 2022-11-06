#include <bits/stdc++.h>

using namespace std;
//hard 不用太在意

//想不到
//cuts => how many cuts are available
bool check(vector<int> &nums, int cuts, long long max)
{
    int acc = 0;
    for(auto num : nums)
    {
        if(num > max)
            return false;
        else if(acc+num <= max)
            acc += num;
        else
        {
            cuts--;
            acc = num;
            if(cuts < 0)
                return false;
        }
    }

    return true;
}

int splitArray(vector<int> &nums, int k)
{
    long long l = 0, r = 0;
    for(auto num : nums)
    {
        l = max(l, (long long)num);
        r += num;
    }

    while(l < r)
    {
        long long mid = l + (r-l)/2;
        if(check(nums, k-1, mid))
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

int main()
{
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    int ans = splitArray(nums, k);

    cout << ans << endl;

    return 0;
}