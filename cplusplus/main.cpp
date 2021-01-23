#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct student {
  string name;
  float grade;
}

int main () 
{
  string line;
  string filepath = "../student-grades.txt";
  ifstream gradesFile (filepath);

  if (gradesFile.is_open())
  {
    while (getline (gradesFile, line)) 
    {
      cout << line << "\n";
    }
    gradesFile.close();
  } else {
    cout << "Unable to open grades file";
    return 0;
  }
}