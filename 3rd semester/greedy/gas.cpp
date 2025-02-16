#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> items = {1, 2, 3, 4, 5, 6, 7};
    vector<int> weights = {2, 3, 4, 2, 5, 4, 1};
    vector<int> benifit = {7, 6, 9, 6, 12, 10, 3};

    int capacity = 15;

    vector<int> ratio;
    for (int i = 0; i < items.size(); i++)
    {
        ratio.push_back(benifit[i] / weights[i]);
    }

    for (int i = 0; i < items.size(); i++)
    {
        for (int j = i + 1; j < items.size(); j++)
        {
            if (ratio[i] < ratio[j])
            {
                swap(ratio[i], ratio[j]);
                swap(items[i], items[j]);
                swap(weights[i], weights[j]);
                swap(benifit[i], benifit[j]);
            }
        }
    }

    int total_weight = 0;
    int total_benifit = 0;
    for (int i = 0; i < items.size(); i++)
    {
        cout << items[i] << ", ";
        if (total_weight + weights[i] <= capacity)
        {
            total_weight += weights[i];
            total_benifit += benifit[i];
        }
        else
        {
            int remain = capacity - total_weight;
            total_benifit += (benifit[i] / weights[i]) * remain;
            total_weight += remain;
            cout<<endl;
            break;
        }
    }
    cout <<"Total Profit: $"<< total_benifit << endl;
    cout <<"Total Weights: "<< total_weight << endl;

    return 0;
}
