#include <bits/stdc++.h>

using namespace std;

class ArrayReader
{
    public:
        ArrayReader()
        {
            secret = {5};
        }
        int get(int index) const
        {
            if(index < secret.size())
                return secret[index];
            else
                return INT_MAX;
        }
    private:
        vector<int> secret;
};

//想不到
//分成兩步驟
//第一個步驟先找boundary
//第二步驟binary search
int search(const ArrayReader &reader, int target)
{
    int l = 0, r = 1;
    while(reader.get(r) < target)
    {
        l = r;
        r *= 2;
    }

    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(reader.get(mid) >= target)
            r = mid;
        else
            l = mid + 1;
    }

    return (reader.get(l) == target)? l : -1;
}

int main()
{
    ArrayReader reader;
    int target = 5;
    int ans = search(reader, target);

    cout << ans << endl;

    return 0;
}