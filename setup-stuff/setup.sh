sudo apt-get update

#install minecraft tools
mkdir ../temp-stuff
unzip ../setup-stuff/MinecraftToolsLinux.zip -d ../temp-stuff/MAPI
pip install --upgrade pip

cd ../temp-stuff/MAPI/Minecraft_Tools/
sudo chmod 777 Install_API.sh
sudo chmod 777 start_server.sh 
sudo ./Install_API.sh

#install MCPP
cd ../../
git clone https://github.com/rozukke/mcpp.git
cd mcpp
cmake .
make
sudo cp ./src/libmcpp.a /usr/local/lib/
sudo cp -r ./include/mcpp /usr/local/include/ 
