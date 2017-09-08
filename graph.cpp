
/** Arquitetura de Computadores III - Lesandro Ponciano
  * Trabalho Pratico 1 - Flicker Database
  * Integrantes: Igor Machado Seixas
  *              Joao Castro
  * Linguagem utilizada: C++
  * Recursos: <string> substr (int inicio, int quantidade) - Substring
  *           <string> find (String padrao) - "contains" retorna posicao do padrao se achar, se nao achar returna -1
  *           <string> at (int posicao) - "charAt" retorna o char da posicao passada por parametro
  *           <string> stod (string str) - "parseDouble" retorna o valor double da string em parametro
  */

  // Imports
  #include <iostream>
  #include <list>
  #include <algorithm>
  //#include <string> // Not Used
  using namespace std;

  #define ARRAY_SIZE 200  // Define the length of the study group

  class graph {
   public:
   // Atributes
   list<double>* usergraph; // Vertex wich will cotain user id
   list<double>::iterator it;
   int n;

   /**
     * Graph Construtctor
     * @param double V - Number of Vertex of the graph
     */
     graph ( ) {
      usergraph = new list<double> [ARRAY_SIZE];
      n = 0;
     }

   /**
     * Add Edge to Graph
     * @param u1 - Vertex User
     * @param u1 - User to be added
     */
     void addEdge ( double u1, double u2 ) {
       int pos1, pos2;

       // Verificatins if there is User u1
       pos1 = this->binaryFind(u1);
       if ( pos1 == -1 ) {   // Find and check position of first user
         pos1 = n;  // Update pos1 situation
         this->addVertex(u1);
       }
       // Verificatins if there is User u2
       pos2 = this->binaryFind(u2);
       if ( pos2 == -1 ) { // Find and check position of second user
         pos2 = n; // Update pos2 situation
         this->addVertex(u2);
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
       usergraph[n].push_front(v);
       n++;
     }


   /**
     * Binary Find
     * @param u - User wich will be search
     */
     int binaryFind ( double u ) {
       int left = 0, right = n -1, middle;
       int ans = -1;

       while (left <= right) {
         middle = (left+right) /2;

         if ( u == *usergraph[middle].begin( ) ) {
           ans = middle;
           left = ARRAY_SIZE;
         } else {
           if ( u > *usergraph[middle].begin( ) ) {
             left = middle+1;
           } else {
             right = middle-1;
           }
         }
       } // end while

       return ans;
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
/*
void BFS(double u, double userfriend)
{
    // Mark all the vertices as not visited
    int j = 0;
    int s = sequencialSearch(u);
    bool *visited = new bool[n];
    int  *degree = new int[n];
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
        s = queue.front();
        cout << "Grau do o Vertice: " << u << " para o vertice: " << *usergraph[s].begin( ) << " e' de: " << degree[s] << '\n';
        queue.pop_front( );
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = usergraph[s].begin( ); i != usergraph[s].end( ); ++i)
        {
          j = sequencialSearch(*i);
            if(!visited[j])
            {
                visited[j] = true;
                degree[j] = degree[s]+1;;
                queue.push_back(j);
            }
        }
    }
}
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

  }; // end class graph

int main ()
{
  //////////////////////// TESTING AREA \\\\\\\\\\\\\\\\\\\\\\\

  graph g;

  g.addEdge(1,2);
  g.addEdge(2,3);
  g.addEdge(3,4);
  
  g.printGraph( );
  cout << "Distancia: " << g.BFS(1,4);
  cout << '\n';
  //g.BFS(3);
  cout << '\n';
  //int tmp = g.sequencialSearch(1233);
  //cout << g.n << '\n';

  return 0;
}

// github.com/castrob/ac3_filcker/TODO.txt to task list
