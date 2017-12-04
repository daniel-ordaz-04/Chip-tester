/*
IC7486.h - Library to test the integrated circuit 7486 (Quad 2 inputs XOR gates)
Created by Daniel Ordaz November 2017
GNU License
*/
#ifndef IC7486
#include "arduino.h"
class IC7486 {
  public:
   IC7486(int _inputs[4][2], int _outputs[4]);  //Constructor
   int test(); //Main function to check the IC
  private:  
   int inputs[4][2];  //Gate's inputs, one row for each one
   int outputs[4];    //Gate's output, one space for each one
   boolean checkGate(int inputs[2], int output);  //Function to check the specified gate
   int truthTable[4][3]={{0, 0, 0}, 
              {0, 1, 1},
              {1, 0, 1},
              {1, 1, 0}};;
};
#endif