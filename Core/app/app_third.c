/*
 * app_third.c
 *
 *  Created on: Feb 18, 2021
 *      Author: soloungos
 */
#include "app.h"

#define FLAGS_DEFALUT           (0x00000000)

static void init(void);
static void start(void);
static void stop(void);
static void loop(void);
static void on_msg(msg_t msg, uint32_t param1, uint32_t param2);

static app_t this =
{
    APP_third,
    APP_NONE,
    0x00000000,

    init,
    start,
    stop,
    loop,
    on_msg,
};

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
void app_third_init(void)
{
  app_init_app(&this);
}
/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
static void init(void)
{
}

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
static void start(void)
{
}

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
static void stop(void)
{
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
}

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
static void loop(void)
{
  HAL_Delay(500);
  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);
}

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
static void on_msg(msg_t msg, uint32_t param1, uint32_t param2)
{
  switch(msg)
  {
  case MSG_KEY_INTERRUPT:
    app_switch_app(APP_first);
    break;

  default:
    break;
  }
}













