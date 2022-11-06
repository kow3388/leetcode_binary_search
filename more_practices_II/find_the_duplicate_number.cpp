#include <bits/stdc++.h>

using namespace std;

int findDuplicate1(vector<int> &nums)
{
    unordered_map<int, int> cnt;
    for(auto n : nums)
    {
        if(cnt[n] == 0)
            cnt[n]++;
        else
            return n;
    }

    return -1;
}

//網路上其他作法，用binary search
//因為題目有說nums裡面全部都是正整數才可以用這個方法
int findDuplicate(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;
    int cnt;

    while(l <= r)
    {
        int mid = l + (r-l)/2;
        cnt = 0;

        //count number less than equal to mid
        //mid表示在中間最大的數值為多少
        //如果<= mid的數比mid還多，表示有重複出現在左邊
        //反之則出現在右邊
        for(int n : nums)
            if(n <= mid)
                cnt++;
        
        if(cnt <= mid)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return l;
}

int main()
{
    vector<int> nums = {1,3,4,2,2};
    int ans = findDuplicate(nums);

    cout << ans << endl;

    return 0;
}