wget [https://s3.amazonaws.com/artifacts.h2o.ai/releases/ai/h2o/dai/rel-1.7.0-214/x86\_64-centos7/dai-docker-centos7-x86\_64-1.7.0-10.0.tar.gz](https://s3.amazonaws.com/artifacts.h2o.ai/releases/ai/h2o/dai/rel-1.7.0-214/x86_64-centos7/dai-docker-centos7-x86_64-1.7.0-10.0.tar.gz)

docker load &lt; dai-docker-centos7-x86\_64-1.7.0-10.0.tar.gz

mkdir data

mkdir log

mkdir license

mkdir tmp



docker run   --rm    -u \`id -u\`:\`id -g\`    -p 12345:12345    -p 9090:9090    -v \`pwd\`/data:/data   -v \`pwd\`/log:/log  -v \`pwd\`/license:/license   -v \`pwd\`/tmp:/tmp   h2oai/dai-centos7-x86\_64:1.7.0-cuda10.0

