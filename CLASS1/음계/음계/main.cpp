#include <iostream>
using namespace std;

int main(){
    int num[8];
    int ans = 0;
    for(int i=0; i<8; i++){
        cin >>num[i];
    }

    for(int i=0; i<7; i++){
        if(num[i] < num[i+1])
            ans++;
        else ans--;
    }
    
    if(ans == 7)
        cout << "ascending";
    
    else if(ans == -7)
        cout << "descending";
    
    else cout << "mixed";
    return 0;
}
