 
import csv

countLine=0
sum=0

with open('grades.csv', 'rb') as csvfile:
  file = csv.reader(csvfile, delimiter= ',')
  for line in file:
    print ', '.join(line) 
    countLine=countLine+1
    if countLine>1:
      sum=sum+float(line[2])

  
      
print ",AVERAGE, " + str(sum/countLine)	
 