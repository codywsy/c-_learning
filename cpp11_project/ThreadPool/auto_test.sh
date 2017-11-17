#!/bin/bash

make

blade build -pdebug

gdb ../build64_debug/ThreadPool/ThreadPoolTest
