
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
  #include "graph.h"
  //#include <string> // Not Used
  using namespace std;

  /**
    * This function is called to split the string line at each occurence of certain character
    * @param string str - the input line to be splitted
    * @param char c - the paramether to split the string
    * @return returns an array of string
    * Complexity O(n)
    */
  string* split(string str, char c){
    // Initializing the array with 4 slots
    string* answer = new string[4];
    int pos=0;
    for(int i = 0; i < str.size(); i++){
      if(str.at(i) != c){
        answer[pos] = answer[pos] + str.at(i);
      }else{
        pos++;
      }
    }
    return answer;
  }

  /**
    * this Function is called to clear the userId String to remove @N characters and convert it to double
    * @param String str - String with userId to be converted
    * @return double - double value of userId.
    * Complexity O(n)
    */
  double clearUserID(string str){
    string tmp;
    for(int i = 0; i < str.size(); i++){
      if (str.at(i) != '@' && str.at(i) != 'N')
        tmp = tmp + str.at(i);
    }
    return stod(tmp);
  }


 

int main ()
{
  //////////////////////// TESTING AREA \\\\\\\\\\\\\\\\\\\\\\

    // Default occurence of strings

  //std::string base="10000137@N04,10231841@N06,0,0";         //CASO 0
  //std::string base="99997777@N00,6879369765,1,1329283214";    //CASO 1
  // string base="10000126@N02,4074743559,2,1324475489";  //CASO 2


    // Testing Split Function \\

  // string* teste = split(base, ',');
  // cout << clearUserID (teste[0]) <<'\n'
       // << teste[1] <<'\n'
       // << teste[2] <<'\n'
       // << teste[3] <<'\n';

    //////////////////////// END OF TESTING AREA \\\\\\\\\\\\\\\\\\\\\\
  
  // Declaring elements
  graph g;
  string str;  // Declaring str as base string
  string* input; // Declaring the String Array
  string::size_type sz; // alias for size_t
  double userIdA; // Change from String to Int
  double userIdB; // Change from String to Int
  double photoId; // Change from String to Int
  double timeStamp; // Change from String to Int

 
  getline (cin, str);
  while(!str.empty()){
    // Split the str String
    input = split(str, ',');
      // input[0] - userId (ALWAYS)
      // input[1] - userId/PhotoId
      // input[2] - Event (ALWAYS)
      // input[3] - timeStamp (ALWAYS)

    // Event 0 - (Friendship)
    if ( input[2].at(0) == '0' ){ 
      userIdA = clearUserID(input[0]); // clearUserId (String) remove the @N Characters and returns the String long value
      userIdB = clearUserID(input[1]); // clearUserId (String) remove the @N Characters and returns the String long value
      g.addEdge(userIdA,userIdB);
      //timeStamp = stod(input[3]); // Converts the String to a double value
      // cout << "\nEvent 0 - (Friendship)\n" 
      //           << "  userIdA : " << userIdA << '\n' 
      //           << "  userIdB : " << userIdB << '\n'
      //           << "  TimeStamp : "<< timeStamp << '\n';
    // Event 1 - (Post)
    }else if (input[2].at(0) == '1'){  
        userIdA = clearUserID(input[0]); // clearUserId (String) remove the @N Characters and returns the String long value
        photoId = stod(input[1]); // Converts the String to a double value
        timeStamp = stod(input[3]); // Converts the String to a double value
        // cout << "\nEvent 1 - (Post Photo)\n" 
        //         << "  userId : " << userIdA << '\n' 
        //         << "  photoId : " << photoId << '\n'
        //         << "  TimeStamp : "<< timeStamp << '\n';
      // Event 2 - (Faved)                
      }else{
        userIdA = clearUserID(input[0]); // clearUserId (String) remove the @N Characters and returns the String long value
        photoId = stod(input[1]); // Converts the String to a double value
        timeStamp = stod(input[3]); // Converts the String to a double value
        // cout << "\nEvent 2 - (Photo Faved)\n" 
        //         << "  userId : " << userIdA << '\n' 
        //         << "  photoId : " << photoId << '\n'
        //         << "  TimeStamp : "<< timeStamp << '\n';
      }
    getline (cin, str);
    }
  g.printGraph();
  return 0;
}

// github.com/castrob/ac3_filcker/TODO.txt to task list
