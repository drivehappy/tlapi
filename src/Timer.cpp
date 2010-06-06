#include "Timer.h"


LARGE_INTEGER TimeManager::m_nStartTime;
double TimeManager::m_fSimulationFactor;

TimeManager::TimeManager()
{
    QueryPerformanceCounter(&m_nStartTime);

    m_fSimulationFactor = 1.0f;
}
TimeManager::~TimeManager()
{

}

TimeManager& TimeManager::getSingleton()
{
    static TimeManager m_pSingleton;
    return m_pSingleton;
}

double TimeManager::getTime()
{
    static double fTime;
    static LARGE_INTEGER nCounter, nFreq;
    QueryPerformanceCounter(&nCounter);
    QueryPerformanceFrequency(&nFreq);

    fTime = double((nCounter.QuadPart - m_nStartTime.QuadPart) / (double)nFreq.QuadPart);

    return fTime * m_fSimulationFactor;
}

void TimeManager::sleep(int milliseconds)
{
    Sleep(milliseconds);
}

void TimeManager::setSimulationFactor(double _factor) {
    m_fSimulationFactor = _factor;
}


Timer::Timer()
{
    reset();
}
Timer::~Timer()
{
    m_fRunningTime = 0.0f;
    m_fStartTime = 0.0f;
}

void Timer::pause()
{
    if (!m_bPaused) {
        m_fRunningTime += TimeManager::getSingleton().getTime() - m_fStartTime;
        m_bPaused = true;
    }
}

void Timer::resume()
{
    if (m_bPaused) {
        m_fStartTime = TimeManager::getSingleton().getTime();
        m_bPaused = false;
    }
}

void Timer::reset()
{
    m_bPaused = false;
    m_fRunningTime = 0.0f;
    m_fStartTime = TimeManager::getSingleton().getTime();
}

double Timer::getTime()
{
    double fTime = m_fRunningTime;
    if (!m_bPaused)
        fTime += (TimeManager::getSingleton().getTime() - m_fStartTime);

    return fTime > 0.0f ? fTime : 0.0f;
}
