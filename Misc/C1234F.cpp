#include<bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    set<char> st;
    for(char c : s){
        st.insert(c);
    }
    cout << st.size() << endl;
    return 0;
}