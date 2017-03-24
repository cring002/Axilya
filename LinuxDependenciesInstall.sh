#!/bin/bash
mkdir temp
cd temp
echo "This script will download and install g++, libGL, SDL2, FreeType, libCurl, SDL2_ttf and SDL2_mixer"
echo "It may require your password to login or a response to confirm downloads."
#apts
sudo apt-get update
sudo apt-get install g++
sudo apt-get install libgl-dev
#download FreeType
echo "Downloading freetype"
curl -L http://download.savannah.gnu.org/releases/freetype/freetype-2.7.tar.gz -o freetype-2.7.tar.gz
tar -xzf freetype-2.7.tar.gz
cd freetype-2.7
./configure
make && sudo make install
cd ../
#download libcurl
echo "Downloading libcurl"
curl https://curl.haxx.se/download/curl-7.53.1.tar.gz -o curl-7.53.1.tar.gz
tar -xzf curl-7.53.1.tar.gz
cd curl-7.53.1
./configure
make && sudo make install
cd ../
#download SDL2
echo "Downloading SDL2.0.5"
curl https://libsdl.org/release/SDL2-2.0.5.tar.gz -o SDL2-2.0.5.tar.gz
tar -xzf SDL2-2.0.5.tar.gz
cd SDL2-2.0.5
./configure
make && sudo make install
cd ../
#download ttf
echo "Downloading SDL2 ttf"
curl https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.tar.gz -o SDL2_ttf-2.0.14.tar.gz
tar -xzf SDL2_ttf-2.0.14.tar.gz
cd SDL2_ttf-2.0.14
./configure
make && sudo make install
cd ../
#download mixer
echo "Downloading SDL2 mixer"
curl https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.1.tar.gz -o SDL2_mixer-2.0.1.tar.gz
tar -xzf SDL2_mixer-2.0.1.tar.gz
cd SDL2_mixer-2.0.1
./configure
make && sudo make install
cd ../../
echo "Complete, cleaning up"
rm -rf temp