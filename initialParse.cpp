
/** Computer Architecture III - Lesandro Ponciano
  * Work 1 - Flickr Database
  * Group: Igor Machado Seixas
  *        Joao Castro
  *        Paulo Junio
  *
  * Used language: C++
  *
  * For more information please follow to github.com/castrob/ac3_flickr repository
  */
  
  // Imports
  #include <iostream>
  #include "graph.h"
  #include "omp.h"
  #include "dictionary.h"
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
    double answer = 0.0;
    string tmp = "0";
    for(int i = 0; i < str.size(); i++){
      if (str.at(i) != '@' && str.at(i) != 'N')
        tmp = tmp + str.at(i);
    }
    if(!tmp.empty())
      answer = stod(tmp);
    return answer;
  }


 

int main ()
{
  //////////////////////// TESTING AREA \\\\\\\\\\\\\\\\\\\\\\


    //////////////////////// END OF TESTING AREA \\\\\\\\\\\\\\\\\\\\\\
  
  // Declaring elements
  graph g; // graph with all friendship relation
  dictionary d; // dictionary with all photo and owner posted
  string str;  // Declaring str as base string
  string* input; // Declaring the String Array
  string::size_type sz; // alias for size_t
  list<double>* faved = new list<double>[3000000]; // List that will be used to search faved events
  list<string> eventTwo; // String List to store all faved events to only count them on the end
  double userIdA; // Change from String to Int
  double userIdB; // Change from String to Int
  double photoId; // Change from String to Int
  double idOwner;
  int k = 0; // Not Used
  int n = 0; // faved List positions
  double timeStamp; // Change from String to Int

  // Read line function
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
        g.addVertex(userIdA);
        d.addPhoto(photoId,userIdA);
        // cout << "\nEvent 1 - (Post Photo)\n" 
        //         << "  userId : " s<< userIdA << '\n' 
        //         << "  photoId : " << photoId << '\n'
        //         << "  TimeStamp : "<< timeStamp << '\n';
      // Event 2 - (Faved)                
      }else{
        userIdA = clearUserID(input[0]); // clearUserId (String) remove the @N Characters and returns the String long value
        // photoId = stod(input[1]); // Converts the String to a double value
        g.addVertex(userIdA); // Creates the userIdA vertex if it doesnt exists
        eventTwo.push_back(str); // fill the evenTwo list with all faved events to count later
        // idOwner = d.findOwner(photoId);
        // if (idOwner != 0 && n < 500){
        //   faved[n].push_back(idOwner);
        //   faved[n].push_back(userIdA);
        //   n++;
        // }
        // timeStamp = stod(input[3]); // Converts the String to a double value
         // cout << "\nEvent 2 - (Photo Faved)\n" 
         //         << "  userId : " << userIdA << '\n' 
         //         << "  photoId : " << photoId << '\n'
         //         << " owner : " << idOwner << '\n'
         //         << "  TimeStamp : "<< timeStamp << '\n';
      }
     getline (cin, str);
    }
    // now we will count each faved event getting the personId who faved and the ownerId of each faved photo
    // and put it in the faved list to search each level after with BFS
    list<string>::iterator i;
    for (i = eventTwo.begin(); i != eventTwo.end(); i++ ){
      input = split(*i,',');
      userIdA = clearUserID(input[0]); // clearUserId (String) remove the @N Characters and returns the String long value
      photoId = stod(input[1]); // Converts the String to a double value
      idOwner = d.findOwner(photoId);
      if (idOwner != 0){
        faved[n].push_back(idOwner);
        faved[n].push_back(userIdA);
        n++;
        }
    }
  // Print Graph of Friendship and Dictionary of Posted Photos
  g.printGraph();
  d.printPhotos();

  // Parallel area to search each fav level
  int pos = 0;
  #pragma omp paralell for
  for (; pos < n; pos++ ){
      int l = g.BFS(*faved[pos].begin(), *next(faved[pos].begin(),1) );
      g.addLevel(l);
  }
  // printing the percentage of each level
  double sum = g.levelZero + g.levelOne + g.levelTwo + g.levelThree + g.levelFour;
  cout << "0: " << ((double)g.levelZero/sum) << '\n'
  	   << "1: " << ((double)g.levelOne/sum) << '\n'
  	   << "2: " << ((double)g.levelTwo/sum) << '\n'
  	   << "3: " << ((double)g.levelThree/sum) << '\n'
  	   << "4: " << ((double)g.levelFour/sum) << '\n';
  return 0;
}

// github.com/castrob/ac3_filcker/TODO.txt to task list
