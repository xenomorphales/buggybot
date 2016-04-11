#include <hal/uart.hpp>
#include <stream/hal/uart_stream.hpp>

#include <container/buffer.hpp>

#include <protocol/protocol.hpp>
#include <protocol/payload.hpp>
#include <protocol/parser.hpp>

#include <feetech/sc.hpp>
#include "test.hpp"
#include "sc_switcher.hpp"

#include <avr/wdt.h>

using namespace HAL;

auto& MY_UART = UART0; // Choose the UART
auto& TX = E1;         // Choose the TX pin
auto& RX = E0;         // Choose the RX pin

u8 max_servo = 0;

Protocol::Parser<2, 128> parser;
u16 i = 0;

SCSwitcher sc;
//auto& sc = sc2;

Container::Buffer<128, char> inbuff;

void flush_inbuff(void) {
  while(!inbuff.isEmpty()) {
      char c = inbuff.head();
      parser.parse((u8*)&c, 1);
      inbuff.dequeue();
    }
}

int main(int, char**) {
  //wdt_enable(WDTO_120MS);

  UART::Settings settings;
  settings.baudrate = 38400;
  settings.parity = UART::Parity::NONE;
  settings.stop_bit = UART::StopBit::ONE_BIT;
  settings.word_size = 8;

  parser.addHandler(Protocol::DefaultHandler<Protocol::Message, Actuator::ServoPosition>([](const void* msg){
      wdt_reset();
      auto pak = *(Protocol::Pack<Protocol::Message, Actuator::ServoPosition>*)msg;
      if(pak.message.payload.enabled) {
          sc.enableTorque(pak.message.payload.id);
          wdt_reset();
          sc.setPosition(pak.message.payload.id, pak.message.payload.position);
          wdt_reset();
        }
      else {
          sc.disableTorque(pak.message.payload.id);
          wdt_reset();
        }
    }));

  UART::init(MY_UART, TX, RX, settings);
  UART::setHandler(MY_UART, UART::Event::RX_COMPLETE, [](){
          char c = UART::getChar(MY_UART);
          //parser.parse((u8*)&c, 1);
          inbuff.enqueue(c);
    });

  ::HDL::sei();

  while(1) {
      wdt_reset();
      flush_inbuff();

      if(0 == max_servo) {

          for(u8 i = 1 ; i < 0xfe ; i++) {
              wdt_reset();
              if(sc.ping(i)) {
                  max_servo = i+1;
                }
            }

        }
      else {

          if(sc.ping(1)) {
              sc.setId(1, max_servo);
              wdt_reset();
              max_servo++;
            }

          for(u8 i = 2 ; i < max_servo ; i++) {
              Protocol::Pack<Protocol::Message, Actuator::ServoPosition> pak;
              pak.message.payload.id = i;
              pak.message.payload.enabled = sc.isTorqueEnabled(i);
              wdt_reset();
              pak.message.payload.position = sc.getPosition(i);
              wdt_reset();
              u8* data = Protocol::pack(pak);
              UART::write(MY_UART, data, sizeof(pak));
              wdt_reset();
            }

        }
    }

  return 0;
}
