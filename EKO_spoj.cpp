#include <bits/stdc++.h>
using namespace std;
bool isPossibleSolution(vector<long long int> trees, long long int m, long long int mid)
{
    long long int woodCollected = 0;
    for (int i = 0; i < trees.size(); i++)
    {
        if (trees[i] > mid)
        {
            woodCollected += trees[i] - mid;
        }
    }
    return woodCollected >= m;
}
long long int maxHeight(vector<long long int> &trees, long long int m)
{
    long long int ans = -1;
    long long int start = 0;
    long long int end = *max_element(trees.begin(), trees.end());
    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        if (isPossibleSolution(trees, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    long long int n, m;
    cin >> n;
    cin >> m;
    vector<long long int> trees;
    while (n--)
    {
        long long int height;
        cin >> height;
        trees.push_back(height);
    }
    cout << maxHeight(trees, m);
    return 0;
}