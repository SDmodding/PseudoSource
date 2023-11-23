// File Line: 28
// RVA: 0x15ABC90
__int64 UFG::_dynamic_initializer_for__gLocalizationInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gLocalizationInventory,
    "UILocalizationInventory",
    0x90CE6B7A,
    0x90CE6B7A,
    0,
    0);
  UFG::gLocalizationInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::UILocalizationInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gLocalizationInventory__);
}

// File Line: 88
// RVA: 0xA2BBB0
char *__fastcall UFG::UILocalizationChunk::getStringData(UFG::UILocalizationChunk *this)
{
  UFG::qOffset64<void *> *p_mChunkData; // rdx
  __int64 mOffset; // rcx
  _DWORD *v3; // rax

  p_mChunkData = &this->mChunkData;
  mOffset = this->mChunkData.mOffset;
  if ( mOffset )
    v3 = (_DWORD *)((char *)p_mChunkData + mOffset);
  else
    v3 = 0i64;
  if ( mOffset )
    return (char *)p_mChunkData + mOffset + (unsigned int)(*v3 + 8);
  else
    return 0i64;
}

