#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack<int> s;
    
    int n;
    
    cin >> n;
    
    while(n--){
        string cmd;
        cin >> cmd;
        int num;
        if(cmd == "push"){
            cin >> num;
            s.push(num);
        }

        else if(cmd == "pop"){    // pop or top
                if(!s.empty()){
                    int num = s.top(); s.pop();
                    cout << num <<endl;
                }else cout << -1 << endl;
        }
        else if(cmd == "top"){
                if(!s.empty()){
                    cout << s.top() << endl;
                }else{
                    cout << -1 << endl;
                }
        }
        else if(cmd == "size"){       // size
            cout << s.size() <<endl;
        }
        else if(cmd == "empty"){       // empty
            if(s.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    
    return 0;
}
