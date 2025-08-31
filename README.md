# project-example
this project shows how to build cmake, ros and ros2 packages and handle their denpendency.

## cmake-ros-example
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
cd cmake-ros2-example/src/packageA
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=$WORKSPACE/packageA
make install
```

```bash
export WORKSPACE=/root/code/third_party
cd cmake-ros2-example/src/packageB
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH=$WORKSPACE
make
```

### subdirectory
- 内容参考顶层 CMakeLists.txt 
```bash
cd project-example
mkdir build
cd build
cmake ..
make
./cmake-ros2-example/src/packageB/packageB
```

### colcon build
colcon 可以很好的处理纯 cmake 包和 ros2 包及其依赖关系, 且不需要手动 make install
```bash
cd cmake-ros2-example
colcon list
# 输出应该是: 
# packageA        src/packageA    (cmake)
# packageB        src/packageB    (cmake)
# package_b       src/package_b   (ros.ament_cmake)
colcon build
./build/packageB/packageB

source install/setup.bash
ros2 run package_b package_b 
```

colcon 也可以处理 subdirectory, 但是用处不大, 因为 subdirectory 只适用于纯 cmake 包，colcon 一般用于处理 ros2 包
#### subdirectory
```bash
cd project-example
colcon list
# 输出应该是: project-example   .       (cmake)
colcon build
./build/project-example/cmake-ros2-example/src/packageB/packageB
```

