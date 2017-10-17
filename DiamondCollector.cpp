//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> a(50003);
int l[50003], r[50003], ri[50003], li[50003];
bool adj[50003];

int main() {
    
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.begin()+n);
    
    for(int i=0; i<n; i++){
        li[i] = lower_bound(a.begin(), a.begin()+i-1, a[i]-k)-a.begin();
        ri[i] = upper_bound(a.begin()+i+1, a.begin()+n, a[i]+k)-a.begin();
    }
    
    memset(adj, 0, sizeof(adj));
    
    for(int i=1; i<n; i++){
        if(i-li[i] > l[i-1]){
            l[i] = i-li[i];
            adj[i] = 1;
        }
        else{
            l[i] = l[i-1];
            adj[i] = 0;
        }
    }
    
    for(int i=n-2; i>=0; i--){
        if(ri[i]-i > r[i+1]){
            r[i] = ri[i]-i;
            adj[i] = 1;
        }
        else{
            r[i] = r[i+1];
            adj[i] = 0;
        }
    }
    
    int ans = 0;
    for(int i=0; i<n; i++){
        int ans2 = r[i]+l[i];
        if(adj[i]) ans2++;
        ans = max(ans, ans2);
    }
    cout<<min(ans,n)<<endl;
    
    return 0;
}
