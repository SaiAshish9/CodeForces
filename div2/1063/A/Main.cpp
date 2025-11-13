#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n,0);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        bool yes=true;
        for(int i=1;i<n-1;i+=2){
            if(a[i]!=a[i+1]){
                yes=false;
                break;
            }
        }
        if(yes) cout<< "yes"<< "\n";
        else cout<< "no"<< "\n";
    }
}