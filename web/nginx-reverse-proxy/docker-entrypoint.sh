#!/bin/bash
sed -i '42 i\location /'$PROXY_PATH' { \
           proxy_pass '$PROXY_PASS'; \
	   }' /etc/nginx/sites-available/default
service nginx restart
