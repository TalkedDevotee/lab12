#include <iostream>
#include <future>
#include <thread>
#include <curl/curl.h>

using namespace std;

void GetResponse(char* &url)
{
   CURL *curl;
   CURLcode res;
   curl = curl_easy_init();
   if (curl)
   {
      curl_easy_setopt(curl, CURLOPT_URL, url);
      curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
      curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
      res = curl_easy_perform(curl);
      if (res == CURLE_OK)
      {
         long response_code = 0;
         curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
         cout << "Response answer: " << response_code << endl;
      }
      else
      {
         cout << "Code 'curl_easy_perform()' failed: " << curl_easy_strerror(res) << endl;
      }
      curl_easy_cleanup(curl);
   }
}

int main(int argc, char* argv[])
{
   char *url = argv[1];
   promise char *promise;
   future char *future;
   future = promise.get_future();
   thread thread (GetResponse, ref(future));
   promise.set_value(url);
   thread.join();
   return 0;
}
