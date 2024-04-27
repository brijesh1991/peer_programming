#include <iostream>
#include <vector>

using namespace std;

int min (int x,int y , int z){
    if (x<y){
        if(x <z)
            return x;
        else
            return z;
    } else {
        if (y <z)
            return y;
        else
            return z;
    }
}
/*
Approach 1
get a 2D -array for min path cost memoization 
compute : O(mn)
storage : O(mn)
*/
int min_cost1(vector<vector<int>> cost,  int r, int c) {
    vector<vector<int>> tc(r, vector<int>(c,0));

    tc[0][0]= cost[0][0];

    for(int i=1;i<r;i++){
        tc[i][0]=tc[i-1][0]+cost[i][0];
    }

    for(int i=1;i<c;i++){
        tc[0][i]=tc[0][i-1]+cost[0][i];
    }

    for(int i=1;i<r;i++) {
        for (int j=0;j<c;j++) {
            tc[i][j]= min(tc[i-1][j],tc[i][j-1],tc[i-1][j-1])+cost[i][j];
        }
    }
    cout << "input array" <<endl;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout <<cost[i][j]<< " ";
        }
        cout << endl;
    }

    cout << "Min cost array" << endl;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout << tc[i][j]<< " ";
        }
        cout << endl;
    }
    return tc[r-1][c-1];
}



/*
Approach 2
use the same array passed to store the path cost 
compute : O(mn)
storage : O(1)
*/
int min_cost2(vector<vector<int>> cost,  int r, int c) {
    cout << "input array" <<endl;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout <<cost[i][j]<< " ";
        }
        cout << endl;
    }

    for(int i=1;i<r;i++){
        cost[i][0]=cost[i-1][0]+cost[i][0];
    }

    for(int i=1;i<c;i++){
        cost[0][i]=cost[0][i-1]+cost[0][i];
    }

    for(int i=1;i<r;i++) {
        for (int j=0;j<c;j++) {
            cost[i][j]= min(cost[i-1][j],cost[i][j-1],cost[i-1][j-1])+cost[i][j];
        }
    }
    cout << "Min cost array" << endl;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout << cost[i][j]<< " ";
        }
        cout << endl;
    }
    return cost[r-1][c-1];
}


/*
Approach 3
Dijkstra's algo : briv TODO
compute : O(mn)
storage : O(1)
*/

void driver() {
    vector<vector<int>> cost  = { {1,2,3},{4,8,2},{1,5,3}};
    int minc =  min_cost2(cost,3,3);
    cout <<"Min distance to end "<<minc<<endl;
}

int main() {
    driver();
    return 0;
}