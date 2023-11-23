// File Line: 15
// RVA: 0x1466F10
__int64 dynamic_initializer_for__netcodeSL::netcodeEventManager::mInstanceMutex__()
{
  netcodeSL::netcodeEventManager::mInstanceMutex.hMutex = CreateMutexA(0i64, 0, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__netcodeSL::netcodeEventManager::mInstanceMutex__);
}

