#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>

#include <SDL_image.h>
// for using SDL_Delay() functions
#include <SDL_timer.h>

class Time
{
public:
    Time() {}

    void setRefreshRate(int p_refreshRate);

    /**
     * @brief start the tick, should be called right after started the game loop
     * 
     */
    void startPerformanceCouter();

    /**
     * @brief limit the frame rate to the specified the time needed for each frame
     * 
     */
    void cappingFrameRate();

private:
    int m_refreshRate;
    Uint64 m_startTick, m_endTick;
    // Miliseconds to elapsed current frame
    double m_elapsed;
    // 1,000 milliseconds / 60 frames per second = 16.6666666667 (millisecond per frame)
    double m_maxElapsedPerFrame;
};

#endif // TIME_HPP