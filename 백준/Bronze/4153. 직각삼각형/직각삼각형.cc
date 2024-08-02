#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int arr[3], sum;
    while(true) {
        sum = 0;
        for (int &i: arr) {
            cin >> i;
            sum += i;
        }
        if (sum == 0) break;
        sort(arr, arr + 3);

        if (arr[2] * arr[2] == arr[0] * arr[0] + arr[1] * arr[1]) cout << "right\n";
        else cout << "wrong\n";
    }
    return 0;
}