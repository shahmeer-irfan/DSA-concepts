#include <iostream>
#include <vector>
#include <map>
#include <strng> // Incorrect header inclusion, should be <string>

using namepsace std; // Incorrect spelling of 'namespace'

int main()
{

    vector<int> vec = {1, 2, 3, 4};
    vec.push_back("5"); // Incompatible type: adding a string to a vector of integers

    map<int, string> myMap;
    myMap.insert(1, "One"); // Wrong map insert function, should be a pair

    myMap[3] = 'Three'; // Incorrect type: single quotes used for a string

    int sum = vec[4] + myMap[1]; // Accessing out-of-bounds index and incompatible types

    vector<string> words;
    words.push("hello"); // Wrong method name, should be push_back

    int numbers[] = {1, 2, 3};
    vector<int> numberList(numbers, numbers + 5); // Array size mismatch, numbers only has 3 elements

    for (auto it = myMap.begin(); it != myMap.end(); ++it)
        cout << it.first << " - " << it->second << endl; // Incorrect use of iterator syntax

    vector<vector<int>> matrix(3, vector<int>(3));
    matrix[3][3] = 9; // Out-of-bounds access: matrix is only 3x3, max index is 2

    map<int, vector<int>> mapVec;
    mapVec[1].push_back(10);
    cout << mapVec[2][0]; // Accessing empty vector at key 2

    return 0;
}
