// $Id: http.h 14 2007-02-01 15:49:12Z mitza $

#include "global.h"

#define CONTENT_ENCODING_HEADER "Content-encoding: "
#define CONTENT_TYPE_HEADER "Content-type: "
#define INCOMING_FILE_NAME "/tmp/sumedh.web.inc"
#define TEMPORARY_FILE_NAME "/tmp/sumedh.web.tmp"

#define ENCODING_TAB "./encoding.tab"
#define CONTENT_TAB  "./content.tab"

int demime(void);
int decode(char *encoding);
int view(char *content);

