FROM python:3.10

WORKDIR /app

RUN apt-get update \
        && apt-get install -y \
        build-essential \
        && rm -rf /var/lib/apt/lists/

CMD ["bash"]

EXPOSE 4242
