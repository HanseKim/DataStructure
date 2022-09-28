/**
 * @file pa03_shuffle.cpp
 * @author sehankim (kimbird2002@naver.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<algorithm>

using namespace std;

int get_list(int * list){
    int i=0,n=0;
    cin>>n;
    while(n!=-9){
        list[i++] = n;
        cin>>n;
    }
    return i;
}

int* shuffle(int* list,int size){
    int l1[size],l2[size],l1_i=0,l2_i=0,n;
    
    if(size%2==0) n=size/2;
    else n = size/2+1;

    for(int i=0;i<n;i++){
        l1[i] = list[i];
        l2[i] = list[n+i];
    }
    for(int i=0;i<size;i++){
        if(i%2 == 0)
            list[i] = l1[l1_i++];
        else
            list[i] = l2[l2_i++];
    }
    return list;
}

int is_diff(int* l,int* list,int size){
    int diff=0;
    for(int i=0;i<size;i++){
        if(l[i] != list[i]){
            diff=1;
            break;
        }
    }
    return diff;
}

void copy_list(int*l, int*list, int size){
    for(int i=0;i<size;i++){
        list[i] = l[i];
    }
}

void print_list(int* list,int size){
    for(int i=0;i<size;i++){
        cout<<list[i]<<" ";
    }
    cout<<"\n";
}

int compare(int*l1,int*l2, int*list,int size){
    int cnt=0;
    copy_list(l1,list,size);
    while(1){
        if(!is_diff(l2,list,size)) break;
        list = shuffle(list,size);
        cnt++;
        if(cnt > 5000){
            cout<<"NOT";
            return -1;
        }   
    }
    return cnt;
}

int main(){
    int *l0,*l1,*l2,*list,cnt1=0,cnt2=0,min,size=0;
    l0 = new int[5001];
    l1 = new int[5001];
    l2 = new int[5001];
    list = new int[5001];

    size = get_list(l1);
    size = get_list(l2);

    copy_list(l1,l0,size);
    sort(l0,l0+size);

    int cnt01=0,cnt02=0;
    cnt01 = compare(l0,l1,list,size);
    if(cnt01==-1) return 0;
    cnt02 = compare(l0,l2,list,size);
    if(cnt02==-1) return 0;
    cnt1 = compare(l1,l2,list,size);
    if(cnt1==-1) return 0;
    cnt2 = compare(l2,l1,list,size);
    if(cnt2==-1) return 0;
    
    {
        (cnt1 < cnt2)? (min = cnt1):(min=cnt2);
        cout<<min;
    }
}