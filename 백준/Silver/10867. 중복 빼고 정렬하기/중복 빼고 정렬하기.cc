#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int cnt; cin>>cnt;
	
	int arr[cnt];
	for(int i=0; i<cnt; i++) cin>>arr[i];
	
	sort(arr, arr+cnt);
	cout<<arr[0]<<" ";
	for(int i=1; i<cnt; i++)
	    if(arr[i]!=arr[i-1])
	        cout<<arr[i]<<" ";
	
	return 0;
}