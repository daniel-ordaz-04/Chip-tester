/*
IC7404.h - Library to test the integrated circuit 7404 (Six 2 inputs not gates)
Created by Daniel Ordaz November 2017
GNU License
*/
#ifndef IC7404
#include "arduino.h"
class IC7404 {
  public:
   IC7404(int _inputs[6], int _outputs[6]);  //Constructor
   int test(); //Main function to check the IC
  private:  
   int inputs[6];  //Gate's inputs, one space for each one
   int outputs[6];    //Gate's output, one space for each one
   boolean checkGate(int input, int output);  //Function to check the specified gate
   int truthTable[2][2]={{0, 1}, 
						 {1, 0}};
};
#endif