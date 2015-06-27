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

#include "TivaGPIO.hxx"
// The first LED is driven by the blinker device from BlinkerGPIO.hxx. We just
// create an alias for symmetry.
typedef BLINKER_Pin LED_RED_Pin;
// These are GPIO output pins from TivaGPIO.hxx
GPIO_PIN(LED_GREEN, LedPin, F, 3);
GPIO_PIN(LED_BLUE, LedPin, F, 2);

nmranet::ConfiguredConsumer consumer_red(stack.node(),
    cfg.seg().consumers().entry<0>(), LED_RED_Pin());
nmranet::ConfiguredConsumer consumer_green(stack.node(),
    cfg.seg().consumers().entry<1>(), LED_GREEN_Pin());
nmranet::ConfiguredConsumer consumer_blue(stack.node(),
    cfg.seg().consumers().entry<2>(), LED_BLUE_Pin());

int appl_main(int argc, char *argv[])
{
    // Add one of these three
    // stack.add_can_port_select("/dev/can0");
    // stack.add_gridconnect_port("/dev/serUSB0");
    stack.add_gridconnect_port("/dev/ser0");

    stack.loop_executor();
    return 0;
}
