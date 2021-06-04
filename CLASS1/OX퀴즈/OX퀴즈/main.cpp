#include <iostream>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;
    
    while(T--){
        string str;
        cin >> str;
        
        int sum = 0;
        int point = 0;
        for(int i=0; i<str.size(); i++){
            
            if(str[i] == 'O'){
                sum += ++point;
            }
            else point = 0;
        }
        
        cout << sum << endl;
    }
    
    return 0;
}
