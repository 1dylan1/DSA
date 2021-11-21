#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;


vector<int> fillVector(int n) {
	vector<int> list;
	for (int i = 1; i <= n; i++) {
		list.push_back(i);
	}
	return list;
}


vector<int> RemoveElement(vector<int> list, int val) {
	vector<int> newlist;
	for (int i = 0; i < list.size(); i++) {
		if (list[i] != val) {
			newlist.push_back(list[i]);
		}
	}
	return newlist;
}


pos FindMax(vector<vector<double>> matrix, vector<int> found, vector<int> unfound) {
	int max = -1;
	int x;
	int y;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < found.size(); j++) {
			for (int k = 0; k < unfound.size(); k++) {
				if (matrix[found[j] - 1][unfound[k] - 1] > max) {
					max = matrix[found[j] - 1][unfound[k] - 1];
					x = found[j];
					y = unfound[k];
				}
			}
		}
	}
	pos content;
	content.x = x;
	content.y = y;
	content.val = max;
	return content;
}

double maximumST(vector< vector<double> > adjacencyMatrix) {
	double sum = 0;
	vector<int> found;
	vector<int> unfound = fillVector(adjacencyMatrix.size());
	//Add root node
	found.push_back(1);
	unfound = RemoveElement(unfound, 1);
	while (unfound.empty() != true) {
		pos content = FindMax(adjacencyMatrix, found, unfound);
		adjacencyMatrix[content.x - 1][content.y - 1] = 0;
		adjacencyMatrix[content.y - 1][content.x - 1] = 0;
		sum += content.val;
		unfound = RemoveElement(unfound, content.y);
		found.push_back(content.y);
	}
	return sum;
}
