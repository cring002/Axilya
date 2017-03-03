#include "headers/AXNetwork.hpp"

bool AXNetwork::hasInit = false;

AXNetwork::~AXNetwork(){
	curl_global_cleanup();
}

void AXNetwork::init(){
	if(hasInit){
		return;
	}
	curl_global_init(CURL_GLOBAL_ALL);
	hasInit = true;
}

bool AXNetwork::POSTRequestSimple(const std::string& url, const std::vector<AXNetworkPair>& pair){
	CURL* curl = curl_easy_init();
	CURLcode res;
	if(curl) {
	    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	    if(pair.size() > 0){
		    std::string post;
		    //construct the first kvp without a &
		    post.append(pair[0].first);
		    post.append("=");
		    post.append(pair[0].second);
		    //for the rest build &first=second etc.
		    for(int i = 1; i < pair.size(); i++){
		    	post.append("&");
			    post.append(pair[i].first);
		    	post.append("=");
		    	post.append(pair[i].second);
		    }
		    //set the post fields
		    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post.c_str());
		}
		//send
	    res = curl_easy_perform(curl);
	    //if it broke
	    if(res != CURLE_OK){
	      fprintf(stderr, "POSTRequestSimple failed to send: %s\n", curl_easy_strerror(res));
	      curl_easy_cleanup(curl);
	      return false;
	    }
	    curl_easy_cleanup(curl);
	    return true;
    }else{
    	return false;
    }
}