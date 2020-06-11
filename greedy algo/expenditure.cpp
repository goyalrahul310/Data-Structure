#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std ;





bool compare(pair<int,int> a,pair<int,int> b){
	return  a.first > b.first ;

}
int main(int argc, char const *argv[])
{

	int t ;
	cin >> t ;
	while(t--){
		int n,fl = 0 ;
		cin >> n ;

        priority_queue<int> pq ;
		vector<pair<int,int> > f ;
        int f1,d2 ;
		for(int i = 0; i <n ;i++){
			cin >> d2 >> f1;
			f.push_back(make_pair(d2,f1)) ;
		}

		sort(f.begin(),f.end(),compare) ;
		int F,D ;
		cin >> D >> F ;
		//cout << D ;
		for(int i = 0 ; i< n;i++){
			//cout << f[i].first << "p" << endl ;
			f[i].first = D - f[i].first ;
			//cout << f[i].first << "p" << endl ;
		}
		int x = 0 ,prev= 0,ans  = 0  ;
		while(x<n){
			if(F>= (f[x].first-prev)){
				F = F - (f[x].first-prev) ;
				//cout << f[x].first << "hh" << endl ;
				prev = f[x].first ;
				//cout << F ;
				pq.push(f[x].second) ;
			}
			else{
				if(pq.empty()){
					fl = 1 ;
					break ;
				}
				//refuel
				F += pq.top() ;
				pq.pop() ;
				ans += 1  ;
				continue ;
			}
			x++ ;
		}

		if(fl==1){
			cout << -1 ;
			continue ;
		}

		if(F >= D - f[n-1].first){
			cout << ans << endl ;
			continue ;
		}

		while(F < D - f[n-1].first){
			if(pq.empty()) {
				fl = 1 ;
				break ;
			}

			F += pq.top() ;
			pq.pop() ;
			ans += 1  ;
		}
		if(fl==1){
			cout << -1 ;
			continue ;
		}

		cout << ans << "test";

	}
	return 0;
}
