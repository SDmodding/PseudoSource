// File Line: 17
// RVA: 0x146B330
__int64 Render::_dynamic_initializer_for__gDynamicLightManager__()
{
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gDynamicLightManager__);
}

// File Line: 45
// RVA: 0x1D27E0
void __fastcall Render::DynamicLightManager::RemoveLight(Render::DynamicLightManager *this, Render::Light *pLight)
{
  unsigned int size; // r9d
  __int64 v3; // r8
  Render::Light **i; // rax

  size = this->mLights.size;
  v3 = 0i64;
  if ( this->mLights.size )
  {
    for ( i = this->mLights.p; *i != pLight; ++i )
    {
      v3 = (unsigned int)(v3 + 1);
      if ( (unsigned int)v3 >= size )
        return;
    }
    if ( size > 1 )
      this->mLights.p[v3] = this->mLights.p[size - 1];
    if ( this->mLights.size > 1 )
      --this->mLights.size;
    else
      this->mLights.size = 0;
  }
}

// File Line: 60
// RVA: 0x1CC350
__int64 __fastcall Render::DynamicLightManager::GetDynamicLights(
        Render::DynamicLightManager *this,
        Render::Light **pBuffer,
        unsigned int maxLights)
{
  __int64 result; // rax
  __int64 v5; // r8

  result = 0i64;
  if ( pBuffer && this->mLights.size )
  {
    do
    {
      if ( (unsigned int)result >= maxLights )
        break;
      v5 = result;
      result = (unsigned int)(result + 1);
      pBuffer[v5] = this->mLights.p[v5];
    }
    while ( (unsigned int)result < this->mLights.size );
  }
  return result;
}

