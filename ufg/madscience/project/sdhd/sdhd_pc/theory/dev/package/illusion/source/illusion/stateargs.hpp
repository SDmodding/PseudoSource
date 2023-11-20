// File Line: 84
// RVA: 0x7B70
void __fastcall Illusion::StateArg::~StateArg(Illusion::StateArg *this)
{
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v1; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v2; // rax

  v1 = this->mPrev;
  v2 = this->mNext;
  v1->mNext = v2;
  v2->mPrev = v1;
  this->mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&this->mPrev;
  this->mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&this->mPrev;
}

// File Line: 90
// RVA: 0x7720
void __fastcall Illusion::StateArg::ExecuteSetStateBlock<Render::cbLocalTransformState>(Illusion::StateArg *this, Illusion::StateArg *arg, Illusion::StateValues *state_values)
{
  __int16 v3; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v4; // r9

  v3 = Render::cbLocalTransformState::sStateParamIndex;
  v4 = this[1].mPrev;
  if ( (unsigned int)(signed __int16)Render::cbLocalTransformState::sStateParamIndex >= 0x40 )
    arg->mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)((_QWORD)arg->mNext | (1i64 << ((unsigned __int8)Render::cbLocalTransformState::sStateParamIndex - 64)));
  else
    arg->mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)((_QWORD)arg->mPrev | (1i64 << Render::cbLocalTransformState::sStateParamIndex));
  *((_QWORD *)&arg->mCallback + v3) = v4;
}

// File Line: 169
// RVA: 0x2ADA0
void __fastcall Illusion::StateArgs::~StateArgs(Illusion::StateArgs *this)
{
  `eh vector destructor iterator(
    this->mStateArgs,
    0x10ui64,
    128,
    (void (__fastcall *)(void *))UFG::qList<Render::Decal,Render::Decal,0,0>::~qList<Render::Decal,Render::Decal,0,0>);
}

// File Line: 182
// RVA: 0x7850
void __fastcall Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(Illusion::StateArgs *this, Render::cbLocalTransformInverseState *arg)
{
  __int16 v2; // ax
  Illusion::StateArgs *v3; // r9
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v4; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v5; // rax
  unsigned int v6; // ecx
  signed __int64 v7; // r8
  signed __int64 v8; // rax
  char v9; // cl
  char v10; // r10
  __m128i v11; // xmm0
  __m128i v12; // [rsp+0h] [rbp-18h]

  v2 = arg->mStateParamIndex;
  v3 = this;
  if ( v2 != -1 )
  {
    v12.m128i_i64[0] = 0i64;
    v4 = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)(&this->mStateArgsCreateMask + v2 + 3i64);
    v5 = v4->mNext;
    v4->mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg->mPrev;
    arg->mPrev = v4;
    arg->mNext = v5;
    v5->mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg->mPrev;
    v6 = arg->mStateParamIndex;
    v7 = 0i64;
    arg->mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))Illusion::StateArg::ExecuteSetStateBlock<Render::cbLocalTransformInverseState>;
    v8 = 0i64;
    v12.m128i_i64[1] = 0i64;
    if ( v6 >= 0x40 )
    {
      v9 = v6 - 64;
      v8 = 1i64 << v9;
      v12.m128i_i64[1] = 1i64 << v9;
    }
    else
    {
      v7 = 1i64 << v6;
      v12.m128i_i64[0] = 1i64 << v6;
    }
    v10 = arg->mFlags;
    v3->mStateArgsCreateMask.mFlags[0] |= v7;
    v3->mStateArgsCreateMask.mFlags[1] |= v8;
    v11 = v12;
    if ( v10 & 1 )
      _mm_store_si128(&v12, v12);
    else
      v12 = 0ui64;
    *(_OWORD *)&v3->mStateParamModelFreqMask |= *(_OWORD *)&v12;
    if ( v10 & 2 )
      _mm_store_si128(&v12, v11);
    else
      v12 = 0ui64;
    *(_OWORD *)&v3->mStateParamMeshFreqMask |= *(_OWORD *)&v12;
    arg->mIsSet = 1;
  }
}

// File Line: 184
// RVA: 0xC450
void __fastcall Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(Illusion::StateArgs *this, Render::cbLocalTransformInverseState *arg)
{
  __int16 v2; // ax
  Illusion::StateArgs *v3; // r9
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v4; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v5; // rax
  signed __int64 v6; // r8
  unsigned int v7; // ecx
  signed __int64 v8; // rax
  char v9; // cl
  char v10; // r10
  __m128i v11; // xmm0
  __int64 v12; // rax
  __m128i v13; // [rsp+0h] [rbp-18h]

  v2 = arg->mStateParamIndex;
  v3 = this;
  if ( v2 != -1 )
  {
    v13.m128i_i64[0] = 0i64;
    v4 = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)(&this->mStateArgsCreateMask + v2 + 3i64);
    arg->mPrev = v4;
    v5 = v4->mNext;
    v4->mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg->mPrev;
    v6 = 0i64;
    arg->mNext = v5;
    v7 = arg->mStateParamIndex;
    v5->mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg->mPrev;
    arg->mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))Illusion::StateArg::ExecuteSetStateBlock<Render::cbLocalTransformInverseState>;
    v8 = 0i64;
    v13.m128i_i64[1] = 0i64;
    if ( v7 >= 0x40 )
    {
      v9 = v7 - 64;
      v8 = 1i64 << v9;
      v13.m128i_i64[1] = 1i64 << v9;
    }
    else
    {
      v6 = 1i64 << v7;
      v13.m128i_i64[0] = 1i64 << v7;
    }
    v10 = arg->mFlags;
    v3->mStateArgsCreateMask.mFlags[0] |= v6;
    v3->mStateArgsCreateMask.mFlags[1] |= v8;
    v11 = v13;
    if ( v10 & 1 )
      _mm_store_si128(&v13, v13);
    else
      v13 = 0ui64;
    *(_OWORD *)&v3->mStateParamModelFreqMask |= *(_OWORD *)&v13;
    if ( v10 & 2 )
      _mm_store_si128(&v13, v11);
    else
      v13 = 0ui64;
    v12 = v13.m128i_i64[0];
    arg->mIsSet = 1;
    v3->mStateParamMeshFreqMask.mFlags[0] |= v12;
    v3->mStateParamMeshFreqMask.mFlags[1] |= v13.m128i_u64[1];
  }
}

// File Line: 185
// RVA: 0xC2F0
void __fastcall Illusion::StateArgs::Clear<Render::cbLocalTransformInverseState>(Illusion::StateArgs *this, Render::cbLocalTransformState *arg)
{
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v2; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v3; // r8
  Illusion::StateArgs *v4; // r9
  __int64 v5; // rcx
  unsigned __int64 *v6; // rdx

  v2 = arg->mNext;
  v3 = arg->mPrev;
  v4 = this;
  v5 = arg->mStateParamIndex;
  v3->mNext = v2;
  v2->mPrev = v3;
  arg->mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg->mPrev;
  arg->mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg->mPrev;
  arg->mIsSet = 0;
  if ( (Illusion::StateArgs *)v4->mStateArgsCreateMask.mFlags[2 * (v5 + 3) + 1] == (Illusion::StateArgs *)((char *)v4 + 16 * (v5 + 3)) )
  {
    v6 = &v4->mStateArgsCreateMask.mFlags[(unsigned int)(signed __int16)v5 >> 6];
    *v6 &= ~(1i64 << (v5 & 0x3F));
  }
}

