DOCKER_COMPOSE := ~/goinfre/docker-compose-darwin-x86_64
# DOCKER_COMPOSE := docker compose

.PHONY : all down iclean vclean fclean re

all: up

re: fclean all

up: 
	mkdir -p ./srcs/requirements/wordpress/data ./srcs/requirements/mariadb/mariadb-db
	cd srcs && ${DOCKER_COMPOSE} up --build

ls:
	docker container ls -a
	docker images -a
	docker volume ls
	docker network ls

down:
	cd srcs && ${DOCKER_COMPOSE} down -v
	cd srcs && ${DOCKER_COMPOSE} down --rmi all -v

cclean:
	docker container prune -f

iclean:
	docker image prune -af

vclean:
	docker volume rm -f srcs_word
	docker volume prune -f

clean:
	docker compose down
	make cclean
	make vclean

fclean: 
	make down 
	make cclean
	make iclean 
	make vclean
	rm -rf ./srcs/requirements/wordpress/data ./srcs/requirements/mariadb/data/* -y
	docker system prune -af
