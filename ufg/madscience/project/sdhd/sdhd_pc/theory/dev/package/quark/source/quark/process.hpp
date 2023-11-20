// File Line: 73
// RVA: 0x163F10
void __fastcall UFG::qMutexScopeLocker::~qMutexScopeLocker(UFG::qMutexScopeLocker *this)
{
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)this->mMutex);
}

// File Line: 138
// RVA: 0xA16E90
UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor *__fastcall UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>>::operator->(UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> > *this, UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor *result)
{
  UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor *v2; // rbx
  UFG::qMutex *v3; // rcx

  v2 = result;
  result->mObj = this->mObj;
  v3 = &this->mMutex;
  result->mLock.mMutex = v3;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)v3);
  return v2;
}

