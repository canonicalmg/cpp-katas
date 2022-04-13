ARG RELEASE=20.04

FROM ubuntu:${RELEASE} as cpp-dev-environment

MAINTAINER borisskert <boris.skert@gmail.com>

ENV DEBIAN_FRONTEND     noninteractive

RUN apt update && \
    apt install -y git \
                   build-essential \
                   cmake \
    && \
    apt clean && \
    rm -rf /var/lib/apt/lists/*

ENV SHELL /bin/bash


FROM cpp-dev-environment as build

COPY . /usr/local/src

WORKDIR /usr/local/src

RUN cd build && \
    cmake .. && \
    cmake --build .


FROM ubuntu:${RELEASE}

WORKDIR /opt

COPY --from=build /usr/local/src/build/test/cpp_katas_test .

CMD ["./cpp_katas_test"]
