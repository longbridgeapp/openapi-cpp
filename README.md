# OpenAPI C++

Longbridge OpenSDK for C++ User. 

## Platform
OpenAPI use Rustls, and
Rustls uses ring for implementing the cryptography in TLS. 
As a result, rustls only runs on platforms supported by ring. 
At the time of writing this means x86, x86-64, armv7, and aarch64.

## User Guide
We offer [user guide](docs/user_guide.md) to help using this SDK.


## Reference
[1] https://docs.rs/rustls/latest/rustls/