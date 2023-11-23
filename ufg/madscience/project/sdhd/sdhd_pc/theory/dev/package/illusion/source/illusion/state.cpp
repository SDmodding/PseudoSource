// File Line: 32
// RVA: 0x1458260
__int64 Illusion::_dynamic_initializer_for__gStateSystem__()
{
  int v0; // ecx
  __int16 *p_mParamIndex; // rax

  v0 = 127;
  p_mParamIndex = &Illusion::gStateSystem.mStateParamDescs[0].mParamIndex;
  do
  {
    --v0;
    *(_DWORD *)p_mParamIndex = 0;
    p_mParamIndex += 38;
  }
  while ( v0 >= 0 );
  UFG::qMemSet(&Illusion::gStateSystem, 0, 0x2600u);
  Illusion::gStateSystem.mCurrentParamIndex = 0;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gStateSystem__);
}

// File Line: 54
// RVA: 0x92910
void __fastcall Illusion::StateSystem::Init(Illusion::StateSystem *this)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax

  Illusion::StateSystem::AddParam(this, 0, "iUnknown", 0);
  v2 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(this, v2, "iShader", 1);
  v3 = UFG::qStringHash32("iVertexDecl", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(this, v3, "iVertexDecl", 1);
  v4 = UFG::qStringHash32("iIndexBuffer", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(this, v4, "iIndexBuffer", 1);
  v5 = UFG::qStringHash32("iVertexBuffer0", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(this, v5, "iVertexBuffer0", 1);
  v6 = UFG::qStringHash32("iVertexBuffer1", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(this, v6, "iVertexBuffer1", 1);
  v7 = UFG::qStringHash32("iVertexBuffer2", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(this, v7, "iVertexBuffer2", 1);
  v8 = UFG::qStringHash32("iVertexBuffer3", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(this, v8, "iVertexBuffer3", 1);
  v9 = UFG::qStringHash32("iInstanceBuffer", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(this, v9, "iInstanceBuffer", 1);
  v10 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(this, v10, "iAlphaState", 1);
  v11 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(this, v11, "iRasterState", 1);
  v12 = UFG::qStringHash32("iTarget", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(this, v12, "iTarget", 0);
  v13 = UFG::qStringHash32("iViewportScissor", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(this, v13, "iViewportScissor", 0);
  _((AMD_HD3D *)this);
}

// File Line: 82
// RVA: 0x923B0
__int64 __fastcall Illusion::StateSystem::GetParam(Illusion::StateSystem *this, unsigned int uid)
{
  int mCurrentParamIndex; // r8d
  int v5; // r9d
  int v6; // eax
  Illusion::StateSystem *v7; // rdx
  unsigned int mNameUID; // ecx

  mCurrentParamIndex = this->mCurrentParamIndex;
  if ( mCurrentParamIndex <= 0 )
    return 0i64;
  v5 = 0;
  while ( 1 )
  {
    v6 = (mCurrentParamIndex + v5) / 2;
    v7 = (Illusion::StateSystem *)((char *)this + 8 * v6);
    mNameUID = v7->mStateParamLookup[0].mNameUID;
    if ( uid <= mNameUID )
      break;
    v5 = v6 + 1;
LABEL_7:
    if ( v5 > mCurrentParamIndex )
      return 0i64;
  }
  if ( uid < mNameUID )
  {
    mCurrentParamIndex = v6 - 1;
    goto LABEL_7;
  }
  return LOWORD(v7->mStateParamLookup[0].mParamIndex);
}

// File Line: 124
// RVA: 0x92420
__int64 __fastcall Illusion::StateSystem::GetParam(Illusion::StateSystem *this, const char *name)
{
  unsigned int v3; // eax
  int mCurrentParamIndex; // r8d
  unsigned int v5; // r10d
  int v6; // r9d
  int v7; // eax
  char *v8; // rdx
  unsigned int v9; // ecx

  v3 = UFG::qStringHash32(name, 0xFFFFFFFF);
  mCurrentParamIndex = this->mCurrentParamIndex;
  v5 = v3;
  if ( mCurrentParamIndex <= 0 )
    return 0i64;
  v6 = 0;
  while ( 1 )
  {
    v7 = (mCurrentParamIndex + v6) / 2;
    v8 = (char *)this + 8 * v7;
    v9 = *((_DWORD *)v8 + 2432);
    if ( v5 <= v9 )
      break;
    v6 = v7 + 1;
LABEL_7:
    if ( v6 > mCurrentParamIndex )
      return 0i64;
  }
  if ( v5 < v9 )
  {
    mCurrentParamIndex = v7 - 1;
    goto LABEL_7;
  }
  return *((unsigned __int16 *)v8 + 4866);
}

// File Line: 136
// RVA: 0x8E320
__int64 __fastcall Illusion::StateSystem::AddParam(
        Illusion::StateSystem *this,
        Illusion::StateParam *param,
        const char *name,
        char is_resource_data)
{
  __int64 result; // rax

  result = Illusion::StateSystem::AddParam(this, param->mNameUID, name, is_resource_data);
  param->mParamIndex = result;
  return result;
}

// File Line: 147
// RVA: 0x8E340
__int64 __fastcall Illusion::StateSystem::AddParam(
        Illusion::StateSystem *this,
        const char *name,
        char is_resource_data)
{
  unsigned int v6; // eax

  v6 = UFG::qStringHash32(name, 0xFFFFFFFF);
  return Illusion::StateSystem::AddParam(this, v6, name, is_resource_data);
}

// File Line: 155
// RVA: 0x8E180
__int64 __fastcall Illusion::StateSystem::AddParam(
        Illusion::StateSystem *this,
        unsigned int uid,
        const char *name,
        char is_resource_data)
{
  int v4; // ebx
  int mCurrentParamIndex; // r10d
  int v10; // r11d
  int v11; // eax
  char *v12; // rdx
  unsigned int v13; // ecx
  Illusion::StateParamDesc *v14; // rsi
  __int64 v15; // rdx
  __int64 v16; // rcx
  Illusion::StateParamLookup *mStateParamLookup; // rax
  unsigned __int16 v18; // ax
  Illusion::StateParamLookup *v19; // r8
  __int64 v20; // rdx
  Illusion::StateParamLookup v21; // rax

  v4 = 0;
  if ( this->mCurrentParamIndex <= 0 )
    goto LABEL_8;
  mCurrentParamIndex = this->mCurrentParamIndex;
  v10 = 0;
  if ( mCurrentParamIndex < 0 )
    goto LABEL_8;
  while ( 1 )
  {
    v11 = (mCurrentParamIndex + v10) / 2;
    v12 = (char *)this + 8 * v11;
    v13 = *((_DWORD *)v12 + 2432);
    if ( uid <= v13 )
      break;
    v10 = v11 + 1;
LABEL_7:
    if ( v10 > mCurrentParamIndex )
      goto LABEL_8;
  }
  if ( uid < v13 )
  {
    mCurrentParamIndex = v11 - 1;
    goto LABEL_7;
  }
  v18 = *((_WORD *)v12 + 4866);
  if ( v18 )
  {
    v14 = &this->mStateParamDescs[v18];
    if ( v14 )
    {
      if ( !v14->mName[0] )
      {
        UFG::qStringCopy(v14->mName, 63, name, -1);
        v14->mIsResourceData = is_resource_data;
      }
      return (unsigned __int16)v14->mParamIndex;
    }
  }
LABEL_8:
  if ( this->mCurrentParamIndex == 128 )
    UFG::qPrintf("Illusion: Run out of state blocks.  Size=%d\n (tried to add param name %s)", 128i64, name);
  v14 = &this->mStateParamDescs[this->mCurrentParamIndex];
  v14->mNameUID = uid;
  v14->mParamIndex = this->mCurrentParamIndex;
  v14->mIsResourceData = is_resource_data;
  UFG::qStringCopy(v14->mName, 63, name, -1);
  v15 = this->mCurrentParamIndex;
  v16 = 0i64;
  if ( (int)v15 > 0 )
  {
    mStateParamLookup = this->mStateParamLookup;
    while ( v14->mNameUID >= mStateParamLookup->mNameUID )
    {
      ++v4;
      ++v16;
      ++mStateParamLookup;
      if ( v4 >= (int)v15 )
        goto LABEL_22;
    }
    if ( v15 > v16 )
    {
      v19 = &this->mStateParamLookup[v15];
      v20 = v15 - v16;
      do
      {
        v21 = v19[-1];
        --v19;
        v19[1] = v21;
        --v20;
      }
      while ( v20 );
    }
  }
LABEL_22:
  this->mStateParamLookup[v4].mNameUID = v14->mNameUID;
  this->mStateParamLookup[v4].mParamIndex = v14->mParamIndex;
  ++this->mCurrentParamIndex;
  return (unsigned __int16)v14->mParamIndex;
}

