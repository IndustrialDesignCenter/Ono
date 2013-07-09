#include <Arduino.h>

#ifndef DOF_H
#define DOF_H

class DOF{
  public:
    DOF(int pin, int minpos, int maxpos, int midpos);
    void Init();
    void SendPulse(int pulse);
    void SendPos(int pos);
    int GetPos();
  private:
    int _min;
    int _max;
    int _mid;
    int _pin;
    int _pos;
};

#endif
