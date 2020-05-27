#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int n, k;
  cin>>n>>k;
  int *arr = new int[n];
  
  unordered_map <int,int> m;
  
  for(int i=1; i<=n; i++){
    cin>>arr[i];
    m[arr[i]] = i;
  }

  for(int i = n ;i>=1&&k>0;i--){
    int best = n - i + 1 ;
    int ind = 0 ;
    if(m.count(i)){
      ind = m[i] ;
    }
    if(ind!=best){
      swap(arr[ind],arr[best]) ;
      m[arr[best]] = best ;
      m[arr[ind]] = ind ;
      k-- ;
    }
  }
  for(int i = 1 ; i<=n;i++){
    cout << arr[i] << " " ;
  }

  delete[] arr;
  
  return 0;
}
