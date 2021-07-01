'''
Anup is interested in Word Play, He invented a new game on words
Anup will give you a string S and index P (1-indexed).
You need apply the rules of the game on that string  
and find out the character at a given index P.

Rules are as follows:
1. You have to read one character at a time and keep appending as a word until you find a digit(d).
2. Once you find a digit, the entire word is repeatedly appended d-1 more times in total.

Input Format:
----------------
Line-1 -> A String S
Line-2 -> An integer P, index value.

Output Format:
------------------
Print the result as a String.


Sample Input-1:
-------------------
kmit2ngit3
12

Sample Output-1:
---------------------
t

Explanation-1:
----------------
The resultant string is "kmitkmitngitkmitkmitngitkmitkmitngit".
The 12th character in the string is "t".

Sample Input-2:
-------------------
ab3c4
9

Sample Output-2:
---------------------
b

Explanation-2:
----------------
The resultant string is "abababcabababcabababcabababc"
The 9th character in the string is "b".


'''
word = input()
idx = int(input())

i = 0
Lst = []
temp = []
num = 0

while(i < len(word)):
    while(i < len(word) and word[i].isdigit()):
        num = num*10 + int(word[i])
        i += 1
    # print(num)
    if(num > 0):
        temp = Lst.copy()
        for x in range(0, num-1):
            Lst += temp
        num = 0
    # print(Lst)
    if(i >= len(word)):
        break
    Lst.append(word[i])
    i += 1

print(("".join(Lst))[idx-1])
# print(Lst)

# kmitkmitngitkmitkmitngitkmitkmitngit
# kmitkmitngitkmitkmitngitkmitkmitngitkmitkmitngit
# kmitkmitngitkmitkmitngitkmitkmitngit
# kmitkmitngitkmitkmitngitkmitkmitngit


# abababcabababcabababcabababc
# abababcabababcabababcabababc
# ababababcababababcababababcababababcababababcababababcababababcababababc
