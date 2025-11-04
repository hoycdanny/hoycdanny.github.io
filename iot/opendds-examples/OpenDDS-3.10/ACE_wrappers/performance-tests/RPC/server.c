/*
 * $Id: server.c 943 2008-12-12 15:11:28Z mitza $
 */

#include "ping.h"
#include <rpc/rpc.h>
#include <stdio.h>

static int return_value = 0;

int* ping_1_svc (int* value, struct svc_req* r)
{
  return_value = *value;
  return &return_value;
}
