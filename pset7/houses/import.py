from sys import argv, exit
import csv
import cs50

# check arguments
# open file
# parse name
# insert


db = cs50.SQL("sqlite:///students.db")


def main():
    if len(argv) != 2:

        print("Usage: python import.py characters.csv")
        exit()


csv_path = argv[1]


with open(csv_path) as csv_file:

    reader = csv.DictReader(csv_file)
    for row in reader:
        names = row["name"].split(' ')
        if len(names) == 3:
            first = names[0]
            middle = names[1]
            last = names[2]
        else:
            first = names[0]
            middle = None
            last = names[1]

        house = row["house"]
        birth = row["birth"]
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)", first, middle, last, house, birth)


main()