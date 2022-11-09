/**
 * @file pa09_tracks.cpp
 * @author SehanKim (kimbird2002@naver.com)
 * @brief array-> timelimit : map -> key 중복x : 멀테맵으로 해결
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int n;
vector< pair<int, int> > v;
multimap<int,int,greater<int>> m;
multimap<int,int,greater<int>>::iterator it;
bool compare (pair<int, int> a, pair<int, int> b){
	if(a.second==b.second) return a.first < b.first;
	return a.second < b.second;
}
int tracks(){
	int arr[n] = {0,};
	int i=0,j=0,cnt=0;
	for(i=0;i<n;i++){
		int state=1;
		if(i==0){
			m.insert(pair<int,int>(v[0].second,v[0].first));
			continue;
		}
		//pq에 들어간 수보다 크다면 pqpop 하고 push하기
		for(it=m.begin();it!=m.end();it++){
			if(v[i].first >= it->first){
				m.erase(it);
				m.insert(pair<int,int>(v[i].second,v[i].first));
				state=0;
				break;
			}
		}
		//포문을 다 돌아도 안넣어진다면 push
		if(state){
			m.insert(pair<int,int>(v[i].second,v[i].first));
		}
	}
	return m.size();
}

int main(){
	cin >> n;
	for (int i=0;i<n;i++){
		int start, finish;
		cin >> start >> finish;
		v.push_back(make_pair(start, start+finish));
	}
	sort(v.begin(), v.end(), compare);
	cout<<tracks();
}