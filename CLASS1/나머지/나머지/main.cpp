#include <iostream>
using namespace std;

int main(){
    int n[10];
    int count = 10;
    for(int i=0; i<10; i++){
        cin >> n[i];
        n[i] = n[i]%42;
    }
    
    for(int i=0; i<10; i++){
        for(int j=i+1; j<10; j++){
            if(n[i] == n[j]){
                count--;
                break;
                
            }
        }
    }
    
    cout << count;
    return 0;
}
