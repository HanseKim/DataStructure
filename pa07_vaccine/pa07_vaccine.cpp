#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int number,age;
    char gender;
    int om_i=0,of_i=0,af_i=0,am_i=0,c_i=0;
    int Old_male[n],Old_female[n],Adult_female[n],Adult_male[n],Child[n];
    for(int i=0;i<n;i++){
        cin>>number>>age>>gender;
        if(age<=15) Child[c_i++] = number;
        else if(age<=60){
            if(gender == 'M')
                Adult_male[am_i++] = number;
            else 
                Adult_female[af_i++] = number;
        }
        else{
            if(gender=='M') Old_male[om_i++] =number;
            else Old_female[of_i++] = number;
        }
    }
    for(int i=0;i<om_i;i++) cout<<Old_male[i]<<"\n";
    for(int i=0;i<of_i;i++) cout<<Old_female[i]<<"\n";
    for(int i=0;i<c_i;i++) cout<<Child[i]<<"\n";
    for(int i=0;i<af_i;i++) cout<<Adult_female[i]<<"\n";
    for(int i=0;i<am_i;i++) cout<<Adult_male[i]<<"\n";
}