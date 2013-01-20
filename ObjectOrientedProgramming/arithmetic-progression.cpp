/*Write a function that checks if an array is arithmetic progression
*/

#include <iostream>
using namespace std;

bool is_arithmetic_prog (int * arr, int n)
{
	if(n == 1) return true;
	int subst = arr[1] - arr[0];
	for(int i = 1; i<n-1; i++){
		if( subst != arr[i+1] - arr[i]){
			return false;
		}
	}
	return true;
}

bool is_geom_prog (int * arr, int n)
{
	if(n == 1) return true;
	double subst = (double)arr[1]/arr[0];
	for(int i = 1; i<n-1; i++){
		if( subst != arr[i+1]/arr[i]){
			return false;
		}
	}
	return true;
}

bool is_fib (int * arr, int n)
{
	if(n == 1 && arr[0]==0 ) return true;
	if(n == 2 && arr[0]==0 && arr[1]==1 ) return true;

	
	for(int i = 1; i<n-1; i++){
		if(arr[i+1] != arr[i] + arr[i-1]){
			return false;
		}
	}
	return true;
}

int main()
{
	int arr[5] = {1,3,5,7,9};
	int a[] = {2,4,9};
	int f[] = {0,1,1,2,3};
	if (is_fib(f,5)){
		cout<< "Yes"<<endl;
	}
	else
	{cout<<"No"<<endl;
	}
	
	return 0;
}
