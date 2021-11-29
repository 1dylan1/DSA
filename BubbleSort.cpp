#include<iostream>
#include<vector>

using namespace std;


vector<int> bubbleSort(vector<int> list) {
	for (int i = 0; i < list.size()-1; i++) {
		for (int j = 0; j < list.size() - i - 1; j++) {
			if (list[j] > list[j + 1]) {
				swap(list[j], list[j + 1]);
			}
		}
	}
	return list;
}

void printVector(vector<int> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}
int main() {

	vector<int> list = { 4, 3, 2, 1 ,5 };
	cout << "Before Sort: " << endl;
	printVector(list);

	cout << "After Sort: " << endl;
	vector<int> sorted = bubbleSort(list);
	printVector(sorted);

	return 0;
}
