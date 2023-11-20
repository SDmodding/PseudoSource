// File Line: 55
// RVA: 0x95610
UFG::qResourceData *__fastcall Illusion::ShaderTemplate::SelectShader(Illusion::ShaderTemplate *this, Illusion::StateValues *state_values, Illusion::ShaderSelector *shader_selector)
{
  unsigned __int64 v3; // r9
  unsigned __int64 v4; // r10
  __int64 v5; // rax
  __int64 v6; // rax
  unsigned int v7; // eax
  int v8; // er11
  signed int v9; // er8
  UFG::BitFlags128 *v10; // rdx
  __int64 v11; // rbx
  signed __int64 v12; // rax

  v3 = this->mPermutationStateBlockMask.mFlags[0] & state_values->mSetValueMask.mFlags[0];
  v4 = state_values->mSetValueMask.mFlags[1] & this->mPermutationStateBlockMask.mFlags[1];
  if ( shader_selector )
  {
    v5 = shader_selector->mLod;
    v3 = shader_selector->mRemoveState.mFlags[0] & (shader_selector->mAddState.mFlags[0] | v3);
    v4 = shader_selector->mRemoveState.mFlags[1] & (shader_selector->mAddState.mFlags[1] | v4);
    if ( this->mHasLod )
    {
      if ( (_DWORD)v5 )
      {
        v6 = v5;
        v3 &= this->mlodRemoveFlags[v6].mFlags[0];
        v4 &= this->mlodRemoveFlags[v6].mFlags[1];
      }
    }
  }
  v7 = this->mComponentLookup.mNumComponentBits;
  v8 = 0;
  v9 = 1;
  if ( v7 )
  {
    v10 = this->mComponentLookup.mComponentBit;
    v11 = v7;
    do
    {
      if ( v3 & v10->mFlags[0] | v4 & v10->mFlags[1] )
        v8 |= v9;
      v9 *= 2;
      ++v10;
      --v11;
    }
    while ( v11 );
  }
  v12 = (_QWORD)&this->mPermutationIndexTable[v8] & 0xFFFFFFF0i64;
  return this->mShaderPermutations[(unsigned __int64)*(unsigned __int16 *)(v12
                                                                         + 2
                                                                         * ((_QWORD)((_QWORD)&this->mPermutationIndexTable[v8]
                                                                                   - v12) >> 1))].mShaderHandle.mData;
}

