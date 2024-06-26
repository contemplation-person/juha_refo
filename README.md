# Hi Juha_refo

Usage

```shell
git clone git@github.com:contemplation-person/juha_refo.git --recursive-submodul
```

## summary

This repository is the outcome of my project-based learning (PBL) at 42 Seoul.  
All assignments were written for the Intel Mac environment.

## contents

| index (readme)  |                                                   Project name (refo)                                                    | Simple explanation                                                                                                                   |                         Skill                         | Collaboration  |
| :-------------: | :----------------------------------------------------------------------------------------------------------------------: | ------------------------------------------------------------------------------------------------------------------------------------ | :---------------------------------------------------: | :------------: |
| [1](#pong-nyan) |      [pong-nyan](https://github.com/pong-nyan/pong-nyan/tree/33c0c451e01b6fa4921665fc78dd165a5ff368ee 'pong-nyan')       | make [ping-pong game](https://docs.pong-nyan.site/) website                                                                          | Typescript, next, nest, docker, postgresql, metter.js |    5 people    |
|    [2](#irc)    |              [IRC](https://github.com/5Circle42IRC/IRC/tree/4136d45d78612c07b6d22208b89892a9fe776f35 'IRC')              | make [irc](https://datatracker.ietf.org/doc/html/rfc1459) chatting program                                                           |                          cpp                          |    3 people    |
| [3](#inception) |            [inception](https://github.com/contemplation-person/juha_refo/tree/main/success_mission/inception)            | written Dockerfiles for WordPress, Nginx, and MariaDB, and bundled them together using Docker Compose, then deployed them to Docker. |                        docker                         | single project |
|    [4](#cpp)    |                  [CPP](https://github.com/contemplation-person/juha_refo/tree/main/success_mission/CPP)                  | I have acquired fundamental [C++](https://en.cppreference.com/w/) skills.                                                            |                          cpp                          | single project |
|   [5](#philo)   |                [philo](https://github.com/contemplation-person/juha_refo/tree/main/success_mission/philo)                | I implemented the well-known Dining Philosophers problem and experimented with multi-threading.                                      |                           C                           | single project |
| [6](#minishell) | [minishell](https://github.com/contemplation-person/minishell/tree/66994c69098979f35fe7778f190e06af55e2f7a3 'minishell') | make small shell                                                                                                                     |                           C                           |    2 people    |
|  [7](#so_long)  |              [so_long](https://github.com/contemplation-person/juha_refo/tree/main/success_mission/so_long)              | Implementing a Small 2D Game using MLX                                                                                               |                           C                           | single project |
|   [8](#pipex)   |                [pipex](https://github.com/contemplation-person/juha_refo/tree/main/success_mission/pipex)                | Implementing Pipe Communication.                                                                                                     |                           C                           | single project |
|  [9](#printf)   |               [printf](https://github.com/contemplation-person/juha_refo/tree/main/success_mission/printf)               | Implementing c function printf, using the Variadic Arguments                                                                         |                           C                           | single project |
|  [10](#libft)   |                [libft](https://github.com/contemplation-person/juha_refo/tree/main/success_mission/libft)                | Creating My Own Library                                                                                                              |                           C                           | single project |

---

## Detail

<!-- pong-nyan -->

### pong-nyan

<details>
<summary>web programming</summary>

## ![main](image/ts_main_page.png)

- In this assignment, the login function was implemented using Oauth.
  ![Oauth](image/ts_Oauth_login.png)

---

- If users wish, they can set up 2FA using Google Authenticator.
  ![2fa](image/ts_2fa.png)

---

- We have implemented an advanced game that combines the basic ping pong game and pinball.
  ![game](image/ts_game_page.png)
  ![game](image/ts_original_game.png)
  ![scoreboard1](image/ts_scoreboard.png)
  ![scoreboard1](image/ts_scoreboard_full.png)

---

- Chat channels and chat rooms have also been implemented, and user profiles can also be changed.
  ![chat](image/ts_chatting_channel.png)
  ![chat](image/ts_chatting_page.png)

---

- We also implemented a score page that shows each user's recorded score.
  ![score](image/ts_rank_page.png)

---

- We used nginx to connect the socket, front, and backend.
- User match records are stored in postgresql.
- A docker compose file was created to allow development regardless of the development environment, nest was used for the backend, and react and next were used for the frontend.
  ![docker](image/ts_docker.png)
- Rather than using a separate library to maintain the state, we implemented it individually using drilling technology.

[top](#contents)

</details>

---

### IRC

<details>

![IRC](image/IRC.png)

<summary>We created a chat server using the basic Internet Relay Chat Protocol. (socket programming)</summary>
* I created a server using multiplexing technology using the select function.
* I was in charge of server implementation and implemented the channel topic and mode.
[top](#contents)
</details>

---

### INCEPTION

<details>
<summary>docker programming</summary>
* This is a project that involves writing Dockerfiles and Docker Compose files to make Docker and Docker Compose work. To verify this, you need to make nginx, MariaDB, and WordPress run, and display the WordPress page.
---

![shell_prompt](image/in_operating_docker.png)
![shell_prompt](image/in_operating_docker_two.png)

- The shell prompt runs Docker based on the Dockerfile and Docker Compose file I have written.

---

![basic_webpage](image/in_basic_page.png)
![basic_weblogin](image/in_login_page.png)

- When you navigate from the default page to the login page, you can log in.

---

![basic_dashboard](image/in_basic_dashboard.png)
![Bulletin_board](image/in_wrriting_word.png)
![basic_Bulletin_board](image/in_writing_list_dashboard.png)
![basic_Bulletin_board](image/in_writing_list_page.png)

- Write a post on the bulletin board.

[top](#contents)

</details>

---

### CPP

<details>
<summary> chapter 00 : I have learned about namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff.  </summary>

![cpp00](image/CPP_zero.png)

- Module 00 - 00 is a simple project that prints a sentence.
- Module 00 - 01 is creating the phonebook.

Usage

```bash
cd juha_refo/success_mission/CPP/CPP00/ex*
make
```

</details>

<details>
<summary> chapter 01 : I have learned about Memory allocation, pointers to members, references, switch statement.</summary>

#### cpp01_00

![cpp01_00](image/CPP01_00.png)

- This program used C++ memory allocation techniques to create an object called "zombie."

Usage

```bash
cd juha_refo/success_mission/CPP/CPP01/ex00
make
./Zombie
```

---

#### cpp01_01

![cpp01_01](image/CPP01_01.png)

- I have written a C++ program that allocates and deallocates a zombie array.

Usage

```bash
cd juha_refo/success_mission/CPP/CPP01/ex01
make
./Zombie
```

---

#### cpp01_02

![cpp01_02](image/CPP01_02.png)

- I studied pointers and references, and confirmed the differences through output.

Usage

```bash
cd juha_refo/success_mission/CPP/CPP01/ex02
make
./Brain
```

---

#### cpp01_03

![cpp01_03](image/CPP01_03.png)

- I gained a clearer understanding of the differences between pointers and references through the specific situation of equipping weapons.

Usage

```bash
cd juha_refo/success_mission/CPP/CPP01/ex03
make
./Human
```

---

#### cpp01_04

![cpp01_04](image/CPP01_04.png)

- A program that reads the content of a file and replaces specific words or sentences with others.

Usage

```bash
cd juha_refo/success_mission/CPP/CPP01/ex03
make
./Replace infile "let it" "go"
```

---

#### cpp01_05

![cpp01_05](image/CPP01_05.png)

- The assignment is to learn writing elegant code using the switch statement.
- command : debug, info, warning, error

Usage

```bash
cd juha_refo/success_mission/CPP/CPP01/ex03
make
./Harl debug
```

---

#### cpp01_06

![cpp01_06](image/CPP01_06.png)

- The assignment is to learn writing elegant code using the switch statement.
- command : debug, info, warning, error

Usage

```bash
cd juha_refo/success_mission/CPP/CPP01/ex03
make
./Harl debug
```

</details>

<details>
<summary>chapter 02 : I have learned about Ad-hoc polymorphism, operator overloadingand Orthodox Canonical class form</summary>

#### cpp02_00

![cpp02_00](image/CPP02_00.png)

- The topic is learning about CPP's orthodox canonical form and polymorphism.

Usage

```bash
cd juha_refo/success_mission/CPP/CPP02/ex00
make
./Fixed
```

#### cpp02_01

![cpp02_01](image/CPP02_01.png)

- I study fixed point numbers

Usage

```bash
cd juha_refo/success_mission/CPP/CPP02/ex01
make
./Fixed
```

#### cpp02_02

![cpp02_02](image/CPP02_02.png)

- I study operator overloading

Usage

```bash
cd juha_refo/success_mission/CPP/CPP02/ex02
make
./Fixed
```

</details>
<!-- ------------------------ cpp 03 ---------------------- -->
<details>
<summary>chapter 03 : This chapter focuses on learning about inheritance in C++. Additionally, in this assignment, I studied about diamond inheritance.</summary>

#### cpp03_00

![cpp03_00](image/CPP03_00.png)

- Create a monster that can attack, repair itself, and display damage.

Usage

```bash
cd juha_refo/success_mission/CPP/CPP03/ex00
make
./ClapTrap
```

#### cpp03_01

![cpp03_01](image/CPP03_01.png)

- create ScavTrap by inheriting from the previously made ClapTraps, using constructors and destructors for ScavTrap. The functionalities for attack, repair, and damage display are used separately. Additionally, unlike ClapTraps, ScavTrap has defense capabilities.

Usage

```bash
cd juha_refo/success_mission/CPP/CPP03/ex01
make
./ScavTrap
```

#### cpp03_02

![cpp03_02](image/CPP03_02.png)

- Implement FragTrap, which inherits from ClapTrap, and ensure it displays different messages upon creation and destruction.Additionally, create a function named highFivesGuys.

Usage

```bash
cd juha_refo/success_mission/CPP/CPP03/ex02
make
./FragTrap
```

#### cpp03_03

![cpp03_03](image/CPP03_03.png)

- Inherit from ClapTrap and FragTrap using the name DiamondTrap, and implement a function called whoAmI to examine what occurs with "diamond inheritance."

Usage

```bash
cd juha_refo/success_mission/CPP/CPP03/ex03
make
./DiamondTrap
```

</details>

[top](#contents)

---

### philo

<details>

![Philosophers](image/philo.png)

<summary>A program that implements the famous dining philosophers problem in code.</summary>
* I used multithreading to write the program.
* The output may vary depending on the user's computer environment.

Usage

- 1 < Number of philosohpers < 100
- eating time + sleeping time \* 1.4 < Total suvival time
- 0 < Meal time per philosopher < INT_MAX

```bash
cd juha_refo/success_mission/philo
make; ./philo 20 500 200 200 4
#./philo [Number of philosophers] [Total survival time] [Eating time] [Sleeping time] [Meal time per philosopher]
```

[top](#contents)

</details>

---

### Minishell

<details>
<summary>It's an assignment to create a small shell.</summary>

![minishell](image/minishell.png)

Usage

```bash
cd juha_refo/success_mission/minishell
make; ./minishell
```

- Handle ’ (single quote) which should prevent the shell from interpreting the meta- characters in the quoted sequence.
- Handle " (double quote) which should prevent the shell from interpreting the meta- characters in the quoted sequence except for $ (dollar sign).
- Implement redirections:
- < should redirect input.
- \> should redirect output.
- << should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
- \>> should redirect output in append mode.
- Implement pipes (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
- Handle environment variables ($ followed by a sequence of characters) which should expand to their values.
- Handle $? which should expand to the exit status of the most recently executed foreground pipeline.
- Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
- In interactive mode:
- ctrl-C displays a new prompt on a new line.
- ctrl-D exits the shell.
- ctrl-\ does nothing.
- Your shell must implement the following builtins:
- echo with option -n
- cd with only a relative or absolute path
- pwd with no options
- export with no options
- unset with no options
- env with no options or arguments
- exit with no options

[top](#contents)

</details>

---

### So_long

<details>

![so_long](image/so_long.png)

<summary> It's a simple 2D program where you pass through the exit after collecting all the coins. </summary>

Usage

```bash
cd juha_refo/success_mission/so_long
make; ./so_long ./map/13.ber
```

Movement keys:
Up : w
Down : s
Left : a
Right: d

game clear condition

- Collect all the coins and exit pipe

[top](#contents)

</details>

---

### Pipex

<details>
<summary> The task is to implement pipes, a shell command-line option. </summary>

![pipex](image/pipex.png)

Usage

```bash
cd juha_refo/success_mission/printf
make; ./pipex [input_filename] [cmd] [cmd] [output_filename]
```

[top](#contents)

</details>

---

### Printf

<details>
<summary>make printf function</summary>

![Printf](image/printf.png)

- %c, %s, %p, %d, %i, %u, %x, %X, %% of actual printf were implemented using variable arguments.

Usage

```bash
cd juha_refo/success_mission/printf
make
```

[top](#contents)

</details>

---

### Libft

<details>
<summary> The libft task is to create my own static C library. </summary>

![Libft](image/libft.png)

- Some functions were created identically to the standard C library, and functions such as list functions and get_next_line were created as needed.

Usage

```bash
cd juha_refo/success_mission/libft
make
```

[top](#contents)

</details>
