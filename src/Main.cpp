#include <game\Explorer.h>

int main() {

    if (Explorer::instance().init()) Explorer::instance().run();

    return Explorer::instance().stop();
}