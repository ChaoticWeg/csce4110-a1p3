<h3 align="center">Assignment 1 (Due October 25 2018)</h3>

You are encouraged to work in groups (but not more than 2 persons in a group). Show all your computation to get full credit. Please put comments in your code. I will deduct points for uncommented code. You can write the programs in any language you choose so long as we can run it. This assignment is worth 13% of your total grade.

#### Part 1. Proofs (5 * 3 = 15 points)

Prove the following statements.

1. <img src="http://latex.codecogs.com/gif.latex?\sqrt3" title="\sqrt3" /> is an irrational number
2. If a - b is divisible by c, then <img src="http://latex.codecogs.com/gif.latex?a^n" title="a^n"> - <img src="http://latex.codecogs.com/gif.latex?b^n" title="b^n"> is divisible by c
3. If <img src="http://latex.codecogs.com/gif.latex?2^n" title="2^n"> - 1 is a prime number then n is a prime number

#### Part 2. Complexity Computation (5 * 5 = 25 points)

Compute the big Oh complexity for the following recursion relations.

1. <img src="http://latex.codecogs.com/gif.latex?T(n)&space;=&space;2T(n/4)&space;&plus;&space;\sqrt&space;n" title="T(n) = 2T(n/4) + \sqrt n" />
2. <img src="http://latex.codecogs.com/gif.latex?T(n)&space;=&space;4T(n/2)&space;&plus;&space;n^2&space;\sqrt&space;n" title="T(n) = 4T(n/2) + n^2 \sqrt n" />
3. <img src="http://latex.codecogs.com/gif.latex?T(n)&space;=&space;T(n-1)&space;&plus;&space;1/n" title="T(n) = T(n-1) + 1/n" />
4. <img src="http://latex.codecogs.com/gif.latex?T(n)&space;=&space;\sqrt&space;n&space;\times&space;T(\sqrt&space;n)&space;&plus;&space;n" title="T(n) = \sqrt n \times T(\sqrt n) + n" />
5. <img src="http://latex.codecogs.com/gif.latex?T(n)&space;=&space;3T(n/3&space;&plus;&space;5)&space;&plus;&space;n/2" title="T(n) = 3T(n/3 + 5) + n/2" />

#### Part 3. Multimethod Sorting (35 points)

Create sets of integers with the following characteristics with array sizes of 100,000; 500,000; and 1,000,000 (10).

1. Set where no integer is repeated
2. Set where the range is 1% of the array size and the integers repeat

Compare the performances of the following sorting algorithms. You can either write the algorithms on your own or modify algorithms obtained from elsewhere (15).

Create a table with the rows being the different algorithms and the columns being the inputs. Run each input 10 times and report the mean, and standard deviation for each run. You can also represent the results as a table. Write a short summary (about 1 paragraph) on your observations (10).

1. Quicksort
2. Quicksort until size of set is <= 1,000; 500; 100; 10 and then using insertion sort
3. Countingsort

#### Part 4. Red-Black Trees (35 points)

Consider these two relaxations to the constraints of red-black trees together.

1. The root can be red _or_ black
2. The red nodes can have _at most_ one red child

List the changes to the addition and deletion rules you need to maintain these conditions (10).

Modify existing code (or write your own) of a red-black tree to include these relaxations (9).

Explain either analytically or through empirical results whether the black height will be maintained in all paths (5).

Create a set of 100,000 integers. Insert these integers to (i) the original red-black tree; and (ii) the modified red-black tree. Repeat this step about 6 times with different sets of integers, and report the mean, maximum, and minimum values of the following (4 * 4 = 16).

1. Tree height
2. Black height
3. Time to insert
4. Time to search
