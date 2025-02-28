#include <iostream>
#include <fstream>
#include <string>
#include <cassert> 
#include <cmath> //to add the sprt function  
#include <iomanip> // to do 2 decimal places 

using namespace std;

// Function prototypes
double ComputeMean(const double values[], int count);
double ComputeSdv(const double values[], int count, double mean);

int main() {

    const int MAX_SIZE = 100; //max array size 
    double values[MAX_SIZE];
    int count = 0; 

    string filename;
    cout << "Enter the data file name: ";
    cin >> filename;  
    cout << endl; 

    //if file does not open 
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: File not found!" << endl;
        return 1;
    }

    // Read values from the file into the array
    while (inputFile >> values[count] && count < MAX_SIZE) {
        count++;
    }

    //close file 
    inputFile.close(); 

    //output values from file using a loop 
    cout << "The values read are: ";
    for (int i = 0; i < count; i++) {
        cout << values[i] << " ";
    }

    cout << endl;

    double mean = ComputeMean(values, count);
    double standardDeviation = ComputeSdv(values, count, mean);  

    //print output 
    cout << endl; 
    cout << fixed << setprecision(2);
    cout << "The mean is " << mean << ". The standard deviation is " << standardDeviation << "." << endl; 

    return 0;
}

double ComputeMean(const double values[], int count) {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += values[i];
    }
    return sum / count;
}

double ComputeSdv(const double values[], int count, double mean) {
    double sumSquaredDifferences = 0.0;
    for (int i = 0; i < count; i++) {
        sumSquaredDifferences += (values[i] - mean) * (values[i] - mean);
    }
    
    return sqrt(sumSquaredDifferences / count);
}
