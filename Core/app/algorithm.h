/*
 * algorithm.h
 *
 *  Created on: Feb 19, 2021
 *      Author: soloungos
 */

#ifndef APP_ALGORITHM_H_
#define APP_ALGORITHM_H_

#include "_typedef.h"

typedef struct
{
  void (*init)(void);
  void (*execute)(void *param1, void *param2, void *param3);
}algorithm_t;



#endif /* APP_ALGORITHM_H_ */
