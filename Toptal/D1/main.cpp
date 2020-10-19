#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;


std::string removingPairsGame(std::vector<int> numbers) {
    int countPairs = 0;
    cout<<"test";
    stack<int> s;

    s.push(numbers[0]);
    for(int i = 1; i < numbers.size(); i++){

        if(s.top()==numbers[i]){
            s.pop();
            countPairs++;

        }
        else{
            s.push(numbers[i]);
        }
    }

    if(countPairs / 2) return "Bob";
    else return "Alice";

}


int main() {

    stack<int> st;
//    cerr << "cerr";
//    cout << "aziz";
    st.pop();

//    cout << removingPairsGame({1, 4, 5, 5, 6});
    return 0;
}




