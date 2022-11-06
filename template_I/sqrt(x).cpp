#include <bits/stdc++.h>

using namespace std;

int mySqrt(int x)
{
    long l = 1;
    long r = static_cast<long>(x) + 1;

    while(l < r)
    {
        long m = l + (r - l)/2;
        if(m*m > x)
            r = m;
        else
            l = m + 1;
    }

    return l - 1;
}

int main()
{
    int x = 8;
    int ans = mySqrt(x);

    cout << ans << endl;

    return 0;
}