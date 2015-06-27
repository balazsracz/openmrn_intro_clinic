#include "os/os.h"
#include "utils/blinker.h"

#include "config.hxx"
#include "nmranet/SimpleStack.hxx"

const uint64_t NODE_ID = 0x050101011801ULL;
nmranet::SimpleCanStack stack(NODE_ID);

extern const char *const nmranet::SNIP_DYNAMIC_FILENAME = "/dev/eeprom";

#include "BlinkerGPIO.hxx"

nmranet::ConfigDef cfg(0);
extern const char *const nmranet::CONFIG_FILENAME = "/dev/eeprom";
// The size of the memory space to export over the above device.
extern const size_t nmranet::CONFIG_FILE_SIZE =
    cfg.seg().size() + cfg.seg().offset();

nmranet::ConfiguredConsumer consumer(
    stack.node(), cfg.seg().blinker(), BLINKER_Pin());

int appl_main(int argc, char *argv[])
{
    // Add one of these three
    // stack.add_can_port_select("/dev/can0");
    // stack.add_gridconnect_port("/dev/serUSB0");
    stack.add_gridconnect_port("/dev/ser0");

    stack.loop_executor();
    return 0;
}
