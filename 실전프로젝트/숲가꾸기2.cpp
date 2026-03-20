#include <bits/stdc++.h>

using namespace std; // 지력 보드

int dx[8] = {1,0,-1,0,1,-1,1,-1}; // 인접한 8칸
int dy[8] = {0,1,0,-1,1,1,-1,-1};

// 한칸에 나무가 여러개 있을 수 있음. 여러 나무가 있으면 .. 어린 나무 부터 지력을 흡수
// 죽은 나무는 그 위치의 지력으로 변함 . 죽은 나무 나이를 2로 나눈 값 만큼 지력으로 변함 ..
// 이후 나무의 번식이 진행 .. 5의 배수 인접한 8칸에 !. 1인 나무 생성 ..
// 5의 배수 주변에 1인 나무 생성하면 됨 .

// 마지막으로 .. 각 칸에 k만큼의 지력이 회복됨 .

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--){
        int n,m,c,k,p;
        cin >> n >> c >> k >> p;
        // 격차 크기, 나무의 수, 지력 회복 크기, 시뮬레이션 반복 횟수 p ..
        m = n;

        int board[12][12] = {0,}; // 지력에 대한 정보 저장 .

        for(int cnt_i=0;cnt_i<n;cnt_i++){
            for(int cnt_j=0;cnt_j<m;cnt_j++){
                cin >> board[cnt_i][cnt_j];
            }
        }

        vector<int> tree[12][12];
        // tree의 나이 저장 .

        // c개의 나무 
        for(int cnt_i=0;cnt_i<c;cnt_i++){
            int r1,c1,a;
            cin >> r1 >> c1 >> a;
            tree[r1][c1].push_back(a); // tree의 나이 저장.
        }

        // 시뮬레이션은 p번 반복한다 .
        while(p--){
            vector<int> die[12][12];

            // 1. 지력 흡수 처리 ..
            
            for(int cnt_i=0;cnt_i<n;cnt_i++){
                for(int cnt_j=0;cnt_j<m;cnt_j++){
                    if(tree[cnt_i][cnt_j].size()){
                        // 벡터 정렬 해주고 .
                        sort(tree[cnt_i][cnt_j].begin(), tree[cnt_i][cnt_j].end());

                        for(int cnt_k=0;cnt_k<tree[cnt_i][cnt_j].size();cnt_k++){
                            if(board[cnt_i][cnt_j] >= tree[cnt_i][cnt_j][cnt_k]){
                                board[cnt_i][cnt_j] -= tree[cnt_i][cnt_j][cnt_k];
                                tree[cnt_i][cnt_j][cnt_k] += 1; // 기력 흡수
                            }
                            else{
                                die[cnt_i][cnt_j].push_back(tree[cnt_i][cnt_j][cnt_k]);
                                // 나무가 죽는 경우. die에 넣어둠 .
                            }
                        }
                    }
                }
            }
            // 2 죽은 나무에 대한 처리 ..

            for(int cnt_i=0;cnt_i<n;cnt_i++){
                for(int cnt_j=0;cnt_j<m;cnt_j++){
                    int index = die[cnt_i][cnt_j].size()-1;
                    int size = die[cnt_i][cnt_j].size();
                    for(int cnt_k=0;cnt_k<size;cnt_k++){
                        board[cnt_i][cnt_j] += (die[cnt_i][cnt_j][index]/2);
                        die[cnt_i][cnt_j].pop_back();
                        index -= 1;
                        tree[cnt_i][cnt_j].pop_back();
                    }
                }
            }

            // 3. 나무의 번식 .. 5의 배수이면 주변에 번식시킴.

            for(int cnt_i=0;cnt_i<n;cnt_i++){
                for(int cnt_j=0;cnt_j<m;cnt_j++){
                    bool flag = false;
                    for(int cnt_k=0;cnt_k<tree[cnt_i][cnt_j].size();cnt_k++){
                        if(tree[cnt_i][cnt_j][cnt_k]%5 == 0){
                            for(int dir=0;dir<8;dir++){
                                int nx = cnt_i+dx[dir];
                                int ny = cnt_j+dy[dir];

                                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                                tree[nx][ny].push_back(1);
                            }
                            flag = true;
                        }
                    }
                }
            }

            // 4. k만큼의 지력 회복 !.
            for(int cnt_i=0;cnt_i<n;cnt_i++){
                for(int cnt_j=0;cnt_j<m;cnt_j++){
                    board[cnt_i][cnt_j] += k;
                }
            }
        }

        // for(int cnt_i=0;cnt_i<n;cnt_i++){
        //     for(int cnt_j=0;cnt_j<m;cnt_j++){
        //         cout << tree[cnt_i][cnt_j].size() << " ";
        //     }
        //     cout << "\n";
        // }

        // for(int cnt_i=0;cnt_i<n;cnt_i++){
        //     for(int cnt_j=0;cnt_j<m;cnt_j++){
        //         if(tree[cnt_i][cnt_j].size() == 0) cout << 0 << " ";
        //         for(int cnt_k=0;cnt_k<tree[cnt_i][cnt_j].size();cnt_k++){
        //             cout << tree[cnt_i][cnt_j][cnt_k] << ", ";
        //         }
        //     }
        //     cout << "\n";
        // }

        int sum=0;
        for(int cnt_i=0;cnt_i<n;cnt_i++){
            for(int cnt_j=0;cnt_j<m;cnt_j++){
                sum += tree[cnt_i][cnt_j].size();
            }
        }
        cout << sum << "\n";
    }
}