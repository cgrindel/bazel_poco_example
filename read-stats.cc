#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>
#include <iostream>
#include <string>

using namespace Poco::Net;
using namespace Poco;
using namespace std;

int main(int argc, char **argv)
{
  try
  {
    // prepare session
    URI uri("http://localhost:8001");
    HTTPClientSession session(uri.getHost(), uri.getPort());
    // send request
    HTTPRequest request(HTTPRequest::HTTP_GET, "/stats/prometheus", HTTPMessage::HTTP_1_1);
    session.sendRequest(request);
    // get response
    HTTPResponse response;
    // print response
    istream &inStream = session.receiveResponse(response);
    std::string buffer;
    StreamCopier::copyToString(inStream, buffer);    
    cout << "Bingo [" << buffer << "] length = " << buffer.length() << endl;
  }
  catch (Exception &ex)
  {
    cerr << ex.displayText() << endl;
    return -1;
  }

  return 0;
}

