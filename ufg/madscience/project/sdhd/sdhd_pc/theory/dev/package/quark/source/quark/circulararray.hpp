// File Line: 38
// RVA: 0xA16000
void __fastcall UFG::qCircularArray<UFG::GameLogManager::sGameLogEntry const *>::~qCircularArray<UFG::GameLogManager::sGameLogEntry const *>(UFG::qCircularArray<UFG::GameLogManager::sGameLogEntry const *> *this)
{
  if ( this->mpMemoryPool )
    UFG::qMemoryPool::Free(this->mpMemoryPool, this->mData);
  else
    operator delete[](this->mData);
}

