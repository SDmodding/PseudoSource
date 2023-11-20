// File Line: 139
// RVA: 0xA1AEB0
ID3D11InputLayout *__fastcall Illusion::CombinedObjectManager<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Get(Illusion::CombinedObjectManager<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *this, Illusion::Shader *t1, Illusion::VertexDecl *t2)
{
  Illusion::VertexDecl *v3; // rbx
  Illusion::Shader *v4; // rdi
  Illusion::CombinedObjectManager<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> *v5; // rsi
  ID3D11InputLayout *v6; // rax
  UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor *v7; // rax
  ID3D11InputLayout *v8; // rbp
  ID3D11InputLayout *v9; // r14
  UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor *v10; // rax
  UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout> >::TemporaryAccessor result; // [rsp+28h] [rbp-30h]

  v3 = t2;
  v4 = t1;
  v5 = this;
  if ( !t1 || !t2 )
    return 0i64;
  v6 = Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Get(
         &this->mLocalCache,
         t1,
         t2);
  if ( !v6 )
  {
    v7 = UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>>::operator->(
           v5->mGlobalCache,
           &result);
    v8 = Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Get(v7->mObj, v4, v3);
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)result.mLock.mMutex);
    if ( v8 )
    {
      Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Set(
        &v5->mLocalCache,
        v4,
        v3,
        v8);
      v6 = v8;
    }
    else
    {
      v6 = (ID3D11InputLayout *)v5->vfptr->CreateD3DObject(v5, v4, v3);
      v9 = v6;
      if ( v6 )
      {
        v10 = UFG::qThreadSafeHandle<Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>>::operator->(
                v5->mGlobalCache,
                &result);
        Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Set(
          v10->mObj,
          v4,
          v3,
          v9);
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)result.mLock.mMutex);
        Illusion::CombinedObjectCache<Illusion::Shader,Illusion::VertexDecl,ID3D11InputLayout>::Set(
          &v5->mLocalCache,
          v4,
          v3,
          v9);
        v9->vfptr->Release((IUnknown *)&v9->vfptr);
        v6 = v9;
      }
    }
  }
  return v6;
}

