// File Line: 32
// RVA: 0x95B70
void __fastcall Illusion::MaterialUser::MaterialUser(Illusion::MaterialUser *this)
{
  *this = (Illusion::MaterialUser)31;
}

// File Line: 38
// RVA: 0x95F10
void __fastcall Illusion::MaterialUser::OnLoad(Illusion::MaterialUser *this, Illusion::Material *material)
{
  __int64 v2; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // r9
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // r10
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v5; // rax
  __int16 v6; // dx

  v2 = material->mNumParams;
  v3 = 0i64;
  v4 = 0i64;
  if ( (_DWORD)v2 )
  {
    v5 = &material[1].mResourceHandles;
    do
    {
      v6 = (__int16)v5[-2].mNode.mNext;
      if ( v6 == 9 )
      {
        v3 = v5->mNode.mPrev;
      }
      else if ( v6 == 10 )
      {
        v4 = v5->mNode.mPrev;
      }
      v5 = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)((char *)v5 + 56);
      --v2;
    }
    while ( v2 );
    if ( v3 && BYTE5(v3[5].mNext) )
      this->mShadowFlags |= 1u;
    if ( v4 )
    {
      if ( !BYTE3(v4[5].mNext) )
        this->mShadowFlags |= 2u;
    }
  }
}

