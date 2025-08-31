# project-example
this project shows how to build cmake, ros and ros2 packages and handle their denpendency.

## cmake-example
- 纯 cmake 环境下, 两种方式: make install & subdirrectory
- ros2 环境下，colcon 可以自动 build 并处理包的依赖关系，非常方便
 
### make install

#### packageA (被依赖的包)
- CMakeLists 需要包含安装库(.a/.so),头文件(.h)和配置文件(cmake)的命令，参考 cmake-example/src/packageA/CMakeLists.txt
- cmake 时需要指定 CMAKE_INSTALL_PREFIX ，不指定也可以，但是会安装到 /usr/local

#### packageB (依赖 packageA 的包)
- CMakeLists 需要 find_package，参考 cmake-example/src/packageB/CMakeLists.txt
- cmake 时需要指定 DCMAKE_PREFIX_PATH
```bash
export WORKSPACE=/root/code/third_party
cd cmake-example/src/packageA
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=$WORKSPACE/packageA
make install
```

```bash
export WORKSPACE=/root/code/third_party
cd cmake-example/src/packageB
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH=$WORKSPACE
make
```

### subdirrectory
- 在顶层创建 CMakeLists.txt, 内容参考 cmake-example/CMakeLists.txt 
- 保证工程结构为:
```
project
├── build
├── src
    ├── packageA
    ├── packageB
├── CMakeLists.txt
```

```bash
cd cmake-example
mkdir build
cd build
cmake ..
make
```

### colcon
无论是使用 make install 还是 subdirectory 的库， colcon 都可以很好的处理

#### subdirectory
```bash
cd cmake-example
colcon list
# 输出应该是: cmake-example   .       (cmake)
colcon build
./build/cmake-example/src/packageB/packageB
```

#### make install
colcon 会默认使用顶层的 CMakeLists.txt ，从而使用 subdirectory，所以需要先删除顶层的 CMakeLists.txt
```bash
cd cmake-example
rm CMakeLists.txt
colcon list
# 输出应该是: 
# packageA        src/packageA    (cmake)
# packageB        src/packageB    (cmake)
colcon build
./build/packageB/packageB
```