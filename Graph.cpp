/*
 *
 * Copyright (C) 2022 Sujit Das
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; if not, see <http://www.gnu.org/licenses/>.
 */
 
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph{
public:
    vector<list<int>> adjacentList;
    int noOfVertices;

    Graph(int v){
        adjacentList.resize(v);
        noOfVertices=v;
    }

    void addEdge(int u,int v,bool bi){
        adjacentList[u].push_back(v);
        if(bi){
            adjacentList[v].push_back(u);
        }
    }

    void print(){
        for(int i=0;i<noOfVertices;i++){
            cout<<i<<"-->";
            for(auto it:adjacentList[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    // DFS traversal of the vertices reachable from v
    // It returns a list of resultant vertices
    list<int> DFS(int v)
    {
        static vector<bool> visited(noOfVertices, false);
        static list<int> dfs;

        visited[v] = true;
        dfs.push_back(v);
        for(auto it:adjacentList[v])
        {
            if(visited[it] == false)
                DFS(it);
        }
        return dfs;
    }
    
    // BFS traversal of the vertices
    // from a given source v
    list<int> BFS(int v)
    {
        list<int> bfs;
        vector<bool> visited(noOfVertices, false);
        list<int> vertices;

        visited[v] = true;
        vertices.push_back(v);
        while(!vertices.empty())
        {
            auto vertice = vertices.front();
            bfs.push_back(vertice);
            vertices.pop_front();
            for(auto it:adjacentList[vertice])
            {
                if(visited[it] == false)
                {
                    visited[it] = true;
                    vertices.push_back(it);                
                }
            }   
        }
        return bfs;
    }
};

int main()
{
    // Graph initialization
    Graph g(4);
    g.addEdge(0,1,true);
    g.addEdge(3,1,true);
    g.addEdge(0,2,true);
    g.addEdge(3,2,true);
    g.addEdge(0,3,true);

    cout << "Printing adjacency matrix" << endl;
    g.print();

    list<int> dfs_local = g.DFS(2);
    cout << "Printing DFS travelsal flow" << endl;
    for(auto it:dfs_local)
    {
        cout << it << " ";
    }

    list<int> bfs_local = g.BFS(2);
    cout << endl << "Printing BFS travelsal flow" << endl;
    for(auto it:bfs_local)
    {
        cout << it << " ";
    }
}



