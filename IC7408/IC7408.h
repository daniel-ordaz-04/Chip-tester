/*
IC7408.h - Library to test the integrated circuit 7408 (Quad 2 inputs AND gates)
Created by Daniel Ordaz November 2017
GNU License
*/
#ifndef IC7408
#include "arduino.h"
class IC7408 {
  public:
   IC7408(int _inputs[4][2], int _outputs[4]);  //Constructor
   int test(); //Main function to check the IC
  private:  
   int inputs[4][2];  //Gate's inputs, one row for each one
   int outputs[4];    //Gate's output, one space for each one
   boolean checkGate(int inputs[2], int output);  //Function to check the specified gate
   int truthTable[4][3]={{0, 0, 0}, 
              {0, 1, 0},
              {1, 0, 0},
              {1, 1, 1}};;
};
#endif