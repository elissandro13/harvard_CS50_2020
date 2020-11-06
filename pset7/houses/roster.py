from sys import argv, exit
import csv
import cs50

db = cs50.SQL("sqlite:///students.db")


def main():
    if len(argv) != 2:

        print("Usage: python roster.py house")
        exit()


house = argv[1]

rows = db.execute("SELECT first, middle, last, birth from students WHERE house = ? ORDER BY last, first;", house)

for row in rows:
    if(row["middle"] == None):
        print(row["first"], row["last"] + ",", "born", row["birth"])
    else:
        print(row["first"], row["middle"],  row["last"] + ",", "born", row["birth"])

main()