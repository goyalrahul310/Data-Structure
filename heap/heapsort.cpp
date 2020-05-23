//max heap to min heap

#include<iostream>
#include<vector>
using namespace std ;



void downheapify(vector<int> &heap,int idx){
	int left = 2*idx + 1 ;
	int right = 2*idx + 2 ;

	if(left>=heap.size() && right>=heap.size())
		return ;

	int lar = idx ;
	if(left<heap.size() && heap[left]>lar){
		lar = left ;
	}
	if(right<heap.size() && heap[right]>lar){
		lar = right ;
	}
	if(lar == idx)return ;
	swap(heap[idx],heap[lar]) ;
	downheapify(heap,lar) ;
}
void buildheap(vector<int> &heap){
	for(int i = heap.size()-1 ; i >= 0 ;i--){
		downheapify(heap,i) ;
	}

}


void downheapifyhelper(vector<int> &heap,int idx,int hsize){
	int left = 2*idx + 1 ;
	int right = 2*idx + 2 ;

	if(left>=hsize && right>=hsize)
		return ;

	int lar = idx ;
	if(left<hsize && heap[left]>heap[lar]){
		lar = left ;
	}
	if(right<hsize && heap[right]>heap[lar]){
		lar = right ;
	}
	if(lar == idx)return ;
	swap(heap[idx],heap[lar]) ;
	downheapifyhelper(heap,lar,hsize) ;
}
void heapsort(vector<int> &heap){
	buildheap(heap) ;
	int n = heap.size() ;
	for(int i = n-1 ; i>0;i--){
		swap(heap[0],heap[i]) ;
		n-=1 ;
		downheapifyhelper(heap,0,n) ;
	}
}
int main(){
	int n ;
	cin >> n ;
	int d ;

	vector<int> heap;
	for(int i = 0 ;i<n;i++){
		cin >> d ;
		heap.push_back(d) ;
	}
	buildheap(heap) ;

	 heapsort(heap) ;
	for(int i = 0 ;i<heap.size();i++){
		cout << heap[i] << " " ;
	}
}