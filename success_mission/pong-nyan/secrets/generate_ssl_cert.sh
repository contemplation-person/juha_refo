#/bin/sh

openssl req -x509 -nodes -days 365 -newkey rsa:2048\
  -keyout /etc/ssl/certs/localhost.key\
  -out /etc/ssl/certs/localhost.crt\
  -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost"
