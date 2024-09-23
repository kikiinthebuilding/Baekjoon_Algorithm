#include <iostream>
using namespace std;

int main() {
    int N; cin>>N;
    unsigned long long num_array[N];
    for(int i=0; i<N; i++) cin>>num_array[i];
    
    if(num_array[2]-num_array[1] == num_array[1]-num_array[0])
        cout<<num_array[N-1] + (num_array[1]-num_array[0])<<endl;
    else
        cout<<num_array[N-1] * (unsigned long long)(num_array[1]/num_array[0])<<endl;

    return 0;
}