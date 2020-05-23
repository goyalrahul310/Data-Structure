#include<iostream>
#include<vector>
#include<queue>
using namespace std ;

typedef pair<int,pair<int,int>> custom ;

vector<int> fun(vector<vector<int>> arr ){
	vector<int> r ;
	priority_queue<custom,vector<custom>,greater<custom>> pq ;
	for(int i = 0 ; i<arr.size();i++){
		pq.push({arr[i][0],{i,0}}) ;

	}

	while(!pq.empty()){
		custom curr = pq.top() ;
		pq.pop() ;
		int x = curr.second.first ;
		int y = curr.second.second ;
		r.push_back(curr.first) ;
		if(y+1<arr[x].size()){
			pq.push({arr[x][y+1],{x,y+1}}) ;
		}
	}
	return r ;


	}
int main(){
	vector<vector<int>> a{{1,2,3},{5, 7 ,9},{6,8,11}} ;


	vector<int> out = fun(a) ;
	for(int i = 0 ;i < out.size() ;i++){
		cout<<out[i] << " " ;
	}
}