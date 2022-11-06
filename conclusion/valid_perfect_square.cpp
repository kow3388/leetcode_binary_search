#include <bits/stdc++.h>

using namespace std;

bool isPerfectSquare(int num)
{
    long long l = 1;
    long long r = num;

    while(l < r)
    {
        long long mid = l + (r-l)/2;
        if(mid*mid >= num)
            r = mid;
        else
            l = mid + 1;
    }

    return (l*l == num);
}

int main()
{
    int n = 16;
    bool ans = isPerfectSquare(n);

    cout << ans << endl;

    return 0;
}