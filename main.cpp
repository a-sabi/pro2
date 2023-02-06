#include <iostream>
using namespace std;


class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int l = 0;
        int r = s.length();
        int cnt = 0;
        int mid = -1;
        while(l<r-1)
        {
            if(s[l] == s[r-1])
            {
                l++;
                r--;
            }
            else
            {
                int j = l+1;
                while(j<r-1)
                {
                    if(s[j] == s[r-1])
                        break;
                    j++;
                }
                if(j==r-1)
                {
                    mid = r-1;
                    r--;
                }
                else
                {
                    for(int i = j; i > l; i--)
                    {
                        swap(s[i], s[i-1]);
                        cnt++;
                    }
                    l++;
                    r--;
                }
            }
        }
        if(mid != -1)
        {
            cnt += mid-s.length()/2;
        }
        return cnt;
    }
};
int main() {
    string s;
    cin>>s;
    Solution t;
    cout<< t.minMovesToMakePalindrome(s);
    return 0;
}
