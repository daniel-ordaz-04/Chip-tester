#include <IC7404.h>

int inputs[6]={2, 4, 6, 8, 10, 12};
int outputs[6]={3, 5, 7, 9, 11, 13};
int result;
IC7404 myIC(inputs, outputs);

void setup() { 
  Serial.begin(9600);
}
void loop() {
  result=myIC.test();
  if(result==0)
  {
    Serial.println("There's no errors");
  }else{
    Serial.println("Error in gate " + String(result));
  }
  delay(500);
}
