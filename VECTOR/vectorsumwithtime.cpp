#include <iostream>
#include <vector>
#include <chrono> 
using namespace std; // For measuring execution time

int main() {
    // Step 1: Initialize the vector with some values
    vector<int> v(1000000,1) ;  // Example vector
    
    // Step 2: Start the timer using chrono library
 auto start = chrono::high_resolution_clock::now();
    
    // Step 3: Initialize a variable to store the sum
    int sum = 0;
    
    // Step 4: Sum the values in the vector
    for (int i=0;i<v.size();i++) {
        sum =sum+v[i];
    }
    
    // Step 5: Stop the timer
    auto end = chrono::high_resolution_clock::now();
    
    // Step 6: Calculate the duration (execution time)
  chrono::duration<double> time = end - start;
    
    // Step 7: Output the results
  cout << "Sum: " << sum << endl;
  float a = time.count();
    cout << "Execution Time: " << a << " seconds" << endl;
    
    return 0;
}
