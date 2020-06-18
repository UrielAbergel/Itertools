//
// Created by uriel on 16/06/2020.
//



#pragma once
#include "accumulate.hpp"
#include "range.hpp"
#include "filterfalse.hpp"
#include <vector>
#include "doctest.h"
#include <string>
#include <iostream>
#include "compress.hpp"
using namespace itertools;
using namespace std;

//TEST_CASE("TEST THE RANGE")
//
//{
//   int to_check = 1; // check positive 5 number
//
//   for(int i : range(1,6))
//   {
//       CHECK(i == to_check++);
//   }
//
//   to_check = -5;  // check negative 5 number
//   for(int i : range (-5 , -11))
//   {
//       CHECK(i == to_check++);
//   }
//
//    to_check = -2;  // check negative and positive
//    for(int i : range (-2 , 3))
//    {
//                CHECK(i == to_check++);
//    }
//}

TEST_CASE("CHECK THE RANGE IN THE ACCUMULATE"){
    vector<int> the_vector_to_check ={10,21,33,46}; // check the positive number
    int the_current_index=0;
    for(int i : accumulate(range(10,15))){
                CHECK(the_vector_to_check[the_current_index++]==i);
    }

    the_current_index=0;  // check negative number
    the_vector_to_check={-5,-9,-12,-14,-15};
    for(int i : accumulate(range(-5,0))){
                CHECK(the_vector_to_check[the_current_index++]==i);
    }
}

TEST_CASE("CHECK THE VECTOR IN ACCUMLATE"){
    vector<string> the_first_vec_to_check = {"uriel" , "and" , "yair" , "write" , "this" , "test"};
    vector<string> the_second_vec_to_check = {"uriel" , "urieland" , "urielandyair" , "urielandyairwrite" , "urielandyairwritethis" , "urielandyairwritethistest" };
    int currend_index=0;
    for(string i : accumulate(the_first_vec_to_check)){
                CHECK(the_second_vec_to_check[currend_index++]==i);
    }

    currend_index=0;
    vector<double > the_first_vec_to_check_1 = {3.2,3.3,3.4};
    vector<double > the_second_vec_to_check_2 = {3.2,6.5,9.9};
    for(double i : accumulate(the_first_vec_to_check_1)){
                CHECK(the_second_vec_to_check_2[currend_index++]==i);
    }
    currend_index=0;
    vector<float> the_first_vec_to_check_2 = {-1.4,2.3,5.2,-7.7};
    vector<float> the_second_vec_to_check_3 ={-1.4,0.9,6.1,-1.6};
    for(float i :accumulate(the_first_vec_to_check_2)){
                CHECK(the_second_vec_to_check_3[currend_index++]-i<0.00005f);
    }
    currend_index=0;
    vector<int> vector_check = {1,-3,4,5,-2,0,-1,0};
    vector<int> vector_check_1 = {1,-2,2,7,5,5,4,4};
    for(int i :accumulate(vector_check)){
                CHECK(vector_check_1[currend_index++]==i);
    }
}

TEST_CASE("CHECK LAMBADA FUNCTION IN ACC"){
    vector<int> check_the_first_vec= {1,2,3,4,5,6,7,8,9,10};
    vector<int> check_the_first_vec_answer={1,2,6,24,120,720,5040,40320,362880,3628800};
    int current_index = 0;
    for(int i :accumulate(check_the_first_vec,[](int a,int b){return a*b;})){
                CHECK(check_the_first_vec_answer[current_index++]==i);
    }

    vector<double> check_the_first_vec_1 = {1.5,1.5,-2.5,2.5,-3.5,3.5,-4.5,4.5,-5.5,5.5};
    vector<double > check_the_first_vec_answer_1 = {1.5,0.0,2.5,0.0,3.5,0.0,4.5,0.0,5.5,0.0};
    current_index=0;
    for(double i : accumulate(check_the_first_vec_1, [](double a , double b){return a-b;})){
                CHECK(check_the_first_vec_answer_1[current_index++]==i);
    }
}

