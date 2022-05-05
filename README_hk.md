# Longbridge OpenAPI SDK for C++

## 用户手冊

Longbridge OpenAPI SDK 提供了通過[用户認證獲取的 Auth](https://open.longbridgeapp.com) 創建 HttpClient 和 WebSocketClient 的能力。

HttpClient 提供了標準的 `get`, `post`, `put`, `del` 方法，方便用户使用 [接口官網](https://open.longbridgeapp.com/docs) 的接口。

WebSocketClient 提供了請求的方法，以及推送消息的回調定義和註冊，支持用户請求行情或者訂閲股票數據在回調函數中處理推送數據。

同時還提供了基本的日誌能力，方便用户使用，日誌路徑支持用户自定義，默認路徑是 [path](https://docs.rs/dirs/4.0.0/dirs/fn.data_local_dir.html) `/Longbridge OpenAPI`，

需要注意 macOS 系統的默認路徑是 `$HOME/Library/Logs/Longbridge OpenAPI`。日誌的默認名稱是 `longbridge.log`。

**如果在使用過程中出現問題或者有什麼疑問，請提出 Issue。**

### 準備

- C++ 編譯環境（至少支持 C++ 11 標準的編譯器）
  - clang (MacOS)
  - gcc (Unix)
  - msvc (Windows only)
- CMake 構建工具
- Protobuf 環境

### Usage
### 下載 SDK 庫
   ```bash
   # clone sdk repo
   cd /your/path
   git clone https://github.com/longbridgeapp//openapi-cpp.git
   # init submodule about proto
   cd openapi-cpp
   git submodule update --init
   ```

> NOTE: 首先用户需要根據自己的開發環境在 Release 中選擇需要的庫文件鏈接

訪問 OpenAPI 開發者認證，獲得 **App Key**, **App Secret**, **Access Token**

https://open.longbridgeapp.com/account

然後將壓縮包解壓得到靜態庫文件移動到 `openapi-cpp/lib` 中，並將 `demo/src/const_value.h` 中的 `app_key`, `app_secret`, `access_token` 替換成申請到的值。

## 運行 Demo

- Clion 用户可以直接打開本工程，demo 中已經有了三個 binary_target 直接運行即可。
- Unix-like 用户也可以直接運行下面的命令

  ```bash
  cd /path/to/lb-openapi-cpp
  mkdir build
  cmake ..
  make

  # 執行編譯得到的 binary 可執行文件
  # cd demo
  # ./http
  # ./ws_test
  # ./logger
  ```

- Windows 用户可以使用 VS Code 配置 C++ / CMake 插件後，`CMD + Shift + P` 打開命令執行窗口，使用 `CMake:Config`，會自動創建 build 目錄，
  在 VS Code 下方的執行按鈕選擇 binary_target 選擇執行即可
- 不使用上述工具的用户請參看下面的 User Fully Document 自行配置項目

## User Fully Document

### 工程目錄

```bash
demo
 └─src -- demo 示例代碼
    └─proto -- proto 生成的 pb.cc/pb.h 文件
docs -- 可以通過根目錄 gendoc.sh 生成文檔到該目錄
include -- SDK 的頭文件
lib -- 用户自主下載的對應庫文件
proto -- 接口的 proto 消息定義
src -- SDK cpp 的實現
```

### 工程詳解

SDK 主要分為幾個部分

- HttpClient 實現
- WebSocketClient 實現
- 日誌工具
- proto 文件定義
- demo 示例

你可以方便的使用 HttpClient 和 WebSocketClient 調用 [官網](https://open.longbridgeapp.com) 提供的長橋行情和交易接口，
日誌工具可以選用，也可以使用你現有的日誌工具，demo 示例提供了使用兩種 Client 的示例。

#### 關於 Protobuf 文件
proto 文件中存在官網定義的 pb 消息文件， `demo/src/proto` 是通過 proto 中的 pb 文件編譯好的文件，
用户可以自行更新編譯最新的 pb 文件
