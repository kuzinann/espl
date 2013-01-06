
import sys
import random

lines = open('long-words.txt').read().splitlines()
myWord =random.choice(lines)
myLetters = ['-']* len(myWord)
numOfTry=len(myWord)+6

for i in range (numOfTry):
  letter = raw_input("Enter something: ")
  print "your letter ", letter
  
  if letter in myWord:
    print "Yes! The letter correct!"
    start= 0
    numOfCorrectLetters = myWord.count(letter)
    
    for i in range(numOfCorrectLetters):
      placeInWord= myWord.find(letter, start)
      start = placeInWord+1
      myLetters[placeInWord] = letter
    print myLetters

      
  if not letter in myWord:
    print "no! The letter wrong!"
      
  if not '-' in myLetters:
    print "You are the winner!"
    sys.exit(0)
  
  numOfTry = numOfTry-1
  print "%s%i%s" % ("you have ",numOfTry," tries left")
      
print "You are losssssssser!!!"
     
      


