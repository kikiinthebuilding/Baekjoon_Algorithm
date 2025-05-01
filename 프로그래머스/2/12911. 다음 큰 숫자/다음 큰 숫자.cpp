#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = n+1;
    int cnt = bitset<20>(n).count();
    while(bitset<20>(answer).count() != cnt) answer++;
    return answer;
}