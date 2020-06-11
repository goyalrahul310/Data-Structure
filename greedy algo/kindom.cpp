#include<iostream>
#include<algorithm>
using namespace std ;

int main(){
	int t ,dx,dy,w,h,n;
	cin >> t ;
	while(t--){
		cin >> w >> h >> n ;
		int x[n],y[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> x[i] >> y[i] ;
		}
        sort(x,x+n) ;
        sort(y,y+n) ;


		dx = x[0] - 1 ;
		dy = y[0] - 1 ;

		for(int i = 1 ; i < n ;i++){
			dx = max(dx,x[i] - x[i-1] -1) ;
			dy = max(dy,y[i] - y[i-1] - 1) ;
		}

		dx = max(dx,w - x[n-1]) ;
		dy = max(dy,h - y[n-1]) ;

		cout << dx*dy << endl ;
	}
}