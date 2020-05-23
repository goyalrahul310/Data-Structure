#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std ;

//max heap
void upheapify(vector<int> &heap,int n){
	if(n==0) return ;

	int parentidx = (n-1)/2 ;
	if(heap[parentidx] < heap[n]){
		int t = heap[parentidx] ;
		heap[parentidx] = heap[n] ;
		heap[n] = t ;
		upheapify(heap,parentidx) ;
    }
    else{
    	return ;
    }
}

void insertheap(vector<int> &heap,int data){
	heap.push_back(data) ;
	upheapify(heap,heap.size()-1) ;
}

void downheapify(vector<int> &heap,int k){

	int leftidx = 2*k + 1 ;
	int rightidx = 2*k + 2 ;
	if(leftidx>=heap.size() && rightidx>=heap.size()){
		return ;
	}
	int laridx = k ; 
	if(leftidx<heap.size() && heap[leftidx] > heap[laridx]){
		laridx = leftidx ;
	}
	if(rightidx < heap.size() && heap[rightidx] > heap[laridx]){
		laridx = rightidx ;
	}
	if(laridx == k) return ;

	swap(heap[k],heap[laridx]) ;
	downheapify(heap,laridx) ;
}
void buildheapoptimised(vector<int> &heap){
	for(int i = heap.size()-1 ; i>=0 ; i--){
		downheapify(heap,i) ;
	}
}
void deleteheap(vector<int> &heap){
	swap(heap[0],heap[heap.size()-1]) ;
	heap.pop_back() ;
	downheapify(heap,0) ;
}

void deleteanynode(vector<int> &heap,int idx){
	heap[idx] = INT_MAX ;
	upheapify(heap,idx) ; // logn
	swap(heap[0],heap[heap.size()-1]) ;
	heap.pop_back() ;
	downheapify(heap,0) ;
}
void display(vector<int> heap){
	for(int i = 0 ; i<heap.size() ;i++){
		cout << heap[i] << " " ;
	}

}
int main(){
	int n,d;
	cin >> n ;
	vector<int> heap ;
	for(int i = 0 ; i<n;i++){
		cin >> d ;
		heap.push_back(d) ;
		//insertheap(heap,d) ;
	}
	deleteanynode(heap,3) ;
    buildheapoptimised(heap) ;
	display(heap) ;
}