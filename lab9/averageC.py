 
import csv

grades={}
count=0

with open('grades.csv', 'rb') as csvfile:
  file = csv.reader(csvfile, delimiter= ',')
  for line in file:
    count=count+1
    if count>1:
      if line[2] in grades:
	grades[line[2]]['count'] = grades[line[2]]['count'] +1
	(grades[line[2]]['students']).append(line[0])
      else: 
	grades[line[2]]= {'count': 1, 'students': [line[0]]}
	
for g, n in grades.items():
  print "%s %s" % (g,n)
