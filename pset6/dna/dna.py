from sys import argv, exit
import csv


def long_subsequence(s, sub):

    ans = [0] * len(s[0])
    for i in range(len(s[0]) - len(sub)):
        if s[0][i: i + len(sub)] == sub:
            if(i - len(sub) < 0):
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i - len(sub)]

    return max(ans)


def print_match(result, data_list, dnaTags):

    for data in data_list:
        person = data[0]
        values = data[1:]
        values = [int(i) for i in values]

        if values == result:
            return person

    return "No match"


def main():
    if len(argv) != 3:

        print("Usage: python dna.py data.csv sequence.txt")
        exit()


csv_path = argv[1]
sequence_path = argv[2]
data_list = []
dna_sequence = " "
resultDict = {
    "AGATC": 0,
    "TTTTTTCT": 0,
    "AATG": 0,
    "TCTAG": 0,
    "GATA": 0,
    "TATC": 0,
    "GAAA": 0,
    "TCTG": 0
}

# dnaTags = ['AGATC']

with open(csv_path) as csv_file:

    reader = csv.reader(csv_file)
    for row in reader:
        data_list.append(row)

with open(sequence_path) as dna_file:

    reader = csv.reader(dna_file)
    for row in reader:
        dna_sequence = row

# dnaTags = ['AGATC', 'TTTTTTCT', 'AATG', 'TCTAG', 'GATA', 'TATC', 'GAAA', 'TCTG']  dnaTags = ['AGATC', 'TTTTTTCT', 'AATG', 'TCTAG', 'GATA', 'TATC', 'GAAA', 'TCTG']
dnaTags = data_list[0][1: len(data_list[0])]
data_list = data_list[1:]
# print(data_list)

# print(data_list)

arrayValues = []

for tag in dnaTags:
    # print(tag)
    # resultDict[tag] = long_subsequence(dna_sequence,tag)
    arrayValues.append(long_subsequence(dna_sequence, tag))
# print(arrayValues)
print(print_match(arrayValues, data_list, dnaTags))

main()