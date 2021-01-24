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

int main () 
{
  string line;
  string filepath = "../student-grades.txt";
  ifstream gradesFile (filepath);

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
        } else {
          token.erase(remove_if(token.begin(), token.end(), ::isspace), token.end()); // remove whitespace
          student.grade = stof(token);
          wordPosition = 0;
        }
        wordPosition += 1;
      }
      
      cout << student.name << ' ' << student.grade << '\n';
    }
    gradesFile.close();
  } else {
    cout << "Unable to open grades file";
    return 0;
  }
}