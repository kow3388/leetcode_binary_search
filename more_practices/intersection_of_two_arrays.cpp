#include <bits/stdc++.h>

using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> n1;
    unordered_set<int> n2;
    vector<int> ans;

    for(auto num1 : nums1)
        n1.insert(num1);
    for(auto num2 : nums2)
        n2.insert(num2);
    
    if(n1.size() > n2.size())
    {
        for(auto num : n2)
            if(n1.find(num) != n1.end())
                ans.push_back(num);
    }
    else
    {
        for(auto num : n1)
            if(n2.find(num) != n2.end())
                ans.push_back(num);
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> ans = intersection(nums1, nums2);

    for(auto a : ans)
        cout << a << endl;

    return 0;
}