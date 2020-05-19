#ifndef MovementController_H
#define MovementController_H

#include "main.h"
#include "MotorSet.h"

typedef enum
{
    Clockwise,
    CounterClockwise,
    NoRotation
} Rotation;

typedef struct
{
    MotorSet *LeftMotorSet;
    MotorSet *RightMotorSet;
    int BlockedForward;
    int BlockedBackward;
    Direction CurrentDirection;
    Rotation CurrentRotation;
    TIM_HandleTypeDef *SpeedTim;
    int Speed;
} MovementController;

void MCSetup(MovementController *movementController, MotorSet *leftMotorSet, MotorSet *rightMotorSet, TIM_HandleTypeDef *speedTim);

void MCStop(MovementController *movementController);

void MCSetDirection(MovementController *movementController, Direction direction);

void MCSetRotation(MovementController *movementController, Rotation rotation);

void MCUpdateSpeed(MovementController *movementController, int speedChange);

void MCBlockDirection(MovementController *movementController, Direction direction);

void MCUnblockDirection(MovementController *movementController, Direction direction);

#endif