// File Line: 135
// RVA: 0x939F0
signed __int64 __fastcall Illusion::ShaderTemplate::OnLoad(Illusion::ShaderTemplate *this)
{
  Illusion::ShaderTemplate *v1; // r13
  unsigned __int64 v2; // rdx
  __int64 v3; // rax
  unsigned __int64 v4; // rcx
  const char *v5; // r12
  int v6; // ebx
  unsigned __int64 v7; // rax
  char *v8; // rax
  int v9; // edx
  _QWORD *v10; // rcx
  unsigned int v11; // ebx
  const char *v12; // rsi
  unsigned int v13; // eax
  unsigned __int16 v14; // ax
  unsigned __int16 v15; // di
  unsigned int v16; // edx
  __int64 v17; // r9
  unsigned int v18; // er8
  unsigned __int64 v19; // r10
  unsigned __int64 v20; // r11
  unsigned __int64 v21; // rax
  signed __int64 v22; // rdx
  signed __int64 v23; // r9
  int v24; // edi
  unsigned __int64 v25; // rax
  unsigned __int8 v26; // cf
  unsigned __int64 v27; // rax
  char *v28; // rax
  signed __int64 v29; // rbx
  unsigned int v30; // eax
  _QWORD *v31; // rsi
  unsigned int *v32; // r12
  unsigned int v33; // er14
  unsigned int v34; // ebx
  unsigned int v35; // edi
  unsigned int v36; // er15
  unsigned int v37; // er12
  UFG::qResourceInventory *v38; // rax
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
  unsigned int v53; // er10
  int v54; // ecx
  int v55; // er8
  int v56; // eax
  char *v57; // r9
  unsigned int v58; // edx
  unsigned __int16 v59; // ax
  __int64 v60; // r8
  const char *v61; // rbx
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
  UFG::qResourceHandle v77; // [rsp+30h] [rbp-89h]
  UFG::qResourceHandle v78; // [rsp+50h] [rbp-69h]
  UFG::qResourceHandle v79; // [rsp+70h] [rbp-49h]
  UFG::qResourceHandle v80; // [rsp+90h] [rbp-29h]
  __int64 v81; // [rsp+B0h] [rbp-9h]
  UFG::qResourceHandle v82; // [rsp+B8h] [rbp-1h]
  unsigned int v83; // [rsp+120h] [rbp+67h]
  signed __int64 v84; // [rsp+128h] [rbp+6Fh]
  const char *v85; // [rsp+128h] [rbp+6Fh]

  v81 = -2i64;
  v1 = this;
  if ( this )
    Illusion::ShaderTemplate::ShaderTemplate(this);
  v1->mNumShaderPermutations = LOWORD(v1[1].mResourceHandles.mNode.mNext);
  v2 = WORD1(v1[1].mResourceHandles.mNode.mNext);
  v1->mNumComponents = v2;
  v3 = WORD2(v1[1].mResourceHandles.mNode.mNext);
  v1->mNumPermutationIndices = v3;
  v4 = (unsigned __int64)&v1[1].mDebugName[11] & 0xFFFFFFFFFFFFFFF0ui64;
  v1->mPermutationIndexTable = (unsigned __int16 *)v4;
  v5 = (const char *)(v4 + 2 * v3);
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
  v1->mComponents = (Illusion::ShaderComponent *)v8;
  v11 = 0;
  if ( v1->mNumComponents )
  {
    do
    {
      v12 = v5;
      v5 += (signed int)((unsigned __int64)UFG::qStringLength(v5) + 1);
      v13 = UFG::qStringHash32(v12, 0xFFFFFFFF);
      v14 = Illusion::StateSystem::AddParam(&Illusion::gStateSystem, v13, v12, 0);
      v15 = v14;
      v16 = 0;
      v17 = v1->mComponentLookup.mNumComponentBits;
      if ( (_DWORD)v17 )
      {
        v18 = v14;
        v19 = (unsigned __int64)v14 >> 6;
        v20 = v14 & 0x3F;
        while ( 1 )
        {
          v21 = v1->mComponentLookup.mComponentBit[0].mFlags[v19 + 2i64 * v16];
          if ( _bittest64((const signed __int64 *)&v21, v20) )
            break;
          if ( ++v16 >= (unsigned int)v17 )
            goto LABEL_16;
        }
      }
      else
      {
LABEL_16:
        v22 = (signed __int64)v1 + 16 * v17;
        v1->mComponentLookup.mNumComponentBits = v17 + 1;
        v18 = v15;
        if ( v15 >= 0x40u )
          *(_QWORD *)(v22 + 288) |= 1i64 << ((unsigned __int8)v15 - 64);
        else
          *(_QWORD *)(v22 + 280) |= 1i64 << v15;
      }
      v1->mComponents[v11].mStateBlockName = v12;
      v23 = (signed __int64)&v1->mComponents[v11];
      if ( v18 >= 0x40 )
        *(_QWORD *)(v23 + 16) |= 1i64 << ((unsigned __int8)v18 - 64);
      else
        *(_QWORD *)(v23 + 8) |= 1i64 << v18;
      ++v11;
    }
    while ( v11 < v1->mNumComponents );
  }
  v1->mPermutationStateBlockMask.mFlags[1] = 0i64;
  v1->mPermutationStateBlockMask.mFlags[0] = 0i64;
  v1->mlodRemoveFlags[0].mFlags[1] = 0i64;
  v1->mlodRemoveFlags[0].mFlags[0] = 0i64;
  v1->mlodRemoveFlags[1].mFlags[1] = 0i64;
  v1->mlodRemoveFlags[1].mFlags[0] = 0i64;
  v1->mlodRemoveFlags[2].mFlags[1] = 0i64;
  v1->mlodRemoveFlags[2].mFlags[0] = 0i64;
  v1->mlodRemoveFlags[3].mFlags[1] = 0i64;
  v1->mlodRemoveFlags[3].mFlags[0] = 0i64;
  v1->mlodRemoveFlags[4].mFlags[1] = 0i64;
  v1->mlodRemoveFlags[4].mFlags[0] = 0i64;
  v1->mlodRemoveFlags[5].mFlags[1] = 0i64;
  v1->mlodRemoveFlags[5].mFlags[0] = 0i64;
  v1->mlodRemoveFlags[6].mFlags[1] = 0i64;
  v1->mlodRemoveFlags[6].mFlags[0] = 0i64;
  v1->mlodRemoveFlags[7].mFlags[1] = 0i64;
  v1->mlodRemoveFlags[7].mFlags[0] = 0i64;
  v24 = v1->mNumShaderPermutations;
  v25 = (unsigned __int64)v1->mNumShaderPermutations << 6;
  if ( !is_mul_ok(v1->mNumShaderPermutations, 0x40ui64) )
    v25 = -1i64;
  v26 = __CFADD__(v25, 16i64);
  v27 = v25 + 16;
  if ( v26 )
    v27 = -1i64;
  v28 = UFG::qMalloc(v27, "ShaderPermutations", 0i64);
  if ( v28 )
  {
    *(_DWORD *)v28 = v24;
    v29 = (signed __int64)(v28 + 16);
    `eh vector constructor iterator'(
      v28 + 16,
      0x40ui64,
      v24,
      (void (__fastcall *)(void *))Illusion::ShaderPermutation::ShaderPermutation);
  }
  else
  {
    v29 = 0i64;
  }
  v1->mShaderPermutations = (Illusion::ShaderPermutation *)v29;
  v30 = 0;
  v83 = 0;
  if ( v1->mNumShaderPermutations )
  {
    do
    {
      v31 = &v1->mShaderPermutations[(unsigned __int64)v30].mShaderName;
      v32 = (unsigned int *)((unsigned __int64)(v5 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
      v33 = *v32;
      v34 = v32[1];
      v35 = v32[2];
      v36 = v32[3];
      v84 = (signed __int64)(v32 + 4);
      v37 = v32[4];
      *((_DWORD *)v31 + 14) = *(unsigned __int8 *)(v84 + 4);
      v84 += 6i64;
      *v31 = v84;
      v85 = (const char *)((signed int)((unsigned __int64)UFG::qStringLength((const char *)v84) + 1) + v84);
      UFG::qResourceHandle::qResourceHandle(&v82);
      UFG::qResourceHandle::qResourceHandle(&v80);
      UFG::qResourceHandle::qResourceHandle(&v78);
      UFG::qResourceHandle::qResourceHandle(&v77);
      UFG::qResourceHandle::qResourceHandle(&v79);
      v38 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result )
      {
        v39 = UFG::qResourceWarehouse::Instance();
        v38 = UFG::qResourceWarehouse::GetInventory(v39, 0xE80F42E1);
        `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result = v38;
      }
      UFG::qResourceHandle::Init(&v82, 0xE80F42E1, v33, v38);
      if ( v34 )
      {
        v40 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result )
        {
          v41 = UFG::qResourceWarehouse::Instance();
          v40 = UFG::qResourceWarehouse::GetInventory(v41, 0xE80F42E1);
          `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result = v40;
        }
        UFG::qResourceHandle::Init(&v80, 0xE80F42E1, v34, v40);
      }
      if ( v35 )
      {
        v42 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result )
        {
          v43 = UFG::qResourceWarehouse::Instance();
          v42 = UFG::qResourceWarehouse::GetInventory(v43, 0xE80F42E1);
          `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result = v42;
        }
        UFG::qResourceHandle::Init(&v78, 0xE80F42E1, v35, v42);
      }
      if ( v36 )
      {
        v44 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result )
        {
          v45 = UFG::qResourceWarehouse::Instance();
          v44 = UFG::qResourceWarehouse::GetInventory(v45, 0xE80F42E1);
          `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result = v44;
        }
        UFG::qResourceHandle::Init(&v77, 0xE80F42E1, v36, v44);
      }
      if ( v37 )
      {
        v46 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result )
        {
          v47 = UFG::qResourceWarehouse::Instance();
          v46 = UFG::qResourceWarehouse::GetInventory(v47, 0xE80F42E1);
          `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result = v46;
        }
        UFG::qResourceHandle::Init(&v79, 0xE80F42E1, v37, v46);
      }
      v48 = UFG::qStringHashUpper32((const char *)*v31, 0xFFFFFFFF);
      v49 = `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result )
      {
        v50 = UFG::qResourceWarehouse::Instance();
        v49 = UFG::qResourceWarehouse::GetInventory(v50, 0x8B5561A1);
        `UFG::qGetResourceInventory<Illusion::Shader>'::`2'::result = v49;
      }
      UFG::qResourceHandle::Init((UFG::qResourceHandle *)(v31 + 1), 0x8B5561A1, v48, v49);
      v51 = 0;
      v5 = v85;
      if ( *((_DWORD *)v31 + 14) )
      {
        do
        {
          v52 = *(unsigned __int8 *)v5++;
          v53 = UFG::qStringHash32(v1->mComponents[v52].mStateBlockName, 0xFFFFFFFF);
          v54 = Illusion::gStateSystem.mCurrentParamIndex;
          if ( Illusion::gStateSystem.mCurrentParamIndex > 0 )
          {
            v55 = 0;
            if ( Illusion::gStateSystem.mCurrentParamIndex >= 0 )
            {
              do
              {
                v56 = (v54 + v55) / 2;
                v57 = (char *)&Illusion::gStateSystem + 8 * v56;
                v58 = *((_DWORD *)v57 + 2432);
                if ( v53 <= v58 )
                {
                  if ( v53 >= v58 )
                  {
                    v59 = *((_WORD *)v57 + 4866);
                    goto LABEL_62;
                  }
                  v54 = v56 - 1;
                }
                else
                {
                  v55 = v56 + 1;
                }
              }
              while ( v55 <= v54 );
            }
          }
          v59 = 0;
LABEL_62:
          if ( v59 >= 0x40u )
            v31[6] |= 1i64 << ((unsigned __int8)v59 - 64);
          else
            v31[5] |= 1i64 << v59;
          if ( v59 >= 0x40u )
            v1->mPermutationStateBlockMask.mFlags[1] |= 1i64 << ((unsigned __int8)v59 - 64);
          else
            v1->mPermutationStateBlockMask.mFlags[0] |= 1i64 << v59;
          v60 = v31[3];
          if ( v59 >= 0x40u )
            *(_QWORD *)(v60 + 96) |= 1i64 << ((unsigned __int8)v59 - 64);
          else
            *(_QWORD *)(v60 + 88) |= 1i64 << v59;
          ++v51;
        }
        while ( v51 < *((_DWORD *)v31 + 14) );
      }
      v1->mHasLod = 0;
      v61 = (const char *)*v31;
      v62 = 9;
      v63 = (unsigned __int64)UFG::qStringLength((const char *)*v31) - 1;
      if ( v63 )
      {
        v64 = v63;
        do
        {
          if ( *v61 == 95 )
          {
            v65 = v61[1];
            if ( (unsigned __int8)(v65 - 48) <= 9u && (unsigned int)v65 - 48 < v62 )
              v62 = v65 - 48;
          }
          ++v61;
          --v64;
        }
        while ( v64 );
      }
      if ( VerboseShaderTemplate )
        UFG::qPrintf("Permutation %25s StateBlockMask=0x%016x64", *v31, v31[5]);
      v66 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result )
      {
        v67 = UFG::qResourceWarehouse::Instance();
        v66 = UFG::qResourceWarehouse::GetInventory(v67, 0xE80F42E1);
        `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result = v66;
      }
      UFG::qResourceHandle::Close(&v79, v66);
      UFG::qResourceHandle::~qResourceHandle(&v79);
      v68 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result )
      {
        v69 = UFG::qResourceWarehouse::Instance();
        v68 = UFG::qResourceWarehouse::GetInventory(v69, 0xE80F42E1);
        `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result = v68;
      }
      UFG::qResourceHandle::Close(&v77, v68);
      UFG::qResourceHandle::~qResourceHandle(&v77);
      v70 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result )
      {
        v71 = UFG::qResourceWarehouse::Instance();
        v70 = UFG::qResourceWarehouse::GetInventory(v71, 0xE80F42E1);
        `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result = v70;
      }
      UFG::qResourceHandle::Close(&v78, v70);
      UFG::qResourceHandle::~qResourceHandle(&v78);
      v72 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result )
      {
        v73 = UFG::qResourceWarehouse::Instance();
        v72 = UFG::qResourceWarehouse::GetInventory(v73, 0xE80F42E1);
        `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result = v72;
      }
      UFG::qResourceHandle::Close(&v80, v72);
      UFG::qResourceHandle::~qResourceHandle(&v80);
      v74 = `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result )
      {
        v75 = UFG::qResourceWarehouse::Instance();
        v74 = UFG::qResourceWarehouse::GetInventory(v75, 0xE80F42E1);
        `UFG::qGetResourceInventory<Illusion::ShaderBinary>'::`2'::result = v74;
      }
      UFG::qResourceHandle::Close(&v82, v74);
      UFG::qResourceHandle::~qResourceHandle(&v82);
      v30 = v83 + 1;
      v83 = v30;
    }
    while ( v30 < v1->mNumShaderPermutations );
  }
  return 1i64;
}

