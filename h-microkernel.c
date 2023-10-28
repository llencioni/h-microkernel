/*
* 
*/

#include "h-microkernel.h"
#include <stdio.h>

/* Temporary tasks configuration ... under construction */
void task1 (void)
{
    printf("\nThis is Task1");
}

void task2 (void)
{
    printf("\nThis is Task2");
}

void task3 (void)
{
    printf("\nThis is Task3");
}


#define NUM_TASKS   3
TCB_t tasks_tcb[NUM_TASKS] = {
    {.task=task1, .event=1},
    {.task=task2, .event=1},
    {.task=task3, .event=1}
};

/*****************************/

int main (int argc, char* argv[])
{
    int i;

    printf("\n");

    // Task loop - problem: it is O(n)
    for(i=0; i<NUM_TASKS; i++)
    {
        // Check if there is any event for the task
        if(tasks_tcb[i].event != 0)
        {
            // Call task
            tasks_tcb[i].task();
            // Clear handled task event
            tasks_tcb[i].event = 0;
        }
    }

    printf("\n\n");
}