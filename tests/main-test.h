#include "UniquePointer-test.h"
#include "Singleton-test.h"

#include <gtest/gtest.h>

#if defined(_WIN32) || defined(WIN32)
#if defined(MEMORY_LEAK)
#define _DEBUG
#include <vld.h>
#endif
#endif

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
