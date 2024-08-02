#include <iostream>
#include <algorithm>
#define max 100000
using namespace std;

bool cmpr(pair<int, int>& p1, pair<int, int>& p2) {
    if(p1.second==p2.second)
        return p1.first<p2.first;
    return p1.second<p2.second;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    pair<int, int> pr[max];
    int cnt; cin>>cnt;
	
	for(int i=0; i<cnt; i++)
	    cin>>pr[i].first>>pr[i].second;
	sort(&pr[0], &pr[cnt], cmpr);
	for(int i=0; i<cnt; i++)
	    cout<<pr[i].first<<" "<<pr[i].second<<'\n';
	
	return 0;
}