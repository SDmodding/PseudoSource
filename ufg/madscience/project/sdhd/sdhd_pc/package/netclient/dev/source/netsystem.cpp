// File Line: 79
// RVA: 0x1467190
__int64 dynamic_initializer_for__NetSystem::mSSLLibMutex__()
{
  UFG::qMutex::qMutex(&NetSystem::mSSLLibMutex, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__NetSystem::mSSLLibMutex__);
}

