// File Line: 28
// RVA: 0x15ABC90
__int64 UFG::_dynamic_initializer_for__gLocalizationInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gLocalizationInventory.vfptr,
    "UILocalizationInventory",
    0x90CE6B7A,
    0x90CE6B7A,
    0,
    0);
  UFG::gLocalizationInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::UILocalizationInventory::`vftable;
  return atexit(UFG::_dynamic_atexit_destructor_for__gLocalizationInventory__);
}

// File Line: 88
// RVA: 0xA2BBB0
char *__fastcall UFG::UILocalizationChunk::getStringData(UFG::UILocalizationChunk *this)
{
  UFG::qOffset64<void *> *v1; // rdx
  __int64 v2; // rcx
  char *v3; // rax
  char *result; // rax

  v1 = &this->mChunkData;
  v2 = this->mChunkData.mOffset;
  if ( v2 )
    v3 = (char *)v1 + v2;
  else
    v3 = 0i64;
  if ( v2 )
    result = (char *)v1 + v2 + (unsigned int)(*(_DWORD *)v3 + 8);
  else
    result = 0i64;
  return result;
}

