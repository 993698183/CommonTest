#pragma once
#ifndef BOOST_TEST_THREAD_INTERRUPT
#define BOOST_TEST_THREAD_INTERRUPT

#include <iostream>
#include <string>

//线程中断的思考
/*
thread库预定义了9个中断点：
1. thread::join();
2. thread::timed_join();
3. condition_variable::wait();
4. condition_variable::timed_wait();
5. condition_variable_any::wait();
6. condition_variable_any::timed_wait();
7. thread::sleep();
8. this_thread::sleep();
9. this_thread::interruption_point()
*/

#endif // BOOST_TEST_THREAD_INTERRUPT
