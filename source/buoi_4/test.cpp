#include <iostream>
using namespace std;
class KhoaHoc{
	friend void check(KhoaHoc [], int );
	private:
		int id;
		string name;
		float time;
		float price;
	public:
		void input();
		void output();
};
void KhoaHoc::input(){
	cout<<"ID course :";
	cin>>id;
	cout<<"Name course :";
	cin>>name;
	cout<<"Time course :";
	cin>>time;
	cout<<"Price course : ";
	cin>>price;
	cout<<"================== \n";
}
void KhoaHoc::output(){
	cout<<"ID Course : "<<id<<endl;
	cout<<"Name Course : "<<name<<endl;
	cout<<"Time Course : "<<time<<endl;
	cout<<"Price Course :"<<price<<endl;
}
void inputlist(KhoaHoc a[],int &n){
	cout<<"Number of course :"<<endl;
	cin>>n;
	for ( int i = 0 ; i < n ; i++){
		a[i].input();
	}
}
void outputlist(KhoaHoc a[] , int n) {
	for ( int i = 0 ; i < n ; i++){
		a[i].output();
	}
}
void check(KhoaHoc a[], int n){
    KhoaHoc temp;
    for( int i=0; i<n-1;i++){
        for( int j=i+1; j<n;j++){
      if(a[i].price< a[j].price){
          temp = a[i];
          a[i] = a[j];
          a[j]=temp;
      }
}
int main(){
	int n;
	KhoaHoc g[100];
	inputlist(g,n);
	check(g,n);
	outputlist(g,n);
	return 0;
}
