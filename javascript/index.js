const fs = require('fs')

fpStudentGrades = '../student-grades.txt'

// read the file and its contents
const file = fs.readFileSync(fpStudentGrades)
const content = file.toString()

// parse the contents into an array - each line an array element
const contentArray = content.split('\n')

// organize the contents into a structured object
const contentObject = {}
contentArray.forEach(contentLine => {
  const dataLine = contentLine.split(',')
  const [studentName, studentGrade] = dataLine
  contentObject[studentName] = Number(studentGrade)
});

function calculateAverage(arrayNumbers) {
  let sum = 0
  arrayNumbers.forEach(value => {
    sum += value
  })

  const average = sum/arrayNumbers.length
  return average
}

const arrayGrades = Object.keys(contentObject).map(studentName => {
  return contentObject[studentName]
})

function calculateMode(arrayNumbers) {
  const sortedArrayNumbers = [...arrayNumbers] // copy array
  sortedArrayNumbers.sort((a, b) => a - b) // sort modifies inline

  const numElements = sortedArrayNumbers.length
  const hasEvenNumberOfElements = numElements % 2 === 0

  if (hasEvenNumberOfElements) {
    // calculate the value of the middle two elements
    const indexMiddleLeft = numElements / 2 - 1
    const indexMiddleRight = numElements / 2
    return (sortedArrayNumbers[indexMiddleLeft] + sortedArrayNumbers[indexMiddleRight]) / 2
  } else {
    // return the element in the middle
    const indexMiddleElement = Math.floor(numElements / 2) + 1
    return sortedArrayNumbers[indexMiddleElement]
  }
}

function calculateVariance(arrayNumbers) {
  const average = calculateAverage(arrayNumbers)

  let summSquareDifferences = 0
  arrayNumbers.forEach(value => {
    const squareDiff = (value - average) * (value - average)
    summSquareDifferences += squareDiff
  })

  const variance = summSquareDifferences / (arrayNumbers.length)
  return variance
}

function calculateStandardDeviation(arrayNumbers) {
  const variance = calculateVariance(arrayNumbers)
  return Math.sqrt(variance)
}

const average = calculateAverage(arrayGrades)
const std = calculateStandardDeviation(arrayGrades)
const variance = calculateVariance(arrayGrades)
const mode = calculateMode(arrayGrades)

console.log('average: ', average)
console.log('standardDeviation: ', std)
console.log('variance: ', variance)
console.log('mode: ', mode)