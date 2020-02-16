> c++ 日常联系, 使用 cmake 构建
> 建议使用 CLion 编辑器打开
>
> cmake 3.15

---

run

- windows

    1. clion 中重置 cmake 缓存: *tools -> cmake -> reset cache and reload project*. 过几秒就可以重新生成, 就可以 build and run.
    2. 可以直接 build 或 使用命令
    
        ```json
        cmake.exe --build E:\ws_cpp\CppLab\cmake-build-debug --target CppLab -- -j 6
        ```
    
- linux

    ```json
    mkdir build
    cd build
    cmake ..
    make
    ```



---