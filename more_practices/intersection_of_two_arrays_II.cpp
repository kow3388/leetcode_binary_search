#include <bits/stdc++.h>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> n1, n2;
    vector<int> ans;
    for(auto num : nums1)
        n1[num]++;
    for(auto num : nums2)
        n2[num]++;
    
    if(n1.size() > n2.size())
    {
        for(auto &n : n2)
            if(n1[n.first] != 0)
            {
                int cnt = min(n1[n.first], n.second);
                for(int i = 0; i < cnt; i++)
                    ans.push_back(n.first);
            }
    }
    else
    {
        for(auto &n : n1)
            if(n2[n.first] != 0)
            {
                int cnt = min(n2[n.first], n.second);
                for(int i = 0; i < cnt; i++)
                    ans.push_back(n.first);
            }
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> ans = intersect(nums1, nums2);

    for(auto a : ans)
        cout << a << endl;

    return 0;
}