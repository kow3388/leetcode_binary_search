#include <bits/stdc++.h>

using namespace std;

double myPow_(double x, int n)
{
    if(n == 0)
        return 1;
    else
        return myPow_(x*x, n/2)*(n%2? x : 1);
}

double myPow(double x, int n)
{
    return n >= 0? myPow_(x, n) : 1.0/myPow_(x, n);
}

int main()
{
    double x = 2.0;
    int n = 10;
    double ans = myPow(x, n);

    cout << ans << endl;

    return 0;
}