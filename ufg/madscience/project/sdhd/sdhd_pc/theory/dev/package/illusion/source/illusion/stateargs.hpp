// File Line: 84
// RVA: 0x7B70
void __fastcall Illusion::StateArg::~StateArg(Illusion::StateArg *this)
{
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax

  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 90
// RVA: 0x7720
void __fastcall Illusion::StateArg::ExecuteSetStateBlock<Render::cbLocalTransformState>(
        Illusion::StateArg *this,
        Illusion::StateArg *arg,
        Illusion::StateValues *state_values)
{
  __int16 v3; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // r9

  v3 = Render::cbLocalTransformState::sStateParamIndex;
  mPrev = this[1].mPrev;
  if ( (unsigned int)(__int16)Render::cbLocalTransformState::sStateParamIndex >= 0x40 )
    arg->mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)((__int64)arg->mNext | (1i64 << ((unsigned __int8)Render::cbLocalTransformState::sStateParamIndex - 64)));
  else
    arg->mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)((__int64)arg->mPrev | (1i64 << Render::cbLocalTransformState::sStateParamIndex));
  *((_QWORD *)&arg->mCallback + v3) = mPrev;
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
void __fastcall Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
        Illusion::StateArgs *this,
        Render::cbLocalTransformInverseState *arg)
{
  __int16 mStateParamIndex; // ax
  UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *v4; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned int v6; // ecx
  __int64 v7; // r8
  __int64 v8; // rax
  char mFlags; // r10
  __int128 v10; // xmm0
  __int128 v11; // [rsp+0h] [rbp-18h]
  __int128 v12; // [rsp+0h] [rbp-18h]

  mStateParamIndex = arg->mStateParamIndex;
  if ( mStateParamIndex != -1 )
  {
    v11 = 0ui64;
    v4 = &this->mStateArgs[mStateParamIndex];
    mNext = v4->mNode.mNext;
    v4->mNode.mNext = arg;
    arg->mPrev = &v4->mNode;
    arg->mNext = mNext;
    mNext->mPrev = arg;
    v6 = arg->mStateParamIndex;
    v7 = 0i64;
    arg->mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))Illusion::StateArg::ExecuteSetStateBlock<Render::cbLocalTransformInverseState>;
    v8 = 0i64;
    if ( v6 >= 0x40 )
    {
      v8 = 1i64 << ((unsigned __int8)v6 - 64);
      *((_QWORD *)&v11 + 1) = v8;
    }
    else
    {
      v7 = 1i64 << v6;
      *(_QWORD *)&v11 = 1i64 << v6;
    }
    mFlags = arg->mFlags;
    this->mStateArgsCreateMask.mFlags[0] |= v7;
    this->mStateArgsCreateMask.mFlags[1] |= v8;
    v10 = v11;
    if ( (mFlags & 1) == 0 )
      v11 = 0ui64;
    *(_OWORD *)&this->mStateParamModelFreqMask |= v11;
    if ( (mFlags & 2) != 0 )
      v12 = v10;
    else
      v12 = 0ui64;
    *(_OWORD *)&this->mStateParamMeshFreqMask |= v12;
    arg->mIsSet = 1;
  }
}

// File Line: 184
// RVA: 0xC450
void __fastcall Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
        Illusion::StateArgs *this,
        Render::cbLocalTransformInverseState *arg)
{
  __int16 mStateParamIndex; // ax
  UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *v4; // r8
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  __int64 v6; // r8
  unsigned int v7; // ecx
  __int64 v8; // rax
  char mFlags; // r10
  __int128 v10; // xmm0
  __int128 v11; // [rsp+0h] [rbp-18h]
  __int128 v12; // [rsp+0h] [rbp-18h]

  mStateParamIndex = arg->mStateParamIndex;
  if ( mStateParamIndex != -1 )
  {
    v11 = 0ui64;
    v4 = &this->mStateArgs[mStateParamIndex];
    arg->mPrev = &v4->mNode;
    mNext = v4->mNode.mNext;
    v4->mNode.mNext = arg;
    v6 = 0i64;
    arg->mNext = mNext;
    v7 = arg->mStateParamIndex;
    mNext->mPrev = arg;
    arg->mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))Illusion::StateArg::ExecuteSetStateBlock<Render::cbLocalTransformInverseState>;
    v8 = 0i64;
    if ( v7 >= 0x40 )
    {
      v8 = 1i64 << ((unsigned __int8)v7 - 64);
      *((_QWORD *)&v11 + 1) = v8;
    }
    else
    {
      v6 = 1i64 << v7;
      *(_QWORD *)&v11 = 1i64 << v7;
    }
    mFlags = arg->mFlags;
    this->mStateArgsCreateMask.mFlags[0] |= v6;
    this->mStateArgsCreateMask.mFlags[1] |= v8;
    v10 = v11;
    if ( (mFlags & 1) == 0 )
      v11 = 0ui64;
    *(_OWORD *)&this->mStateParamModelFreqMask |= v11;
    if ( (mFlags & 2) != 0 )
      v12 = v10;
    else
      v12 = 0ui64;
    arg->mIsSet = 1;
    *(_OWORD *)&this->mStateParamMeshFreqMask |= v12;
  }
}

// File Line: 185
// RVA: 0xC2F0
void __fastcall Illusion::StateArgs::Clear<Render::cbLocalTransformInverseState>(
        Illusion::StateArgs *this,
        Render::cbLocalTransformState *arg)
{
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // r8
  __int64 mStateParamIndex; // rcx
  unsigned __int64 *v6; // rdx

  mNext = arg->mNext;
  mPrev = arg->mPrev;
  mStateParamIndex = arg->mStateParamIndex;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  arg->mPrev = arg;
  arg->mNext = arg;
  arg->mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)this->mStateArgs[mStateParamIndex].mNode.mNext == &this->mStateArgs[mStateParamIndex] )
  {
    v6 = &this->mStateArgsCreateMask.mFlags[(unsigned int)(__int16)mStateParamIndex >> 6];
    *v6 &= ~(1i64 << (mStateParamIndex & 0x3F));
  }
}

