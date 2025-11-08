#include <bits/stdc++.h>

using namespace std;

char board[1002][1002];
int dist[1002][1002];

int player[10]; // 플레이어 수 .. 9번 플레이어까지 가능 .

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){

    int n,m,p;
    cin >> n >> m >> p;

    for(int cnt_i=1;cnt_i<=p;cnt_i++){
        cin >> player[cnt_i];
    }

    queue<pair<int,int>> Q[10];
    queue<pair<int,int>> nextQ[10];

    for(int cnt_i=0;cnt_i<n;cnt_i++) fill(dist[cnt_i], dist[cnt_i]+m, -1);

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            cin >> board[cnt_i][cnt_j];
            if(board[cnt_i][cnt_j] != '.' && board[cnt_i][cnt_j] != '#'){
                Q[board[cnt_i][cnt_j]-'0'].push({cnt_i,cnt_j});
                dist[cnt_i][cnt_j] = 0;
            }
        }
    }

    while(1){
        // 확장 게임 시작

        for(int cnt_i=0;cnt_i<n;cnt_i++){
            for(int cnt_j=0;cnt_j<m;cnt_j++){
                cout << board[cnt_i][cnt_j];
            }
            cout << "\n";
        }

        bool flag = false;
        for(int cnt_i=1;cnt_i<=p;cnt_i++){
            while(!Q[cnt_i].empty()){
                auto cur = Q[cnt_i].front(); Q[cnt_i].pop();

                if(board[cur.first][cur.second] == '.'){
                    board[cur.first][cur.second] = '0'+cnt_i;
                }
                
                for(int dir=0;dir<4;dir++){
                    int nx = cur.first+dx[dir];
                    int ny = cur.second+dy[dir];

                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(board[nx][ny] == '#' || board[nx][ny] != '.' || dist[nx][ny] != -1) continue;
                    
                    if(dist[cur.first][cur.second]+1 > player[cnt_i]){
                        nextQ[cnt_i].push({nx,ny});
                        flag = true;
                    }else{
                        Q[cnt_i].push({nx,ny});
                        dist[nx][ny] = dist[cur.first][cur.second]+1;
                    }
                }
            }
        }

        if(!flag) break;

        for(int cnt_i=0;cnt_i<n;cnt_i++) fill(dist[cnt_i], dist[cnt_i]+m,-1);

        for(int cnt_i=1;cnt_i<=p;cnt_i++){
            while(!nextQ[cnt_i].empty()){
                auto cur = nextQ[cnt_i].front(); nextQ[cnt_i].pop();
                
                dist[cur.first][cur.second] = 0;
                Q[cnt_i].push({cur.first,cur.second});
            }
        }
    }

    int ans[10] = {0,};

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            cout << board[cnt_i][cnt_j];
        }
        cout << "\n";
    }

    for(int cnt_i=0;cnt_i<n;cnt_i++){
        for(int cnt_j=0;cnt_j<m;cnt_j++){
            if(board[cnt_i][cnt_j] != '#' || board[cnt_i][cnt_j] != '.'){
                ans[board[cnt_i][cnt_j]-'0'] += 1;
            }
        }
    }

    for(int cnt_i=1;cnt_i<=p;cnt_i++){
        cout << ans[cnt_i] << " ";
    }

    return 0;
}