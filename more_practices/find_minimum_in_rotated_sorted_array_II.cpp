#include <bits/stdc++.h>

using namespace std;

//用原本的解法有一些case會錯，想不到怎麼解
int findMin(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;

    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(nums[mid] > nums[r])
            l = mid + 1;
        else if(nums[mid] < nums[r])
            r = mid;
        //表示出現重複數字，往前移來解決
        else
            r--;
    }

    return nums[l];
}

int main()
{
    vector<int> nums = {1,3,3};
    int ans = findMin(nums);

    cout << ans << endl;

    return 0;
}