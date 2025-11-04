FROM nvcr.io/nvidia/pytorch:20.03-py3
ARG DEBIAN_FRONTEND=noninteractive
RUN chmod 777 /tmp
RUN apt-get update -y
RUN apt-get install -y vim
RUN apt install -y cmake>=3.14.0
RUN apt install -y libopencv-dev python3-opencv
RUN apt install -y make git g++

#8888:jupyter
#8070:flask
#5000:flask default
#8080:nothing
#5901:VNC(if installed)
EXPOSE 8888 8070 5000 8080 5901
ENTRYPOINT echo "Hello yolov4"
