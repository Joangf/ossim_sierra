/*
 * Copyright (C) 2025 pdnguyen of HCMC University of Technology VNU-HCM
 */

/* Sierra release
 * Source Code License Grant: The authors hereby grant to Licensee
 * personal permission to use and modify the Licensed Source Code
 * for the sole purpose of studying while attending the course CO2018.
 */

#include "common.h"
#include "syscall.h"
#include "stdio.h"
#include "libmem.h"
#include <string.h>
#include "queue.h"
#include <stdlib.h>
int __sys_killall(struct pcb_t *caller, struct sc_regs *regs)
{
    char proc_name[100];
    uint32_t data;

    // hardcode for demo only
    uint32_t memrg = regs->a1;

    /* TODO: Get name of the target proc */
    // proc_name = libread..
    int i = 0;
    data = 0;
    while (data != -1)
    {
        libread(caller, memrg, i, &data);
        proc_name[i] = data;
        if (data == -1)
            proc_name[i] = '\0';
        i++;
    }

    char path[100];
    strcpy(path, "input/proc/");
    strcat(path, proc_name);
    struct pcb_t *proc = NULL;
    for (int i = 0; i < caller->running_list->size; i++)
    {
        if (strcmp(path, caller->running_list->proc[i]->path) == 0)
        {
            // terminate the process
            proc = caller->running_list->proc[i];
            caller->running_list->size--;
            // remove from running list
            for (int j = i; j < caller->running_list->size; j++)
            {
                caller->running_list->proc[j] = caller->running_list->proc[j + 1];
            }
        }
    }
    for (int i = 0; i < MAX_PRIO; i++)
    {
        for (int j = 0; j < caller->mlq_ready_queue[i].size; j++)
        {
            if (strcmp(path, caller->mlq_ready_queue[i].proc[j]->path) == 0)
            {
                // terminate the process
                caller->mlq_ready_queue[i].size--;
                // remove from mlq ready queue
                for (int k = j; k < caller->mlq_ready_queue[i].size; k++)
                {
                    caller->mlq_ready_queue[i].proc[k] = caller->mlq_ready_queue[i].proc[k + 1];
                }
            }
        }
    }
    if (proc != NULL)
        printf("===== KILL %s =====\n", path);
    free(proc);
    return 0;
}
