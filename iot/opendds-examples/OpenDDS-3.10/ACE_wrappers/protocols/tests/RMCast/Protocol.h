// file      : Protocol.h
// author    : Boris Kolpackov <boris@kolpackov.net>
// cvs-id    : $Id: Protocol.h 14 2007-02-01 15:49:12Z mitza $

#ifndef PROTOCOL_H
#define PROTOCOL_H

unsigned short const payload_size = 200;
unsigned long const message_count = 100;

struct Message
{
  unsigned long sn;

  unsigned short payload[payload_size];
};

#endif  // PROTOCOL_H
