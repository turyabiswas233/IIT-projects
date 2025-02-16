#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minOperation(string word1, string word2)
{
    int x = word1.length();
    int y = word2.length();
    
    vector<vector<int>> table(x + 1, vector<int>(y + 1, 0));

    for (int i = 1; i <= x; ++i)
    {
        table[i][0] = i;
    }
    for (int j = 1; j <= y; ++j)
    {
        table[0][j] = j;
    }
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {

            if (word1[i - 1] == word2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1];
            }
            else
            {
                table[i][j] = min(min(table[i - 1][j], table[i][j - 1]), table[i - 1][j - 1])+1;
            }
        }
    }
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    return table[x][y];
}

int main()
{
    string word1, word2;
    cout << "Enter the two words: ";
    cin >> word1 >> word2;
    int distance = minOperation(word1, word2);
    cout << "The minimum number of operations required to convert " << word1 << " to " << word2 << " is " << distance << endl;

    return 0;
}
