import hashlib
import random
import string

# Generates a random 10 character string
def createString():
  newString = ''.join(random.choice(string.ascii_letters) for i in range(10))
  return newString

# Generates a 256-bit hash for a given string
def hashString(givenString):
  hashValue = hashlib.sha256(givenString.encode())
  return hashValue.hexdigest()

# Simulates a weak collision resistance attack on a hash with a given number of bytes a given number of times
def weakCollision(numBytes, numTests):
  testCount = 0
  netCollisions = 0
  for i in range(numTests):
    stringOne = createString()
    attemptNum = 0
    testCount += 1
    print("Test ", testCount)
    while 1:
      stringTwo = createString()
      if stringOne == stringTwo:
        continue
      else:
        hashValueOne = hashString(stringOne)
        hashValueTwo = hashString(stringTwo)
        attemptNum += 1
        print("  BREAKING...", attemptNum, end='\r')
        if(hashValueOne[0:numBytes] == hashValueTwo[0:numBytes]):
          break
    print(attemptNum)
    print("  BROKEN in ", attemptNum, " attempts!")
    netCollisions += attemptNum
  average = netCollisions / testCount
  return average

# Simulates a strong collision resistance attack on a hash with a given number of bytes a given number of times
def strongCollision(numBytes, numTests):    
  testCount = 0
  netCollisions = 0
  for i in range(numTests):
    attemptNum = 0
    testCount += 1
    print("Test ", testCount)
    while 1:
      stringOne = createString()
      stringTwo = createString()
      if stringOne == stringTwo:
        continue
      else:
        hashValueOne = hashString(stringOne)
        hashValueTwo = hashString(stringTwo)  
        attemptNum += 1
        print("  BREAKING...", attemptNum, end='\r')
        if(hashValueOne[0:numBytes] == hashValueTwo[0:numBytes]):
          break
    print("  BROKEN in ", attemptNum, " attempts!")
    print(attemptNum)
    netCollisions += attemptNum
  average = netCollisions / testCount
  return average

# Tests weak and strong collision resistance attacks and displays infomration about the results
def main():
  numBytes = 3
  numTests = 15
  print("\nWeak Collision Resistance Tests\n===============================")
  weakAverage = weakCollision(numBytes * 2, numTests)
  print("\nStrong Collision Resistance Tests\n===============================")
  strongAverage = strongCollision(numBytes * 2, numTests)
  print("\nWeak Collision Resistance Results")
  print("  Number of tests ran: %s" % (numTests))
  print("  Average attempts to break: %s" % weakAverage)
  print("Strong Collision Resistance Results")
  print("  Number of tests ran: %s" % (numTests))
  print("  Average attempts to break: %s" % strongAverage)

main()