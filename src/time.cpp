#include "time.hpp"

void Time::setRefreshRate(int p_refreshRate)
{
    m_refreshRate = p_refreshRate;
}

void Time::startPerformanceCouter()
{
    m_startTick = SDL_GetPerformanceCounter();
}

void Time::cappingFrameRate()
{
    m_endTick = SDL_GetPerformanceCounter();
    m_elapsed = (m_endTick - m_startTick) / static_cast<float>(SDL_GetPerformanceFrequency()) * 1000.0f;

    // 1,000 milliseconds / 60 frames per second = 16.6666666667 (millisecond per frame)
    m_maxElapsedPerFrame = 1000 / static_cast<double>(m_refreshRate);
    fprintf(stdout, "Elapsed: %f, RefreshRate : %lf, FPS: %d\n", 1.0f / m_elapsed, m_maxElapsedPerFrame, m_refreshRate);
    if (m_elapsed < m_maxElapsedPerFrame)
    {
        SDL_Delay(floor(m_maxElapsedPerFrame - m_elapsed));
    }
}