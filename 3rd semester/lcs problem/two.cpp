#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

unordered_map<char, pair<int, int>> numPad = {
    {'1', {0, 0}}, {'2', {0, 1}}, {'3', {0, 2}}, {'4', {1, 0}}, {'5', {1, 1}}, {'6', {1, 2}}, {'7', {2, 0}}, {'8', {2, 1}}, {'9', {2, 2}}, {'*', {3, 0}}, {'0', {3, 1}}, {'#', {3, 2}}};

double distance(char key1, char key2)
{
    int x1 = numPad[key1].first;
    int y1 = numPad[key1].second;
    int x2 = numPad[key2].first;
    int y2 = numPad[key2].second;
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    if (dx > 0 && dy > 0)
    {
        return 1.5;
    }
    else
    {
        return dx + dy;
    }
}

double solve(const string &number, char finger1, char finger2, int digits_left, unordered_map<string, double> &dp)
{
    if (digits_left == 0)
    {
        return 0;
    }
    string key = string(1, finger1) + string(1, finger2) + to_string(digits_left);
    if (dp.find(key) != dp.end())
    {
        return dp[key];
    }

    char next_digit = number[number.size() - digits_left];
    double effort = min(
        distance(finger1, next_digit) + solve(number, next_digit, finger2, digits_left - 1, dp),
        distance(finger2, next_digit) + solve(number, finger1, next_digit, digits_left - 1, dp));
    dp[key] = effort;
    return effort;
}

double min_keypad_effort(const string &number)
{
    unordered_map<string, double> dp;
    return solve(number, '*', '#', number.size(), dp);
}

int main()
{
    string number;
    cin >> number;
    cout << min_keypad_effort(number) << endl;

    return 0;
}