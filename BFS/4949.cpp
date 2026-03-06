#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 열린 괄호는 스택에 넣고, 닫힌 괄호 나왔을때 stack이 비어있거나, 짝이 안맞으면 no 출력
    // 마지막에 stack이 비어있어야함 . 안비어있으면 isValid = false;

    while(true){
        string s;
        getline(cin, s);
        if(s == ".") break;
        bool isValid = true;

        stack<char> st;
        for(char c : s){
            if(c == '(' || c == '['){
                st.push(c);
            }
            else if(c == ')'){
                if(st.empty() || st.top() != '('){
                    isValid = false;
                    break;
                }
                // 조건에 맞으면 pop 해줘야함 .
                st.pop();
            }
            else if(c == ']'){
                if(st.empty() || st.top() != '['){
                    isValid = false;
                    break;
                }
                st.pop();
            }
        }
        if(!st.empty()) isValid = false;
        if(isValid) cout << "yes" << "\n";
        else cout << "no" << "\n"; 
    }

    return 0;
}