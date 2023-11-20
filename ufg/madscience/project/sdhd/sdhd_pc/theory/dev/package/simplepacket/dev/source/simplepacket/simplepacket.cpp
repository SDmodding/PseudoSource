// File Line: 33
// RVA: 0x146BC70
__int64 UFG::_dynamic_initializer_for__gSimplePacketMemoryPool__()
{
  UFG::qMemoryPool::qMemoryPool(&gSimplePacketMemoryPool);
  return atexit(UFG::_dynamic_atexit_destructor_for__gSimplePacketMemoryPool__);
}

