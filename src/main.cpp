#include <stdio.h>
#include <iostream>
#include <curl/curl.h>

std::string handleArgs(int argc, char** argv){
    if(argc == 2){
        return argv[1];
    }
    return "";
}

int main(int argc, char** argv)
{
    std::string webpage = handleArgs(argc, argv);   
    if(webpage != ""){

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    curl = curl_easy_init();
    if(curl){
        std::string url = "https://"+webpage;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    
        #ifdef SKIP_PEER_VERIFICATION
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        #endif

        #ifdef SKIP_HOSTNAME_VERIFICATION
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        #endif

        res = curl_easy_perform(curl);

        if(res != CURLE_OK)
        {
            std::cout << "curl_easy_perform() failed " << curl_easy_strerror(res) << "\n"; 
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    }else{
        std::cout << "Error: A webpage url is required./n The program will now exit/n"; 
    }
    return 0; 
}