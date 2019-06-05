#include "readint.h"
#include "gtest/gtest.h"
#include <iostream>
#include <fstream>

using namespace std;

TEST(TestCase, FirstCase) {
    istringstream ss("Hello\n0");
    //if (inp.fail())
    //    throw int(-1);

    // Replace the cin read buffer with the read buffer from the file stream
    streambuf *orig_cin = cin.rdbuf(ss.rdbuf());
    
    ASSERT_EQ(0, read_int("My Prompt: ", -3, 3));

    //return to normal cin
    cin.rdbuf(orig_cin);

    //ss.close();
}

TEST(TestCase, Exception) {
    ASSERT_THROW(read_int("My Prompt: ", 5, 1),invalid_argument);
}

TEST(TestCase, input3) {
    istringstream ss("-3\n5\n10\n-2\n3");
    //ifstream ss("outRange.txt");
    if (ss.fail())
        throw int(-1);
     

    // Replace the cin read buffer with the read buffer from the file stream
    streambuf *orig_cin = cin.rdbuf(ss.rdbuf());
    
    ASSERT_EQ(3, read_int("My Prompt: ", 0, 4));

    //return to normal cin
    cin.rdbuf(orig_cin);

    //ss.close();
}

TEST(TestCase, ExceptionOf0) {
    ASSERT_THROW(read_int("My Prompt: ", 0, 0),invalid_argument);
}
int main (int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}