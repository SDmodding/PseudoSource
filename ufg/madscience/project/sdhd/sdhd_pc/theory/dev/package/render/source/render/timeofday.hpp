// File Line: 119
// RVA: 0x6BC10
void __fastcall UFG::TimeOfDayManager::SetWeather(UFG::TimeOfDayManager *this, float weather_amount)
{
  if ( weather_amount <= 0.0 )
  {
    weather_amount = 0.0;
  }
  else if ( weather_amount >= 2.0 )
  {
    this->m_WeatherState = FLOAT_2_0;
    this->m_WeatherTarget = FLOAT_2_0;
    this->m_NextWeatherTarget = FLOAT_2_0;
    return;
  }
  this->m_WeatherState = weather_amount;
  this->m_WeatherTarget = weather_amount;
  this->m_NextWeatherTarget = weather_amount;
}

// File Line: 120
// RVA: 0x4BDDC0
void __fastcall UFG::TimeOfDayManager::SetWeatherTarget(UFG::TimeOfDayManager *this, float weather_target)
{
  if ( weather_target <= 0.0 )
  {
    weather_target = 0.0;
  }
  else if ( weather_target >= 2.0 )
  {
    this->m_WeatherTarget = FLOAT_2_0;
    this->m_NextWeatherTarget = FLOAT_2_0;
    return;
  }
  this->m_WeatherTarget = weather_target;
  this->m_NextWeatherTarget = weather_target;
}

