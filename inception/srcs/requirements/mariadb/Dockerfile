FROM debian:bullseye

RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install mariadb-server -y

# 디렉터리 위치  나중에  다시  확인해보기
COPY ./tools/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools/script.sh /

CMD ["/script.sh"]

# RUN chmod +x /script.sh
# ENTRYPOINT ["/script.sh"]

# ENTRYPOINT [ "executable" ]

# 권한이 없어서 VM에서만 가능
# CMD ["/script.sh"]
