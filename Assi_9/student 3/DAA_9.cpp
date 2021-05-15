#include<bits/stdc++.h>
using namespace std;

countingsort(vector<int> &a, vector<int> &b, int k)//k is the maximum element in the array
{
	vector<int> c(k+2);
	
	for(int i = 0; i <= k; i++)
		c[i] = 0;
		
	for(int i = 1; i < a.size(); i++)
		c[a[i]+1]++; 								//c[i+1] now contains the no. of elements equal to i
		
	for(int i = 1; i <= k; i++)
		c[i] += c[i-1];								//c[i+1] now contains the no. of elements less than or equal to i, i.e. strictly less than i+1
		
	for(int i = 1; i < a.size(); i++) {				//Since c[a[i]] is the number of elements strictly less than a[i], 
		b[c[a[i]]+1] = a[i];						//first occurence of a[i] takes the position c[a[i]]+1 in b													
		c[a[i]]++;									//c[a[i]] is then incremented to accomodate next occurences of a[i] in further positions in b,
	}												//thus retaining their original order and maintaining stability
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n+1), b(n+1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int k = *max_element(a.begin()+1, a.end());
	countingsort(a, b, k);
	for(int i = 1; i <= n; i++)
		cout << b[i] << " ";
 return 0;}


