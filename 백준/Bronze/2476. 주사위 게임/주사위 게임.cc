#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, score, max=0;
    int nums[3];
    cin>>N;
    while(N--) {
        score=0;
        cin>>nums[0]>>nums[1]>>nums[2];
        sort(nums, nums+3);
        if(nums[0]==nums[2]) score = 10000+nums[2]*1000;
        else if(nums[0]==nums[1]) score = 1000+nums[1]*100;
        else if(nums[1]==nums[2]) score = 1000+nums[2]*100;
        else score = nums[2]*100;
        if(score>max) max=score;
    }
    cout<<max<<endl;
}