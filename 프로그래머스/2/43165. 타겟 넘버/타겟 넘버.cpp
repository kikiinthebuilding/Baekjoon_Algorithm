#include <string>
#include <vector>

using namespace std;

int ans_cnt=0;

void dfs(vector<int> numbers, int target, int sum, int cnt) {
    if(cnt==numbers.size()) {
        if(sum==target) ans_cnt++;
        return;
    }
    
    int arr[2] = {1, -1};
    for(int i=0; i<2; i++)
        dfs(numbers, target, sum+arr[i]*numbers[cnt], cnt+1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return ans_cnt;
}