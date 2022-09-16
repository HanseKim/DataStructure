#include<iostream>

using namespace std;

int main(){
    int n,min=0;
    cin>>n;
    int arr[100][100] = {{0,}};
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        (min > x) ? min = x : min=min;
        for(int j=x;j<=x+z;j++){
            for(int k=0;k<=y;k++){
                arr[j][k] = 1;
            }
        }
    }

    int star=0;
    cin>>star;
    for(int i=0;i<star;i++){
        int x,y;
        cin>>x>>y;
        if(arr[x][y]==1){
            
        }
        else cout<<"over\n";
    }
}