#include<algorithm>

    //Function to get the maximum total value in the knapsack.
bool comp(pair<int, int> a, pair<int, int> b) {
    double r1 = (double) a.second / (double) a.first;
    double r2 = (double) b.second / (double) b.first;
    return r1 > r2;
}
   // function to return fractionalweights
double maximumValue (vector<pair<int, int>>& arr, int n, int W)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(arr.begin(), arr.end(), comp);

    int curWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++) {

        if (curWeight + arr[i].first <= W) {
            curWeight += arr[i].first;
            finalvalue += arr[i].second;
        } else {
            int remain = W - curWeight;
            finalvalue += (arr[i].second / (double) arr[i].first) * (double) remain;
            break;
        }
      }
      return finalvalue;
}
// time: O(nlogn)+ O(n)
// Space : O(1)
