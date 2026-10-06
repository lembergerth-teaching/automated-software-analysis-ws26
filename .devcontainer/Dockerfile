FROM ubuntu:26.04

ENV LANG=C.UTF-8 \
    LC_ALL=C.UTF-8 \
    CC=clang-21 \
    CXX=clang++-21 \
    PATH="/usr/lib/llvm-21/bin:${PATH}"

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
        build-essential \
        ca-certificates \
        clang-21 \
        clang-format-21 \
        clang-tidy-21 \
        clang-tools-21 \
        clangd-21 \
        cmake \
        curl \
        emacs \
        file \
        gdb \
        git \
        less \
        llvm-21 \
        llvm-21-dev \
        llvm-21-tools \
        neovim \
        openjdk-25-jdk-headless \
        openssh-client \
        procps \
        python3 \
        python3-venv \
        ripgrep \
        sudo \
        unzip \
    && rm -rf /var/lib/apt/lists/*

ARG CHECKSTYLE_VERSION=14.3.0
ARG CHECKSTYLE_SHA256=754e218ab1fcabb1e1c5f8530e9d3aa37636806c22987bb279dd907a6ee749b2

# The official all.jar bundles dependencies and works on both amd64 and arm64.
RUN mkdir -p /opt/checkstyle \
    && curl --fail --show-error --silent --location --retry 3 \
        "https://github.com/checkstyle/checkstyle/releases/download/checkstyle-${CHECKSTYLE_VERSION}/checkstyle-${CHECKSTYLE_VERSION}-all.jar" \
        --output /opt/checkstyle/checkstyle.jar \
    && printf '%s  %s\n' "${CHECKSTYLE_SHA256}" /opt/checkstyle/checkstyle.jar > /opt/checkstyle/checkstyle.sha256 \
    && sha256sum --check /opt/checkstyle/checkstyle.sha256

RUN python3 -m venv /opt/jupyter \
    && /opt/jupyter/bin/python -m pip install --no-cache-dir 'jupyterlab>=4,<5' nbclient

ENV PATH="/opt/jupyter/bin:${PATH}"
