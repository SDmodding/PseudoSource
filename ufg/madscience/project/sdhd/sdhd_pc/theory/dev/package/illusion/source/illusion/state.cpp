// File Line: 32
// RVA: 0x1458260
__int64 Illusion::_dynamic_initializer_for__gStateSystem__()
{
  signed int v0; // ecx
  __int16 *v1; // rax

  v0 = 127;
  v1 = &Illusion::gStateSystem.mStateParamDescs[0].mParamIndex;
  do
  {
    --v0;
    *(_DWORD *)v1 = 0;
    v1 += 38;
  }
  while ( v0 >= 0 );
  UFG::qMemSet(&Illusion::gStateSystem, 0, 0x2600u);
  Illusion::gStateSystem.mCurrentParamIndex = 0;
  return atexit(Illusion::_dynamic_atexit_destructor_for__gStateSystem__);
}

// File Line: 54
// RVA: 0x92910
void __fastcall Illusion::StateSystem::Init(Illusion::StateSystem *this)
{
  Illusion::StateSystem *v1; // rbx
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

  v1 = this;
  Illusion::StateSystem::AddParam(this, 0, "iUnknown", 0);
  v2 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(v1, v2, "iShader", 1);
  v3 = UFG::qStringHash32("iVertexDecl", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(v1, v3, "iVertexDecl", 1);
  v4 = UFG::qStringHash32("iIndexBuffer", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(v1, v4, "iIndexBuffer", 1);
  v5 = UFG::qStringHash32("iVertexBuffer0", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(v1, v5, "iVertexBuffer0", 1);
  v6 = UFG::qStringHash32("iVertexBuffer1", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(v1, v6, "iVertexBuffer1", 1);
  v7 = UFG::qStringHash32("iVertexBuffer2", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(v1, v7, "iVertexBuffer2", 1);
  v8 = UFG::qStringHash32("iVertexBuffer3", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(v1, v8, "iVertexBuffer3", 1);
  v9 = UFG::qStringHash32("iInstanceBuffer", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(v1, v9, "iInstanceBuffer", 1);
  v10 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(v1, v10, "iAlphaState", 1);
  v11 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(v1, v11, "iRasterState", 1);
  v12 = UFG::qStringHash32("iTarget", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(v1, v12, "iTarget", 0);
  v13 = UFG::qStringHash32("iViewportScissor", 0xFFFFFFFF);
  Illusion::StateSystem::AddParam(v1, v13, "iViewportScissor", 0);
  _((AMD_HD3D *)v1);
}

// File Line: 82
// RVA: 0x923B0
__int64 __fastcall Illusion::StateSystem::GetParam(Illusion::StateSystem *this, unsigned int uid)
{
  int v2; // er8
  unsigned int v3; // er10
  Illusion::StateSystem *v4; // r11
  int v5; // er9
  int v6; // eax
  Illusion::StateSystem *v7; // rdx
  unsigned int v8; // ecx

  v2 = this->mCurrentParamIndex;
  v3 = uid;
  v4 = this;
  if ( v2 <= 0 )
    return 0i64;
  v5 = 0;
  if ( v2 < 0 )
    return 0i64;
  while ( 1 )
  {
    v6 = (v2 + v5) / 2;
    v7 = (Illusion::StateSystem *)((char *)v4 + 8 * v6);
    v8 = v7->mStateParamLookup[0].mNameUID;
    if ( v3 <= v8 )
      break;
    v5 = v6 + 1;
LABEL_7:
    if ( v5 > v2 )
      return 0i64;
  }
  if ( v3 < v8 )
  {
    v2 = v6 - 1;
    goto LABEL_7;
  }
  return LOWORD(v7->mStateParamLookup[0].mParamIndex);
}

// File Line: 124
// RVA: 0x92420
__int64 __fastcall Illusion::StateSystem::GetParam(Illusion::StateSystem *this, const char *name)
{
  Illusion::StateSystem *v2; // rbx
  unsigned int v3; // eax
  int v4; // er8
  unsigned int v5; // er10
  int v6; // er9
  int v7; // eax
  signed __int64 v8; // rdx
  unsigned int v9; // ecx

  v2 = this;
  v3 = UFG::qStringHash32(name, 0xFFFFFFFF);
  v4 = v2->mCurrentParamIndex;
  v5 = v3;
  if ( v4 <= 0 )
    return 0i64;
  v6 = 0;
  if ( v4 < 0 )
    return 0i64;
  while ( 1 )
  {
    v7 = (v4 + v6) / 2;
    v8 = (signed __int64)v2 + 8 * v7;
    v9 = *(_DWORD *)(v8 + 9728);
    if ( v5 <= v9 )
      break;
    v6 = v7 + 1;
LABEL_7:
    if ( v6 > v4 )
      return 0i64;
  }
  if ( v5 < v9 )
  {
    v4 = v7 - 1;
    goto LABEL_7;
  }
  return *(unsigned __int16 *)(v8 + 9732);
}

// File Line: 136
// RVA: 0x8E320
__int64 __fastcall Illusion::StateSystem::AddParam(Illusion::StateSystem *this, Illusion::StateParam *param, const char *name, bool is_resource_data)
{
  Illusion::StateParam *v4; // rbx
  __int64 result; // rax

  v4 = param;
  result = Illusion::StateSystem::AddParam(this, param->mNameUID, name, is_resource_data);
  v4->mParamIndex = result;
  return result;
}

// File Line: 147
// RVA: 0x8E340
__int64 __fastcall Illusion::StateSystem::AddParam(Illusion::StateSystem *this, const char *name, bool is_resource_data)
{
  const char *v3; // rdi
  Illusion::StateSystem *v4; // rsi
  bool v5; // bl
  unsigned int v6; // eax

  v3 = name;
  v4 = this;
  v5 = is_resource_data;
  v6 = UFG::qStringHash32(name, 0xFFFFFFFF);
  return Illusion::StateSystem::AddParam(v4, v6, v3, v5);
}

// File Line: 155
// RVA: 0x8E180
__int64 __fastcall Illusion::StateSystem::AddParam(Illusion::StateSystem *this, unsigned int uid, const char *name, bool is_resource_data)
{
  signed int v4; // ebx
  bool v5; // r12
  const char *v6; // r15
  unsigned int v7; // ebp
  Illusion::StateSystem *v8; // rdi
  int v9; // er10
  int v10; // er11
  int v11; // eax
  signed __int64 v12; // rdx
  unsigned int v13; // ecx
  signed __int64 v14; // rsi
  __int64 v15; // rdx
  __int64 v16; // rcx
  Illusion::StateParamLookup *v17; // rax
  unsigned __int16 v18; // ax
  signed __int64 v19; // r8
  __int64 v20; // rdx
  __int64 v21; // rax
  __int64 v22; // rcx

  v4 = 0;
  v5 = is_resource_data;
  v6 = name;
  v7 = uid;
  v8 = this;
  if ( this->mCurrentParamIndex <= 0 )
    goto LABEL_8;
  v9 = this->mCurrentParamIndex;
  v10 = 0;
  if ( v9 < 0 )
    goto LABEL_8;
  while ( 1 )
  {
    v11 = (v9 + v10) / 2;
    v12 = (signed __int64)v8 + 8 * v11;
    v13 = *(_DWORD *)(v12 + 9728);
    if ( v7 <= v13 )
      break;
    v10 = v11 + 1;
LABEL_7:
    if ( v10 > v9 )
      goto LABEL_8;
  }
  if ( v7 < v13 )
  {
    v9 = v11 - 1;
    goto LABEL_7;
  }
  v18 = *(_WORD *)(v12 + 9732);
  if ( v18 )
  {
    v14 = (signed __int64)&v8->mStateParamDescs[v18];
    if ( v14 )
    {
      if ( !*(_BYTE *)(v14 + 12) )
      {
        UFG::qStringCopy((char *)(v14 + 12), 63, name, -1);
        *(_BYTE *)(v14 + 75) = v5;
      }
      return *(unsigned __int16 *)(v14 + 8);
    }
  }
LABEL_8:
  if ( v8->mCurrentParamIndex == 128 )
    UFG::qPrintf("Illusion: Run out of state blocks.  Size=%d\n (tried to add param name '%s')", 128i64);
  v14 = (signed __int64)&v8->mStateParamDescs[v8->mCurrentParamIndex];
  *(_DWORD *)v14 = v7;
  *(_WORD *)(v14 + 8) = v8->mCurrentParamIndex;
  *(_BYTE *)(v14 + 75) = v5;
  UFG::qStringCopy((char *)(v14 + 12), 63, v6, -1);
  v15 = v8->mCurrentParamIndex;
  v16 = 0i64;
  if ( (signed int)v15 > 0 )
  {
    v17 = v8->mStateParamLookup;
    while ( *(_DWORD *)v14 >= v17->mNameUID )
    {
      ++v4;
      ++v16;
      ++v17;
      if ( v4 >= (signed int)v15 )
        goto LABEL_22;
    }
    if ( v15 > v16 )
    {
      v19 = (signed __int64)&v8->mStateParamLookup[v15];
      v20 = v15 - v16;
      do
      {
        v21 = *(_QWORD *)(v19 - 8);
        v19 -= 8i64;
        *(_QWORD *)(v19 + 8) = v21;
        --v20;
      }
      while ( v20 );
    }
  }
LABEL_22:
  v22 = v4;
  v8->mStateParamLookup[v22].mNameUID = *(_DWORD *)v14;
  v8->mStateParamLookup[v22].mParamIndex = *(signed __int16 *)(v14 + 8);
  ++v8->mCurrentParamIndex;
  return *(unsigned __int16 *)(v14 + 8);
}

