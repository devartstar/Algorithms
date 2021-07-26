## Order of Algorithms

1.  Introduction to Flow Networks, Maximum Flow and Other Terminologies
2.  Ford-Fulkerson Algorithm for comp[utation of max flows
3.  Edmond-Karp Algorithm and its Implementation



## Terminologies

### Network - 
A network is a directed graph G with vertex V and edge E combine with a function C which maps all the edges to some non negative integer(e) which is the capacity of edge.

### Flow Network - 
Additionally in network if we label 2 nodes/vertices as source and sink - its called a flow network
*Source* - all out edges from source
*Sink* - all edges comming insdie sink

### Flow - 
A function F which maps all the edges(say e) to some non-negative intergers (or real numbers) which is called a flow throuch state e.
The function has to full-fill 2 conditions
->  Flow on an edge cannot exceed capacity of the edge F(e)<=C(e)
->  For a;; vertex(except soucr and sink) *inFlow = outFlow*
    Outflow of source == Inflow of sink

####    MaxFlow -> maximum capacity that can flow from the Source to the Sink
