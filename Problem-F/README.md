# Anagram Grouping (Scrabble Database)

A C-language solution for an algorithmic problem focused on grouping words by anagrams, inspired by the classic word game Scrabble.

## Overview

Scrabble is one of the world's most popular word games, invented by Alfred Butts in 1931. In this challenge, Bytek is building an online version of the game and needs a module to power a helper database that suggests valid words from a set of available letters.

To organize the word database efficiently, words are categorized into groups of **anagrams** (words formed by rearranging the letters of another word, such as *listen* and *silent*). Case sensitivity is ignored when determining anagram matches.

## Problem Specification

### Input
* **$z$**: Number of test cases ($1 \le z \le 10^9$).
* For each test case:
  * **$n$**: Number of words in the dictionary ($1 \le n \le 10000$).
  * A sequence of $n$ words composed of English letters (up to 100 characters per word).

### Output
For each test case:
1. An integer $a$ indicating the number of distinct anagram groups.
2. The $a$ groups printed on separate lines, ordered as follows:
   * **Primary sorting:** Descending by group size (largest group first).
   * **Secondary sorting:** Lexicographically by comparing sorted representatives of equal-sized groups.
3. Each line begins with the count of words in that group, followed by the words themselves (in any order).

### Constraints
* **Memory Limit:** 4 MB
* **Programming Language:** C

## Example

### Input
```text
2
8
CARE race AT eaT Acre rear Ate tea
14
AUTO algorithm rife meat FIRE tame logarithm least slate stale TEAM mate steal tales
```

### Output
```text
4
3 CARE race Acre
3 eaT Ate tea
1 rear
1 AT
5
5 least slate stale steal tales
4 meat tame TEAM mate
2 algorithm logarithm
2 rife FIRE
1 AUTO
```

## Setup & Execution

### Prerequisites
* GCC or any C99-compliant compiler.

### Compilation
```bash
gcc -O3 main.c -o scrabble
```

### Running the Program
```bash
./scrabble < input.txt
```