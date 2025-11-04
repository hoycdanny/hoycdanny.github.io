FROM ubuntu:14.04
MAINTAINER <hoyc.danny@gmail.com>
RUN repo="$(wget -q -O - http://public.apt.atomia.com/setup.sh.shtml | sed s/%distcode/`lsb_release -c | awk '{ print $2 }'`/g)"; echo "$repo"
RUN echo "$repo" | sh
RUN apt-get install atomiadns-masterserver
