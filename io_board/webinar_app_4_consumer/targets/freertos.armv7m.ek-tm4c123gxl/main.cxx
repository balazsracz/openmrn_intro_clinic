#include "os/os.h"
#include "utils/blinker.h"

#include "nmranet/SimpleStack.hxx"

const uint64_t NODE_ID = 0x050101011801ULL;
nmranet::SimpleCanStack stack(NODE_ID);

extern const char *const nmranet::SNIP_DYNAMIC_FILENAME = "/dev/eeprom";

#include "BlinkerGPIO.hxx"
#include "nmranet/EventHandlerTemplates.hxx"

const uint64_t EVENT_ID = 0x0501010118010203ULL;
nmranet::GPIOBit blinker_bit(
    stack.node(), EVENT_ID, EVENT_ID + 1, BLINKER_Pin());
nmranet::BitEventConsumer consumer(&blinker_bit);

int appl_main(int argc, char *argv[])
{
    // Add one of these three
    // stack.add_can_port_select("/dev/can0");
    // stack.add_gridconnect_port("/dev/serUSB0");
    stack.add_gridconnect_port("/dev/ser0");

    stack.loop_executor();
    return 0;
}
