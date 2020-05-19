#include "UltraSonic.h"

void USSetup(UltraSonic *ultraSonic, uint16_t trigger_Pin, uint16_t echo_Pin)
{
    ultraSonic->Trigger_Pin = trigger_Pin;
    ultraSonic->Echo_Pin = echo_Pin;
}

int USGetDistance(UltraSonic *ultraSonic)
{
    HAL_GPIO_WritePin(GPIOB, ultraSonic->Trigger_Pin, GPIO_PIN_SET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(GPIOB, ultraSonic->Trigger_Pin, GPIO_PIN_RESET);
    
    while (!HAL_GPIO_ReadPin(GPIOB, ultraSonic->Echo_Pin));

		int initialTick = HAL_GetTick();

    while (HAL_GPIO_ReadPin(GPIOB, ultraSonic->Echo_Pin));

    int distance = (HAL_GetTick() - initialTick) * 17;

    return distance;
}
