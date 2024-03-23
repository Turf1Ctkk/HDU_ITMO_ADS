#include <iostream>
#include <vector>
using namespace std;


int dp(const vector<int>& Pi) {
    int a = 0, b = 0;
    for(int i = 0; i < Pi.size(); i++) {
        b = max(Pi[i], b + Pi[i]);
        a = max(a, b);
    }
    if(a <= 0){
        return 0;
    }
    return a;
}

int main() {
    int N;
    cin >> N;

    vector<int> Pi(N);

    for (int i = 0; i < N; i++) {
        cin >> Pi[i];
    }

    int maxSum = dp(Pi);

    cout << maxSum << endl;

    return 0;
}
// dp[i] = max((dp[i - 1] + dp[i]), dp[i])


int MaxEnergy(const vector<int>& Pi) {
    int maxSoFar = 0, maxEndingHere = 0;

    for (int i = 0; i < Pi.size(); i++) {
        maxEndingHere = max(Pi[i], maxEndingHere + Pi[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    if(maxSoFar <= 0){
        return 0;
    }

    return maxSoFar;
}
