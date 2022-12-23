/*
 * alogrithm.c
 *
 *  Created on: Feb 19, 2021
 *      Author: soloungos
 */
#include "algorithm.h"

static void init(void);
static void execute(void *param1, void *param2, void *param3);

static algorithm_t this =
{
    init,
    execute
};

/**
  * @brief  This function is executed in case of ...
  * @retval ..
  */
algorithm_t* algorithm_sum(void)
{
  return &this;
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
static void execute(void *param1, void *param2, void *param3)
{
  uint32_t total = 0;
  uint32_t *value = (uint32_t *)param1;
  uint32_t *count = (uint32_t *)param2;
  uint32_t *result = (uint32_t *)param3;

  for(uint32_t i=0; i<*count; i++)
  {
    total += *(value++);
  }

  *result = total;
}










