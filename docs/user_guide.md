## 用户手册

lb-openapi-cpp SDK 提供了通过[用户认证获取的 Auth ](https://open.longbridgeapp.com)创建 HttpClient 和 WebSocketClient 的能力。

HttpClient 提供了标准的 `get`,`post`,`put`,`del` 方法，方便用户使用[接口官网](https://open.longbridgeapp.com/docs)的接口。

WebSocketClient 提供了请求的方法，以及推送消息的回调定义和注册，支持用户请求行情或者订阅股票数据在回调函数中处理推送数据。

同时还提供了基本的日志能力，方便用户使用，日志路径支持用户自定义，默认路径是 [path](https://docs.rs/dirs/4.0.0/dirs/fn.data_local_dir.html)`/Longbridge OpenAPI`，
需要注意 MacOS 系统的默认路径是 `$HOME/Library/Logs/Longbridge OpenAPI`。日志的默认名称是`longbridge.log`。

**如果在使用过程中出现问题或者有什么疑问，请提出 Issue。**


### 环境准备
- C++ 编译环境（至少支持 C++11 标准的编译器）
  - clang (MacOS)
  - gcc (Unix)
  - msvc (Windows only)
- CMake 构建工具 
- Protobuf 环境

### Get Started
1. clone 本项目到本地
    ```shell
    cd /your/path
    git clone https://github.com/longbridgeapp/lb-openapi-cpp.git
    ```
2. 下载 SDK 的库文件并选择对应的文件内容

    **首先用户需要根据自己的开发环境在 Release 中选择需要的库文件链接**

    然后将压缩包解压得到静态库文件移动到 lb-openapi-cpp/lib 中
3. 将 demo/src/const_value.h 中的 `app_key, app_secret, token` 替换成申请到的值
4. 运行 Demo 文件夹中的示例

    - Clion 用户可以直接打开本工程，demo 中已经有了三个 binary_target 直接运行即可。
    - Unix-like 用户也可以直接运行下面的命令
      ```shell
      cd /path/to/lb-openapi-cpp
      mkdir build
      cmake ..
      make
        
      # 执行编译得到的 binary 可执行文件      
      # ./http
      # ./ws_test
      # ./logger
      ```
    - Windows 用户可以使用 VSCode 配置 C++/CMake 插件后，`Ctrl+Shift+P` 打开命令执行窗口，使用 `CMake:Config`，会自动创建 build 目录，
        在 VSCode 下方的执行按钮选择 binary_target 选择执行即可
    - 不使用上述工具的用户请参看下面的 User Fully Document 自行配置项目 

### User Fully Document
#### 工程目录
```shell
demo 
 └─src -- demo 示例代码
    └─proto -- proto 生成的 pb.cc/pb.h 文件
docs -- 可以通过根目录 gendoc.sh 生成文档到该目录
include -- SDK 的头文件
lib -- 用户自主下载的对应库文件
proto -- 接口的 proto 消息定义
src -- SDK cpp 的实现
```

#### 工程详解
SDK 主要分为几个部分
- HttpClient 实现
- WebSocketClient 实现
- 日志工具
- proto 文件定义
- demo 示例

你可以方便的使用 HttpClient 和 WebSocketClient 调用[官网](https://open.longbridgeapp.com)提供的长桥行情和交易接口，
日志工具可以选用，也可以使用你现有的日志工具，demo 示例提供了使用两种 Client 的示例。





