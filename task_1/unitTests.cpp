#define BOOST_TEST_MAIN
#include "./mergeList.hpp"
#include <boost/test/included/unit_test.hpp>
#define BOOST_TEST_MODULE test



BOOST_AUTO_TEST_SUITE(test)

BOOST_AUTO_TEST_CASE(test_emptyList){

    std::list<std::list<int>> in_func;
    std::list<int> test_list = mergeLists(in_func);
    std::list<int> answerList;

    BOOST_CHECK_EQUAL_COLLECTIONS(test_list.begin(), test_list.end(), answerList.begin(), answerList.end());
}



BOOST_AUTO_TEST_CASE(test_intArg){

    std::list<int> l1;
    std::list<int> l2;
    std::list<int> l3;

    for(int i = 0; i < 10; ++i)
    {
        l1.push_back(i);
    }
    for(int i = 5; i < 15; ++i)
    {
        l2.push_back(i);
    }
    for(int i = 10; i < 20; ++i)
    {
        l3.push_back(i);
    }

    std::list<std::list<int>> in_func;
    in_func.push_back(l1);
    in_func.push_back(l2);
    in_func.push_back(l3);

    std::list<int> test_list = mergeLists(in_func);
    std::list<int> answerList = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

    BOOST_CHECK_EQUAL_COLLECTIONS(test_list.begin(), test_list.end(), answerList.begin(), answerList.end());
}



BOOST_AUTO_TEST_CASE(test_doubleArg){

    std::list<double> l1 = {1.3, 1.4, 6.2, 7.13, 8.14, 9.89, 10.123, 12.3454};
    std::list<double> l2 = {10.234, 11.12, 12.1, 13.3, 14.14, 15.89, 17.123, 19.1111};
    std::list<double> l3 = {16.45, 17.123, 18.444, 19.1111, 20.20, 21.56, 22.12, 23.9};

    std::list<std::list<double>> in_func;
    in_func.push_back(l1);
    in_func.push_back(l2);
    in_func.push_back(l3);

    std::list<double> test_list = mergeLists(in_func);
    std::list<double> answerList = {1.3, 1.4, 6.2, 7.13, 8.14, 9.89, 10.123, 10.234, 11.12, 12.1, 12.3454, 13.3,
                                     14.14, 15.89, 16.45, 17.123, 18.444, 19.1111, 20.2, 21.56, 22.12, 23.9};

    BOOST_CHECK_EQUAL_COLLECTIONS(test_list.begin(), test_list.end(), answerList.begin(), answerList.end());
}



BOOST_AUTO_TEST_CASE(test_classArg){

    class A{
        int value;
    public:
        explicit A(int i){
            value = i;
        }
        bool operator<(const A& other) const{
            return value < other.value;
        }
        bool operator==(const A& other) const{
            return other.value == value;
        }
        int getValue() const { return value; }
    };

    std::list<A> l1 = {A(1), A(2), A(2), A(3), A(3), A(4)};
    std::list<A> l2 = {A(2), A(4), A(5), A(6), A(6), A(7)};
    std::list<A> l3 = {A(7), A(8), A(9), A(10), A(10), A(10)};

    std::list<std::list<A>> in_func;
    in_func.push_back(l1);
    in_func.push_back(l2);
    in_func.push_back(l3);

    std::list<A> test_list = mergeLists(in_func);
    std::list<int> answerList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto first1 = test_list.begin();
    auto last1 = test_list.end();

    auto first2 = answerList.begin();
    auto last2 = answerList.end();

    while(first1 != last1 && first2 != last2)
    {
        BOOST_REQUIRE_EQUAL(first1->getValue(), *first2);
        ++first1;
        ++first2;
    }
    if(first1 != last1 || first2 != last2)
    {
        BOOST_CHECK(false);
    }
}



BOOST_AUTO_TEST_CASE(test_stringArg){

    std::list<std::string> l1 = {"ae","bl","co"};
    std::list<std::string> l2 = {"co", "dd,"};
    std::list<std::string> l3 = {"ei", "ei", "fd"};

    std::list<std::list<std::string>> in_func;
    in_func.push_back(l1);
    in_func.push_back(l2);
    in_func.push_back(l3);

    std::list<std::string> test_list = mergeLists(in_func);
    std::list<std::string> answerList = {"ae", "bl", "co", "dd,", "ei", "fd"};

    BOOST_CHECK_EQUAL_COLLECTIONS(test_list.begin(), test_list.end(), answerList.begin(), answerList.end());
}


