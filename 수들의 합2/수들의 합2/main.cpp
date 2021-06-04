#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int start = 0, end = 0, length = 1e5;
    long long sum = 0;
//    while(true){
//        if(sum >= m){
//            sum -= v[start++];
//        }
//        else if(end == n)
//            break;
//        else{
//            sum += v[end++];
//        }
//
//        if(sum == m){
//            int diff = end - start;
//            if(diff < length)
//                length = diff;
//        }
//    }
    
    while(true){
        if(sum < m){
            if(end == n) break;
            sum += v[end++];
        }
        else if(sum >= m){
            length = min(length, end - start);
            sum -= v[start++];
        }
    }

    if(length == 1e5)
        length = 0;
    cout << length;
    return 0;
}
