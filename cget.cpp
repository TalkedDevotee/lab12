#include <iostream>
#include <future>
#include <thread>
#include <curl/curl.h>

using namespace std;

int main(int argc, char *argv[]) {

    CURL *curl = curl_easy_init();

    string url;

    if (argc < 2) 
    {
        cout << "Enter: ";
        getline(cin, url);
    }
	else 
	{
		url = argv[1];
	}

    if (curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);

        promise<CURLcode> promise;

        auto response = promise.get_future();

        thread request([curl, &promise]() 
	{
            promise.set_value(curl_easy_perform(curl));
        });

        request.detach();

        long response_code;

        auto res = response.get();

        if (res == CURLE_OK)
	{
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            cout << "Response code:" << answer << endl;
        }
        curl_easy_cleanup(curl);
    }
    return 0;
}
