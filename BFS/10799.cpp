#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 닫힌 괄호 나올때 이전 요소가 '(' 이면 레이저 ')' 이면 막대기
    // 레이저이면 stack 크기만큼 더해줌 .
    // 막대기이면 .. +1 (오른쪽 자르기)

    string s;
    cin >> s;

    stack<char> st;
    int result=0; // 조각의 수
    for(int cnt_i=0;cnt_i<s.length();cnt_i++){
        if(s[cnt_i] == '('){
            st.push(s[cnt_i]);
        }
        else if(s[cnt_i] == ')'){
            if(s[cnt_i-1] == '('){
                st.pop();
                result += st.size();
            }else if(s[cnt_i-1] == ')'){
                st.pop();
                result += 1; // 막대기의 끝이니까 .. 이걸 조각에 더해주면 됨 
            }
        }
    }

    cout << result;

    return 0;
}