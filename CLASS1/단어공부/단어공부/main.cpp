#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main(){
    string str;
    
    cin >> str;
    
    vector<int> v(256);
    
    for(int i=0; i<str.size(); i++){
        str[i] = toupper(str[i]);
        v[str[i]]++;
    }
    
    int index = 0;
    int max = 0;
    for(int i=0; i<str.size(); i++){
        if(v[str[i]] > max){
            max = v[str[i]];
            index = i;
        }
    }
    
    for(int i=0; i<256; i++){
        if(v[i] == max && str[index] != i){
            cout << '?';
            return 0;
        }
    }
    
    cout << str[index];
    
    return 0;
}
