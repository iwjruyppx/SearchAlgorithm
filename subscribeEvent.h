
#ifndef __SUBSCRIBE_EVENT_H
#define __SUBSCRIBE_EVENT_H

int subscribeEvent(uint32_t evtType, uint32_t taskId);
void unSubscribeEvent(uint32_t evtType, uint32_t taskId);

int subscribeEventCheck(uint32_t evtType, void* evtData, int (*callback)(uint32_t type, uint32_t taskId, void* data));
void subscribeEventInit(void);

#endif /* __SUBSCRIBE_EVENT_H */
