#include "MovementController.h"
#include "stm32_hal_legacy.h"

void MCSetup(MovementController *movementController, MotorSet *leftMotorSet, MotorSet *rightMotorSet, TIM_HandleTypeDef *speedTim)
{
    movementController->LeftMotorSet = leftMotorSet;
    movementController->RightMotorSet = rightMotorSet;
    movementController->BlockedBackward = 0;
    movementController->BlockedForward = 0;
    movementController->SpeedTim = speedTim;
    movementController->Speed = 50;
	
		__HAL_TIM_SetCompare(movementController->SpeedTim, TIM_CHANNEL_2, movementController->Speed);
}

void MCStop(MovementController *movementController)
{
    MSStop(movementController->LeftMotorSet);
    MSStop(movementController->RightMotorSet);

    movementController->CurrentDirection = NoDirection;
    movementController->CurrentRotation = NoRotation;
}

void MCSetDirection(MovementController *movementController, Direction direction)
{
    if (direction == NoDirection)
        return;

    if ((direction == Forward && movementController->BlockedForward) || (direction == Backward && movementController->BlockedBackward))
    {
        MCStop(movementController);
        return;
    }

    MSSetDirection(movementController->LeftMotorSet, direction);
    MSSetDirection(movementController->RightMotorSet, direction);

    movementController->CurrentDirection = direction;
    movementController->CurrentRotation = NoRotation;
}

void MCSetRotation(MovementController *movementController, Rotation rotation)
{
    if (rotation == NoRotation)
        return;

    if (rotation == Clockwise)
    {
        MSSetDirection(movementController->LeftMotorSet, Forward);
        MSSetDirection(movementController->RightMotorSet, Backward);
    }
    else if (rotation == CounterClockwise)
    {
        MSSetDirection(movementController->LeftMotorSet, Backward);
        MSSetDirection(movementController->RightMotorSet, Forward);
    }

    movementController->CurrentRotation = rotation;
    movementController->CurrentDirection = NoDirection;
}

void MCUpdateSpeed(MovementController *movementController, int speedChange)
{
    movementController->Speed -= speedChange;
	
		if (movementController->Speed > 99)
			movementController->Speed = 99;		
		if (movementController->Speed < 0)
			movementController->Speed = 0;
		
	__HAL_TIM_SetCompare(movementController->SpeedTim, TIM_CHANNEL_2, movementController->Speed);
		
}

void MCBlockDirection(MovementController *movementController, Direction direction)
{
    if (direction == NoDirection)
        return;

    if (movementController->CurrentDirection == direction)
    {
        MCStop(movementController);
        movementController->CurrentDirection = NoDirection;
    }

    switch (direction)
    {
    case Forward:
        movementController->BlockedForward = 1;
        break;
    case Backward:
        movementController->BlockedBackward = 1;
        break;
		default:
			break;
    }
}

void MCUnblockDirection(MovementController *movementController, Direction direction)
{
    if (direction == NoDirection)
        return;

    switch (direction)
    {
    case Forward:
        movementController->BlockedForward = 0;
        break;
    case Backward:
        movementController->BlockedBackward = 0;
        break;
		default:
			break;
    }
}
