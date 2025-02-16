#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

double calculateDistance(pair<int, int> p1, pair<int, int> p2) {
    double x = p2.first - p1.first;
    double y = p2.second - p1.second;
    double d = sqrt(x * x + y * y);
    return round(d * 2) / 2.0;
}

double minTry(string number) {
    unordered_map<char, pair<int, int>> numPad = {
        {'1', {0, 0}}, {'2', {0, 1}}, {'3', {0, 2}},
        {'4', {1, 0}}, {'5', {1, 1}}, {'6', {1, 2}},
        {'7', {2, 0}}, {'8', {2, 1}}, {'9', {2, 2}},
        {'*', {3, 0}}, {'0', {3, 1}}, {'#', {3, 2}}
    };

    int n = number.length();

    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(12, vector<double>(12, 1e10)));

    dp[0][10][11] = 0;

    for (int i = 0; i < n; i++) {
        int digit = number[i] - '0';
        for (int f1 = 0; f1 < 12; f1++) {
            for (int f2 = 0; f2 < 12; f2++) {
                if (dp[i][f1][f2] < 1e10) {
                    dp[i + 1][digit][f2] = min(dp[i + 1][digit][f2],
                        dp[i][f1][f2] + calculateDistance(numPad[f1 == 10 ? '*' : f1 == 11 ? '#' : '0' + f1], numPad[number[i]]));
                    dp[i + 1][f1][digit] = min(dp[i + 1][f1][digit],
                        dp[i][f1][f2] + calculateDistance(numPad[f2 == 10 ? '*' : f2 == 11 ? '#' : '0' + f2], numPad[number[i]]));
                }
            }
        }
    }

    double result = 1e10;
    for (int f1 = 0; f1 < 12; f1++) {
        for (int f2 = 0; f2 < 12; f2++) {
            result = min(result, dp[n][f1][f2]);
        }
    }

    return result;
}

int main() {
    string x ;
    cout << "Enter a numeric digit string: ";
    cin >> x;
    cout << "Minimum effort to dial the number: " << minTry(x) << endl;
    return 0;
}