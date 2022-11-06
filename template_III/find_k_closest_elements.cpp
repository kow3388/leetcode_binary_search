#include <bits/stdc++.h>

using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    if(k == arr.size())
        return arr;

    if(x > arr.back())
    {
        vector<int> ans(arr.end()-k, arr.end());
        return ans;
    }
    
    auto low = lower_bound(arr.begin(), arr.end(), x);
    int idx = low - arr.begin();

    if(*low != x and idx != 0)
        idx = (arr[idx]-x < x-arr[idx-1])? idx : idx-1;
    
    int l = idx, r = idx;
    
    for(int i = 0; i < k-1; i++)
    {
        if(l <= 0)
        {
            r++;
            continue;
        }
        if(r >= arr.size()-1)
        {
            l--;
            continue;
        }

        if(x-arr[l-1] <= arr[r+1]-x)
            l--;
        else
            r++;
    }

    vector<int> ans;

    for(int i = l; i <= r; i++)
        ans.push_back(arr[i]);
    
    return ans;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    int k = 4, x = -1;
    vector<int> ans = findClosestElements(arr, k, x);

    for(auto a : ans)
        cout << a << endl;

    return 0;
}