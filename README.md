# Wordhunt/Boggle solver

Wordhunt/Boggle solver made in C++.

## Build

```
g++ main.cpp gridSearcher.cpp trie.cpp
```

## How to use

Enter in the 4x4 grid in a string of 16 chars. Only lowercase alphanumeric chars.
e.g. the input ``abcdefghijklmnop`` corresponds to the grid:
```
a b c d
e f g h
i j k l
m n o p
```

You can use a custom wordlist to search from by replacing ``words.txt`` with your own file. The default wordlist is the ``words-alpha.txt`` set from https://github.com/dwyl/english-words.