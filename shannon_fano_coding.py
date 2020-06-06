'''
#Input: My name is Utkarsh

Output: Symbol Code
  ' ' : 000
  's' : 001
  'a' : 010
  'm' : 0110
  'M' : 0111
  'n' : 100
  'e' : 100
  'k' : 100
  'U' : 1010
  'y' : 1011
  't' : 1100
  'r' : 1101
  'h' : 1110
  'i' : 1111


'''

import sys
sys.stdin = open("//home//ryuk//Documents//cp//input.txt","r")
sys.stdout = open("//home//ryuk//Documents//cp//output.txt","w")
import math, typing

encodedDictionary = {}
def shannonFanoEncoding(string):
    global encodedDictionary
    encodedDictionary = {symbol: "" for symbol in set(string)}
    frequencies = {symbol: string.count(symbol) for symbol in set(string)}
    sortedFrequencies = sorted(frequencies.items(), key=lambda x: x[1], reverse=True)
    recurse_split(sortedFrequencies)
    print("Symbol Code")
    for symb in sortedFrequencies:
        print(f"  '{symb[0]}' : {encodedDictionary[symb[0]]}")


def recurse_split(split: typing.List):
    global encodedDictionary
    if len(split) == 2:
        encodedDictionary[split[0][0]] += "0"
        encodedDictionary[split[1][0]] += "1"
    min_diff = math.inf
    for i, _ in enumerate(split, start=1):
        if i >= len(split): break

        sections = [split[:i], split[i:]]
        difference = abs(sum([i[1] for i in sections[0]]) - sum([i[1] for i in sections[1]]))
        if min_diff < difference :
            for symb in split[:i-1]:
                encodedDictionary[symb[0]] += "0"
            for symb in split[i-1:]:
                encodedDictionary[symb[0]] += "1"

            recurse_split(split[:i-1])
            recurse_split(split[i-1:])

            break
        else:
            min_diff = difference
 
input_string = input()

shannonFanoEncoding(input_string)

