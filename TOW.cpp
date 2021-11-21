#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

int getTotalSum(vector<int> list) {
	int sum = 0;
	for (int i = 0; i < list.size(); i++) {
		sum += list[i];
	}
	return sum;
}

bool choose(int a, int b) {
	if (a > b) {
		return true; //left
	}
	else if (a < b) {
		return false; //right
	}
	return true; //left again 
}

int getClosestSum(vector<int> list, int i, int currSum, int targetSum) {


	if (currSum > targetSum) { //invalid answer
		return -1;
	}

	if (i == list.size()) { //end of list
		return currSum;
	}

	int a1 = getClosestSum(list, i + 1, currSum + list.at(i), targetSum);
	int b1 = getClosestSum(list, i + 1, currSum, targetSum);
	bool pickSum = choose(a1, b1);

	if (pickSum) {
		return a1;
	}
	else {
		return b1;
	}

}

int tugOfWar(vector<int> weights) {

	int targetSum = ceil(getTotalSum(weights) / 2.0); //do this
	int sum1 = getClosestSum(weights, 0, 0, targetSum);
	int sum2 = getTotalSum(weights) - sum1;
	int difference = fabs(sum1 - sum2);

	return difference;
}
