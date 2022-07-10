# GetWebpage
A program to display and download html from GET responses using ssl from a provided url.
This program uses LibCurl to handle the GET request and then outputs the resulting html to the screen. 

# Usage

./http-get <url>
Url should be in the format of www.example.com. The https protocol is automatically appended in the program.

If successful, the resulting response will be displayed in the console. 

# Compiling
## Mac
1. Install HomeBrew
2. Install Curl-Openssl
```
brew install curl-openssl
```
3. Make sure the makeFile has the correct paths for the curl variables. 
Brew generally outputs them after installation. 
```
CURL_LDFLAGS="-L/opt/homebrew/opt/curl/lib"
CURL_CPP_FLAGS="-I/opt/homebrew/opt/curl/include"
```
4. Create an obj and build folder 
```
mkdir obj build
```
5. Compile with make
```
make
```
6. The compiled program is stored in the build folder. 