NAME := python_piscine
RUN_OPTION := -it --privileged --name $(NAME) \
	-v ./volume:/mnt/volume

.PHONY: all build run clean fclean start re 

all: build run

build:
	mkdir -p volume
	docker build . -t $(NAME) $(ENV_OPTION)

run:
	docker run $(RUN_OPTION) $(NAME) bash

start:
	docker start -i $(NAME)

clean:
	docker container rm $(NAME)

fclean: clean
	docker image rm $(NAME)
	docker system prune -f

re:
	make -C . fclean
	make

