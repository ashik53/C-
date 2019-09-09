#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
vector<int>adjList[507];
int edges, nodes;
int costArray[507][507];
int inf = 10000097;
int mainDistance[507];
vector<int>stationList;
int stationChecker[507];

int dijkstraFinal(int source) ;
void dijkstraInitial(int source);
class Node {
public:
	int source, cost;
	Node(int node, int cost) {
		this->source = node;
		this->cost = cost;
	}
	bool operator<(const Node x) const {
		return cost > x.cost;
	}
};
int main()
{

    int cases,line = 0;
    scanf("%d",&cases);
    while(line<cases){
    if(line!=0) printf("\n");
	int source, destination, cost,stations;
	priority_queue<Node>nodeList;
	fill_n(mainDistance,507,inf);
	stationList.clear();

	memset(stationChecker,0,sizeof(stationChecker));
	//puts("Enter total number of edges:");
	scanf("%d%d",&stations ,&edges);
	//puts("Enter edges");
    for(int i=0;i<stations;i++){
        scanf("%d",&source);
        stationChecker[source] = 1;
        stationList.push_back(source) ;
    }
	for (int i = 0; i < edges; i++) {
		scanf("%d%d%d", &source, &destination, &cost);
		adjList[source].push_back(destination);
		adjList[destination].push_back(source);
		costArray[source][destination] = cost;
		costArray[destination][source] = cost;
	}

	for(int i=0;i<stations;i++){
        dijkstraInitial(stationList[i]);
	}

    //final
	for(int i=1;i<=edges;i++){
        if(stationChecker[i]==0) {
          stationChecker[i]= 1;
          int mx = dijkstraFinal(i);
          nodeList.push(Node{i,mx});
          stationChecker[i]= 0;
          //cout<< "node :"<<i <<"->"<<mx <<endl;
        }//if
	}//for

	printf("%d\n",nodeList.top().source);
	line++;
    }
}

void dijkstraInitial(int source) {
	priority_queue<Node>nodeList;
    int distance[507];

	fill_n(distance,507,inf);

	distance[source] = 0;

	nodeList.push({source,distance[source]});

	while (!nodeList.empty()) {
		Node node = nodeList.top();
		nodeList.pop();
		int currentNode = node.source;
		if(stationChecker[currentNode]==0) {
          mainDistance[currentNode] = min(distance[currentNode],mainDistance[currentNode]);
		}
       // cout<<"currentNode: "<<currentNode<<endl;
        int sz = adjList[currentNode].size();
		for (int i = 0; i < sz; i++) {
			int neighbourNode = adjList[currentNode][i];
			//cout<<"neighbour node: "<<neighbourNode<<", pathCostToTheNeighbour: -> "
			int pathCostToNeighbour = costArray[neighbourNode][currentNode];
			//cout<<pathCostToTheNeighbour<<endl;
			if (distance[neighbourNode] > distance[currentNode]+ pathCostToNeighbour) {
				distance[neighbourNode] = distance[currentNode]+ pathCostToNeighbour;
				nodeList.push(Node{neighbourNode,distance[neighbourNode] });
				//cout<<"neighbour node "<<neighbourNode<< " "<<
			}

		} // for
	}//main loop




}
int dijkstraFinal(int source) {

	priority_queue<Node>nodeList;
    int distance[507],duplicateDistance[507];
	fill_n(distance,507,inf);
	distance[source] = 0;
    int mx = -10;
	nodeList.push({source,distance[source]});
    int len = sizeof(mainDistance)/sizeof(*mainDistance);
    memcpy(duplicateDistance,mainDistance,len*(sizeof(int)));




	while (!nodeList.empty()) {
		Node node = nodeList.top();
		nodeList.pop();
		int currentNode = node.source;
		if(stationChecker[currentNode]==0) {
          duplicateDistance[currentNode] = min(distance[currentNode],duplicateDistance[currentNode]);
          mx = max(mx,duplicateDistance[currentNode]);
		}
       // cout<<"currentNode: "<<currentNode<<endl;
        int sz = adjList[currentNode].size();
		for (int i = 0; i < sz; i++) {
			int neighbourNode = adjList[currentNode][i];
			//cout<<"neighbour node: "<<neighbourNode<<", pathCostToTheNeighbour: -> "
			int pathCostToNeighbour = costArray[neighbourNode][currentNode];
			//cout<<pathCostToTheNeighbour<<endl;
			if (distance[neighbourNode] > distance[currentNode]+ pathCostToNeighbour) {
				distance[neighbourNode] = distance[currentNode]+ pathCostToNeighbour;
				nodeList.push(Node{neighbourNode,distance[neighbourNode] });
				//cout<<"neighbour node "<<neighbourNode<< " "<<
			}

		} // for
	}//main loop

    return mx;


}

