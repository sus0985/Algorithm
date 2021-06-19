#include <iostream>
#include <string>
using namespace std;

int main(){
    while(true){
        string str;
        cin >> str;
        
        if(str == "0")
            break;
        
        bool flag = true;
        for(int i=0; i<str.size()/2; i++){
            if(str[i] != str[str.size()-i-1]){
                flag = false;
            }
        }
        
        string ans = flag ? "yes" : "no";
        cout << ans << endl;
    }
    
    return 0;
}
