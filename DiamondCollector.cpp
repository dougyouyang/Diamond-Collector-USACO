/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

*/


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
