#include<iostream>
#include<cstring>
#include<climits>
using namespace std ;

string windowsub(string str,string ptr){
	int sl = str.size() ;
	int pl = str.size() ;
	if(sl < pl){
		return "No Window" ;
	}
    int hash_str[256] = {0} ;
    int hash_p[256] = {0} ;
	int c = 0 ;
	for(int i = 0 ; i< pl ;i++){
		hash_p[ptr[i]] += 1 ;
		
	}
   int min_len = INT_MAX,start =0 ,min_index = -1 ; ;
	for(int j = 0 ; j < sl ; j++){
		hash_str[str[j]] += 1 ;

		if(hash_p[str[j]] != 0 and hash_str[str[j]] <= hash_p[str[j]]){
			c++  ;
		}
		if(c == pl){
			while(hash_p[str[start]] == 0 or hash_str[str[start]] > hash_p[str[start]]){
				if(hash_str[str[start]] > hash_p[str[start]]){
					hash_str[str[start]] -= 1 ;
				}
				start+=1 ;
			}

			int l = j - start + 1 ;
			if(l < min_len){
				min_len = l ;
				min_index = start ;
			}
		}
	}

	if(min_index == -1){
		return "No window" ;
	}
	return str.substr(min_index,min_len) ;
}

int main(){
	string str,pat ;
	cin >> str >> pat ;
	cout << windowsub(str,pat) ;


}