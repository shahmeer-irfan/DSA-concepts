#include <iostream>
#include <vector>
// Vectors can dynamically grow and shrink.

using namespace std;

int main()
{
  vector<int> v1 = {1, 2, 3, 4, 5}; // Vector of integers, initialized with some values.

  cout << v1[1] << endl; // Outputs the second element of the vector (index 1).

  // v1.front(); // Returns the first element of the vector (not used in this example).
  v1.back(); // Returns the last element of the vector (not used in this example).
  v1.size(); // Returns the current size (number of elements) of the vector (not used in this example).

  v1.push_back(2); // Adds the element 2 to the end of the vector.

  v1.insert(v1.begin(), 3); // Inserts the element 3 at the beginning of the vector.

  v1.erase(v1.begin()); // Erases the first element from the vector.

  v1.pop_back(); // Removes the last element from the vector.

  // Iterator to traverse the vector.
  vector<int>::iterator it;
  for (it = v1.begin(); it != v1.end(); it++)
  {
    cout << *it << endl; // Dereferences the iterator to access the element.
  }

  return 0;
}

// Note: The capacity of a vector doesn't decrease automatically when elements are removed.
// To shrink the capacity to fit the actual number of elements, use shrink_to_fit().
