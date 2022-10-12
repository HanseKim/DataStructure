#include<iostream>

using namespace std;

int erase_car(int car,int* parking,int size){
    for(int i=0;i<size;i++){
        if(car == parking[i]){
            parking[i] = 0;
            return i;
        }
    }
    return size;
}

void compaction(int*parking,int*p2,int size){
    int idx=0;
    for(int i=0;i<size;i++) p2[i] = 0;
    for(int i=0;i<size*2;i++){
        if(parking[i]>0){
            p2[idx++] = parking[i];
        }
    }
}

void copy_array(int*p1,int*p2,int size){
    for(int i=0;i<size;i++){
        p2[i] = p1[i];
    }
    for(int i=size;i<size*2;i++) p2[i] = 0;
}

void push_car(int*p,int car,int size){
    for(int i=0;i<size;i++){
        if(p[i]==0) {
            p[i] = car;
            break;
        }
    }
}

int main(){
    int k,n;
    cin>>k>>n;
    int *parking = new int[k],cnt=0, _k = k;
    for(int i=0;i<k;i++) parking[i] = 0;
    for(int i=0;i<n;i++){
        int car;
        cin>>car;
        if(car>0){
            if(cnt==k){
                k*=2;
                int* p2 = new int[k];
                copy_array(parking,p2,k/2);
                parking = p2;
            }
            cnt++;
            push_car(parking,car,k);
        }
        else{
            int idx = erase_car((-1)*car,parking,k);
            if(idx<k) {
                cnt--;
                if(cnt<=k/3 && k/2 >= _k){
                    k/=2;
                    int *p2 = new int[k];
                    compaction(parking,p2,k);
                    parking = p2;
                }
            }
        }
    }
    for(int i=0;i<k;i++){
        if(parking[i]>0)
            printf("%d %d\n",i+1,parking[i]);
    }
}