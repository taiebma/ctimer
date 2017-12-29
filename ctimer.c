/**************************
* Module de gestion des timer
* Fichier : ctimer.c
* Auteur : Marc TAIEB
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

typedef void (*user_handler)(void *);

typedef struct _ctimer_info {
  int interval;
  void *userData;
  user_handler handler;
  pthread_t thread;
} ctimer_info;

void *_timer_handler( void *threadInfo)
{
  ctimer_info *tm_info = (ctimer_info *)threadInfo;

  while(1) {
      usleep(tm_info->interval * 1000);
      (*tm_info->handler)(tm_info->userData);
  }
}

/**********
* create_timer
* Create a new timer
* interval : interval to wait
* userData : data passed to the handler function when the time ellapsed
* sizeUserData : size of the userData
* handler : handler function that will be called
* return : return the id of the timer or 0 if an error occurs
**********/
size_t create_timer(int interval, void *userData, int sizeUserData, void (*handler)(void *))
{
  pthread_t newThread;
  ctimer_info *tm_info = (ctimer_info*)malloc(sizeof(ctimer_info));

  tm_info->interval = interval;
  tm_info->userData = (void*)malloc(sizeUserData);
  memcpy(tm_info->userData, userData, sizeUserData);
  tm_info->handler = handler;
  if (pthread_create(&tm_info->thread, NULL, _timer_handler, tm_info) == 0)
    return (size_t)tm_info;

  return 0;

}

/**********
* delete_timer
* Delete the timer
* timer : id of the timer to delete
**********/
void delete_timer(size_t timer)
{
  ctimer_info *tm_info = (ctimer_info *)timer;
  pthread_cancel(tm_info->thread);
  free(tm_info->userData);
  free(tm_info);
}
