// File Line: 17
// RVA: 0x146B330
__int64 Render::_dynamic_initializer_for__gDynamicLightManager__()
{
  return atexit(Render::_dynamic_atexit_destructor_for__gDynamicLightManager__);
}

// File Line: 45
// RVA: 0x1D27E0
void __fastcall Render::DynamicLightManager::RemoveLight(Render::DynamicLightManager *this, Render::Light *pLight)
{
  unsigned int v2; // er9
  __int64 v3; // r8
  Render::Light **v4; // rax

  v2 = this->mLights.size;
  v3 = 0i64;
  if ( this->mLights.size )
  {
    v4 = this->mLights.p;
    while ( *v4 != pLight )
    {
      v3 = (unsigned int)(v3 + 1);
      ++v4;
      if ( (unsigned int)v3 >= v2 )
        return;
    }
    if ( v2 > 1 )
      this->mLights.p[v3] = this->mLights.p[v2 - 1];
    if ( this->mLights.size > 1 )
      --this->mLights.size;
    else
      this->mLights.size = 0;
  }
}

// File Line: 60
// RVA: 0x1CC350
__int64 __fastcall Render::DynamicLightManager::GetDynamicLights(Render::DynamicLightManager *this, Render::Light **pBuffer, unsigned int maxLights)
{
  __int64 result; // rax
  unsigned int v4; // er10
  __int64 v5; // r8

  result = 0i64;
  v4 = maxLights;
  if ( pBuffer && this->mLights.size > 0 )
  {
    do
    {
      if ( (unsigned int)result >= v4 )
        break;
      v5 = result;
      result = (unsigned int)(result + 1);
      pBuffer[v5] = this->mLights.p[v5];
    }
    while ( (unsigned int)result < this->mLights.size );
  }
  return result;
}

