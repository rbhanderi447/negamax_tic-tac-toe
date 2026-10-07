# Tic-Tac-Toe in C

A simple command-line Tic-Tac-Toe game in C featuring an unbeatable AI powered by the Negamax algorithm.

## Features

* **Unbeatable AI**: Uses the Negamax algorithm to choose optimal moves.
* **Random Start**: Randomly picks whether you or the computer goes first.
* **Clean Grid**: Simple ASCII board output in the terminal.

---

## How to Play

### 1. Compile

```bash
gcc main.c -o tictactoe

```

### 2. Run

```bash
./tictactoe

```

### 3. Controls

Enter moves using `row column` (numbers 1 to 3 separated by a space):

```text
1 3

```

This places your mark in **Row 1, Column 3** (top-right corner).

---

## Example Board

```text
       1     2     3
    +-----+-----+-----+
  1 |  X  |     |     |
    +-----+-----+-----+
  2 |     |  O  |     |
    +-----+-----+-----+
  3 |     |     |     |
    +-----+-----+-----+

```
