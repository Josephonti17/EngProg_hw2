// Problem 1 
// Homework 2
// ============================================================================
//
// IPO Outline:
//   Input:    Integer measurements from stdin, terminated by -1.
//   Process:  Validate each reading (must be in [0, 500]).
//             Track count, min, max, and running sum for valid readings.
//             Compute average from count and sum.
//   Output:   Number of valid readings, min, max, and average (1 decimal).
//             If no valid readings: "No valid data."
//
// Flowchart:
//
//   [Start]
//      |
//      v
//   Initialize count=0, minVal=INT_MAX, maxVal=INT_MIN, sum=0.0
//      |
//      v
//   [Read value from stdin] <--------------------------+
//      |                                               |
//      v                                               |
//   (value == -1?) ---YES---> [Go to Output]           |
//      |                                               |
//      NO                                              |
//      |                                               |
//      v                                               |
//   (isValid(value)?) ---NO---> [Print warning] -------+
//      |                                               |
//      YES                                             |
//      |                                               |
//      v                                               |
//   [updateStats(value, count, minVal, maxVal, sum)] --+
//      |
//      v
//   [Output]
//      |
//      v
//   (count == 0?) ---YES---> [Print "No valid data."] ---> [End]
//      |
//      NO
//      |
//      v
//   [avg = computeAverage(count, sum)]
//   [printSummary(count, minVal, maxVal, avg)]
//      |
//      v
//   [End]


#include <iostream>
#include <climits>
#include <iomanip>


bool isValid(int value) {
    return (value >= 0 && value <= 500); //Returns true if value is within the range [0, 500].
}


void updateStats(int value,
                 int& count,
                 int& minVal,
                 int& maxVal,
                 double& sum) // Updates running statistics (count, min, max, sum) with a new valid reading
{
    count++;
    if (value < minVal) minVal = value;
    if (value > maxVal) maxVal = value;
    sum += value; 
}


double computeAverage(int count, double sum) {
    return sum / count; // Returns the average of the valid readings.
}


void printSummary(int count,
                  int minVal,
                  int maxVal,
                  double avg) //Prints the summary statistics for the sensor readings
{
    std::cout << "Valid readings: " << count << std::endl;
    std::cout << "Minimum: " << minVal << std::endl;
    std::cout << "Maximum: " << maxVal << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Average: " << avg << std::endl;
}

// main
int main() {
    int count = 0;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    double sum = 0.0;

    int value;
    std::cout << "Enter sensor readings (-1 to stop):" << std::endl;

    while (std::cin >> value && value != -1) {
        if (isValid(value)) {
            updateStats(value, count, minVal, maxVal, sum);
        } else {
            std::cout << "Warning: " << value
                      << " is out of range [0, 500]. Skipped." << std::endl;
        }
    }

    if (count == 0) {
        std::cout << "No valid data." << std::endl;
    } else {
        double avg = computeAverage(count, sum);
        printSummary(count, minVal, maxVal, avg);
    }

    return 0;
}
