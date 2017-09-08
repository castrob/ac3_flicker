
/** Arquitetura de Computadores III - Lesandro Ponciano
  * Trabalho Pratico 1 - Flicker Database
  * Integrantes: Igor Machado Seixas
  *              Joao Castro
  *              Paulo Junio
  * Linguagem utilizada: C++
  * Recursos: <string> substr (int inicio, int quantidade) - Substring
  *           <string> find (String padrao) - "contains" retorna posicao do padrao se achar, se nao achar returna -1
  *           <string> at (int posicao) - "charAt" retorna o char da posicao passada por parametro
  *           <string> stod (string str) - "parseDouble" retorna o valor double da string em parametro
  */

  // Imports
  #include <iostream>
  #include <list>
  #include "omp.h"
  #include <algorithm>
  //#include <string> // Not Used
  using namespace std;

  #define ARRAY_SIZE 3000000  // Define the length of the study group

  class graph {
   public:
   // Atributes
   int levelZero;
   int levelOne;
   int levelTwo;
   int levelThree;
   int levelFour;

   list<double>* usergraph; // Vertex which will cotain user id
   list<double>::iterator it;
   int n;

   /**
     * Graph Construtctor
     * @param double V - Number of Vertex of the graph
     */
     graph ( ) {
      usergraph = new list<double> [ARRAY_SIZE];
      n = 0;
      levelZero = 0;
      levelFour = 0;
      levelTwo = 0;
      levelThree = 0;
      levelOne = 0;
     }

   /**
     * Add Edge to Graph
     * @param u1 - Vertex User
     * @param u1 - User to be added
     */
     void addEdge ( double u1, double u2 ) {
       int pos1, pos2;

       // Verificating if there is User u1
       pos1 = sequencialSearch(u1);
       if ( pos1 == -1 ) {   // Find and check position of first user
         pos1 = n;  // Update pos1 situation
         addVertex(u1);
       }
       // Verificating if there is User u2
       pos2 = sequencialSearch(u2);
       if ( pos2 == -1 ) { // Find and check position of second user
         pos2 = n; // Update pos2 situation
         addVertex(u2);
       }
       // Create Edge between User u1 and User u2
       usergraph[pos1].push_back(u2);
       usergraph[pos2].push_back(u1);

       //it = find(usergraph[0].begin( ), usergraph[0].end( ), 2 );
     }

   /**
     * Add Vertex to Graph
     * @param v - Vertex to be added
     */
     void addVertex (double v) {
      int pos;
      pos = sequencialSearch(v);
       if (pos == -1){
       usergraph[n].push_front(v);
       n++;
      }
     }

    /**
      * Sequencial Search
      * @param u - user which will be search
      */

     int sequencialSearch(double u){
      int answer = -1;
      for(int i = 0; i < n; i++){
        if( u == *usergraph[i].begin()){
          answer = i;
          i = n;
        }
      }
      return answer;
     }


   /**
     * Print Graph
     */
     void printGraph ( ) {
       for ( int i = 0; i < n; i++) {
         for ( list<double>::iterator j = usergraph[i].begin( ); j != usergraph[i].end( ); j++ ) {
           cout << *j << ' ';
         }

         cout << '\n';
       } // end for
     }
  
    /**
      * Breadth first search  to find faved levels
      * @param double u - Photo owner
      * @param double userfriend - person who faved
      * return int - level of like
      */

    int BFS(double u, double userfriend)
    {
      // Mark all the vertices as not visited
      int j = 0;
      int s = sequencialSearch(u);
      bool *visited = new bool[n];
      int  *degree = new int[n];
      int  foundDegree = 999999;
      for(int i = 0; i < n; i++) {
          visited[i] = false;
          degree[i] = 99999;
        
      } // end for
 
      // Create a queue for BFS
      list<int> queue;
 
      // Mark the current node as visited and enqueue it
      visited[s] = true;
      degree[s] = -1;
      queue.push_back(s);
 
      // 'i' will be used to get all adjacent vertices of a vertex
      list<double>::iterator i;
 
      while(!queue.empty( ))
      {
        // Dequeue a vertex from queue and print it
        s = queue.front( );
        //cout << "Grau do o Vertice: " << u << " para o vertice: " << *usergraph[s].begin( ) << " e' de: " << degree[s] << '\n';
        if ( *usergraph[s].begin( ) == userfriend ) {
          //cout << "Grau do o Vertice: " << u << " para o vertice: " << *usergraph[s].begin( ) << " e' de: " << degree[s] << '\n';
          foundDegree = degree[s];
          queue.clear( );
        } else {
          queue.pop_front( );
 
          // Get all adjacent vertices of the dequeued vertex s
          // If a adjacent has not been visited, then mark it visited
          // and enqueue it
          i = usergraph[s].begin( );
          advance(i, 1);
          for(; i != usergraph[s].end( ); ++i)
          {

           j = sequencialSearch(*i);
              if(!visited[j])
              {
                  visited[j] = true;
                  degree[j] = degree[s]+1;;
                  queue.push_back(j);
              }
          } // end for
        
        } // end else
      }
      return foundDegree;
     } // end BFS


     /**
       * This function is called to add a faved level to graph
       * @param int l - faved level
       */

      void addLevel(int l){
        if(l == 0){
          levelZero++;
        }else if (l == 1){
          levelOne++;
        }else if(l == 2){
          levelTwo++;
        }else if(l == 3){
          levelThree++;
        }else if(l == 4){
          levelFour++;
        }
      }
     
/**/    
    }; // end class graph

  //   //////////////////////// TESTING AREA \\\\\\\\\\\\\\\\\\\\\\
  // int main ()
// {
  
  //   graph g;
  
  //   g.addEdge(1,2);
//   g.addEdge(1,123.312);
//   g.addEdge(1,4);
//   g.addEdge(33.33,212);
//   g.addEdge(32,2);
//   g.addEdge(32,1);
//   g.addEdge(32,123123);
//   g.addEdge(1,20);

//   g.printGraph( );

//   return 0;
// }

// github.com/castrob/ac3_filcker/TODO.txt to task list
