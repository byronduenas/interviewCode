//For a given string of numbers, print all the letter combinations for the string
#include <iostream>

using namespace std;

int main ()
{
    string zero = "";
    string one = "";
    string two = "ABC";
    string three = "DEF";
    string four = "GHI";
    string five = "JKL";
    string six = "MNO";
    string seven = "PQRS";
    string eight = "TUV";
    string nine = "WXYZ";
    string numbers[10] = {zero, one, two,three,four,five,six,seven,eight, nine};
    int max[10];
    int maxTotal = 1;

    string message = "278";

    //Getting the max number of letters for every number, eg. 1 -> 3 (A,B,C), 7-> 4 (PQRS)
    for (int i = 0; i < 10; ++i)
        max[i] = numbers[i].size();

    //Printing the max number of letters for each number in the message
    for (int i = 0; i < message.size(); ++i)
        cout << max[message.c_str()[i] - '0'];
    cout << endl;

    //Getting the total number of combinations
    for (int i = 0; i < message.size(); ++i)
    {
        if (i == 0)
            maxTotal = 1;
        maxTotal *= max[message.c_str()[i] - '0'];
    }
    cout << "The max total is " << maxTotal << endl;

    //At most 4^n combinations
    for (int i = 0; i < maxTotal; i++) {
        //n time for every different combination
        int divisor = 1;
        for (int j = 0; j < message.size(); j++) {
            cout << (numbers[message.c_str()[j] - '0']).c_str()[(i/divisor)%max[message.c_str()[j] - '0']];
            divisor *= max[message.c_str()[j] - '0'];
        }
        cout << endl;
    }

    return 0;
}
