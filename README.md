# pb

cross-platform progress bar on terminal written in C language

## COMPILE

### NATIVE ON UBUNTU

First, to build a native application, you need to install these dependencies

- build-essential
- mingw-w64 (If you need to cross compile to Windows)
- cmake (Cmake required for cross-compilation must be version 3.13 or higher)

```shell
cd lib/
sh download
sh compile
cd ..
mkdir -p build
cd build
cmake ..                                                    \
  -DCMAKE_BUILD_TYPE=Release                                \
  -D_0x7cc_sys_root=~/9fd7ba62-9402-4862-ae42-116ea2924339/
make
```

### MINGW-W64 ON UBUNTU

#### x86_64-w64-mingw32

```shell
cd lib/
sh download
sh compile-x86_64-w64-mingw32
cd ..
mkdir -p build
cd build
cmake ..                                                    \
  -DCMAKE_TOOLCHAIN_FILE=x86_64-w64-mingw32.cmake           \
  -DCMAKE_BUILD_TYPE=Release                                \
  -D_0x7cc_sys_root=~/fb23dec8-eff2-40e6-a614-733da8194d02/
make
```

#### i686-w64-mingw32

```shell
cd lib/
sh download
sh compile-i686-w64-mingw32
cd ..
mkdir -p build
cd build
cmake ..                                                    \
  -DCMAKE_TOOLCHAIN_FILE=i686-w64-mingw32.cmake             \
  -DCMAKE_BUILD_TYPE=Release                                \
  -D_0x7cc_sys_root=~/8a36e0b5-27a1-4eff-9f4d-ee4cc0975948/
make
```



