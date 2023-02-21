#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cout<<"Enter the number of values that you want to enter: "<<endl;
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the values: \n";
    double mean=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mean+=v[i];
    }

    mean/=n;

    int sum=0;
    for(auto i:v){
        sum+=pow((i-mean),2);
    }
    sum/=n;

    double standard_dev=sqrt(sum);
    cout<<"Here is the normalized values: \n";

    for(auto i:v){
        cout<<i<<"\t\t";
        cout<<(i-mean)/standard_dev<<endl;
    }

    return 0;
}