#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    
    cin >> n;
    
    vector<int> v(n);
    vector<int> s(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    int sum = 0;
    
    for(int i=0; i<n; i++){
        sum += v[i];
        s[i] = sum;
    }
    
    int res = 0;
    
    for(int i=0; i<n; i++){
        res += s[i];
    }
    
    cout << res;
    return 0;
}
