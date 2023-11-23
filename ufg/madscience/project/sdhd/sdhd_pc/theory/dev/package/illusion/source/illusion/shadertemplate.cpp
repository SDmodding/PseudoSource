// File Line: 55
// RVA: 0x95610
Illusion::Shader *__fastcall Illusion::ShaderTemplate::SelectShader(
        Illusion::ShaderTemplate *this,
        Illusion::StateValues *state_values,
        Illusion::ShaderSelector *shader_selector)
{
  unsigned __int64 v3; // r9
  unsigned __int64 v4; // r10
  __int64 mLod; // rax
  __int64 v6; // rax
  unsigned int mNumComponentBits; // eax
  int v8; // r11d
  int v9; // r8d
  UFG::BitFlags128 *mComponentBit; // rdx
  __int64 v11; // rbx
  __int64 v12; // rax

  v3 = this->mPermutationStateBlockMask.mFlags[0] & state_values->mSetValueMask.mFlags[0];
  v4 = state_values->mSetValueMask.mFlags[1] & this->mPermutationStateBlockMask.mFlags[1];
  if ( shader_selector )
  {
    mLod = shader_selector->mLod;
    v3 = shader_selector->mRemoveState.mFlags[0] & (shader_selector->mAddState.mFlags[0] | v3);
    v4 = shader_selector->mRemoveState.mFlags[1] & (shader_selector->mAddState.mFlags[1] | v4);
    if ( this->mHasLod )
    {
      if ( (_DWORD)mLod )
      {
        v6 = mLod;
        v3 &= this->mlodRemoveFlags[v6].mFlags[0];
        v4 &= this->mlodRemoveFlags[v6].mFlags[1];
      }
    }
  }
  mNumComponentBits = this->mComponentLookup.mNumComponentBits;
  v8 = 0;
  v9 = 1;
  if ( mNumComponentBits )
  {
    mComponentBit = this->mComponentLookup.mComponentBit;
    v11 = mNumComponentBits;
    do
    {
      if ( v3 & mComponentBit->mFlags[0] | v4 & mComponentBit->mFlags[1] )
        v8 |= v9;
      v9 *= 2;
      ++mComponentBit;
      --v11;
    }
    while ( v11 );
  }
  v12 = (__int64)&this->mPermutationIndexTable[v8] & 0xFFFFFFF0i64;
  return (Illusion::Shader *)this->mShaderPermutations[(unsigned __int64)*(unsigned __int16 *)(v12
                                                                                             + 2
                                                                                             * (((__int64)&this->mPermutationIndexTable[v8]
                                                                                               - v12) >> 1))].mShaderHandle.mData;
}

