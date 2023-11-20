// File Line: 17
// RVA: 0x1466EE0
__int64 dynamic_initializer_for__netcodeSL::netcodeMatchmakingSystemImpl::mDeletePreventionMutex__()
{
  netcodeSL::netcodeMatchmakingSystemImpl::mDeletePreventionMutex.hMutex = CreateMutexA(0i64, 0, 0i64);
  return atexit(dynamic_atexit_destructor_for__netcodeSL::netcodeMatchmakingSystemImpl::mDeletePreventionMutex__);
}

