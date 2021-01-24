#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
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

  vector<int> studentGrades;

  // print all student data in students vector
  for (auto i = studentsVector.begin(); i != studentsVector.end(); ++i) {
    // cout << (*i).name << " " << (*i).grade << "\n"; 
    studentGrades.push_back((*i).grade);
  }

  int numElements = studentGrades.size();
  float average = calculateAverage(studentGrades, numElements);

  cout << "average grade: " << average << '\n';
}