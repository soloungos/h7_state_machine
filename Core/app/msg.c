/*
 * msg.c
 *
 *  Created on: Feb 17, 2021
 *      Author: soloungos
 */
#include "_typedef.h"
#include "msg.h"

#define MSGS_QUEUE_LEN (64)
static msgs_t g_msgs_queue[MSGS_QUEUE_LEN]={MSG_NONE};
static uint8_t g_msgs_queue_head = 0;
static uint8_t g_msgs_queue_tail = 0;

/**
********************************************************************************************************************************
********************************************************************************************************************************
*/
void msgs_clear_msg(void)
{
  g_msgs_queue_head = 0;
  g_msgs_queue_tail = 0;
}
/**
********************************************************************************************************************************
********************************************************************************************************************************
*/
void msgs_set_msg(msg_t msg, uint32_t param1, uint32_t param2)
{
  g_msgs_queue[g_msgs_queue_head].msg = msg;
  g_msgs_queue[g_msgs_queue_head].param1 = param1;
  g_msgs_queue[g_msgs_queue_head].param2 = param2;

  g_msgs_queue_head++;

  if(g_msgs_queue_head >= MSGS_QUEUE_LEN)
    g_msgs_queue_head = 0;
}


/**
********************************************************************************************************************************
********************************************************************************************************************************
*/
int msgs_get_msg(msg_t *msg, uint32_t *param1, uint32_t *param2)
{
  if(g_msgs_queue_head == g_msgs_queue_tail)
    return -1;

  *msg = g_msgs_queue[g_msgs_queue_tail].msg;
  *param1 = g_msgs_queue[g_msgs_queue_tail].param1;
  *param2 = g_msgs_queue[g_msgs_queue_tail].param2;

  g_msgs_queue_tail++;

  if(g_msgs_queue_tail >= MSGS_QUEUE_LEN)
    g_msgs_queue_tail = 0;

  return 0;
}

