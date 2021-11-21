#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

/*
Finds the maximum number of overlapping intervals when given n number of ranges, where n = the size of the start/end vector.

When both vectors are sorted correctly, iterate through the start vector elements until the end element is greater than the starter element,
then increase j to the next end element and continue. Add 1 every iteration and subtract 1 when start > end on their respective elements.
*/
int overlappingIntervals( vector<double> start , vector<double> end ) {

    int count = 0;
    int maxcount = 0;
    int i = 0;
    int j = 0;

    sort(end.begin(), end.end()); //only need it for the end, since the start vector is technically already sorted.

    while (i < start.size()) {
        count++;
        if (start[i] > end[j]) {
            count--;
            j++;
        }
        if (count > maxcount) {
            maxcount = count;
        }
        i++;
    }

    return maxcount;

}
