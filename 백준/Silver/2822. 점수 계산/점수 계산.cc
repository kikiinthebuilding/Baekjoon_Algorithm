#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, int>> scores;
    int temp;
    for(int i=0; i<8; i++) {
        cin>>temp;
        scores.push_back({temp, i+1});
    }
    
    sort(scores.begin(), scores.end());
    
    int sum=0; vector<int> probs;
    for(int i=0; i<5; i++) {
        sum += scores[7-i].first;
        probs.push_back(scores[7-i].second);
    }
    
    sort(probs.begin(), probs.end());
    
    cout<<sum<<endl;
    for(int i=0; i<5; i++) {
        cout<<probs[i]<<" ";
    }
    
    return 0;
}