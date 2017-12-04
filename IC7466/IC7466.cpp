/*
IC7466.cpp - Library to test the integrated circuit 7466 (Quad 2 inputs XNOR gates)
Created by Daniel Ordaz November 2017
GNU License-
*/

#include "arduino.h"
#include "IC7466.h"

IC7466::IC7466(int _inputs[4][2], int _outputs[4])
{
  
  for(int row=0;row<4;row++)
  {
    outputs[row]=_outputs[row];
    pinMode(outputs[row], INPUT);
    for(int col=0;col<2;col++)
    {
      inputs[row][col]=_inputs[row][col];
      pinMode(inputs[row][col], OUTPUT);
    }
  }
}

/*
  0 = Succesful
 [1-4] = Error in gate [1-4]
*/
int IC7466::test()
{
  int actualIn[2];
  for(int i=0;i<4;i++)
  {
    actualIn[0]=inputs[i][0];
    actualIn[1]=inputs[i][1];
    if(!checkGate(actualIn, outputs[i]))
      return i+1;
  }
  return 0;
}

boolean IC7466::checkGate(int inputs[2], int output)
{
  for(int i=0;i<4;i++)
  {
    digitalWrite(inputs[0], truthTable[i][0]);
    digitalWrite(inputs[1], truthTable[i][1]);
    if(!digitalRead(output)==truthTable[i][2])
      return false;
  }
  return true;
}