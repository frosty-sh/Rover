#ifndef UltraSonic_H
#define UltraSonic_H

#include "main.h"

typedef struct
{
    uint16_t Trigger_Pin;
    uint16_t Echo_Pin;
} UltraSonic;

void USSetup(UltraSonic *ultraSonic, uint16_t trigger_Pin, uint16_t echo_Pin);

int USGetDistance(UltraSonic *ultraSonic);

#endif
