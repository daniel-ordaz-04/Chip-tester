/*
IC7404.cpp - Library to test the integrated circuit 7404 (Six 2 inputs NOT gates)
Created by Daniel Ordaz November 2017
GNU License-
*/

#include "arduino.h"
#include "IC7404.h"

IC7404::IC7404(int _inputs[6], int _outputs[6])
{
  
  for (int i=0;i<6;i++)
  {
	  inputs[i]=_inputs[i];
	  outputs[i]=_outputs[i];	  
  }
}

/*
  0 = Succesful
 [1-6] = Error in gate [1-6]
*/
int IC7404::test()
{
  for(int i=0;i<6;i++)
  {
    if(!checkGate(inputs[i], outputs[i]))
      return i+1;
  }
  return 0;
}

boolean IC7404::checkGate(int input, int output)
{
  for(int i=0;i<6;i++)
  {
	digitalWrite(input, truthTable[i][0]);
    if(!digitalRead(output)==truthTable[i][1])
      return false;
  }
  return true;
}