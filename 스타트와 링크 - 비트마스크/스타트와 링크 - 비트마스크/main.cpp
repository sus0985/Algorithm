#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;
    int ans = 1e10;
    cin >> n;
    
    vector<vector<int>> v(n, vector<int>(n));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
        }
    }
    
    for(int i=0; i<(1<<n); i++){
        int start = 0;
        int link = 0;
        vector<bool> pos(n);
        for(int j=0; j<n; j++){
            pos[j] = i & (1<<j);
        }
        int count = 0;
        for(int j=0; j<n; j++){
            if(pos[j])
                count++;
        }
        if(count == n/2){
            for(int j=0; j<n; j++){
                if(pos[j]){
                    for(int k=j+1; k<n; k++){
                        if(pos[k]){
                            start += v[j][k];
                            start += v[k][j];
                        }
                    }
                }
                else{
                    for(int k=j+1; k<n; k++){
                        if(!pos[k]){
                            link += v[j][k];
                            link += v[k][j];
                        }
                    }
                }
            }
            
            int res = abs(start - link);
            if(res < ans)
                ans = res;
        }
        else continue;
    }
    
    cout << ans;
    
    return 0;
}
