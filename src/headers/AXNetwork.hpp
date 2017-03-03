/**
* @file
* @author William Meaton <will.meaton@gmail.com>
*
* @section LICENSE
*
* The MIT License
* 
* Copyright (c) 2017 WillMeaton http://willmeaton.com
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
* @section DESCRIPTION
*
* This class allows users to use HTTP network requests.
*
*/

#ifndef AXNetwork_hpp
#define AXNetwork_hpp
#include <curl/curl.h>
#include <vector>
#include <utility>
#include <string>
typedef std::pair<std::string, std::string> AXNetworkPair;
class AXNetwork{
	static bool hasInit;
	~AXNetwork();
public:
    /*!
    * A method to initialise the AXNetwork class.
    *
    * This will be called at the start of the program automatically.
    */ 
	static void init();
    /*!
    * A method to send a simple HTTP POST with no callback.
    *
    * @param url the URL to send the POST request
    * @param pair a set of <key, value> pairs to send as parameters
    * @return if the POSTRequest completed successfully
    */ 
	static bool POSTRequestSimple(const std::string& url, const std::vector<AXNetworkPair>& pair);
};
#endif