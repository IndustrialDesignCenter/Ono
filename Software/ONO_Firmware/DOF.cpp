#include "DOF.h"

DOF::DOF(int pin, int minpos, int midpos, int maxpos){
  _pin = pin;
  _min = minpos;
  _max = maxpos;
  _mid = midpos;
  _pos = 0;
}

void DOF::Init(){
  SendPulse(_mid);
}

void DOF::SendPulse(int pulse){
  pulse = constrain(pulse, 500, 2500);
  Serial.print("#");
  Serial.print(_pin);
  Serial.print(" P");
  Serial.print(pulse);
  Serial.print(" ");
  // Does NOT send timing or \r char!
}

void DOF::SendPos(int pos){
  // Pos: -100 = minpos
  //         0 = midpos
  //       100 = maxpos
  pos = constrain(pos, -100, 100);
  _pos = pos;
  if(pos == 0){
    Init(); // Set to mid
  }else if(pos < 0){
    SendPulse(map(pos, 0, -100, _mid, _min));
  }else if(pos > 0){
    SendPulse(map(pos, 0, 100, _mid, _max));
  }
}

int DOF::GetPos(){
  return _pos;
}
