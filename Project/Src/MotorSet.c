#include "Motorset.h"

void MSSetup(MotorSet *motorSet, uint16_t input1_pin, uint16_t input2_pin)
{
    motorSet->Input1_Pin = input1_pin;
    motorSet->Input2_Pin = input2_pin;
}

void MSSetDirection(MotorSet *motorSet, Direction direction)
{
    if (direction == NoDirection)
        return;

    if (direction == Forward)
    {
        HAL_GPIO_WritePin(GPIOB, motorSet->Input1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, motorSet->Input2_Pin, GPIO_PIN_RESET);
    }

    else if (direction == Backward)
    {

        HAL_GPIO_WritePin(GPIOB, motorSet->Input1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, motorSet->Input2_Pin, GPIO_PIN_SET);
    }
}

void MSStop(MotorSet *motorSet)
{
    HAL_GPIO_WritePin(GPIOB, motorSet->Input1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, motorSet->Input2_Pin, GPIO_PIN_RESET);
}
