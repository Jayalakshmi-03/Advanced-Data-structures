#include<bits/stdc++.h>
using namespace std;
class graph
{
   int v;
   list<int> *adjacencylist;
   bool checkcycle2(int v, bool vertvisited[], int parentnode);
public:
    graph(int v);
    void drawedge(int v, int u);
    bool checkcycle();
};
graph::graph(int v)
{
    this->v=v;
    adjacencylist= new list<int>[v];
}
void graph::drawedge(int v, int u)
{
    adjacencylist[v].push_back(u);
    adjacencylist[u].push_back(v);
}
bool graph::checkcycle2(int v, bool vertvisited[], int parentnode)
{
    vertvisited[v]=true;
    list<int>::iterator itr;

for(itr=adjacencylist[v].begin();itr!=adjacencylist[v].end();++itr)
    {
     if (!vertvisited[*itr])
        {
         if(checkcycle2(*itr, vertvisited, v))
            {
                return true;
            }
         }
else if (*itr != parentnode){
         return true;}
         }
return false;
}
bool graph::checkcycle()

{
bool *vertvisited=new bool[v];
for(int i=0;i<v;i++)
    {
        vertvisited[i]=false;
    }
for(int i=0;i<v;i++)
{
if(!vertvisited[i])
{
if(checkcycle2(i, vertvisited, -1))
{
return true;
}
}
}
return false;
}
int main()
{
graph g(6);
g.drawedge(0, 1);
g.drawedge(1, 5);
g.drawedge(5, 4);
g.drawedge(4, 0);
g.drawedge(4, 3);
g.drawedge(3, 2);
g.drawedge(0, 2);
if(g.checkcycle())
cout << "Graph is cyclic";
else
cout << "Graph is acyclic";
return 0;
}
