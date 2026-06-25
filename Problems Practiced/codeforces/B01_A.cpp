#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t; 
    for(int i=1; i<=t; i++){
        int n,k; cin>>n>>k; 
        vector<int> v(n); for(int i=0; i<n; i++) cin>>v[i];
        int index=0;
        while(k--){
            while (index<n-1 && v[index]==0){
                index++;
            }
            if(index==n-1) break;
            v[index]--; v[n-1]++;
        }
        for(int i=0; i<n; i++){
            cout<<v[i]<<" ";
        } cout<<endl;
    }
}