// File Line: 350
// RVA: 0x1458190
__int64 Illusion::_dynamic_initializer_for__gShaderTemplateInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Illusion::gShaderTemplateInventory.vfptr,
    "iShaderTemplateInventory",
    0x1FD4E5C5u,
    0xC46AEEFu,
    0,
    0);
  Illusion::gShaderTemplateInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::iShaderTemplateInventory::`vftable';
  return atexit(Illusion::_dynamic_atexit_destructor_for__gShaderTemplateInventory__);
}

// File Line: 358
// RVA: 0x8DFE0
void __fastcall Illusion::iShaderTemplateInventory::Add(Illusion::iShaderTemplateInventory *this, UFG::qResourceData *resource_data)
{
  Illusion::iShaderTemplateInventory *v2; // rdi
  UFG::qResourceData *v3; // rbx

  v2 = this;
  v3 = resource_data;
  Illusion::ShaderTemplate::OnLoad((Illusion::ShaderTemplate *)resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v2->vfptr, v3);
}

// File Line: 368
// RVA: 0x949F0
void __fastcall Illusion::iShaderTemplateInventory::Remove(Illusion::iShaderTemplateInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qBaseNodeRB *v3; // rcx
  UFG::qBaseNodeRB **v4; // rbx

  v2 = resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v3 = v2[1].mNode.mChild[0];
  if ( v3 )
  {
    v4 = &v3[-1].mChild[1];
    `eh vector destructor iterator'(
      v3,
      0x40ui64,
      (int)v3[-1].mChild[1],
      (void (__fastcall *)(void *))Illusion::ShaderPermutation::~ShaderPermutation);
    operator delete[](v4);
  }
}

