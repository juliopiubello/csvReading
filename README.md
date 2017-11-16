# csvReading

In my university had the demand to know how much students was aproven, not or other situations, and now wich courses was they from in these 
respective class.

This code takes 
1 - one file that describes the name of the respective file of a class, and must be in a specific format 
EST012_A_2013_1 called turmas.csv
5 digits for the name of the class, 1 for his letter, 4 for his year and 1 for his period ( assuming that it has 1 and 3 in the year but it
may have how much you want)
2 - one file that describes the courses that takes these classes and it is a csv file in a specific format
Administration 33
name of the course and his code for comparisson ( the code takes specific digits in a registration code of the student and extracts his course
example : 201535036 , the code extract the 35 that is relatate to the course computer science.
3 - several classes with the format  registration code , ... 7 items .... , final situation
example : 231231232 , 1 , 2, 3, 4, 5, 6, 7, Aprovado
          123213123 , 1, 2,,3,4,5,6,7, Rep Nota

And for final, the code write a csv file with the information we needed for start


