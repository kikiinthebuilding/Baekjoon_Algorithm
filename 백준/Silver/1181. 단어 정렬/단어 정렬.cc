#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compStr(string s1, string s2) {
    if(s1.length() == s2.length())
        for(int i=0; i<s1.length(); i++)
            if(s1[i]!=s2[i])
                return s1[i] < s2[i];
    return s1.length() < s2.length();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    vector<string> arr; string temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end(), compStr);
    cout << arr[0] << '\n';
    for(int i = 1; i < n; i++)
    {
        if(arr[i-1] == arr[i])
            continue;
        cout << arr[i] << '\n';
    }

    return 0;
}
