# California_Optimized_Travel

### Project Goal
Given a start and end point in the state of California[^1] from the user, we will find the most optimal route to travel the distance between the points using either the amount of roads or the geographical distance, based on user preference.

[^1]: Note: We were unable to run our code on the inital dataset due to the large size, so we used a smaller dataset of the city of Oldenburg for testing purposes.

Documentation: Our Team Project Proposal, Team Contract, and Written Report can be found under the [documents folder.](documents/)

### Running the Code
To run the code, first cd to the folder this project is in and enter: 
``` 
cd California_Optimized_Travel
mkdir build
cd build
```

If there already exists a build directory, first delete the build directory and then run the commands as shown above. Then enter:
```
cmake ..
```

Now, you are ready to run the code. Each time you make changes to main (or any other part of the code), type:
```
make
```
If you only want to make main, then add ``` main ``` at the end of the command, and ```test``` for tests. 


Contraints on files:
If you would like to use different files, keep in mind that the max number of nodes that the computer we used can handle is ~17000 nodes, and the max number of edges was around ~16000.

### Test Suite

The first few test cases check that the files have a valid format and that the constructor can correctly build the graph. User inputs are also tested to ensure that all information is given. We test the graph to make sure the graph is initialized properly and each node contains the correct values. We check the relationships between nodes, ensuring predecessor's and children are well defined. For Floyd-Warshall and A*, a adjacecny matrix is required, so we test the initialization and values for that as well. We then tested each of our algorithms use sample data files, and making sure the outputs matched the expected values. Tests can be run all at once or in groups using tags found in the [tests.cpp file.](tests/tests.cpp) More test examples can be found under the main directory, and in the more_test folder. (Most of the non example test cases (e.g. "test_edges13.txt") in more_test are designed to fail and are used only for invalid input testing purposes.)
