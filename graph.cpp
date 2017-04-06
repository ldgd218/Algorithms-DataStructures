#include<iostream>
#include<list>
#include<queue>
using namespace std;


class Graph{
	
	int V;
	int E;
	list<int> *adjList;
	
	public:
	Graph(int vertices){
		V = vertices;
		adjList = new list<int>[V];
		E = 0;
	}
	void addEdge(int u,int v,bool bidirectional=true){
		if(bidirectional==true){
			adjList[u].push_back(v);
			adjList[v].push_back(u);
			E = E + 2;
		}
		else{
			adjList[u].push_back(v);
			E = E + 1;
		}
	
	}

	void BFSPrint(){
		
		bool *visited = new bool[V];
		for(int i=0;i<V;i++){
			visited[i] = false;
		}
		queue<int> q;
		
		q.push(0);
		visited[0] = true;
		
		while(!q.empty()){
			int f = q.front();
			q.pop();
			cout<< f <<" ";
			//Iterate over the children of f and push them if they are not visited.
			for(auto i= adjList[f].begin();i!=adjList[f].end();i++){
				if(visited[*i]==false){
						q.push(*i);
						visited[*i] = true;
				}
			}
		}
	}
	int  shortestPath(int src,int dest){
	//Print shortest distance array for all nodes
	int *dist = new int[V];
	int *parent = new int[V];


	for(int i=0;i<V;i++){
			dist[i] = -1;
			parent[i] = -1;
	}
	queue<int> q;

	dist[src] = 0;
	q.push(src);

	while(!q.empty()){
		int f = q.front();
		q.pop();
		for(auto it = adjList[f].begin();it!=adjList[f].end();it++)			{ 
			if(dist[*it]==-1){
				parent[*it] = f;
				dist[*it] = dist[f] + 1;
				q.push(*it);
			
				}
			}
		}
		//Print our Path.
		int i=dest;
		while(i!=-1){
			cout<< i <<"<--";
			i = parent[i];
		}
		cout<<endl;

		return dist[dest];
		/*
	//Print our array
	for(int i=0;i<V;i++){
		cout<<"Distance of node "<<i<<" is "<<dist[i]<<endl;
		}
	*/
	}
	void DFSHelper(int index,bool *visited){
		
		cout<< index <<" ";
		visited[index] = true;
		
		for(auto i = adjList[index].begin();i!=adjList[index].end();i++){
			if(visited[*i]==false){
				DFSHelper(*i,visited);
			}
		}
	}
	void DFSPrint(){
		bool *visited = new bool[V];
		for(int i=0;i<V;i++){
			visited[i] = false;
		}
		//Make Some changes Graph is Connected OR Not.
		DFSHelper(0,visited);

	}

	bool isConnected(){
		bool *visited = new bool[V];
		for(int i=0;i<V;i++){
			visited[i] = false;
		}
		//Make Some changes Graph is Connected OR Not.
		DFSHelper(0,visited);

		for(int i=0;i<V;i++){
				if(visited[i]==false){
					return false;
				}
		}
		return true;
	}
	void printConnected(){
		bool *visited = new bool[V];
		for(int i=0;i<V;i++){
			visited[i] = false;
		}
		
		int component = 0;

		for(int i=0;i<V;i++){
				if(visited[i]==false){
				component++;
				cout<<"Component "<<component<<" : ";
				DFSHelper(i,visited);	
				cout<<endl;
				}
		}
	}
	void TopologicalSort(){
			int *indegree = new int[V];
			for(int i=0;i<V;i++){
				indegree[i] = 0;
			}
			//Create the indegree array
			for(int i=0;i<V;i++){
				for(auto j=adjList[i].begin();j!=adjList[i].end();j++)
				{   indegree[*j]++; 
				}		
			}

			queue<int> q;
			//Find the nodes with 0 indegree
			for(int i=0;i<V;i++){
				if(indegree[i]==0){
					q.push(i);
				}
			}

			//Empty the queue.
			while(!q.empty()){
				int task = q.front();
				cout<<task<<" ";
				q.pop();

				for(auto it = adjList[task].begin();it!=adjList[task].end();it++){
					indegree[*it]--;
					if(indegree[*it]==0){
						q.push(*it);
					}
				}

			}


	}
};


int main(){

Graph g(9);
g.addEdge(0,5,false);
g.addEdge(1,2,false);
g.addEdge(1,3,false);
g.addEdge(2,4,false);
g.addEdge(3,4,false);
g.addEdge(3,8,false);
g.addEdge(4,7,false);
g.addEdge(5,6,false);
g.addEdge(6,7,false);

//g.printConnected();
g.TopologicalSort();
/*
if(g.isConnected()==true){
	cout<<"Graph is Connected !";
}
else{
	cout<<"Graph is not Connected !";
}
*/
return 0;
}
