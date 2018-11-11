# Nash_equilibrium_calculator
Compute how many and which Nash equilibria a given game has.

## About Nash equilibria
The Nash equilibrium is an important concept in game theory. It describes states in which each player in the game cannot improve his payout by choosing a different strategy.
Depending on the game there can be zero, one or more than one Nash equilibria.
For instantanous games, where each player knows the action of his opponent only after choosing his own strategy (i.e. course of action) this can be easily computed by putting the game in to the so-called normal-form and checking for each player which strategy yields the highest output for a given strategy of the opposing player.
A combination of strategies for which both players receive the highest output is called a Nash equilibrium.
Let's see this at work in the following famous prisoners dilemma.

### The prisoners dilemma
Let's assume two thieves are catched. However, the evidences are not convincing enough, so the police needs at least one of the thieves to confess. They decide to cross-examinate them. 
Both thieves are now confronted with the following courses of action (strategies):
They can either confess or remain silent. 
If both remain silent, the police has too few evidence to jail them for longer than 2 years. If one of them confesses, however, the confessing one will free while the silent one will be jailed for 12 years. If both of them confess they will both go to jail for 8 years.

In normal form this would now look like this:

|Player 1/Player 2| hush | confess|
|-----------------|------|--------|
|**hush**             | 2/2  | 12/0   |
|**confess**          | 0/12 | 8/8    |

The first number gives the payout for player 1, the second for player 2. If we now check for the strategy with the highest payout for a given strategy of the opposing player we see that each time confessing is the better choice. This leads to them both confessing, which is the only Nash equilibrium in this game.

## About the program
Compile the program, which using Unixoid systems you can do by typing the following commands in your shell:
```
$ g++ -c nash_equilibrium.cc
$ g++ -o nash_equilibrium nash_equilibrium.o
```

Afterwards you can run the program using 
```
$ ./nash_equilibrium
```
First the program will ask you if you want the game to maximize or minimize the payout. In the above game of course you would like to minimze the payout (jail time). However, there are many games where one would want to do the opposite. 
Then you can specify the number of strategies, which each player has and give them a name.
In the following you need to give a payout for each strategy of the player given the strategy of the opposing player. If you choose a non-symmetric game you need to do this twice, once for player 1 and once for player 2.
After all the inputs have been given the program will look for Nash equilibria and print them out. Finally it will display the number of Nash equilibria it has found.

### Notes
This program was only tested on the prisoners dilemma. While it should work with arbitrary two-player instantanous games this has not been tested. 
Also the program only calculates pure Nash equlibria. Mixed Nash equilibria, where choosing each a strategy with a certain probability leads to a Nash equilibrium, are not implemented (yet).
