FROM debian:bullseye

RUN apt update && apt upgrade && apt install nginx -y && apt install openssl
COPY ./tools /test

# create certification
RUN chmod +x ./test/certification.sh && ./test/certification.sh

# copy nginx configration
COPY ./nginx.conf /etc/nginx/sites-available/default

# TODO 실행.
EXPOSE 443
# EXPOSE 80
# ENTRYPOINT nginx -g "daemon off;"
