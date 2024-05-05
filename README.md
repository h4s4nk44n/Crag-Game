# Crag-Game

Crag is a dice game, that is played with three dice. You will write a program for playing a Crag game
between a player and a computer.At the beginning to decide who is going to start the game, each player rolls one die.
The player who rolls the highest die starts the game. The game consists of N rounds – each player will play N turns.
The game is played with 3 dice. The first player rolls all three dice to start his/her turn. Players take turns rolling
three dice and assign them to certain combinations according to the scoring table given below. After
throwing the dice, a player may choose to reroll any number of those dice. This second roll is final. The
player doesn’t have to use all two throws and may stop after the first. The scoring categories have
varying point values, some of which are fixed values and others where the score depends on the value of
the dice. The winner is the player who scores the most points.

|    Category    |                  Description                      |     Score    |     Example      |
|  :---          | :---                                              |     :---:    |     :---:        |
| Crag           | combination that contain a pair and totalling 13  |  50          | Dice shows: 6-6-1|
| Thirteen       | Any combination totalling 13                      |  26          | Dice shows: 3-4-6|
| Three-Of-A-Kind| Three dice showing the same face                  |  25          | Dice shows: 4-4-4|
| Low Straight   | 1-2-3                                             |  20          | Dice shows: 1-2-3|
| High Straight  | 4-5-6                                             |  20          | Dice shows: 4-5-6|
| Odd Straight   | 1-3-5                                             |  20          | Dice shows: 1-3-5|
| Even Straight  | 2-4-6                                             |  20          | Dice shows: 2-4-6|
| Sum            | Sum of any other combination                      |  20          | Dice shows: 3-2-6|

