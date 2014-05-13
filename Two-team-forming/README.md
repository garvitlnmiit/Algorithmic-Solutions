Two Team Formation With Restrictions
====================================
Harry is now in his 6th year at Hogwarts. He has been made the captain of the Gryffindor Quidditch team by Headmaster 
Dumbledore. Its time for Quidditch practice. So all players must be divided into two teams for practice sessions. 
Now the problem that he faces before selecting the team is that some players don't feel comfortable playing on the 
same team as some other players. Harry knows about these restrictions that he has while forming the teams. He wonders 
if he can make two teams taking into account these restrictions and further how many different teams he can make. But 
since Harry has detention from Professor Snape, he leaves the task to you.

Calculate the total number of different possible team distributions for Harry. Output the answer modulo (10^9)+7.

Note
----
The two teams must not necessarily have equal number of players i.e. there can be 3 players on one team and only 
1 player on other team. But there has to be atleast one player in each team.

Input
-----
The first line of each test file contains a single integer T. Then T test cases follow. Each line contains two integers 
N - the number of players and M - the number of different restrictions that Harry must take care of. The next M line 
each contain two integers A and B, which indicate that player A would not like to play with player B and vice versa.

Output
------
For each test case output the number of different possible team formations modulo (10^9)+7. If no such formation 
is possible, output "NOT POSSIBLE" (quotes for clarity only). Each output must be followed by a newline.

Constraints
-----------
1<= T <=100

2<= N <= 10^4

0<= M <= 10^5

0<= A,B <=N-1
