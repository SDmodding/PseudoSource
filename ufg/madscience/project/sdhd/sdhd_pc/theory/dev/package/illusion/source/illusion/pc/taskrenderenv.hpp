// File Line: 139
// RVA: 0xA1AEB0
ID3D11InputLayout *__fastcall Illusion::CombinedObjectManager<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Get(
        Illusion::CombinedObjectManager<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *this,
        Illusion::Shader *t1,
        Illusion::VertexDecl *t2)
{
  ID3D11InputLayout *v6; // rax
  UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor *v7; // rax
  ID3D11InputLayout *v8; // rbp
  ID3D11InputLayout *v9; // r14
  UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor *v10; // rax
  UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor result; // [rsp+28h] [rbp-30h] BYREF

  if ( !t1 || !t2 )
    return 0i64;
  v6 = Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Get(
         &this->mLocalCache,
         t1,
         t2);
  if ( !v6 )
  {
    v7 = UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>>::operator->(
           this->mGlobalCache,
           &result);
    v8 = Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Get(v7->mObj, t1, t2);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)result.mLock.mMutex);
    if ( v8 )
    {
      Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Set(
        &this->mLocalCache,
        t1,
        t2,
        v8);
      return v8;
    }
    else
    {
      v6 = (ID3D11InputLayout *)this->vfptr->CreateD3DObject(this, t1, t2);
      v9 = v6;
      if ( v6 )
      {
        v10 = UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>>::operator->(
                this->mGlobalCache,
                &result);
        Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Set(
          v10->mObj,
          t1,
          t2,
          v9);
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)result.mLock.mMutex);
        Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Set(
          &this->mLocalCache,
          t1,
          t2,
          v9);
        v9->vfptr->Release(v9);
        return v9;
      }
    }
  }
  return v6;
}

