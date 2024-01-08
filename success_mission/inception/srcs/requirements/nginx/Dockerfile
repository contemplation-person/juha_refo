FROM debian:bullseye

COPY ./tools /test

# create certification
RUN apt update && apt upgrade -y && apt install nginx curl openssl -y \
&& chmod +x ./test/certification.sh && ./test/certification.sh

# copy nginx configration
COPY ./tools/nginx.conf /etc/nginx/sites-available/default

EXPOSE 443
ENTRYPOINT nginx -g "daemon off;"
