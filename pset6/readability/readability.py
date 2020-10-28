letters = 0
sentences = 0
words = 1

text = input("Text: ")


for c in text:
    if c.islower() or c.isupper():
        letters += 1.0
    elif c == "." or c == "!" or c == "?":
        sentences += 1.0
    elif c.isspace():
        words += 1.0

L =  letters /  words  * 100.0
S =  sentences /  words  * 100.0
index = (0.0588 * L  - 0.296 * S) - 15.8

index = int(round(index))

if index < 1:
     print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f'Grade {index}')




