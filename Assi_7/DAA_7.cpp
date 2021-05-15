#include <bits/stdc++.h>
using namespace std;
vector<int> a, b;

// Normal partition function
int partition_function(int p, int r) {
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
    	if (a[j] <= x) {
        	i++;
        	swap(a[i], a[j]);
    	}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}

// Updated partition function where we return mid of partiton in case all elements are same
int updated_partition_function(int p, int r) {
	int x = b[r];
	int k = p - 1;
	int i = p - 1;
	for (int j = p; j < r; j++) {
    	if (b[j] < x) {
        	k++;
        	swap(b[k], b[j]);
        	i++;
    	} else if (b[j] == x) {
        	i++;
        	swap(b[j], b[i]);
    	}
	}
	swap(b[i + 1], b[r]);
	return (i + k) / 2 + 1;
}

int main() {
	int n;
	int q;
	cout << "Enter size of Array:\n";
	cin >> n;
	a.resize(n + 1);
	b.resize(n + 1);
	cout << "Enter elements of Array:\n";
	for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	b[i] = a[i];
	}
	q = partition_function(1, n);
	cout << "Normal Partition Function:\n";
	cout << q << endl;

	q = updated_partition_function(1, n);
	cout << "Modified Partition Function:\n";
	cout << q << endl;
}
