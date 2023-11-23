// File Line: 41
// RVA: 0x15AE2B0
__int64 UFG::_dynamic_initializer_for__gWSAInit__()
{
  WSAData WSAData; // [rsp+20h] [rbp-1A8h] BYREF

  WSAStartup(0x202u, &WSAData);
  return atexit(UFG::_dynamic_atexit_destructor_for__gWSAInit__);
}

