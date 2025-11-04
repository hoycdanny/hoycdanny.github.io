FROM centos:7
MAINTAINER Danny Ho <danny.ho@hpe.com>
RUN yum -y install \
	epel-release \
	erlang \
	wget \
	zip unzip
RUN yum clean all
RUN wget http://emqtt.io/static/brokers/emqttd-centos7-v2.2.0.zip
RUN unzip emqttd-centos7-v2.2.0.zip -d .
COPY docker-entrypoint.sh /usr/local/bin/
RUN ln -s usr/local/bin/docker-entrypoint.sh /entrypoint.sh
ENTRYPOINT sh entrypoint.sh && bash
