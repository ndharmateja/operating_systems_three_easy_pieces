FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    gdb \
    valgrind \
    strace \
    python3 \
    python3-pip \
    man-db \
    manpages-dev \
    git \
    curl \
    zsh \
    && rm -rf /var/lib/apt/lists/*

RUN yes | unminimize

RUN echo 'PROMPT="%F{cyan}%~%f %(?.%F{green}✓%f.%F{red}✗%f)\n$ "' >> /root/.zshrc