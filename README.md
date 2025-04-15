# Roulette Game in C

A simple command-line roulette game written in C. This game simulates a European-style roulette table, allowing a single user to place bets and try their luck with randomized spins. The game also simulates probability based payouts on the hypothetical bet amount.

## Features

- European roulette wheel (0-36)
- Four types of betting options (E.g. single color, type of number etc.)
- Starting balance and bet tracking
- Console based interface
- Simulation of a spinning wheel, with added physics of loss of momentum with time
- Number of playable rounds constrained only by balance amount

## Getting started 

### Requirements

- GCC or any standard C compiler
- Terminal or command prompt

### Compile and Run

```bash
# Compile
gcc -o roulette roulette.c

# Run
./roulette
