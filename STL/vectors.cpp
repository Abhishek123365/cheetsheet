#include<bits/stdc++.h>
using namespace std;
int main(){
    // cout<<"Hello world!"<<endl;
    int n;
    cout<<"Enter the size of the vector: ";
    cin>>n;
    vector<int> v(n);
    for (auto &x:v) cin>>x;
    for (auto x:v) cout<<x<<" ";
    return 0;
}