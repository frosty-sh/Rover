#ifndef Motorset_H
#define Motorset_H

#include "main.h"

typedef enum
{
    Forward,
    Backward,
    NoDirection
} Direction;

typedef struct
{
    uint16_t Input1_Pin;
    uint16_t Input2_Pin;
} MotorSet;

void MSSetup(MotorSet *motorSet, uint16_t input1_pin, uint16_t input2_pin);

void MSSetDirection(MotorSet *motorSet, Direction direction);

void MSStop(MotorSet *motorSet);

#endif