TEST_CASE("filterfalse"){
    vector<int> check_the_first_vec= {2,4,6,8,10,12};
    vector<int> check_the_first_vec_answer={2,4,6,8,10,12};
    int current_index = 0;
    int n = rand();
    for(int i : filterfalse([](int a){return a+2%2==0;},check_the_first_vec)){
                CHECK(check_the_first_vec_answer[current_index++]==i);
    }

    vector<char> check_the_first_vec_1= {'a','b','c','d','e','A','B','C','D','E'};
    vector<char> check_the_first_vec_answer_1={'a','b','c','d','e'};
    current_index=0;
    for(char i : filterfalse([](char s){return s < 97;},check_the_first_vec_1)){
                CHECK(check_the_first_vec_answer_1[current_index++]==i);
    }

    vector<string> check_the_first_vec_2 ={"now","i","check" ,"if","the" , "size" , "are", "mode" , "1"};
    vector<string> check_the_first_vec_answer_2 ={"now","i","check" , "the" , "are" , "1" };
    current_index=0;
    for(auto i : filterfalse([](string s){return s.size()%2!=0;},check_the_first_vec_2)){
                CHECK(check_the_first_vec_answer_2[current_index++]==i);
    }
    vector<string> c1 ={"now","i","check" ,"if","the" , "size" , "are", "mode" , "1"};
    vector<string> c2 ={"now","i","check" , "the" , "are" , "1" };
    current_index=0;
    for(auto i : filterfalse([](string s){return s.size()%2!=0;},c2)){
                CHECK(c2[current_index++]==i);
    } vector<string> c3 ={"now","i","check" ,"if","the" , "size" , "are", "mode" , "1"};
    vector<string> c4 ={"now","i","check" , "the" , "are" , "1" };
    current_index=0;
    for(auto i : filterfalse([](string s){return s.size()%2!=0;},c2)){
                CHECK(c2[current_index++]==i);
    }

    vector<string> c5 ={"now","i","check" ,"if","the" , "size" , "are", "mode" , "1"};
    vector<string> c6 ={"now","i","check" , "the" , "are" , "1" };
    current_index=0;
    for(auto i : filterfalse([](string s){return s.size()%2!=0;},c6)){
                CHECK(c6[current_index++]==i);
    }

    for(int i = 0 ; i < 30 ; i ++ ){
    vector<string> c7 ={"now","i","check" ,"if","the" , "size" , "are", "mode" , "1"};
    vector<string> c8 ={"now","i","check" , "the" , "are" , "1" };
    current_index=0;
    for(auto i : filterfalse([](string s){return s.size()%2!=0;},c7)){
                CHECK(c7[current_index++]==i);
    }}


}


TEST_CASE("CHECK THE COMPRESS ITER") {
//    vector<bool> check_the_first_vec =  {true,true,true,true};
//    vector<int> check_the_first_vec_answer = {1,2,3,4};
//    vector<int> answer ={1,2,3,4};
//    int current_index =0;
//    for (auto i :compress(check_the_first_vec_answer,check_the_first_vec)){
//                CHECK(answer[current_index++]==i);
//    }
//    current_index=0;
//    vector<double> check_the_first_vec_1 = {4.4};
//    check_the_first_vec = {false,false,false,true};
//    vector<double> vecdub = {1,2,3,4.4};
//    for(auto i :compress(vecdub,check_the_first_vec)){
//                CHECK(check_the_first_vec_1[current_index]==i);
//    }
//    current_index=0;
//    vector<string> vecstr = {"the","lion", "that" ,"love" , "stwabery" , "so","much"};
//    vector<string> astr = {"the","lion", "that" ,"love" , "stwabery"};
//    check_the_first_vec={true,true,true,true,true,false};
//    for(auto i :compress(vecstr,check_the_first_vec)){
//        cout<<"i is:"<<i<<"|||| boolvec[idx]="<<check_the_first_vec[current_index]<<endl;
//                CHECK(astr[current_index++]==i);
//    }
//
//    check_the_first_vec_answer = {1,2,3,4,5,6,7,8,9,10};
//    answer = {1,3,5,7,9,10};
//    check_the_first_vec = {true,false,true,false,true,false,true,false,true,true};
//    current_index=0;
//    for(auto i :compress(check_the_first_vec_answer,check_the_first_vec)) {
//        cout << "i is:" << i << "|||| boolvec[idx]=" << check_the_first_vec[current_index] << endl;
//                CHECK(answer[current_index++] == i);
//    }
//};
}