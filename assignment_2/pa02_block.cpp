#include<iostream>

using namespace std;

int get_left(int * hl){
    int idx=0,num=0;
    while(num!=-9){
        cin>>num;
        if(num==-9) break;
        hl[idx++] = num;
    }
    return idx;
}

int get_right(int* hr){
    int idx=0,num=0;
    while(num!=-9){
        cin>>num;
        if(num==-9) break;
        hr[idx++] = num;
    }
    return idx;
}  

void get_block(int *hr,int *hl,int left_idx){
    int max =0,block[1001][1001];
    for(int i=0;i<left_idx;i++){
        (max < hr[i]+hl[i]+1)? (max = hr[i]+hl[i]+1):(max = max);
    }
    int top_idx = max;
    

    for(int i=0;i<left_idx;i++){
        for(int j=0;j<hl[i];j++){
            block[i][j] = 0;
        }
        for(int j=hl[i];j<top_idx-hr[i];j++){
            block[i][j] = 1;
        }
        for(int j=top_idx-hr[i];j<top_idx;j++){
            block[i][j]=0;
        }
    }
    
    int *vt,*vb;
    vt = new int[top_idx];
    vb = new int[top_idx];
    for(int j=0;j<top_idx;j++){
        int t_num=0,b_num=0,state=0;
        for(int i=0;i<left_idx;i++){
            if(block[i][j] == 1 && state == 0){
                t_num = i; state=1;
            }
            if(block[i][j] == 0 && state == 1){
                b_num = left_idx - i;
                break;
            }
            if(state==0 && i==left_idx-1){
                t_num=left_idx;
                b_num = -1;
            }
            if(state==1 && i==left_idx-1){
                b_num = 0;
            }
        }
        vt[j] = t_num;
        vb[j] = b_num;
    }
    
    for(int i=0;i<top_idx;i++) cout<<vt[i]<<" ";
    cout<<"-9\n";
    for(int i=0;i<top_idx;i++) cout<<vb[i]<<" ";
    cout<<"-9\n";

}

int main(){
    int *hl,*hr,block[101][101];
    hl = new int[101];
    hr = new int[101];
    int left_idx = get_left(hl);
    int right_idx = get_right(hr);

    get_block(hr,hl,left_idx);
    
}