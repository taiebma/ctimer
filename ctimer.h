/**************************
* Module de gestion des timer
* Fichier : ctimer.h
* Auteur : Marc TAIEB
**************************/
#ifndef __CTIMER__
#define __CTIMER__

/**********
* create_timer
* Create a new timer
* interval : interval to wait
* userData : data passed to the handler function when the time ellapsed
* sizeUserData : size of the userData
* handler : handler function that will be called
* return : return the id of the timer or 0 if an error occurs
**********/
size_t create_timer(int interval, void *userData, int sizeUserData, void (*handler)(void *));

/**********
* delete_timer
* Delete the timer
* timer : id of the timer to delete
**********/
void delete_timer(size_t timer);


#endif
