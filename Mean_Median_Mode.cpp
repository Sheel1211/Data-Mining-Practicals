#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,maxm=INT_MIN;
    cout<<"Enter the number of numbers you want to enter: ";
    cin>>n;
    double sum=0;
    vector<double>v(n);
    map<double,int>m;
    cout<<"Enter numbers: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
        m[v[i]]++;
    }
    
    cout<<"Mean of given numbers is "<<sum/n<<endl;
    
    for(auto i:m){
        if(i.second>maxm)maxm=i.second;
    }
    cout<<"Mode of given Numbers is ";
    for(auto i:m){
        if(i.second==maxm)cout<<i.first<<" "; 
    }
    cout<<endl;
    
    sort(v.begin(),v.end());
    if(n&1){
        cout<<"Median of given Numbers is "<<v[(n/2)]<<endl;
    }
    else{
        cout<<"Median of given Numbers is "<<(v[(n/2)-1]+v[(n/2)])/2<<endl;
    }
    
    double sum_sd=0;
    double mean=sum/n;
    for(auto i:v){
        sum_sd+=(pow(i-mean,2));
    }
    
    cout<<"Standard deviation of given data is "<<sqrt(sum_sd/(n-1));
    return 0;
}
