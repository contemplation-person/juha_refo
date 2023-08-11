.PHONY : all down iclean vclean fclean re

all: up

re: fclean all

up: 
	mkdir ./srcs/requirements/wordpress/wp-data
	cd srcs && docker compose up

ls:
	docker container ls -a
	docker images -a
	docker volume ls
	docker network ls

down:
	cd srcs && docker compose down

cclean:
	docker container prune -f

iclean:
	docker image prune -af

vclean:
	docker volume prune -f

fclean: 
	make down 
	rm -rf ./srcs/requirements/wordpress/wp-data
	make cclean
	make iclean 
	make vclean
	docker system prune -af
