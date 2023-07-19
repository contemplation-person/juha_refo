.PHONY: all build up down start stop down-volumes erase fclean ls

all : 
	make build
	make up

build :
	@docker compose -f ./srcs/docker-compose.yml build

up :
	@docker compose -f ./srcs/docker-compose.yml up -d

down :
	@docker compose -f ./srcs/docker-compose.yml down
# @docker compose -f ./srcs/docker-compose.yml down --volumes

start :
	@docker compose -f ./srcs/docker-compose.yml start

stop :
	@docker compose -f ./srcs/docker-compose.yml stop

down-volumes :
	@docker compose -f ./srcs/docker-compose.yml down --volumes

erase :
	docker rm -f `docker ps -aq`
	docker rmi -f `docker images -aq`
	
fclean:
	docker stop `docker ps -aq`
	docker rm `docker ps -aq`
	docker rmi `docker images -aq`
	docker compose -f ./srcs/docker-compose.yml down --volumes
	
ls:
	@echo container
	@docker ps -a
	@echo
	@echo images 
	@docker images
	@echo
	@echo volumes
	@docker volume ls
	@echo