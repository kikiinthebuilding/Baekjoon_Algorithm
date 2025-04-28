#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

bool check_prime(int num) {
    if(num<2) return false;
    
    for(int i=2; i<=sqrt(num); i++) {
        if(num%i==0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> ans;
    
    sort(numbers.begin(), numbers.end());
    
    do {
        string temp_str;
        for(int i=0; i<numbers.size(); i++) {
            temp_str += numbers[i];
            if(check_prime(stoi(temp_str))) ans.insert(stoi(temp_str));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    return answer=ans.size();
}