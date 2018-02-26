
#ifndef __SUBSCRIBE_EVENT_H
#define __SUBSCRIBE_EVENT_H

int subscribeEvent(uint32_t evtType, uint32_t taskId);
void unSubscribeEvent(uint32_t evtType, uint32_t taskId);

void subscribeEventCheck(uint32_t evtType, int (*callback)(uint32_t evtType, uint32_t taskId));
void subscribeEventInit(void);

#endif /* __SUBSCRIBE_EVENT_H */
