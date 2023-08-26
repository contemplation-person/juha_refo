# DOCKER_COMPOSE := ~/Desktop/docker-compose-darwin-x86_64
DOCKER_COMPOSE := docker compose

.PHONY : all down iclean vclean fclean re

all: up

re: fclean all

up: 
	mkdir -p -m 755 ./srcs/requirements/wordpress/data ./srcs/requirements/mariadb/data
	cd srcs && ${DOCKER_COMPOSE} up --build

ls:
	docker container ls -a
	docker images -a
	docker volume ls
	docker network ls

down:
	cd srcs && ${DOCKER_COMPOSE} down --rmi all -v

cclean:
	docker container prune -f

iclean:
	docker image prune -af

vclean:
	docker volume prune -f

clean:
	docker compose down
	make cclean
	make vclean

fclean: 
	sudo rm -rf ./srcs/requirements/wordpress/data ./srcs/requirements/mariadb/data
	make down 
	make cclean
	make iclean 
	make vclean
	docker system prune -af
