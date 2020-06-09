#include<iostream>
#include<algorithm>
using namespace std ;


int moneychange(int money,int *coin,int n){
	int ans = 0 ;
	while(money>0){
	int idx  = upper_bound(coin,coin+n,money) - coin - 1  ;

		money = money-coin[idx] ;
		ans++ ;
	}
	return ans ;


}

int main(){
	int coin[] = {1,2,5,10,20,50,100,500,2000} ;
	int money ;
	cin >> money ;
	cout << "Coins needed" << moneychange(money,coin,9) ;
}