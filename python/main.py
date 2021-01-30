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
  studentGrades = studentData.values()
  sortedGrades = sorted(studentGrades)

  numElements = len(studentData.items())
  isEven = (numElements % 2) == 0
  
  if (isEven):
    # return the average of the middle two elements
    x1 = sortedGrades[int(numElements/2) - 1]
    x2 = sortedGrades[int(numElements/2)]
    return (x1 + x2) / 2
  else:
    # return value in the middle
    return sortedGrades[math.floor(numElements/2)]  

studentData = readStudentData()

mean = calculateMean(studentData)
variance = calculateVariance(studentData)
std = calculateStandardDeviation(studentData)
mode = calculateMode(studentData)

print(f'mean: {mean} \n\
variance: {variance} \n\
standard deviation: {std}\n\
mode: {mode}')