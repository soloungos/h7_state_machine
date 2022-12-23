/*
 * msg.h
 *
 *  Created on: Feb 17, 2021
 *      Author: soloungos
 */

#ifndef SRC_APP_MSG_H_
#define SRC_APP_MSG_H_

typedef enum
{
  MSG_NONE = 0x00,
  MSG_KEY_INTERRUPT,
  MSG_COUNT,
}msg_t;

typedef struct
{
  msg_t msg;
  uint32_t param1;
  uint32_t param2;
}msgs_t;

extern void msgs_clear_msg(void);
extern void msgs_set_msg(msg_t msg, uint32_t param1, uint32_t param2);
extern int msgs_get_msg(msg_t *msg, uint32_t *param1, uint32_t *param2);

#endif /* SRC_APP_MSG_H_ */
