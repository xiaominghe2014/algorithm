#VERSION 0.0.1
#build algorithm container image

FROM gcc:4.9

MAINTAINER ximena "xiaominghe2014@gmail.com"

COPY . /usr/src/algorithm
WORKDIR /usr/src/algorithm
# RUN pwd \
#     make -f makefile \
#     make cleanobj \
#     ./algorithm
CMD ["make"]
