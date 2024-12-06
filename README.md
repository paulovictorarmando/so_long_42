# SO_LONG

###
So_long is a 42 project focused on creating a simple 2D game using the MiniLibX library. The goal is to develop a program where the player collects items, avoids obstacles, and reaches the exit of a map configured in a .ber file format. It emphasizes graphics handling, event management, and game logic.
###

### To perform the tests, make sure these packages are installed on your machine:
```
sudo apt update
sudo apt install libx11-dev
sudo apt install libxft-dev libxext-dev
sudo apt install libbsd-dev
```

## 🚀 Use
### 1. Clone the Repository
```
git clone https://github.com/paulovictorarmando/so_long_42.git
cd so_long_42
```
### 2.Build
Use the Makefile to compile the source files:
```
make all
```
### 3. Clean Up
To remove object files and the binary, run:
```
make clean
make fclean
```
### 4. Using:
```
./so_long map.ber
```
###
