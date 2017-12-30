# ctimer.h

Use of timer in C

```c

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ctimer.h"


void my_timer(void *a)
{
  printf("Timer %s\n", a);
}

int main(int argc, char **argv) {

  size_t tm1 = create_timer(1000, "Timer1", 6, my_timer);
  size_t tm2 = create_timer(3000, "Timer2", 6, my_timer);

  sleep(10);

  printf("Delete timer 1\n");
  delete_timer(tm1);

  sleep(10);

  printf("Delete timer 2\n");
  delete_timer(tm2);
}

```
