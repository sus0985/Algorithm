#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int table[1001][1001];
int check[1001];

int main(){
    int n, m;
    
    cin >> n >> m;
    
    memset(table, 0, sizeof(table));
    memset(check, 0, sizeof(check));
    
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        
        table[x][y] = 1;
        table[y][x] = 1;
    }
    
    int count = 0;
    for(int i=1; i<=n; i++){
        
        if(!check[i]){
            count++;
            
            queue<int> q;
            q.push(i);
            check[i] = 1;
            
            while(!q.empty()){
                int current = q.front(); q.pop();
                
                for(int j=1; j<=n; j++){
                    if(table[current][j] && j != current){
                        if(!check[j]){
                            q.push(j);
                            check[j] = 1;
                        }
                    }
                }
            }
            
        }
    }
    
    cout << count;
    
    return 0;
}
