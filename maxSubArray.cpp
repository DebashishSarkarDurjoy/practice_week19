#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void maxSubArray(vector<int> &numbers, int k) {
    deque<int> d(k);
    int i = 0;
    for(; i < k; i++) {
        while (!d.empty() && numbers[i] > numbers[d.back()]) {
            d.pop_back();
        }
        d.push_back(i);
    }
    for (int j = i; j < numbers.size(); j++) {
        cout << numbers[d.front()] << " ";
        while (!d.empty() && d.front() < j - k) d.pop_front();
        while (!d.empty() && numbers[j] > numbers[d.back()]) d.pop_back();
        d.push_back(j);
    }
    cout << numbers[d.front()] << endl;
}

int main(void) {
    vector<int> numbers = {1,2,3,1,4,5,2,3,5};
    maxSubArray(numbers, 3);


    return 0;
}