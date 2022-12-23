/*
 * app_second.c
 *
 *  Created on: Feb 18, 2021
 *      Author: soloungos
 */
#include "app.h"
#include "algorithm.h"
#include "algorithm_avg.h"

#define FLAGS_DEFALUT           (0x00000000)

static void init(void);
static void start(void);
static void stop(void);
static void loop(void);
static void on_msg(msg_t msg, uint32_t param1, uint32_t param2);

static app_t this =
{
    APP_second,
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
void app_second_init(void)
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
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_RESET);
}

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
static void loop(void)
{
  uint32_t array[10] = {1,2,3,4,5,6,7,8,9,10};
  uint32_t length = 10;
  uint32_t result = 0;
  algorithm_t *algorithm = algorithm_avg();

  algorithm->init();
  algorithm->execute((void *)array, (void *)&length, (void *)&result);

  HAL_Delay(250);
  HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_1);
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
    app_switch_app(APP_third);
    break;

  default:
    break;
  }
}













