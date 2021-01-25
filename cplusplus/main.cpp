#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <math.h>
using namespace std;

struct sstudent {
  string name;
  float grade;
};

float calculateAverage(vector<int>& array, int numElements) {
  int sum = 0;
  for (int i=0; i<numElements; i++) {
    sum += array[i];
  }
  float average = (float)sum / numElements;
  return average;
}

float calculateVariance(vector<int>&array, int numElements) {
  float sumSquaresDiff = 0; // numerator
  float squareDiff;         // temp variable placeholder
  float mean = calculateAverage(array, numElements);

  for (int i=0; i<numElements; i++) {
    squareDiff = (array[i]-mean);   // split out the heavy compute operation into two,
    squareDiff *= squareDiff;       // and reuse temp variable (faster)
    sumSquaresDiff += squareDiff;
  }
  float variance = sumSquaresDiff / (numElements-1);
  return variance;
}

float calculateStandardDeviation(vector<int>&array, int numElements) {
  float variance = calculateVariance(array, numElements);
  float std = sqrt(variance);
  return std;
}

int main () 
{
  string line;
  string filepath = "../student-grades.txt";
  ifstream gradesFile (filepath);

  vector<sstudent> studentsVector;

  if (gradesFile.is_open())
  {
    while (getline (gradesFile, line)) 
    {
      istringstream ss(line);
      string token;

      sstudent student; 
      string studentName;
      float studentGrade;

      int wordPosition = 0;
      while(getline(ss, token, ',')) {
        if (wordPosition == 0) {
          student.name = token;
          wordPosition += 1;
        } else {
          token.erase(remove_if(token.begin(), token.end(), ::isspace), token.end()); // remove whitespace
          student.grade = stof(token);
          wordPosition = 0;

          studentsVector.push_back(student);
        }
      }
    }
    gradesFile.close();
  } else {
    cout << "Unable to open grades file";
    return 0;
  }

  // create array of all students grades
  vector<int> studentGrades;
  for (auto i = studentsVector.begin(); i != studentsVector.end(); ++i) {
    studentGrades.push_back((*i).grade);
  }

  int numElements = studentGrades.size();
  float average = calculateAverage(studentGrades, numElements);
  float variance = calculateVariance(studentGrades, numElements);
  float std = calculateStandardDeviation(studentGrades, numElements);

  cout << "average grade: " << average << '\n';
  cout << "variance: " << variance << '\n';
  cout << "standard deviation: " << std << '\n';
}