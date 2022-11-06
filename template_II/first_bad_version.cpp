#include <bits/stdc++.h>

using namespace std;

bool isBadVersion(int n)
{
    int bad = 4;

    return n >= bad? true : false;
}

int firstBadVersion(int n)
{
    int l = 0;
    int r = n;

    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(isBadVersion(mid))
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

int main()
{
    int n = 5;
    int ans = firstBadVersion(n);

    cout << ans << endl;

    return 0;
}