#include "nzmqtApp.h"

int main(int argc, char *argv[])
{
    NzmqtApp nzmqtApp(argc, argv);

    return nzmqtApp.exec();
}
