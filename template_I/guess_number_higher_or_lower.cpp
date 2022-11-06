#include <bits/stdc++.h>

using namespace std;

int guess(int n)
{
    int pick = 6;
    if(n > pick)
        return -1;
    else if(n < pick)
        return 1;
    else
        return 0;
}

int guessNumber(int n)
{
    int l = 1;
    int r = n;

    while(l <= r)
    {
        int m = l + (r-l)/2;
        int re = guess(m);
        switch(re)
        {
            case 1:
                l = m+1;
                break;
            case -1:
                r = m-1;
                break;
            default:
                return m;
                break;
        }
    }

    return -1;
}

int main()
{
    int n = 10;
    int ans = guessNumber(n);

    cout << ans << endl;

    return 0;
}