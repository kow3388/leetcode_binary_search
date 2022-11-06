#include <bits/stdc++.h>

using namespace std;

double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2)
{
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    vector<int> merge;
    int i = 0, j = 0, k = 0;

    int idx = (n1+n2)/2 + 1;
    while(k < idx)
    {
        if(i == n1 and j != n2)
        {
            merge.push_back(nums2[j]);
            j++;
        }
        else if(j == n2 and i != n1)
        {
            merge.push_back(nums1[i]);
            i++;
        }
        else if(i != n1 and j != n2)
        {
            if(nums1[i] < nums2[j])
            {
                merge.push_back(nums1[i]);
                i++;
            }
            else
            {
                merge.push_back(nums2[j]);
                j++;
            }
        }
        k++;
    }

    if((n1+n2)%2 != 0)
    {
        double ans = merge.back();
        return ans;
    }
    else
    {
        int tmp = merge.back();
        merge.pop_back();
        double ans = (tmp+merge.back())/2.0;
        return ans;
    }
}

//binary search的解法，難易度: hard
//不用太在意
//非常不容易看懂
//解釋: https://leetcode.com/explore/learn/card/binary-search/146/more-practices-ii/1040/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    const int N1 = nums1.size();
    const int N2 = nums2.size();
    //make sure nums2 is shorter
    if(N1 < N2)
        return findMedianSortedArrays(nums2, nums1);
    
    int l = 0, r = N2*2;
    while(l <= r)
    {
        //try cut 2
        int mid2 = (l+r)/2;
        //calculate cut 1
        int mid1 = N1 + N2 - mid2;

        double L1 = (mid1 == 0)? INT_MIN : nums1[(mid1-1)/2];
        double L2 = (mid2 == 0)? INT_MIN : nums2[(mid2-1)/2];
        double R1 = (mid1 == N1*2)? INT_MAX : nums1[mid1/2];
        double R2 = (mid2 == N2*2)? INT_MAX : nums2[mid2/2];

        if(L1 > R2)
            l = mid2 + 1;
        else if(L2 > R1)
            r = mid2 - 1;
        else
            return (max(L1, L2)+min(R1, R2))/2;
    }

    return -1;
}

int main()
{
    vector<int> nums1 = {};
    vector<int> nums2 = {1,2};
    double ans = findMedianSortedArrays(nums1, nums2);

    cout << ans << endl;

    return 0;
}