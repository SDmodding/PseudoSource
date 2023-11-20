// File Line: 31
// RVA: 0x2DD50
void __fastcall UFG::qHashMapBase::~qHashMapBase(UFG::qHashMapBase *this)
{
  UFG::qMemoryPool::Free(this->mPool, this->mTable);
}

