import math

gradesFilePath = "../student-grades.txt"

def readStudentData():
  studentData = {}
  with open(gradesFilePath, "r") as f:
    for line in f.readlines():
      # left side of comma contains student name, right side contains grade
      items = line.split(',')
      studentName = items[0]
      studentGrade = items[1]
      # extend student data object
      studentData[studentName] = int(studentGrade)
  return studentData

def calculateMean(studentData):
  summ, numElements = 0, 0
  for studentName, studentGrade in studentData.items():
    summ += studentGrade
    numElements += 1
  mean = summ / numElements
  return mean

def calculateVariance(studentData):
  mean = calculateMean(studentData)

  summSquareDiff, numElements = 0, 0
  for studentName, studentGrade in studentData.items():
    diff =  (studentGrade - mean) 
    summSquareDiff += diff*diff
    numElements += 1
  variance = summSquareDiff / numElements
  return variance

def calculateStandardDeviation(studentData):
  variance = calculateVariance(studentData)
  std = math.sqrt(variance)
  return std

def calculateMode(studentData):
  numElements = len(studentData.items())
  

studentData = readStudentData()

mean = calculateMean(studentData)
variance = calculateVariance(studentData)
std = calculateStandardDeviation(studentData)
mode = calculateMode(studentData)

print(f'mean: {mean} \n\
variance: {variance} \n\
standard deviation: {std}\n\
mode: {mode}')