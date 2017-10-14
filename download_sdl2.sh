#!/bin/sh

/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)";

brew install sdl2;
brew install sdl2_image;
brew install sdl2_ttf;
