# Install dependencies
On Ubuntu 20.04:
```sh
sudo apt install cmake gcc-arm-none-eabi
```

# Compile
From the `fw/preamp` directory:
```sh
mkdir build
cd build
cmake ..
make
```

## Debug Build
To set debug build:
```sh
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```
