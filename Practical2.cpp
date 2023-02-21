#include <bits/stdc++.h>
using namespace std;
double findModeOfVector(vector<double> a)
{
    map<double, int> m;
    for (auto i : a)
    {
        m[i]++;
    }
    int maxm = 0;
    double mode = 0;
    for (auto i : m)
    {
        if (i.second > maxm)
        {
            maxm = i.second;
            mode = i.first;
        }
    }
    return mode;
}

double findMedianOfVector(vector<double> a)
{
    double median = 0;
    sort(a.begin(), a.end());
    int n = a.size();
    if (n & 1)
    {
        median = a[(n / 2)];
    }
    else
    {
        median = (a[(n / 2) - 1] + a[(n / 2)]) / 2;
    }
    return median;
}

double findMeanOfVector(vector<double> a)
{
    double mean = 0;
    for (auto i : a)
    {
        mean += i;
    }
    return mean / a.size();
}
int main()
{
    int n, maxm = INT_MIN;
    cout << "Enter the number of numbers you want to enter: ";
    cin >> n;
    vector<double> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<vector<double>> ans;
    vector<double> temp;

    int bin, cnt = 0;
    cout << "Enter bin size: ";
    cin >> bin;
    for (int i = 0; i < n; i++)
    {
        if (cnt == bin)
        {
            ans.push_back(temp);
            temp.clear();
            cnt = 0;
        }
        cnt++;
        temp.push_back(v[i]);
    }
    ans.push_back(temp);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << " -> ";
        cout << "Min boundary is " << i[0] << " Maximum boundary is " << i[bin - 1];
        cout << " Mean = " << findMeanOfVector(i) << " Mode = " << findModeOfVector(i) << " Median = " << findMedianOfVector(i);
        cout << endl;
    }

    int choice = 0;
    cout << "What you want to do with the data: \n";
    cout << "1. Smoothing by bin boundaries \n"
         << "2. Smoothing by bin means\n"
         << "3. Smoothing by bin medians\n"
         << "4. Smoothing by bin mode\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "Smoothing by bin boundaries: \n";
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << ((abs(j - i[0]) > abs(j - i[bin - 1])) ? i[bin - 1] : i[0]) << " ";
            }

            cout << endl;
        }
        break;
    }

    case 2:{
        cout << "Smoothing by bin means: \n";
        for(auto i : ans){
            for (auto j : i)
            {
                cout<<findMeanOfVector(i)<<" ";
            }
            cout<<endl;
        }
        break;
    }
    case 3:{
        cout << "Smoothing by bin medians: \n";
        for(auto i : ans){
            for (auto j : i)
            {
                cout<<findMedianOfVector(i)<<" ";
            }
            cout<<endl;
        }
        break;
    }
    case 4:{
        cout << "Smoothing by bin mode: \n";
        for(auto i : ans){
            for (auto j : i)
            {
                cout<<findModeOfVector(i)<<" ";
            }
            cout<<endl;
        }
        break;
    }
    default:
        cout << "Invalid Option Selected: \n";
        break;
    }
    return 0;
};