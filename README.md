[![Say Thanks!](https://img.shields.io/badge/Say%20Thanks-!-1EAEDB.svg)](https://saythanks.io/to/alphaWizard)
[![Help Contribute to Open Source](https://www.codetriage.com/alphawizard/8-sliding-puzzle-solver/badges/users.svg)](https://www.codetriage.com/alphawizard/8-sliding-puzzle-solver)

# 8-sliding-puzzle-solver
Solves the famous sliding puzzle  https://en.wikipedia.org/wiki/Sliding_puzzle by taking input of 3x3 matrix, and returning the optimal sequence of moves until destination.

salient features regarding the implementation:

1. Implementation utilises the A* search algorithm with respect to the heuristic on manhattan distance between the states.
2. Repetition of states were avoided by maintaining a boolean vector of states (in this case a map).
3. State of the game is represented by two parameters being paired i.e.,the 3x3 matrix and the no. of moves done till that state.
4. Feasibility of solution is ensured by making sure that the inversion count in the initial matrix is even because the destination state has zero inversion count and no sequence of moves changes the parity of inversion count.
5. The implementation can easily be modified to solve any square box sliding puzzle.



  
