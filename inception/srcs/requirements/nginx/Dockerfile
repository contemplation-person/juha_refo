FROM debian:bullseye

RUN apt update && apt upgrade -y && apt install nginx curl openssl -y

COPY ./tools /test

# create certification
RUN chmod +x ./test/certification.sh && ./test/certification.sh

# copy nginx configration
COPY ./tools/nginx.conf /etc/nginx/sites-available/default

# TODO 실행.
EXPOSE 443
# EXPOSE 80
# ENTRYPOINT nginx -g "daemon off;"
