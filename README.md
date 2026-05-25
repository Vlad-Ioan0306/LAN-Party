# LAN Party

## DESCRIPTION
* This program simulates a LAN tournament where multiple teams participate.

### Phase 1: Team Filtering.

* The LAN Party program looks at all the teams.
* It checks each players score. Calculates the score for each team.
* Then it removes teams with scores until there are only teams that can fit into a bracket.


### Phase 2: Knockout Simulation.

* Teams are paired up and play against each other.
* The winning team moves on to the next round.
* The losing team is out of the tournament.
* Repeats this until only 1 team remains.
* The LAN Party program keeps track of the teams.


### Phase 3: Elite Rankings.

* The top eight teams are put into a list sorted by their score.
* If two teams have the same score they are sorted by their name.
* The LAN Party program then prints out the rankings.


## USAGE

### COMPILE
* You do this by typing the following inside the terminal:
`gcc -Wall solve.c solve1.c solve2.c solve3.c -o lanParty`

### RUN
* Then you can run it by typing this in the terminal:
`./lanParty c.in d.in r.out`


#### DESCRIPTION OF FILES

* `c.in` tells the LAN Party program which part of the tournament to run.

* `d.in` has a list of teams their players and their starting scores.

* `r.out` shows you the results.


## IMPROVEMENTS TO BE MADE

* The current program works, but it has room for improvement in areas like: stability, resource management and reliability.

### Memory management
* Allocation verification: currently doesn't check for malloc errors
* Resource deallocation: currently it doesn't free everything using strict cleanup routines

### Reliability
* Input validation: it doesn't guard against malformed data, duplicate entries or unexpected inputs since it needs a specific format inside the input file
* Data persistence: has no way of recording progress if stopped/impeded in the process

### Scalability
* Dynamic scaling: it doesn't use dynamic allocation, only fixed size
