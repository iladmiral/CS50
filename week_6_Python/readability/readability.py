# Get the text from user
print("Text: ", end='')
text = input()

# Initialize counters
count_letters = 0
count_words = 1
count_Sentences = 0

# Counting words, sentences, letters
for i in range(len(text)):
    if ((text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z')):
        count_letters += 1
    if text[i] == ' ':
        count_words += 1
    if text[i] == '.' or text[i] == '!' or text[i] == '?':
        count_Sentences += 1

# Calculate the level
L = count_letters * 100 / count_words
S = count_Sentences * 100 / count_words
index = 0.0588 * L - 0.296 * S - 15.8

# Print the result
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade ", round(index))

