#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,maxm=INT_MIN;
  cout<<"Enter the number of numbers you want to enter: ";
  cin>>n;
  vector<double>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
 
  sort(v.begin(),v.end());
 
  vector<vector<double>>ans;
  vector<double>temp;
 
  int bin,cnt=0;
  cout<<"Enter bin size: ";
  cin>>bin;
  for(int i=0;i<n;i++){
    if(cnt==bin){
      ans.push_back(temp);
      temp.clear();
      cnt=0;
     
    }
    cnt++;
    temp.push_back(v[i]);
   
  }
  ans.push_back(temp);

 int new_max=1,new_min=0;
 int minm=*min_element(v.begin(),v.end());
 maxm=*max_element(v.begin(),v.end());

  for(auto i:ans){
    for(auto j:i){
      cout<<j<<" ";
      cout<<" --> ";
      double finalans=((j-minm)*1.0/(maxm-minm))*(new_max-new_min) + new_min;
      cout<<finalans<<endl;
    }
    // cout<<" -> ";
    // cout<<"Min boundary is "<<i[0]<<" Maximum boundary is "<<i[bin-1]<<endl;
  }

  cout<<"Max = "<<maxm<<" Min = "<<minm<<endl;
  return 0;
}