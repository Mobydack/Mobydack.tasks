FROM gcc:12 AS c_lang

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y \
    build-essential \
    ninja-build \
    make \
    cmake

CMD ["sleep", "infinity"]
