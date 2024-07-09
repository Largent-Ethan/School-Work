from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad

# Reads the file words.txt into an array
def getWords():
    wordList = []
    file = open('words.txt', 'r')
    for line in file:
        newLine = line.strip()
        wordList.append(newLine)
    file.close()
    return wordList

# Applies padding to strings
def wordPadding(word, buffer):
    for x in range(0, buffer):
        word += ' '
    return word

# Finds the key used to get an encrypted message from a plain text message
def main():
    ptxMsg = 'This is a top secret.'
    encMsg = '8d20e5056a8d24d0462ce74e4904c1b513e10d1df4a2ef2ad4540fae1ca0aaf9'
    wordList = getWords()
    for word in wordList:
        if(len(word) < 16):
            key = bytearray(wordPadding(word, 16 - len(word)), encoding = "utf-8")
            iv = bytearray.fromhex("00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00")
            if(encMsg == AES.new(key, AES.MODE_CBC, iv).encrypt(pad(str.encode(ptxMsg), AES.block_size)).hex()):
                print("A key was found!\n== ", word)
                return
        else:
            continue
    print("No key exists.")

main()