BOOST_AUTO_TEST_CASE(test_pyramidStringWithoutLength){

    std::list<std::string> l1 = {"a","eg","tgh"};
    std::list<std::string> l2 = {"tlv", "rfdv", "ascvf"};
    std::list<std::string> l3 = {"rfdv", "asdvb", "fnrqxd"};

    std::list<std::list<std::string>> in_func;
    in_func.push_back(l1);
    in_func.push_back(l2);
    in_func.push_back(l3);

    std::list<std::string> test_list = mergeLists(in_func,
                                                  [](const std::string& s1, const std::string& s2){ return s1.length() < s2.length(); });
    std::list<std::string> answerList = {"a", "eg", "tgh", "tlv", "rfdv", "ascvf", "asdvb", "fnrqxd"};

    BOOST_CHECK_EQUAL_COLLECTIONS(test_list.begin(), test_list.end(), answerList.begin(), answerList.end());
}



BOOST_AUTO_TEST_CASE(test_pyramidStringWithLength){

    std::list<std::string> l1 = {"a","eg","tgh"};
    std::list<std::string> l2 = {"tlv", "rfdv", "ascvf"};
    std::list<std::string> l3 = {"rfdv", "asdvb", "fnrqxd"};

    std::list<std::list<std::string>> in_func;
    in_func.push_back(l1);
    in_func.push_back(l2);
    in_func.push_back(l3);

    std::list<std::string> test_list = mergeLists(in_func,
                                                  [](const std::string& s1, const std::string& s2){ return s1.length() < s2.length(); },
                                                  [](const std::string& s1, const std::string& s2){ return s1.length() == s2.length(); });
    std::list<std::string> answerList = {"a", "eg", "tgh", "rfdv", "ascvf", "fnrqxd"};

    BOOST_CHECK_EQUAL_COLLECTIONS(test_list.begin(), test_list.end(), answerList.begin(), answerList.end());
}


BOOST_AUTO_TEST_CASE(test_reverseComp){

    std::list<int> l3 = {1, 2, 3, 4, 5};
    std::list<int> l2 = {3, 4, 5, 6, 7};
    std::list<int> l1 = {6, 7, 8, 9, 10};

    l1.reverse();
    l2.reverse();
    l3.reverse();

    std::list<std::list<int>> in_func;
    in_func.push_back(l1);
    in_func.push_back(l2);
    in_func.push_back(l3);

    std::list<int> test_list = mergeLists(in_func,
                                          [](int& a1, int& a2){ return a1 > a2; });
    std::list<int> answerList = {10,9,8,7,6,5,4,3,2,1};

    BOOST_CHECK_EQUAL_COLLECTIONS(test_list.begin(), test_list.end(), answerList.begin(), answerList.end());
}



BOOST_AUTO_TEST_CASE(test_equalClassArg){

    class A{
        int value;
    public:
        explicit A(int i){
            value = i;
        }
        int getValue() const { return value; }
    };

    std::list<A> l1 = {A(1), A(2), A(2), A(3), A(3), A(4)};
    std::list<A> l2 = {A(2), A(4), A(5), A(6), A(6), A(7)};
    std::list<A> l3 = {A(7), A(8), A(9), A(10), A(10), A(10)};

    std::list<std::list<A>> in_func;
    in_func.push_back(l1);
    in_func.push_back(l2);
    in_func.push_back(l3);

    std::list<A> test_list = mergeLists(in_func,
                                        [](A& a1, A& a2){ return a1.getValue() < a2.getValue(); },
                                        [](A& a1, A& a2){ return a1.getValue() == a2.getValue(); });
    std::list<int> answerList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto first1 = test_list.begin();
    auto last1 = test_list.end();

    auto first2 = answerList.begin();
    auto last2 = answerList.end();

    while(first1 != last1 && first2 != last2)
    {
        BOOST_REQUIRE_EQUAL(first1->getValue(), *first2);
        ++first1;
        ++first2;
    }
    if(first1 != last1 || first2 != last2)
    {
        BOOST_CHECK(false);
    }
}


BOOST_AUTO_TEST_SUITE_END()