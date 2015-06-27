#include "os/os.h"
#include "utils/blinker.h"

#include "nmranet/SimpleStack.hxx"

const uint64_t NODE_ID = 0x050101011801ULL;
nmranet::SimpleCanStack stack(NODE_ID);

extern const char* const nmranet::SNIP_DYNAMIC_FILENAME = "/dev/eeprom";

int appl_main(int argc, char*argv[]) {
    stack.print_all_packets();
    stack.loop_executor();
    return 0;
}
