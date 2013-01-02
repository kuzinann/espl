 
import csv

grades={}
count=0

with open('grades.csv', 'rb') as csvfile:
  file = csv.reader(csvfile, delimiter= ',')
  for line in file:
    count=count+1
    if count>1:
      if line[2] in grades:
	grades[line[2]]=grades[line[2]]+1
      else: 
	grades[line[2]]=1
	
for g, n in grades.items():
  print "%s students got %s" % (n,g)
