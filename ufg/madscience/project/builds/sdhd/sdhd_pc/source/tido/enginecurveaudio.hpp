// File Line: 156
// RVA: 0x67B1C0
UFG::qSymbol *__fastcall UFG::AudioCurve::GetSourceValueSymbol(UFG::AudioCurve *this)
{
  UFG::AudioCurveSymbolManager *v2; // rdx
  UFG::allocator::free_link *v3; // rax
  UFG::AudioCurveSymbolManager *v4; // rax

  v2 = UFG::AudioCurveSymbolManager::ms_instance;
  if ( !UFG::AudioCurveSymbolManager::ms_instance )
  {
    v3 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x400ui64, "AudioCurveSymbolManager", 0i64, 1u);
    if ( v3 )
    {
      UFG::AudioCurveSymbolManager::AudioCurveSymbolManager((UFG::AudioCurveSymbolManager *)v3);
      v2 = v4;
    }
    else
    {
      v2 = 0i64;
    }
    UFG::AudioCurveSymbolManager::ms_instance = v2;
  }
  return (UFG::qSymbol *)v2 + this->mSourceValue;
}

// File Line: 157
// RVA: 0x67B2E0
UFG::qSymbol *__fastcall UFG::AudioCurve::GetTargetValueSymbol(UFG::AudioCurve *this)
{
  UFG::AudioCurveSymbolManager *v2; // rdx
  UFG::allocator::free_link *v3; // rax
  UFG::AudioCurveSymbolManager *v4; // rax

  v2 = UFG::AudioCurveSymbolManager::ms_instance;
  if ( !UFG::AudioCurveSymbolManager::ms_instance )
  {
    v3 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x400ui64, "AudioCurveSymbolManager", 0i64, 1u);
    if ( v3 )
    {
      UFG::AudioCurveSymbolManager::AudioCurveSymbolManager((UFG::AudioCurveSymbolManager *)v3);
      v2 = v4;
    }
    else
    {
      v2 = 0i64;
    }
    UFG::AudioCurveSymbolManager::ms_instance = v2;
  }
  return (UFG::qSymbol *)v2 + this->mTargetValue;
}

// File Line: 158
// RVA: 0x679640
UFG::qSymbol *__fastcall UFG::AudioCurve::GetBlendModeSymbol(UFG::AudioCurve *this)
{
  UFG::AudioCurveSymbolManager *v2; // rdx
  UFG::allocator::free_link *v3; // rax
  UFG::AudioCurveSymbolManager *v4; // rax

  v2 = UFG::AudioCurveSymbolManager::ms_instance;
  if ( !UFG::AudioCurveSymbolManager::ms_instance )
  {
    v3 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x400ui64, "AudioCurveSymbolManager", 0i64, 1u);
    if ( v3 )
    {
      UFG::AudioCurveSymbolManager::AudioCurveSymbolManager((UFG::AudioCurveSymbolManager *)v3);
      v2 = v4;
    }
    else
    {
      v2 = 0i64;
    }
    UFG::AudioCurveSymbolManager::ms_instance = v2;
  }
  return (UFG::qSymbol *)v2 + this->mBlendMode;
}

