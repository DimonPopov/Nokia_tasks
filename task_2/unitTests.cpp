#define BOOST_TEST_MAIN
#include "./deleteASCIIchain.hpp"
#include <boost/test/included/unit_test.hpp>
#define BOOST_TEST_MODULE test



BOOST_AUTO_TEST_SUITE(test)

BOOST_AUTO_TEST_CASE(test_emptyString){

    std::string testString = {""};
    std::string answerString = {""};

    deleteChain(testString);

    BOOST_CHECK_EQUAL_COLLECTIONS(testString.begin(), testString.end(), answerString.begin(), answerString.end());
    BOOST_CHECK_EQUAL(testString.length(), answerString.length());
}


BOOST_AUTO_TEST_CASE(test_oneSymbolString){

    std::string testString = {"a"};
    std::string answerString = {"a"};

    deleteChain(testString);

    BOOST_CHECK_EQUAL_COLLECTIONS(testString.begin(), testString.end(), answerString.begin(), answerString.end());
    BOOST_CHECK_EQUAL(testString.length(), answerString.length());
}


BOOST_AUTO_TEST_CASE(test_shortString){

    std::string testString = {"mabcngt"};
    std::string answerString = {"gt"};

    deleteChain(testString);

    BOOST_CHECK_EQUAL_COLLECTIONS(testString.begin(), testString.end(), answerString.begin(), answerString.end());
    BOOST_CHECK_EQUAL(testString.length(), answerString.length());
}


BOOST_AUTO_TEST_CASE(test_alphabetString){

    std::string testString = {"abcdefghijklmnopqrstuvwxyz"};
    std::string answerString = {""};

    deleteChain(testString);

    BOOST_CHECK_EQUAL_COLLECTIONS(testString.begin(), testString.end(), answerString.begin(), answerString.end());
    BOOST_CHECK_EQUAL(testString.length(), answerString.length());
}


BOOST_AUTO_TEST_CASE(test_uppercaseString){

    std::string testString = {"ABCDEFG"};
    std::string answerString = {""};

    deleteChain(testString);

    BOOST_CHECK_EQUAL_COLLECTIONS(testString.begin(), testString.end(), answerString.begin(), answerString.end());
    BOOST_CHECK_EQUAL(testString.length(), answerString.length());
}


BOOST_AUTO_TEST_CASE(test_upAndLowCasesString){

    std::string testString = {"AbCdEfG"};
    std::string answerString = {"AbCdEfG"};

    deleteChain(testString);

    BOOST_CHECK_EQUAL_COLLECTIONS(testString.begin(), testString.end(), answerString.begin(), answerString.end());
    BOOST_CHECK_EQUAL(testString.length(), answerString.length());
}


BOOST_AUTO_TEST_CASE(test_longString){

    std::string testString = {"abcdefghijklmnopqrstuvwxyzcompleteabcdefghijklmnopqrstuvwxyz"};
    std::string answerString = {"complete"};

    deleteChain(testString);

    BOOST_CHECK_EQUAL_COLLECTIONS(testString.begin(), testString.end(), answerString.begin(), answerString.end());
    BOOST_CHECK_EQUAL(testString.length(), answerString.length());
}


BOOST_AUTO_TEST_CASE(test_strangeString){

    std::string testString = {"!\"#$%&"};
    std::string answerString = {""};

    deleteChain(testString);

    BOOST_CHECK_EQUAL_COLLECTIONS(testString.begin(), testString.end(), answerString.begin(), answerString.end());
    BOOST_CHECK_EQUAL(testString.length(), answerString.length());
}


BOOST_AUTO_TEST_CASE(test_digitString){

    std::string testString = {"1234567890"};
    std::string answerString = {"0"};

    deleteChain(testString);

    BOOST_CHECK_EQUAL_COLLECTIONS(testString.begin(), testString.end(), answerString.begin(), answerString.end());
    BOOST_CHECK_EQUAL(testString.length(), answerString.length());
}


BOOST_AUTO_TEST_CASE(test_aaaString){

    std::string testString = {"aaaab"};
    std::string answerString = {"aaa"};

    deleteChain(testString);

    BOOST_CHECK_EQUAL_COLLECTIONS(testString.begin(), testString.end(), answerString.begin(), answerString.end());
    BOOST_CHECK_EQUAL(testString.length(), answerString.length());
}


BOOST_AUTO_TEST_CASE(test_fromTaskFileString){

    std::string testString = {"wbtnaaqdefrluyzqa"};
    std::string answerString = {"wbtnaaluqa"};

    deleteChain(testString);

    BOOST_CHECK_EQUAL_COLLECTIONS(testString.begin(), testString.end(), answerString.begin(), answerString.end());
    BOOST_CHECK_EQUAL(testString.length(), answerString.length());
}


BOOST_AUTO_TEST_SUITE_END()