// File Line: 135
// RVA: 0x939F0
__int64 __fastcall Illusion::ShaderTemplate::OnLoad(Illusion::ShaderTemplate *this)
{
  unsigned __int64 v2; // rdx
  __int64 v3; // rax
  unsigned __int16 *v4; // rcx
  const char *k; // r12
  int v6; // ebx
  unsigned __int64 v7; // rax
  char *v8; // rax
  int v9; // edx
  _QWORD *v10; // rcx
  unsigned int i; // ebx
  const char *v12; // rsi
  unsigned int v13; // eax
  unsigned __int16 v14; // ax
  unsigned __int16 v15; // di
  int v16; // edx
  __int64 mNumComponentBits; // r9
  unsigned int v18; // r8d
  unsigned __int64 v19; // r10
  unsigned __int64 v20; // r11
  unsigned __int64 v21; // rax
  char *v22; // rdx
  Illusion::ShaderComponent *v23; // r9
  unsigned int mNumShaderPermutations; // edi
  unsigned __int64 v25; // rax
  bool v26; // cf
  unsigned __int64 v27; // rax
  char *v28; // rax
  Illusion::ShaderPermutation *v29; // rbx
  unsigned int v30; // eax
  Illusion::ShaderPermutation *v31; // rsi
  unsigned int *v32; // r12
  unsigned int v33; // r14d
  unsigned int v34; // ebx
  unsigned int v35; // edi
  unsigned int v36; // r15d
  unsigned int v37; // r12d
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v39; // rax
  UFG::qResourceInventory *v40; // rax
  UFG::qResourceWarehouse *v41; // rax
  UFG::qResourceInventory *v42; // rax
  UFG::qResourceWarehouse *v43; // rax
  UFG::qResourceInventory *v44; // rax
  UFG::qResourceWarehouse *v45; // rax
  UFG::qResourceInventory *v46; // rax
  UFG::qResourceWarehouse *v47; // rax
  unsigned int v48; // ebx
  UFG::qResourceInventory *v49; // rax
  UFG::qResourceWarehouse *v50; // rax
  unsigned int v51; // ebx
  __int64 v52; // rax
  unsigned int v53; // r10d
  int mCurrentParamIndex; // ecx
  int v55; // r8d
  int v56; // eax
  char *v57; // r9
  unsigned int v58; // edx
  unsigned __int16 v59; // ax
  UFG::qResourceData *mData; // r8
  const char *mShaderName; // rbx
  unsigned int v62; // edi
  unsigned int v63; // eax
  __int64 v64; // r8
  unsigned __int8 v65; // cl
  UFG::qResourceInventory *v66; // rax
  UFG::qResourceWarehouse *v67; // rax
  UFG::qResourceInventory *v68; // rax
  UFG::qResourceWarehouse *v69; // rax
  UFG::qResourceInventory *v70; // rax
  UFG::qResourceWarehouse *v71; // rax
  UFG::qResourceInventory *v72; // rax
  UFG::qResourceWarehouse *v73; // rax
  UFG::qResourceInventory *v74; // rax
  UFG::qResourceWarehouse *v75; // rax
  UFG::qResourceHandle v77; // [rsp+30h] [rbp-89h] BYREF
  UFG::qResourceHandle v78; // [rsp+50h] [rbp-69h] BYREF
  UFG::qResourceHandle v79; // [rsp+70h] [rbp-49h] BYREF
  UFG::qResourceHandle v80; // [rsp+90h] [rbp-29h] BYREF
  __int64 v81; // [rsp+B0h] [rbp-9h]
  UFG::qResourceHandle v82; // [rsp+B8h] [rbp-1h] BYREF
  unsigned int j; // [rsp+120h] [rbp+67h]
  unsigned int *v84; // [rsp+128h] [rbp+6Fh]
  const char *v85; // [rsp+128h] [rbp+6Fh]

  v81 = -2i64;
  if ( this )
    Illusion::ShaderTemplate::ShaderTemplate(this);
  this->mNumShaderPermutations = LOWORD(this[1].mResourceHandles.UFG::qResourceData::mNode.mNext);
  v2 = WORD1(this[1].mResourceHandles.UFG::qResourceData::mNode.mNext);
  this->mNumComponents = v2;
  v3 = WORD2(this[1].mResourceHandles.UFG::qResourceData::mNode.mNext);
  this->mNumPermutationIndices = v3;
  v4 = (unsigned __int16 *)((unsigned __int64)&this[1].mDebugName[11] & 0xFFFFFFFFFFFFFFF0ui64);
  this->mPermutationIndexTable = v4;
  k = (const char *)&v4[v3];
  v6 = v2;
  v7 = 24 * v2;
  if ( !is_mul_ok(v2, 0x18ui64) )
    v7 = -1i64;
  v8 = UFG::qMalloc(v7, "ShaderComponents", 0i64);
  if ( v8 )
  {
    v9 = v6 - 1;
    if ( v6 - 1 >= 0 )
    {
      v10 = v8 + 8;
      do
      {
        *(v10 - 1) = 0i64;
        *v10 = 0i64;
        v10[1] = 0i64;
        v10 += 3;
        --v9;
      }
      while ( v9 >= 0 );
    }
  }
  else
  {
    v8 = 0i64;
  }
  this->mComponents = (Illusion::ShaderComponent *)v8;
  for ( i = 0; i < this->mNumComponents; ++i )
  {
    v12 = k;
    k += (int)(UFG::qStringLength(k) + 1);
    v13 = UFG::qStringHash32(v12, 0xFFFFFFFF);
    v14 = Illusion::StateSystem::AddParam(&Illusion::gStateSystem, v13, v12, 0);
    v15 = v14;
    v16 = 0;
    mNumComponentBits = this->mComponentLookup.mNumComponentBits;
    if ( (_DWORD)mNumComponentBits )
    {
      v18 = v14;
      v19 = (unsigned __int64)v14 >> 6;
      v20 = v14 & 0x3F;
      while ( 1 )
      {
        v21 = this->mComponentLookup.mComponentBit[v16].mFlags[v19];
        if ( _bittest64((const __int64 *)&v21, v20) )
          break;
        if ( ++v16 >= (unsigned int)mNumComponentBits )
          goto LABEL_16;
      }
    }
    else
    {
LABEL_16:
      v22 = (char *)this + 16 * mNumComponentBits;
      this->mComponentLookup.mNumComponentBits = mNumComponentBits + 1;
      v18 = v15;
      if ( v15 >= 0x40u )
        *((_QWORD *)v22 + 36) |= 1i64 << ((unsigned __int8)v15 - 64);
      else
        *((_QWORD *)v22 + 35) |= 1i64 << v15;
    }
    this->mComponents[i].mStateBlockName = v12;
    v23 = &this->mComponents[i];
    if ( v18 >= 0x40 )
      v23->mStateBlockMask.mFlags[1] |= 1i64 << ((unsigned __int8)v18 - 64);
    else
      v23->mStateBlockMask.mFlags[0] |= 1i64 << v18;
  }
  this->mPermutationStateBlockMask.mFlags[1] = 0i64;
  this->mPermutationStateBlockMask.mFlags[0] = 0i64;
  this->mlodRemoveFlags[0].mFlags[1] = 0i64;
  this->mlodRemoveFlags[0].mFlags[0] = 0i64;
  this->mlodRemoveFlags[1].mFlags[1] = 0i64;
  this->mlodRemoveFlags[1].mFlags[0] = 0i64;
  this->mlodRemoveFlags[2].mFlags[1] = 0i64;
  this->mlodRemoveFlags[2].mFlags[0] = 0i64;
  this->mlodRemoveFlags[3].mFlags[1] = 0i64;
  this->mlodRemoveFlags[3].mFlags[0] = 0i64;
  this->mlodRemoveFlags[4].mFlags[1] = 0i64;
  this->mlodRemoveFlags[4].mFlags[0] = 0i64;
  this->mlodRemoveFlags[5].mFlags[1] = 0i64;
  this->mlodRemoveFlags[5].mFlags[0] = 0i64;
  this->mlodRemoveFlags[6].mFlags[1] = 0i64;
  this->mlodRemoveFlags[6].mFlags[0] = 0i64;
  this->mlodRemoveFlags[7].mFlags[1] = 0i64;
  this->mlodRemoveFlags[7].mFlags[0] = 0i64;
  mNumShaderPermutations = this->mNumShaderPermutations;
  v25 = (unsigned __int64)mNumShaderPermutations << 6;
  if ( !is_mul_ok(mNumShaderPermutations, 0x40ui64) )
    v25 = -1i64;
  v26 = __CFADD__(v25, 16i64);
  v27 = v25 + 16;
  if ( v26 )
    v27 = -1i64;
  v28 = UFG::qMalloc(v27, "ShaderPermutations", 0i64);
  if ( v28 )
  {
    *(_DWORD *)v28 = mNumShaderPermutations;
    v29 = (Illusion::ShaderPermutation *)(v28 + 16);
    `eh vector constructor iterator(
      v28 + 16,
      0x40ui64,
      mNumShaderPermutations,
      (void (__fastcall *)(void *))Illusion::ShaderPermutation::ShaderPermutation);
  }
  else
  {
    v29 = 0i64;
  }
  this->mShaderPermutations = v29;
  v30 = 0;
  for ( j = 0; v30 < this->mNumShaderPermutations; j = v30 )
  {
    v31 = &this->mShaderPermutations[(unsigned __int64)v30];
    v32 = (unsigned int *)((unsigned __int64)(k + 15) & 0xFFFFFFFFFFFFFFF0ui64);
    v33 = *v32;
    v34 = v32[1];
    v35 = v32[2];
    v36 = v32[3];
    v84 = v32 + 4;
    v37 = v32[4];
    v31->mNumStateBlocks = *((unsigned __int8 *)v84 + 4);
    v84 = (unsigned int *)((char *)v84 + 6);
    v31->mShaderName = (const char *)v84;
    v85 = (char *)v84 + (int)(UFG::qStringLength((const char *)v84) + 1);
    UFG::qResourceHandle::qResourceHandle(&v82);
    UFG::qResourceHandle::qResourceHandle(&v80);
    UFG::qResourceHandle::qResourceHandle(&v78);
    UFG::qResourceHandle::qResourceHandle(&v77);
    UFG::qResourceHandle::qResourceHandle(&v79);
    Inventory = `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result )
    {
      v39 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v39, 0xE80F42E1);
      `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&v82, 0xE80F42E1, v33, Inventory);
    if ( v34 )
    {
      v40 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result )
      {
        v41 = UFG::qResourceWarehouse::Instance();
        v40 = UFG::qResourceWarehouse::GetInventory(v41, 0xE80F42E1);
        `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result = v40;
      }
      UFG::qResourceHandle::Init(&v80, 0xE80F42E1, v34, v40);
    }
    if ( v35 )
    {
      v42 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result )
      {
        v43 = UFG::qResourceWarehouse::Instance();
        v42 = UFG::qResourceWarehouse::GetInventory(v43, 0xE80F42E1);
        `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result = v42;
      }
      UFG::qResourceHandle::Init(&v78, 0xE80F42E1, v35, v42);
    }
    if ( v36 )
    {
      v44 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result )
      {
        v45 = UFG::qResourceWarehouse::Instance();
        v44 = UFG::qResourceWarehouse::GetInventory(v45, 0xE80F42E1);
        `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result = v44;
      }
      UFG::qResourceHandle::Init(&v77, 0xE80F42E1, v36, v44);
    }
    if ( v37 )
    {
      v46 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result )
      {
        v47 = UFG::qResourceWarehouse::Instance();
        v46 = UFG::qResourceWarehouse::GetInventory(v47, 0xE80F42E1);
        `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result = v46;
      }
      UFG::qResourceHandle::Init(&v79, 0xE80F42E1, v37, v46);
    }
    v48 = UFG::qStringHashUpper32(v31->mShaderName, 0xFFFFFFFF);
    v49 = `UFG::qGetResourceInventory<Illusion::Shader>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Shader>::`2::result )
    {
      v50 = UFG::qResourceWarehouse::Instance();
      v49 = UFG::qResourceWarehouse::GetInventory(v50, 0x8B5561A1);
      `UFG::qGetResourceInventory<Illusion::Shader>::`2::result = v49;
    }
    UFG::qResourceHandle::Init(&v31->mShaderHandle, 0x8B5561A1, v48, v49);
    v51 = 0;
    for ( k = v85; v51 < v31->mNumStateBlocks; ++v51 )
    {
      v52 = *(unsigned __int8 *)k++;
      v53 = UFG::qStringHash32(this->mComponents[v52].mStateBlockName, 0xFFFFFFFF);
      mCurrentParamIndex = Illusion::gStateSystem.mCurrentParamIndex;
      if ( Illusion::gStateSystem.mCurrentParamIndex > 0 )
      {
        v55 = 0;
        if ( Illusion::gStateSystem.mCurrentParamIndex >= 0 )
        {
          do
          {
            v56 = (mCurrentParamIndex + v55) / 2;
            v57 = (char *)&Illusion::gStateSystem + 8 * v56;
            v58 = *((_DWORD *)v57 + 2432);
            if ( v53 <= v58 )
            {
              if ( v53 >= v58 )
              {
                v59 = *((_WORD *)v57 + 4866);
                goto LABEL_62;
              }
              mCurrentParamIndex = v56 - 1;
            }
            else
            {
              v55 = v56 + 1;
            }
          }
          while ( v55 <= mCurrentParamIndex );
        }
      }
      v59 = 0;
LABEL_62:
      if ( v59 >= 0x40u )
        v31->mStateBlockMask.mFlags[1] |= 1i64 << ((unsigned __int8)v59 - 64);
      else
        v31->mStateBlockMask.mFlags[0] |= 1i64 << v59;
      if ( v59 >= 0x40u )
        this->mPermutationStateBlockMask.mFlags[1] |= 1i64 << ((unsigned __int8)v59 - 64);
      else
        this->mPermutationStateBlockMask.mFlags[0] |= 1i64 << v59;
      mData = v31->mShaderHandle.mData;
      if ( v59 >= 0x40u )
        mData[1].mNode.mChild[0] = (UFG::qBaseNodeRB *)((__int64)mData[1].mNode.mChild[0] | (1i64 << ((unsigned __int8)v59 - 64)));
      else
        mData[1].mNode.mParent = (UFG::qBaseNodeRB *)((__int64)mData[1].mNode.mParent | (1i64 << v59));
    }
    this->mHasLod = 0;
    mShaderName = v31->mShaderName;
    v62 = 9;
    v63 = UFG::qStringLength(v31->mShaderName) - 1;
    if ( v63 )
    {
      v64 = v63;
      do
      {
        if ( *mShaderName == 95 )
        {
          v65 = mShaderName[1];
          if ( (unsigned __int8)(v65 - 48) <= 9u && (unsigned int)v65 - 48 < v62 )
            v62 = v65 - 48;
        }
        ++mShaderName;
        --v64;
      }
      while ( v64 );
    }
    if ( VerboseShaderTemplate )
      UFG::qPrintf("Permutation %25s StateBlockMask=0x%016x64", v31->mShaderName, v31->mStateBlockMask.mFlags[0]);
    v66 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result )
    {
      v67 = UFG::qResourceWarehouse::Instance();
      v66 = UFG::qResourceWarehouse::GetInventory(v67, 0xE80F42E1);
      `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result = v66;
    }
    UFG::qResourceHandle::Close(&v79, v66);
    UFG::qResourceHandle::~qResourceHandle(&v79);
    v68 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result )
    {
      v69 = UFG::qResourceWarehouse::Instance();
      v68 = UFG::qResourceWarehouse::GetInventory(v69, 0xE80F42E1);
      `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result = v68;
    }
    UFG::qResourceHandle::Close(&v77, v68);
    UFG::qResourceHandle::~qResourceHandle(&v77);
    v70 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result )
    {
      v71 = UFG::qResourceWarehouse::Instance();
      v70 = UFG::qResourceWarehouse::GetInventory(v71, 0xE80F42E1);
      `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result = v70;
    }
    UFG::qResourceHandle::Close(&v78, v70);
    UFG::qResourceHandle::~qResourceHandle(&v78);
    v72 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result )
    {
      v73 = UFG::qResourceWarehouse::Instance();
      v72 = UFG::qResourceWarehouse::GetInventory(v73, 0xE80F42E1);
      `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result = v72;
    }
    UFG::qResourceHandle::Close(&v80, v72);
    UFG::qResourceHandle::~qResourceHandle(&v80);
    v74 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result )
    {
      v75 = UFG::qResourceWarehouse::Instance();
      v74 = UFG::qResourceWarehouse::GetInventory(v75, 0xE80F42E1);
      `UFG::qGetResourceInventory<Illusion::ShaderBinary>::`2::result = v74;
    }
    UFG::qResourceHandle::Close(&v82, v74);
    UFG::qResourceHandle::~qResourceHandle(&v82);
    v30 = j + 1;
  }
  return 1i64;
}

// File Line: 350
// RVA: 0x1458190
__int64 Illusion::_dynamic_initializer_for__gShaderTemplateInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Illusion::gShaderTemplateInventory,
    "iShaderTemplateInventory",
    0x1FD4E5C5u,
    0xC46AEEFu,
    0,
    0);
  Illusion::gShaderTemplateInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::iShaderTemplateInventory::`vftable;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gShaderTemplateInventory__);
}

// File Line: 358
// RVA: 0x8DFE0
void __fastcall Illusion::iShaderTemplateInventory::Add(
        Illusion::iShaderTemplateInventory *this,
        Illusion::ShaderTemplate *resource_data)
{
  Illusion::ShaderTemplate::OnLoad(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 368
// RVA: 0x949F0
void __fastcall Illusion::iShaderTemplateInventory::Remove(
        Illusion::iShaderTemplateInventory *this,
        UFG::qResourceData *resource_data)
{
  UFG::qBaseNodeRB *v3; // rcx
  UFG::qBaseNodeRB **v4; // rbx

  UFG::qResourceInventory::Remove(this, resource_data);
  v3 = resource_data[1].mNode.mChild[0];
  if ( v3 )
  {
    v4 = &v3[-1].mChild[1];
    `eh vector destructor iterator(
      v3,
      0x40ui64,
      (int)v3[-1].mChild[1],
      (void (__fastcall *)(void *))Illusion::ShaderPermutation::~ShaderPermutation);
    operator delete[](v4);
  }
}

