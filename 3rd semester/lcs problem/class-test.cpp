#include <iostream>
#include <string>
#include <vector>
using namespace std;

string LCS(string word1, string word2, int x, int y);

int main()
{
    string word1, word2;

    cout << "Enter the two words: ";

    cin >> word1 >> word2;

    int x = word1.length();
    int y = word2.length();

    string result = LCS(word1, word2, x, y);
    cout << "The LCS is: " << result << endl;

    cout << "The length of LCS is " << result.length() << endl;
}

string LCS(string word1, string word2, int x, int y)
{
    vector<vector<int>> table(x + 1, vector<int>(y + 1));

    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }
            else if (word1[i - 1] == word2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else
            {
                table[i][j] = min(table[i - 1][j] , table[i][j - 1]);
            }
        }
    }

    int index = table[x][y];
    string lcs = "";
    lcs.resize(index);

    int i = x, j = y;
    while (i > 0 && j > 0)
    {
        if (word1[i - 1] == word2[j - 1])
        {
            lcs[index - 1] = word1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (table[i - 1][j] > table[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return lcs;
}