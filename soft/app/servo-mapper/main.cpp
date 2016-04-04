#include <iostream>
#include <cmath>
#include <functional>

#include <unistd.h>

#include <zmq.hpp>

#include <cereal/archives/json.hpp>

using namespace std;

int main(int argc, char* argv[]) {
  zmq::context_t ctx(1);

  zmq::socket_t sock(ctx, ZMQ_PUB);

  while(1) {

      cout << "Connecting..." << endl;
      try {
        sock.connect("ipc://embed.out");

        cout << "Connected !" << endl;
        while(sock.connected()) {
            std::stringstream ss;

            {
              cereal::JSONOutputArchive ar(ss);
              ar(string("pos"), (uint8_t)3, (uint16_t)512);
            }

            zmq::message_t msg(ss.str().size());
            ss.str().copy((char*)msg.data(), msg.size());

            sock.send(msg);
            sleep(1);
          }
      }
      catch(zmq::error_t e) {
        cout << e.what() << endl;
        sleep(5);
      }
    }

  return 0;
}

