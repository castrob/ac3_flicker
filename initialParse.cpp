
/** Arquitetura de Computadores III - Lesandro Ponciano
  * Trabalho Pratico 1 - Flicker Database
  * Integrantes: Igor Machado Seixas
  *              Joao Castro
  * Linguagem utilizada: C++
  * Recursos: <string> substr (int inicio, int quantidade) - Substring
  *           <string> find (String padrao) - "contains" retorna posicao do padrao se achar, se nao achar returna -1
  *           <string> at (int posicao) - "charAt" retorna o char da posicao passada por parametro
  */
  
  // Imports
  #include <iostream>
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

int main ()
{

  // Default occurence of strings

  //std::string base="10000137@N04,10231841@N06,0,0";         //CASO 0
  //std::string base="99997777@N00,6879369765,1,1329283214";    //CASO 1
  string base="10000126@N02,4074743559,2,1324475489";  //CASO 2

    //////////////////////// TESTING AREA \\\\\\\\\\\\\\\\\\\\\\

    // Testing Split Function \\
/** /
  string* teste = split(base, ',');
  cout << teste[0] <<'\n'
       << teste[1] <<'\n'
       << teste[2] <<'\n'
       << teste[3] <<'\n';
/**/       
    //////////////////////// END OF TESTING AREA \\\\\\\\\\\\\\\\\\\\\\
  
  // Declaring elements
  string str;  // Declaring str as base string
  string* input; // Declaring the String Array
  string::size_type sz; // alias for size_t
  string userIdA;
  string userIdB;
  string photoId;
  string timeStamp;

  
/** / // WILL BE REMOVED TO TEST THE SPLITED PART OF THE STRING CONTAINING THE EVENT PART
  // testing which case of string it is
   // if find the occurence returns its position, if not returns -1
  pos = str.find(",0,"); // find another way to do it?
  pos1= str.find(",1,"); // find another way to do it? 
  pos2= str.find(",2,"); // find another way to do it?
/**/
  
  getline (cin, str);
  while(!str.empty()){
    // Split the str String 
    input = split(str, ',');
    // input[0] - userId (ALWAYS)
    // input[1] - userId/PhotoId
    // input[2] - Event (ALWAYS)
    // input[3] - timeStamp (ALWAYS)

    if ( input[2].at(0) == '0' ){ // If case 0 ( Friendship Action )
      //userIdA = str.substr(0,12); // goes to string's position 0 and returns the next 12 chars (it counts the 0 too)
      userIdA = input[0];
      //userIdB = str.substr(13,12); // same thing but starts from position 13.
      userIdB = input[1];
      //timeStamp= str.substr(str.size()-1, str.size()); // Knowing that every event 0 the time stamp is 0, just return the last element
      timeStamp = input[3];
      cout << "\nEvent 0 - (Friendship)\n" 
                << "  userIdA : " << userIdA << '\n' 
                << "  userIdB : " << userIdB << '\n'
                << "  TimeStamp : "<< timeStamp << '\n';
    }else if (input[2].at(0) == '1'){  // If case 1 ( Post photo )
        //userIdA = str.substr(0,12); // goes to string's position 0 and returns the next 12 chars (it counts the 0 too)
        userIdA = input[0];
        //photoId = str.substr(13,10); // same thing but starts from position 13 and gets the next 10 elements ( Size of PhotoID ).
        photoId = input[1];
        //timeStamp= str.substr(str.size()-10, str.size()); // knowing that all other TimeStamp has the same size, return the 10 last elements
        timeStamp = input[3];
        cout << "\nEvent 1 - (Post Photo)\n" 
                << "  userId : " << userIdA << '\n' 
                << "  photoId : " << photoId << '\n'
                << "  TimeStamp : "<< timeStamp << '\n';
        // Interpreting as if not 0 and 1 event, then its 100% event 2
      }else{    // this event the size of its elements is equal to event 1
        //userIdA = str.substr(0,12);
        userIdA = input[0];
        //photoId = str.substr(13,10);
        photoId = input[1];
        //timeStamp= str.substr(str.size()-10, str.size());
        timeStamp = input[3];
        cout << "\nEvent 2 - (Photo Faved)\n" 
                << "  userId : " << userIdA << '\n' 
                << "  photoId : " << photoId << '\n'
                << "  TimeStamp : "<< timeStamp << '\n';
      }
    getline (cin, str);  
    }  
  return 0;
}

// github.com/castrob/ac3_filcker/TODO.txt to task list