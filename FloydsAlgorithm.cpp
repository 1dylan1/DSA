#include <iostream>
#include <vector>
#include <cstdio>
#include<cstdio>
#include<algorithm>

using namespace std;

#define INF 1024 // -1 -> 1024 -> -1 

vector<vector<double>> createBlankMatrix(int n) {
    vector<double> row(n, 42); //we will use 42 later as an identifier for a blank.
    vector<vector<double>> matrix(n, row);

    for (int i = 0; i < n; i++) {
        matrix[i][i] = 0;
    }

    return matrix;
}

vector<vector<double>> transferMatrix(int n, vector<vector<double>> source, int stage) {
    vector<vector<double>> current = createBlankMatrix(n);

    for (int i = 0; i < source.size(); i++) {
        for (int j = 0; j < source.size(); j++) {
            if (i == (stage - 1) || j == (stage - 1)) {
                current[i][j] = source[i][j];
            }
        }
    }
    return current;
}


vector<vector<double>> getStage(vector<vector<double>> current, vector<vector<double>> initial, int stage) {
    //replace all infinities
    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial.size(); j++) {
            if (initial[i][j] == -1) {
                initial[i][j] = INF;
            }
        }
    }
    //actual algorithm
    for (int i = 0; i < current.size(); i++) {
        for (int j = 0; j < current.size(); j++) {
            if (current[i][j] == 42) {
                if (initial[i][j] > initial[i][stage - 1] + initial[stage - 1][j]) {
                    current[i][j] = initial[i][stage - 1] + initial[stage - 1][j];
                }
                else {
                    current[i][j] = initial[i][j];
                }
            }
        }
    }
    return current;
}


vector<vector<double>> allPairsSP(vector< vector<double> > adjacencyMatrix, int i) {

    vector<vector<double>> initial = adjacencyMatrix;
    vector<vector<double>> current = createBlankMatrix(initial.size());
    int size = initial.size();
    int stage = 0;
    while (i > stage) {
        stage++;
        //first, translate previous(or initial) stage count matrix to current matrix
        current = transferMatrix(size, initial, stage);
        //calculate a stage of Floyd's algorithm
        current = getStage(current, initial, stage);
        initial = current; //set this to new D(0)
        current = createBlankMatrix(size); //Reset for next cycle
    }
    //convert infinity back to -1
    for (int i = 0; i < initial.size(); i++) {
        for (int j = 0; j < initial.size(); j++) {
            if (initial[i][j] == INF) {
                initial[i][j] = -1;
            }
        }
    }

    return initial;
}
