#include <iostream>
using namespace std;

int num[10];
int main(){
    int n, k;
    
    cin >> n >> k;
    
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    
    int mod;
    
    for(int i=n-1; i>=0; i--){
        mod += k / num[i];
        k %= num[i];
    }
    
    cout << mod << endl;
    return 0;
}
