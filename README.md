# external_gamemode_sample
Example for external ddnet-insta gamemode. Your boilerplate for custom modes!


**WARNING:** external gamemodes are still in draft state. This is not ready for use yet.


## quickstart

```
git clone --recursive https://github.com/ddnet-insta/ddnet-insta
git clone https://github.com/ddnet-insta/external_gamemode_sample ddnet-insta/src/external_gamemodes/sample
cd ddnet-insta
mkdir build
cd build
cmake ..
make

./DDNet-Server "sv_gametype sample"
```

