// Given a long int array
// where all of the numbers within it appear an even number of times except for one number
// Write a method that returns that number that appears an odd number of times

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef std::unordered_map<int, int>::iterator Iter_t;

int FindTheOddOccurence(int numbers[], int size) {

  std::unordered_map<int, int> list;

  for (int i = 0; i < size; i++) {

    Iter_t iter = list.find(numbers[i]);

    if (iter == list.end())
      list.insert(std::make_pair(numbers[i], 1));
    else
      list[numbers[i]] = list[numbers[i]] + 1;
  }

  // //Debug purposes
  // for (Iter_t i = list.begin() ; i != list.end(); i++) {
  //   cout << "first: " << i->first << " second: " << i->second << endl;
  // }

  for (Iter_t i = list.begin() ; i != list.end(); i++) {
    if (i->second % 2 != 0)
      return i->first;
  }
  return 0;
}

int main(void) {
  int numbers[15] = {1,1,2,2,3,3,4,4,4,5,5,6,6,6,6};

  cout << "The odd occurence is " << FindTheOddOccurence(numbers, 15) << endl;
}
