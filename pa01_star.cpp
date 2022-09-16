/**
 * @file pa01_star.cpp
 * @author SehanKim (kimbird2002@naver.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<algorithm>
using namespace std;

class Building{
    private:
    int s;
    int w;
    int h;

    public:
    void set_s(int _s){
        s = _s;
    }
    void set_h(int _h){
        h = _h;
    }
    void set_w(int _w){
        w = _w;
    }
    int get_s(){return s;}
    int get_h(){return h;}
    int get_w(){return w;}

    int where(int x,int y){
        
        if(x > s+w || y > h) return 1;
        
        else if(x>s && x < s+w && y < h) return -1;

        else if(y==h) return 0;
        else if(x==s && y<h) return 0;
        else if(x==s+w && y<h) return 0;
    }

    int right_on(int x,int y){
        if(x==s+w && y<h) return 1;
        else return 0;
    }

    int left_on(int x,int y){
        if(x==s &&y<h) return 1;
        else return 0;
    }
};

bool cmp(Building b1, Building b2){
    if(b1.get_s() < b2.get_s()) return true;
    else return false;
}

int main(){
    int n=0,i=0,star=0;
    cin>>n;
    Building* b = new Building[n];
    for(i=0;i<n;i++){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        b[i].set_s(n1);
        b[i].set_h(n2);
        b[i].set_w(n3);
    }
    
    sort(b,b+n,cmp);
    
    cin>>star;
    
    for(i=0;i<star;i++){
        int x=0,y=0,state=1,max=0;
        cin>>x>>y;
        for(int j=0;j<n;j++){
            if(x >= b[j].get_s()){
                if(b[j].where(x,y) == 0) {
                    if(state == 0){
                        if(y < max && y < b[j].get_h()){
                            if(x==30) continue;
                            state = -1;
                            break;
                        }
                        else continue;
                    }
                    else {
                        (max < b[j].get_h() && b[j].right_on(x,y))?(max = b[j].get_h()):(max=max);
                        state=0;
                    }
                }
                else if(b[j].where(x,y) == -1) {
                    state = -1;
                    break;
                }
                else if(b[j].where(x,y) == 1) {
                    if(state == 0) continue;
                    else state=1;
                }
            }            
        }
        switch (state)
        {
        case 1:
            cout<<"over\n";
            break;
        case -1:
            cout<<"under\n";
            break;
        case 0:
            cout<<"on\n";
        default:
            break;
        }
    }
    
    delete b;
    return 0;
}