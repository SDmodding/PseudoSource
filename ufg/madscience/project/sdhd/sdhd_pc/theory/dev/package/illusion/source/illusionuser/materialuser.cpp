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
  __int64 mNumParams; // r8
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // r9
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // r10
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rax
  __int16 mNext; // dx

  mNumParams = material->mNumParams;
  mPrev = 0i64;
  v4 = 0i64;
  if ( (_DWORD)mNumParams )
  {
    p_mResourceHandles = &material[1].mResourceHandles;
    do
    {
      mNext = (__int16)p_mResourceHandles[-2].mNode.mNext;
      if ( mNext == 9 )
      {
        mPrev = p_mResourceHandles->mNode.mPrev;
      }
      else if ( mNext == 10 )
      {
        v4 = p_mResourceHandles->mNode.mPrev;
      }
      p_mResourceHandles = (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)((char *)p_mResourceHandles + 56);
      --mNumParams;
    }
    while ( mNumParams );
    if ( mPrev && BYTE5(mPrev[5].mNext) )
      this->mShadowFlags |= 1u;
    if ( v4 )
    {
      if ( !BYTE3(v4[5].mNext) )
        this->mShadowFlags |= 2u;
    }
  }
}

