// File Line: 115
// RVA: 0x3F2BA0
void __fastcall UFG::BulletManager::operator delete(void *ptr, const char *name)
{
  UFG::qMemoryPool::Free(&gPhysicsMemoryPool, ptr);
}

