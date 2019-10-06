#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


/*
 * Problem:
 * You have 6 stones indistinguishable strones with weights {1, 2, 3, 4, 5, 6} kilograms.
 * Using a balancing scale twice, prove to the third person the weights of each stone.
*/


// N := the number of stones
// M := how many time you can use the scale
// W := the weights of stones
const int N = 6;
const int M = 2;
const vector<int> W{1, 4, 9, 16, 25, 36};

int sum(int mask, vector<int> weights) {
    int answer = 0;
    for (int i = 0; i < N; i++) {
        if ((mask >> i) & 1) {
            answer += weights[i];
        }
    }
    return answer;
}

int scale(int left, int right, vector<int> weights) {
    int leftAnswer = sum(left, weights);
    int rightAnswer = sum(right, weights);
    if (leftAnswer < rightAnswer) return -1;
    if (leftAnswer > rightAnswer) return +1;
    return 0;

}

bool check(vector<vector<int>> weightings) {
    vector<int> curWeights = W;
    sort(curWeights.begin(), curWeights.end());

    int countCorrect = 0;

    do {
        bool match =
                scale(weightings[0][0], weightings[0][1], curWeights) == weightings[0][2] &&
                scale(weightings[1][0], weightings[1][1], curWeights) == weightings[1][2];
        countCorrect += match;
        if (countCorrect > 1) return false;
    } while (next_permutation(curWeights.begin(), curWeights.end()));

    return countCorrect == 1;
}

void print(vector<vector<int>> weightings) {
    cout << "\n\nPossible solution:" << endl;
    for (auto weighting: weightings) {
        for (int i = 0; i < 2; i++) {
            int side = weighting[i];
            for (int j = 0; j < N; j++) {
                if ((side >> j) & 1) {
                    cout << W[j] << ' ';
                }
            }
            if (i == 0) {
                cout << "-vs- ";
            }
        }
        cout << endl;
    }
}

int main() {

    set<vector<vector<int>>> solutions;

    for (int i = 0; i < M; i++) {
        for (int left1 = 0; left1 < (1 << N); left1++) {
            for (int right1 = 0; right1 < (1 << N); right1++) {
                for (int left2 = 0; left2 < (1 << N); left2++) {
                    for (int right2 = 0; right2 < (1 << N); right2++) {
                        if ((left1 & right1) == 0 && (left2 & right2) == 0) {
                            if (left1 < right1 && left2 < right2 && left1 < left2) {

                                vector<vector<int>> weightings = {
                                        {left1, right1, scale(left1, right1, W)},
                                        {left2, right2, scale(left2, right2, W)},
                                };
                                if (check(weightings)) {
                                    solutions.insert(weightings);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (auto solution: solutions) {
        print(solution);
    }

    return 0;
}