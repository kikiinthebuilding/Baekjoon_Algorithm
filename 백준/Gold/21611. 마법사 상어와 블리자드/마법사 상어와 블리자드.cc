#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 49

struct Map {
    int field[MAX][MAX] = {0, };
    vector<pair<int, int>> order;
};
Map map;
int N;
int boom[4] = {0, 0, 0, 0};

void init_order();
void fill_blank(int);
int exploit_gem();
void exec_ice_spikes(vector<pair<int, int>>, int);
void change_gem();

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    /* 값 입력 */
    int M; cin>>N>>M;

    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>map.field[i][j];

    vector<pair<int, int>> ice_spikes;
    for(int i=0; i<M; i++) {
        int temp1, temp2; cin>>temp1>>temp2;
        ice_spikes.emplace_back(temp1, temp2);
    }
    init_order();

    exec_ice_spikes(ice_spikes, M);

//    for(int i=0; i<N; i++) {
//        for(int j=0; j<N; j++) {
//            printf("%2d ", map.field[i][j]);
//        }
//        cout<<endl;
//    }

    int result = boom[1]*1 + boom[2]*2 + boom[3]*3;
    cout<<result<<endl;

    return 0;
}


void init_order() {
    const int dx[] = {-1,0,1,0};
    const int dy[] = {0,1,0,-1};

    pair<int, int> cursor = {N/2, N/2};
    int repeat=1, index=0;
    while(true) {
        for(int i=1; i<=repeat; i++) {
            map.order.push_back({cursor});
            cursor.first += dy[index]; cursor.second += dx[index];
            if(map.order.size()==N*N) return;
        }
        index++; if(index==4) index=0;
        if(index%2==0) repeat++;
    }
}

void fill_blank(int cnt) {
    for(int i=1; i<map.order.size() && cnt; i++) {
        int y = map.order.at(i).first; int x = map.order.at(i).second;
        if(map.field[y][x]==-1) {
            int gap=0;
            for(int j=i+1; j<map.order.size(); j++)
                if(map.field[map.order.at(j).first][map.order.at(j).second]!=-1) {
                    gap = j-i;
                    break;
                }

            for(int j=i; j<map.order.size()-gap; j++)
                map.field[map.order.at(j).first][map.order.at(j).second] = map.field[map.order.at(j+gap).first][map.order.at(j+gap).second];
            for(int k = map.order.size()-gap; k<map.order.size(); k++)
                map.field[map.order.at(k).first][map.order.at(k).second] = 0;

            cnt--;
        }
    }
}

int exploit_gem() {
    int con_cnt = 1, rmv_cnt=0;
    for(int i=2; i<map.order.size(); i++) {
        if(map.field[map.order.at(i).first][map.order.at(i).second] == map.field[map.order.at(i-1).first][map.order.at(i-1).second])
            con_cnt++;
        else {
            if(con_cnt>=4) {
                for(int j=i-con_cnt; j<i; j++) {
                    boom[map.field[map.order.at(j).first][map.order.at(j).second]]++;
                    map.field[map.order.at(j).first][map.order.at(j).second] = -1;
                    rmv_cnt++;
                }
            }
            con_cnt=1;
        }
    }
    return rmv_cnt;
}

void exec_ice_spikes(vector<pair<int, int>> ice_spikes, int M) {
    const pair<int, int> dir[5] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int rmv_cnt=0;
    for(int i=0; i<M; i++) {
        pair<int, int> cursor = {N/2, N/2};
        for(int j=1; j<=ice_spikes.at(i).second; j++) {
            int ny = cursor.first + dir[ice_spikes.at(i).first].first;
            int nx = cursor.second + dir[ice_spikes.at(i).first].second;
            map.field[ny][nx] = -1;
            cursor.first = ny; cursor.second = nx;
            rmv_cnt++;
        }
        fill_blank(rmv_cnt);

        int temp;
        while((temp = exploit_gem())) {
            fill_blank(temp);
        }
        change_gem();
    }
}

void change_gem() {
    int temp_field[MAX][MAX] = {0, };
    int con_cnt = 1, index = 1;
    for(int i=2; i<map.order.size(); i++) {
        if(map.field[map.order.at(i).first][map.order.at(i).second] == map.field[map.order.at(i-1).first][map.order.at(i-1).second]) {
            con_cnt++;
        }
        else {
            if(index>=map.order.size()) break;
            temp_field[map.order.at(index).first][map.order.at(index).second] = con_cnt;
            temp_field[map.order.at(index+1).first][map.order.at(index+1).second] = map.field[map.order.at(i-1).first][map.order.at(i-1).second];
            index += 2;
            con_cnt = 1;
        }
    }
    memcpy(map.field, temp_field, sizeof(temp_field));
}