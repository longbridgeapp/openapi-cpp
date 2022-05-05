# Longbridge OpenAPI SDK for C++

- [简体中文](./README_zh.md)
- [繁体中文](./README_hk.md)

## User Guide

Longbridge OpenAPI SDK offer to use your [Auth](https://open.longbridgeapp.com) to create HttpClient and WebSocketClient.

HttpClient has `get`, `post`, `put`, `del` method, and you can use it to call the [API](https://open.longbridgeapp.com/docs) conveniently.

WebSocketClient has `send_request` method, and you can register the message callback and the WebSocket State callback.
You can have the user-defined function to handle the push message and WebSocket State change. 

Meanwhile the SDK offer the log utility, user can have custom log path, and default path is  [path](https://docs.rs/dirs/4.0.0/dirs/fn.data_local_dir.html) `/Longbridge OpenAPI`，
except macOS system's is `$HOME/Library/Logs/Longbridge OpenAPI`. The log file default is `longbridge.log`.

**If you have any question about using the SDK, please raising an issue。**

### Requirement

- C++ compile (at least C++11 standard)
  - clang (MacOS)
  - gcc (Unix)
  - msvc (Windows only)
- CMake build system
- Protobuf installed

### Usage
### Download the SDK
   ```bash
   # clone sdk repo
   cd /your/path
   git clone https://github.com/longbridgeapp//openapi-cpp.git
   # init submodule about proto
   cd openapi-cpp
   git submodule update --init
   ```

> NOTE: Use need know yourself dev environment, and select the suitable arch static lib.

Open the [Longbridge OpenAPI official site](https://open.longbridgeapp.com/account), and get your
**App Key**, **App Secret**, **Access Token**.

Unzip the downloaded static lib to the path `openapi-cpp/lib`.

And you can use the SDK's HttpClient and WebSocketClient develop yourself application.

## Run Demo

Replacing the `app_key`, `app_secret`, `access_token` in `demo/src/const/value.h` as the value you get from forward step.

- Clion user can open the project, and demo has three binary target, you can run directly.
- Unix-like user else can run follow shell.

  ```bash
  cd /path/to/lb-openapi-cpp
  mkdir build
  cmake ..
  make

  # run the binary
  # cd demo
  # ./http
  # ./ws_test
  # ./logger
  ```

- Windows user can config cmake plugin in VS Code, press `CMD + Shift + P` open the command window, input `CMake:Config`, auto create the build directory.
and the bottom button run the selected binary.
- Other user can read the follow Fully Document to config project as yourself.

## User Fully Document

### Project Dir

```bash
demo
 └─src -- demo src
    └─proto -- protobuf generate .cc/.h file
docs -- gendoc.sh will gen the doc in the directory
include -- SDK include file
lib -- User downloaded static lib
proto -- proto definition
src -- SDK cpp implementation
```

### Project compose

SDK mostly contain:

- HttpClient 
- WebSocketClient 
- Log utility
- proto file
- demo example


#### About Protobuf
`proto` directory submodule another repo, store the Protobuf Message definition from [the site](https://open.longbridgeapp.com/docs),  `demo/src/proto` store the generated cpp from proto file.
You can generate the cpp file by yourself.
