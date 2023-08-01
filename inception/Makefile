.PHONY : all down iclean vclean fclean re

all: up

re: fclean all

up: 
	cd srcs && docker compose up

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
	make cclean
	make iclean 
	make vclean