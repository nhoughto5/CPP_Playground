#pragma once
#include <chrono>
#include <iostream>
class Timer
{
public:
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
    Timer();
    ~Timer();
};

