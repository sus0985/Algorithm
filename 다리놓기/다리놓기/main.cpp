#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T;
    
    cin >> T;
    

    while(T--){
        int n, m;
        
        cin >> n >> m;
        
        vector<int> v(m, 0);

        for(int i=0; i<n; i++){
            v[i] = 1;
 
        }
        int count = 0;
        do{
        
            for(int i=0; i<v.size(); i++){
                if(v[i])
                    count++;
            }
        }while(next_permutation(v.begin(), v.end()));
        
        cout << count << endl;
    }
    
    return 0;
}
