#VERSION 0.0.1
#build algorithm container image

FROM gcc:4.9

MAINTAINER ximena "xiaominghe2014@gmail.com"

COPY . /usr/src/algorithm
WORKDIR /usr/src/algorithm
RUN make \
    make cleanobj \
    ./algorithm
CMD ["make","clean"]
