#include "Test.h"
#include <iostream>
#include "Edge.h"

using namespace std;

//Inicializa el arreglo de enteros de dos dimensiones y le mando size que seria size*size
int** inicial(int size){
    int **answer = new int* [size];
    for(int i = 0; i<size; i++){
        answer[i] = new int[size];

            for(int j = 0; j<size; j++){
                answer[i][j] = -1;
              }
           }

        return answer;
}

//Ve si se crea un ciclo al agregar la nueva edge que ya viene ordenada de menor a mayor, y va una de ida y otra de venida
bool checkCycle(int** graph, int destination, int source, int cycleTarget, int size){

	    int currentVertex = destination;
            if(currentVertex == cycleTarget)
                return true;

	    for(int i = 0; i < size; i++){
	        if(i == source || graph[currentVertex][i] == -1)

                continue;

	        bool flag = checkCycle(graph, i, currentVertex, cycleTarget, size);
	        if(flag)
                return flag;
	    }

	    return false;
	}

// Retorna el grafo resultado donde las unicas transacciones son las del camino que sale del grafo

int** getKruskalMST(int** graph, int size, vector<Edge*> edges){

	    int** mst = inicial(size);
	    Edge* currentEdge = edges[0];
	    mst[currentEdge->source][currentEdge->destination] = currentEdge->weight;
	    mst[currentEdge->destination][currentEdge->source] = currentEdge->weight;
                for(int i = 1; i < edges.size(); i++){
                    currentEdge = edges[i];
                        if(!checkCycle(mst, currentEdge->destination, currentEdge->source, currentEdge->source, size)){
                                mst[currentEdge->source][currentEdge->destination] = currentEdge->weight;
                                    mst[currentEdge->destination][currentEdge->source] = currentEdge->weight;
	       }
	    }

	    return mst;
	}



int main ()
{
    test();
    return 0;
}
