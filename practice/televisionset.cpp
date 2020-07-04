#include<iostream>
#include<math.h>
using namespace std ;


int calreven(int room,int type1,int type2,int target){
 int mon[] = {31,28,31,30,31,30,31,31,30,31,30,31} ;
 int pat ;
 int cost = 0 ;
  for(int i = 0 ; i <= room ;i++){
  	int b = room-i ;
  	cost = 0;
  	for(int j = 1 ; j <= 12 ;j++){
  		for(int k = 1 ; k <= mon[j-1] ; k++){
  			pat = (6-j)*(6-j) + abs(k-15) ;
  			int t = min(pat,room) ;
            if(t > b){
            	cost +=  type1*(t-b) + type2*b ;
            }
            else{
            	cost += type2*t ;
            }
  		}
  	}
  	//cout << cost << " " ;
  	if(cost >= target) return i ;

  }
  return room ;

}

int main(int argc, char const *argv[])
{
	int room ;
	cin >> room ;
	int type1,type2 ;
	cin >> type1 ;
	cin >> type2 ;
	int target ;
	cin >> target ;
	cout << calreven(room,type1,type2,target) ;
	
	return 0;
}