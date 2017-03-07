#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define NMAX 10005
#define INTMAX 0x7fffffff
struct Node{
	int v;
	int cost;
	Node(int vv = 0,int c = 0){
		v = vv;
		cost =  c;
	}
	//重载 
	friend bool operator<(Node n1,Node n2){
		return n1.cost>n2.cost;
	} 
}; 
//edge表示边的另外一端 
struct Edge{
	int v;
	int cost;
	Edge(int vv=0,int c=0){
		v = vv;
		cost = c;
	} 
};

vector<Edge> G[NMAX];//图
bool marked[NMAX];
int disto[NMAX]; //出发点到某点的距离
int costo[NMAX]; //接通该点需要增加的边的权重

int N,M;

void dijkstra(int s){
	for(int i=0;i<=N;i++){
		costo[i] = disto[i] = INTMAX;
		marked[i] = false;
	}
	
	disto[s] = 0;
	costo[s] = 0;
	priority_queue<Node> pq;
	pq.push(Node(s,0));
	marked[0] = true;
	Node tmp;
	while(!pq.empty()){
		tmp = pq.top();
		pq.pop();
		int v = tmp.v;
		if(!marked[v]){
			marked[v] = true;
			int len = G[v].size();
			for(int i=0;i<len;i++)
			{
				int vv = G[v][i].v;
				if(marked[vv])
					continue;
				int cost = G[v][i].cost;
				
				int newdist = disto[v]+cost;
				if(disto[vv]>newdist){
					disto[vv] = newdist;
					costo[vv] = cost;
					pq.push(Node(vv,disto[vv]));
				}
				
				//增加的内容
				if(disto[vv] == newdist){
					costo[vv] = min(costo[vv],cost);
				} 
				
			}
		}
	}
	
} 

int main()
{
	cin>>N>>M;
	int s,e,c;
	for(int i=0;i<M;i++)
	{
		cin>>s>>e>>c;
		G[s].push_back(Edge(e,c));
		G[e].push_back(Edge(s,c));
	}
	
	dijkstra(1);
	
	int res = 0;
	
	for(int i =2;i<=N;i++)
	{
		res+=costo[i];
	}
	
	cout<<res<<endl;

 } 
