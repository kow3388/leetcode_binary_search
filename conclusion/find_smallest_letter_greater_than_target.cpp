#include <bits/stdc++.h>

using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    if((target - 'a') >= (letters.back() - 'a'))
        return letters.front();

    int l = 0;
    int r = letters.size() - 1;

    while(l < r)
    {
        int mid = l + (r-l)/2;
        if((letters[mid] - 'a') > (target - 'a'))
            r = mid;
        else
            l = mid + 1;
    }

    return letters[l];
}

int main()
{
    vector<char> letter = {'c', 'f', 'j'};
    char target = 'c';
    char ans = nextGreatestLetter(letter, target);

    cout << ans << endl;

    return 0;
}