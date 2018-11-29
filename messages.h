#ifndef RDMA_MESSAGES_H
#define RDMA_MESSAGES_H
#include <sys/time.h>

const char *DEFAULT_PORT = "12345";
const size_t BUFFER_SIZE = 64;
const int LIMIT = 1000000;// 1000000;
double total_throughput = 0;
uint64_t start_time, end_time;

uint64_t getTimeStamp() {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec*(uint64_t)1000000+tv.tv_usec;
}


enum message_id
{
  MSG_INVALID = 0,
  MSG_MR,
  MSG_READY,
  MSG_DONE
};

struct message
{
  int id;
  char buffer[64]; // need to change with the buffer

  union
  {
    struct
    {
      uint64_t addr;
      uint32_t rkey;
    } mr;
  } data;
};

#endif
