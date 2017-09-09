# Flickr Database Analysis with openMP
This project consists in analyze the database of Flickr and get the faved level of each posted photo. Read the following [PDF](http://webdav.sistemas.pucminas.br:8080/webdav/sistemas/sga/20172/1257855_ACIII-TrabalhoOpenMP.pdf)(Portuguese) for detailed instruction of this project 
## Tools
1. C++ Language( GCC 7.1.1 )
2. OpenMP
3. Sublime Text (castrob)
4. bash to compile and run
```
$ g++ initialParse.cpp -fopenmp
$ ./a.out
```
## Considerations
In this project the first thing we tried to achieve is to parse each line and see if we were getting the right content of each event. After splitting the line on ',' occurences we decided to build our friendship relation graph, so with that we could use a Breadth-First Search (BSF) that would return the level of each faved event. To save the content of each posted photo we decided to create a dictionary cointaining each photo an its owner. After implementing each of these things, we decided to do a parallel 'for' to split the search(not itself but the hole array of events) in multiples threads. For more information feel free to contact.

