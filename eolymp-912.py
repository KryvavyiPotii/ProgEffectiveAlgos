def sentence_count(text: str) -> int:
    i = 0
    counter = 0
    while i < len(text):
        # Skip words
        while i < len(text) and text[i] not in '.?!':
            i += 1
        counter += 1
        # Skip duplicated punctuation marks
        while i < len(text) and text[i] in '.?!':
            i += 1
    return counter

print(sentence_count(input()))
