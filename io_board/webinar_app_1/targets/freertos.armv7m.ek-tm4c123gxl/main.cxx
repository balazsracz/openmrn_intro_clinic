#include "os/os.h"
#include "utils/blinker.h"

int appl_main(int argc, char*argv[]) {
    resetblink(0x800F2);
    while(true) {}
    return 0;
}
