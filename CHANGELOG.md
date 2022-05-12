## 1.0.2
1. WebSocket client throw server error msg when request error
2. Http support GET method use array param in Json Body
    - json!{"symbol": ["700.HK", "APPLE.US"]} => symbol=700.HK&symbol=APPLE.US

## 1.0.1
1. Auth token rename to access_token
2. tokio update version to 1.18

## 1.0.0
1. 提供长桥接口的 HttpClient
2. 提供长桥长链接的 WebSocketClient
3. 提供基础的日志工具
4. 提供长桥接口的 proto 文件