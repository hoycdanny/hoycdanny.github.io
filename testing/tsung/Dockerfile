FROM          centos:centos7
MAINTAINER    Danny,Ho <danny.ho@hpe.com>

RUN yum update -y
#RUN rpm -Uvh "http://download.fedoraproject.org/pub/epel/6/i386/epel-release-6-8.noarch.rpm"
RUN rpm -Uvh "https://dl.fedoraproject.org/pub/epel/epel-release-latest-7.noarch.rpm"
RUN yum -y install  crontabs\
                    erlang \
                    firefox \
                    gnuplot perl-Template-Toolkit \
                    jq \
                    openssh \
                    openssh-server \
                    openssh-clients \
                    perl-Log-Log4perl-RRDs.noarch \
                    tar
RUN curl http://tsung.erlang-projects.org/dist/tsung-1.6.0.tar.gz --output /tmp/tsung-1.6.0.tar.gz \
    && cd /tmp/ \
    && tar -xvf ./tsung-1.6.0.tar.gz \
    && cd tsung-1.6.0 \
    && ./configure \
    && make debug \
    && make install \
    && rm -rf /tmp/tsung*


RUN ssh-keygen -N "" -f /root/.ssh/id_rsa && \
    cp /root/.ssh/id_rsa.pub /root/.ssh/authorized_keys && \
    echo "Port 21" > /root/.ssh/config && \
    echo "StrictHostKeyChecking no" >> /root/.ssh/config && \
    echo "UserKnownHostsFile /dev/null" >> /root/.ssh/config

#RUN mkdir -p /var/log/tsung && echo "" > /var/log/tsung/tsung.log

ENV ERL_SSH_PORT 21
ENV ERL_EPMD_PORT=4369
ENV BINDIR=/usr/lib64/erlang/erts-5.8.5/


RUN mkdir -p /usr/local/tsung
VOLUME ["/usr/local/tsung"]


RUN sed -i.bak s/"64000"/"9001"/g /usr/bin/tsung
RUN sed -i.bak s/"65500"/"9050"/g /usr/bin/tsung
RUN printf "[{kernel,[{inet_dist_listen_min,9001},{inet_dist_listen_max,9050}]}]. \n\n" > /root/sys.config
RUN sed -i.bak s/"erlexec"/"erlexec -config \/root\/sys "/g /usr/bin/erl


RUN mkdir -p /etc/tsung/
RUN echo "* * * * * /usr/bin/tsung-update-hosts >> /var/log/tsung/tsung-update-hosts.log 2>&1" > /etc/crontab
#RUN touch /var/log/tsung/tsung-update-hosts.log

COPY ./tsung-hosts.sh /usr/bin/tsung-update-hosts
RUN chmod +x /usr/bin/tsung-update-hosts
COPY ./tsung-run.sh /usr/bin/tsung-run
RUN chmod +x /usr/bin/tsung-run

EXPOSE 22
EXPOSE 8091
EXPOSE 4369
EXPOSE 9001-9050
#ENTRYPOINT ["tsung-run"]
