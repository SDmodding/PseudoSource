// File Line: 73
// RVA: 0x163F10
void __fastcall UFG::qMutexScopeLocker::~qMutexScopeLocker(UFG::qMutexScopeLocker *this)
{
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)this->mMutex);
}

// File Line: 138
// RVA: 0xA16E90
UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor *__fastcall UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>>::operator->(
        UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> > *this,
        UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor *result)
{
  UFG::qMutex *p_mMutex; // rcx

  result->mObj = this->mObj;
  p_mMutex = &this->mMutex;
  result->mLock.mMutex = p_mMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)p_mMutex);
  return result;
}

