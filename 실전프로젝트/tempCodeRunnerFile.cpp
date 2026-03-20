#include <bits/stdc++.h>

using namespace std;

vector<int> vec[12][12];
int board[12][12]; // 지력

int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,1,-1,1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m,k,p;
    cin >> n >> m >> k >> p;

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<n;cnt_j++){
            cin >> board[cnt_i][cnt_j];
        }
    }

    for(int cnt_i=0;cnt_i<m;cnt_i++){
        int r,c, age;
        cin >> r >> c >> age;
        vec[r][c].push_back({age}); // 어린 나무부터 지력을 흡수함. 
    }

    // p -> 시뮬레이션 반복 횟수
    while(p--){

        // 1. 지력 흡수.. 어린 나무부터 지력 흡수함 .
        vector<int> sur;

        for(int cnt_i=0;cnt_i<n;cnt_i++){
            for(int cnt_j=0;cnt_j<n;cnt_j++){
                sort(vec[cnt_i][cnt_j].begin(), vec[cnt_i][cnt_j].end()); // sort 해두고 .
                for(int cnt_k=0;cnt_k<vec[cnt_i][cnt_j].size();cnt_k++){
                    if(board[cnt_i][cnt_j] >= vec[cnt_i][cnt_j][cnt_k]){
                        board[cnt_i][cnt_j] -= vec[cnt_i][cnt_j][cnt_k]; // 지력 흡수
                        
                        sur.push_back(vec[cnt_i][cnt_j][cnt_k]); // 살아남은 벡터에 넣어줌 .
                    }else{
                        // 죽은 경우에 지력으로 흡수 .
                        board[cnt_i][cnt_j] += vec[cnt_i][cnt_j][cnt_k]/2;
                    }
                }
            }
        }

        // 나무의 번식이 진행됨 . 5의 배수만 ..인접한 8개의 칸에 번식됨 .
        for(int cnt_i=0;cnt_i<n;cnt_i++){
            for(int cnt_j=0;cnt_j<n;cnt_j++){
                for(int cnt_k=0;cnt_k<vec[cnt_i][cnt_j].size();cnt_k++){
                    if(vec[cnt_i][cnt_j][cnt_k]%5 == 0){
                        for(int dir=0;dir<8;dir++){
                            int nx = cnt_i+dx[dir];
                            int ny = cnt_j+dy[dir];

                            if(nx<0||nx>=n||ny<0||ny>=m) continue;

                            vec[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }


        // 번식 끝나면 k 만큼 땅의 지력이 회복 됩니다.
        for(int cnt_i=0;cnt_i<n;cnt_i++){
            for(int cnt_j=0;cnt_j<n;cnt_j++){
                board[cnt_i][cnt_j] += k;
            }
        }
    }

    // 남아 있는 나무의 수를 출력함 ..

    int result=0;
    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<n;cnt_j++){
            result += vec[cnt_i][cnt_j].size();
        }
    }

    cout << result;

    return 0;
}