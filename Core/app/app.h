/*
 * app.h
 *
 *  Created on: Feb 17, 2021
 *      Author: soloungos
 */

#ifndef SRC_APP_APP_H_
#define SRC_APP_APP_H_

#include "main.h"
#include "msg.h"
#include "_typedef.h"

#include "app_first.h"
#include "app_second.h"
#include "app_third.h"

typedef enum
{
  APP_first,
  APP_second,
  APP_third,
  APP_COUNT,
  APP_NONE,
}app_id_t;

typedef struct
{
  app_id_t id;
  app_id_t prev_id;
  uint32_t flags;
  void (*init)(void);
  void (*start)(void);
  void (*stop)(void);
  void (*loop)(void);
  void (*on_msg)(msg_t msg, uint32_t param1, uint32_t param2);
}app_t;

extern int app_init_app(app_t *app);
extern void app_process(void);
extern int app_set_msg(msg_t msg, uint32_t param1, uint32_t param2);
extern int app_start_app(app_id_t id);
extern int app_switch_app(app_id_t id);
extern app_t *app_get_current_app(void);

#endif /* SRC_APP_APP_H_ */
