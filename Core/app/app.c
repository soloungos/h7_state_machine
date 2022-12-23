/*
 * app.c
 *
 *  Created on: Feb 17, 2021
 *      Author: soloungos
 */
#include "app.h"

static app_id_t current_app_id = APP_NONE;
static app_t *apps[APP_COUNT]={0, };

static int app_loop_current_app(void);
static void app_on_msg_app(void);

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
int app_init_app(app_t *app)
{
  if(app == NULL)
    return -1;

  apps[app->id] = app;
  apps[app->id]->init();

  return 0;
}

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
void app_process(void)
{
  app_on_msg_app();
  app_loop_current_app();
}

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
int app_set_msg(msg_t msg, uint32_t param1, uint32_t param2)
{
  msgs_set_msg(msg, param1, param2);

  return 0;
}

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
int app_start_app(app_id_t id)
{
  if((id >= APP_COUNT) || (apps[id]->start == NULL))
    return -1;

  current_app_id = id;
  apps[id]->start();

  return 0;
}

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
int app_switch_app(app_id_t id)
{
  if((id >= APP_COUNT) || (apps[id] == NULL))
    return -1;

  if(current_app_id == id)
    return -1;

  apps[current_app_id]->stop();
  apps[id]->prev_id = current_app_id;
  current_app_id = id;
  apps[id]->start();

  return 0;
}

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
app_t *app_get_current_app(void)
{
  return apps[current_app_id];
}

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
static void app_on_msg_app(void)
{
  msg_t msg;
  uint32_t param1;
  uint32_t param2;

  if(apps[current_app_id]->on_msg == NULL)
    return;

  while(msgs_get_msg(&msg, &param1, &param2) != -1)
  {
    apps[current_app_id]->on_msg(msg, param1, param2);
  }
}

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
static int app_loop_current_app(void)
{
  if(apps[current_app_id]->loop == NULL)
    return -1;

  apps[current_app_id]->loop();
  return 0;
}














