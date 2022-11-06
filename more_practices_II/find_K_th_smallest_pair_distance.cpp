#include <bits/stdc++.h>

using namespace std;
//hard不要太在意

//想不到，只想的到brute force
//binary search的解法
//check => 檢查有多少個pair差 <= mid
bool check(int mid, vector<int> &nums, int k, const int n)
{
    //total是個數
    int total = 0;
    int j = 0;
    
    for(int i = 0; i < n; i++)
    {
        while(j < n and nums[j]-nums[i] <= mid)
            j++;

        j--;
        total += (j - i);
        cout << total << endl;
    }

    return total >= k;
}

int smallestDistancePair(vector<int> &nums, int k)
{
    const int n = nums.size();
    sort(nums.begin(), nums.end());

    int l = 0, r = nums.back() - nums.front();
    while(l < r)
    {
        int mid = (l+r)/2;
        if(check(mid, nums, k, n))
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

int main()
{
    vector<int> nums = {1,6,1};
    int k = 3;
    int ans = smallestDistancePair(nums, k);

    //cout << ans << endl;

    return 0;
}