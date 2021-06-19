#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

int table[101][101];
int value[101] = {0,};
using namespace std;

int main(){
    int n, t1, t2, line;
    
    cin >> n >> t1 >> t2 >> line;
    
    memset(table, 0, sizeof(table));

    for(int i=0; i<line; i++){
        int x, y;
        
        cin >> x >> y;
        
        table[x][y] = 1;
        table[y][x] = 1;
    }
    
    queue<int> q;
    
    q.push(t1);
    
    int count = 0;
    
    value[t1] = 0;
    
    while(!q.empty()){
        int current = q.front(); q.pop();
        count++;
        
        for(int i=1; i<=n; i++){
            if(table[current][i] && !value[i] && i != current){
                q.push(i);
                value[i] = value[current]+1;
            }
        }
    }
    
    if(value[t2] != 0)
        cout << value[t2];
    else cout << -1;
    
    return 0;
}
