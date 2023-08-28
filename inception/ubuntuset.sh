#!/bin/bash

sudo su - << done
juha
done
sudo echo "juha  ALL=(ALL) ALL" >> /etc/sudoers

sudo apt update && sudo apt upgrade -y && sudo apt install -y curl openssh-server vim << done
ssh-keygen << done



done
sudo echo "Port 4242" >> /etc/ssh/sshd_config
sudo ufw allow 4242 
exit
sudo apt update << done
juha
done

#install chrome
sudo wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo dpkg -i ~/Downloads/google-chrome-stable_current_amd64.deb

sudo curl -fsSL https://get.docker.com -o get-docker.sh
sudo chmod +x get-docker.sh
sudo sh ./get-docker.sh --dry-run