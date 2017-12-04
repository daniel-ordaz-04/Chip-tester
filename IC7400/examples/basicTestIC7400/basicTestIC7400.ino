#include <IC7400.h>

int inputs[4][2]={{2,3},{4,5},{6,7},{8,9}};
int outputs[4]={10, 11, 12, 13};
String result;
IC7400 myIC(inputs, outputs);

void setup() { 
  Serial.begin(9600);
}
void loop() {
  result=myIC.test();
  if(result.equals(""))
  {
    Serial.println("There's no errors");
  }else{
    Serial.println("Error in gate " + result);
  }
  delay(500);
}
