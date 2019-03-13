The knight Tour problem is a very common problem among the enthusiastic of chess. For this assignment, we were asked to solve the knight tour problem using both the Warnsdorf heuristic algorithm and backtracking in order to find a new path when the knight get stuck at a location with no issue. The knight tour problem consists of finding a way to make a knight visit all the squares on a chess board. Knowing that in our case we were asked to use both methods to solve the problem, we decided to use the divide and conquer method to come up with vital solution for the Knight tour problem. First, we divided the project into two sperate pieces. In the first Part, we tried to implement Warnsdoff heuristic algorithm that say always move the knight to an adjacent, unvisited square with minimal degree. Warnsdoff heuristic algorithm is described as follow:
Starting from any square, the knight must move to an unvisited square that has the fewest successive moves. Choosing a square with the fewest successors avoids a possible dead-end when traversing the board. However, because Warnsdorff’s rule is heuristic, it is not guaranteed to find a solution. Fortunately, the proposed SAS solution determines a complete path beginning from any square – Well, almost. Although there are numerous solutions for a given starting point, this solution attempts to generate sixty-four paths on a standard 8x8 chess board, one for each starting position.
Rather than show the knight’s tour as a directional path, it is more expedient to display the ordinal, numerical sequence on the chess board, which more easily indicates the knight’s moves. In the example below, the tour begins in the upper-right corner of the board and ends nearby, just one move away.


Implementation of Warnsdoff Heuristic’s Algorithm
To realize the implementation of Warnsdoff heuristic algorithm, we used two functions denoted:
These two functions interact with each other to fulfil the requirement of the Heuristic Algorithm by Warnsdoff by returning the next location with the fewest moves. First, our current location which we chose to implement as a structure like the following 
is passed into next_location_generator from then, an array of next location   
will be generated. While each element of the array of element containing this various calculation (x − 2,y + 1),(x−1,y +2),(x+1,y +2),(x+2,y +1),(x+2,y −1),(x+1,y −2),(x−1,y −2),(x−2,y −1) is being generated, the generated element is going to get passed into the function called number_of_next_location_Generator. The function named number_of_next_location_Generator is used to generate the number of next possible locations that the location that we passed in the function has. Right after this process is done, we are storing the number of next locations that each next location generated from the present location in an array and returning the index of the element with the least next move. We will then take that index and return the element form the array of next locations that has the same index as our next location to move to (The one with the fewest next move). This process will be repeated until the stack that contains our visited locations   size’s reaches 32. For our implementation of the heuristic algorithm of Warnsdoff if we choose two inputs such as (0,0) and (3,5), we will obtain the following outputs:
The main point that the heuristic algorithm raised is that the next location that the knight is going to go to has its coordinate close to the edge of the chess board.

In the second part of the project, we use our own implementation of how we wanted to move from one location to another. Using our own implementation, we have gotten to some position where there was no way out. Therefore, we had to use backtracking algorithm to find a new path. Backtracking algorithm is described as the following by Wikipedia:
The backtracking algorithm enumerates a set of partial candidates that, in principle, could be completed in various ways to give all the possible solutions to the given problem. The completion is done incrementally, by a sequence of candidate extension step. Conceptually, the partial candidates are represented as the nodes of a tree structure, the potential search tree. Each partial candidate is the parent of the candidates that differ from it by a single extension step; the leaves of the tree are the partial candidates that cannot be extended any further. The backtracking algorithm traverses this search tree recursively, from the root down, in depth first search. At each node c, the algorithm checks whether c can be completed to a valid solution. If it cannot, the whole sub-tree rooted at c is skipped (pruned). Otherwise, the algorithm (1) checks whether c itself is a valid solution, and if so, reports it to the user; and (2) recursively enumerates all sub-trees of c. The two tests and the children of each node are defined by user-given procedures. Therefore, the actual search tree that is traversed by the algorithm is only a part of the potential tree. The total cost of the algorithm is the number of nodes of the actual tree times the cost of obtaining and processing each node. This fact should be considered when choosing the potential search tree and implementing the pruning test.

Implementation of Backtracking Algorithm
	Before we get stuck at a location a start backtracking, the following is our way of finding the next location our knight. To move our knight, we are a function that we have named:
This function will be returning a stack of next possible location that can be visited by the knight from its present location. After the generation of that stack, it will be pushed into  .nextstack is a stack of stack that will be used to store the stack containing the location generated. Every time the stack of next location is generated and it not an empty stack, the program will choose the top of the stack to be the next location that the knight will visit. After that location is chosen, it will be deleted from the stack before being push into nextstack. Whenever a current location generates an empty stack when passed into the next_loaction_Generator_for_backtracking function, it means the knight is stuck at that specific location thus we will start backtracking by using the stack of stack that we implemented. 
After a full run of the code we get the following:
Example of a run: for (0,0)

This is the list of the running time of all the squares located on the chessboard:
(0,0)seconds		(1,0)seconds		(2,0)seconds	        (3,0)seconds
(0,1)seconds		(1,1)seconds		(2,1)hour		(3,1)seconds
(0,2)hour		(1,2)seconds		(2,2)seconds		(3,2)seconds
(0,3)seconds		(1,3)seconds		(2,3)seconds		(3,3)seconds
(0,4)seconds		(1,4)seconds		(2,4)seconds		(3,4)seconds
(0,5)seconds		(1,5)hour		(2,5)hour		(3,5)minutes
(0,6)seconds		(1,6)seconds		(2,6)seconds		(3,6)seconds
(0,7)seconds		(1,7)seconds		(2,7)seconds		(3,7)seconds

(4,0)seconds		(5,0)seconds		(6,0)seconds	        (7,0)seconds
(4,1)seconds		(5,1)seconds		(6,1)10mins		(7,1)seconds
(4,2)seconds		(5,2)seconds		(6,2)seconds		(7,2)seconds
(4,3)seconds		(5,3)seconds		(6,3)seconds		(7,3)seconds
(4,4)hour		(5,4)seconds		(6,4)seconds		(7,4)minutes
(4,5)seconds		(5,5)seconds		(6,5)45 mins 		(7,5)minutes
(4,6)seconds		(5,6)hour		(6,6)10mins		(7,6)seconds
(4,7)seconds		(5,7)seconds		(6,7)seconds		(7,7)seconds
