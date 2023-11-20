// File Line: 30
// RVA: 0xAB4960
void __fastcall CAkMusicTransAware::CAkMusicTransAware(CAkMusicTransAware *this, unsigned int in_ulID)
{
  CAkMusicTransAware *v2; // rbx

  v2 = this;
  CAkMusicNode::CAkMusicNode((CAkMusicNode *)&this->vfptr, in_ulID);
  v2->vfptr = (CAkIndexableVtbl *)&CAkMusicTransAware::`vftable;
  v2->m_arTrRules.m_pItems = 0i64;
  *(_QWORD *)&v2->m_arTrRules.m_uLength = 0i64;
}

// File Line: 34
// RVA: 0xAB49A0
void __fastcall CAkMusicTransAware::~CAkMusicTransAware(CAkMusicTransAware *this)
{
  AkArray<AkMusicTransitionRule,AkMusicTransitionRule const &,ArrayPoolDefault,0,AkArrayAllocatorDefault> *v1; // rbx
  CAkMusicTransAware *v2; // rdi

  v1 = &this->m_arTrRules;
  this->vfptr = (CAkIndexableVtbl *)&CAkMusicTransAware::`vftable;
  v2 = this;
  if ( this->m_arTrRules.m_pItems )
  {
    AkArray<AkMusicTransitionRule,AkMusicTransitionRule const &,ArrayPoolDefault,0,AkArrayAllocatorDefault>::RemoveAll(&this->m_arTrRules);
    AK::MemoryMgr::Free(g_DefaultPoolId, v1->m_pItems);
    v1->m_pItems = 0i64;
    v1->m_ulReserved = 0;
  }
  CAkMusicNode::~CAkMusicNode((CAkMusicNode *)&v2->vfptr);
}

// File Line: 40
// RVA: 0xAB50D0
__int64 __fastcall CAkMusicTransAware::SetMusicTransNodeParams(CAkMusicTransAware *this, char **io_rpData, unsigned int *io_rulDataSize, bool in_bPartialLoadOnly)
{
  char **v4; // rbx
  CAkMusicTransAware *v5; // r15
  __int64 result; // rax
  AkArray<AkMusicTransitionRule,AkMusicTransitionRule const &,ArrayPoolDefault,0,AkArrayAllocatorDefault> *v7; // r15
  unsigned int v8; // er13
  AkMusicTransitionRule *v9; // rax
  unsigned int v10; // er12
  unsigned int v11; // eax
  signed __int64 v12; // rdi
  __int64 v13; // rsi
  void *v14; // rax
  unsigned int v15; // ebp
  unsigned int *v16; // rax
  __int64 v17; // rsi
  void *v18; // rax
  unsigned int v19; // ebp
  unsigned int *v20; // rax
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  int v25; // ecx
  int v26; // ecx
  int v27; // ecx
  int v28; // ecx
  int v29; // ecx
  int v30; // ecx
  _DWORD *v31; // r8
  int v32; // ecx
  int v33; // ecx
  int v34; // ecx
  int v35; // ecx
  int v36; // ecx
  int v37; // ecx
  int v38; // ecx

  v4 = io_rpData;
  v5 = this;
  result = CAkMusicNode::SetMusicNodeParams(
             (CAkMusicNode *)&this->vfptr,
             io_rpData,
             io_rulDataSize,
             in_bPartialLoadOnly);
  if ( (_DWORD)result == 1 )
  {
    v7 = &v5->m_arTrRules;
    if ( v7->m_pItems )
    {
      AkArray<AkMusicTransitionRule,AkMusicTransitionRule const &,ArrayPoolDefault,0,AkArrayAllocatorDefault>::RemoveAll(v7);
      AK::MemoryMgr::Free(g_DefaultPoolId, v7->m_pItems);
      v7->m_pItems = 0i64;
      v7->m_ulReserved = 0;
    }
    v8 = *(_DWORD *)*v4;
    *v4 += 4;
    if ( !v8 )
      return 1i64;
    v9 = (AkMusicTransitionRule *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 88i64 * v8);
    v7->m_pItems = v9;
    if ( v9 )
    {
      v7->m_ulReserved = v8;
      v10 = 0;
      if ( v8 )
      {
        do
        {
          v11 = v7->m_uLength;
          if ( v11 >= v7->m_ulReserved )
          {
            v12 = 0i64;
          }
          else
          {
            v7->m_uLength = v11 + 1;
            v12 = (signed __int64)&v7->m_pItems[v11];
            if ( v12 )
            {
              *(_QWORD *)v12 = 0i64;
              *(_QWORD *)(v12 + 8) = 0i64;
              *(_QWORD *)(v12 + 16) = 0i64;
              *(_QWORD *)(v12 + 24) = 0i64;
              *(_QWORD *)(v12 + 80) = 0i64;
            }
          }
          v13 = *(unsigned int *)*v4;
          *v4 += 4;
          if ( (_DWORD)v13 )
          {
            v14 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 4i64 * (unsigned int)v13);
            *(_QWORD *)v12 = v14;
            if ( !v14 )
              goto LABEL_31;
            *(_DWORD *)(v12 + 12) = v13;
            if ( (_DWORD)v13 )
            {
              do
              {
                v15 = *(_DWORD *)*v4;
                *v4 += 4;
                v16 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast((AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault> *)v12);
                if ( v16 )
                  *v16 = v15;
                --v13;
              }
              while ( v13 );
            }
          }
          v17 = *(unsigned int *)*v4;
          *v4 += 4;
          if ( (_DWORD)v17 )
          {
            v18 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 4i64 * (unsigned int)v17);
            *(_QWORD *)(v12 + 16) = v18;
            if ( !v18 )
              goto LABEL_31;
            *(_DWORD *)(v12 + 28) = v17;
            if ( (_DWORD)v17 )
            {
              do
              {
                v19 = *(_DWORD *)*v4;
                *v4 += 4;
                v20 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast((AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault> *)(v12 + 16));
                if ( v20 )
                  *v20 = v19;
                --v17;
              }
              while ( v17 );
            }
          }
          v21 = *(_DWORD *)*v4;
          *v4 += 4;
          *(_DWORD *)(v12 + 32) = v21;
          v22 = *(_DWORD *)*v4;
          *v4 += 4;
          *(_DWORD *)(v12 + 36) = v22;
          v23 = *(_DWORD *)*v4;
          *v4 += 4;
          *(_DWORD *)(v12 + 40) = v23 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
          v24 = *(_DWORD *)*v4;
          *v4 += 4;
          *(_DWORD *)(v12 + 48) &= 0xFFFFFFE0;
          *(_DWORD *)(v12 + 48) |= v24 & 0x1F;
          v25 = *(_DWORD *)*v4;
          *v4 += 4;
          *(_DWORD *)(v12 + 44) = v25;
          LOBYTE(v25) = *(*v4)++;
          *(_DWORD *)(v12 + 48) &= 0xFFFFFFDF;
          *(_DWORD *)(v12 + 48) |= 32 * (v25 & 1);
          v26 = *(_DWORD *)*v4;
          *v4 += 4;
          *(_DWORD *)(v12 + 52) = v26;
          v27 = *(_DWORD *)*v4;
          *v4 += 4;
          *(_DWORD *)(v12 + 56) = v27;
          v28 = *(_DWORD *)*v4;
          *v4 += 4;
          *(_DWORD *)(v12 + 60) = v28 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
          v29 = *(_DWORD *)*v4;
          *v4 += 4;
          *(_DWORD *)(v12 + 64) = v29;
          v30 = *(_DWORD *)*v4;
          *v4 += 4;
          *(_DWORD *)(v12 + 68) = v30;
          LOWORD(v30) = *(_WORD *)*v4;
          *v4 += 2;
          *(_WORD *)(v12 + 72) &= 0xFFF8u;
          *(_WORD *)(v12 + 72) |= v30 & 7;
          LOBYTE(v30) = *(*v4)++;
          *(_WORD *)(v12 + 72) &= 0xFFF7u;
          *(_WORD *)(v12 + 72) |= 8 * (v30 & 1);
          LOBYTE(v30) = *(*v4)++;
          *(_WORD *)(v12 + 72) &= 0xFFEFu;
          *(_WORD *)(v12 + 72) |= 16 * (v30 & 1);
          LOBYTE(v30) = *(*v4)++;
          if ( (_BYTE)v30 )
          {
            v31 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
            *(_QWORD *)(v12 + 80) = v31;
          }
          else
          {
            v31 = 0i64;
          }
          if ( v31 )
          {
            v32 = *(_DWORD *)*v4;
            *v4 += 4;
            *v31 = v32;
            v33 = *(_DWORD *)*v4;
            *v4 += 4;
            v31[1] = v33;
            v34 = *(_DWORD *)*v4;
            *v4 += 4;
            v31[2] = v34;
            v35 = *(_DWORD *)*v4;
            *v4 += 4;
            v31[3] = v35 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
            v36 = *(_DWORD *)*v4;
            *v4 += 4;
            v31[4] = v36;
            v37 = *(_DWORD *)*v4;
            *v4 += 4;
            v31[5] = v37;
            v38 = *(_DWORD *)*v4;
            *v4 += 4;
            v31[6] = v38 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
            LOBYTE(v38) = *(*v4)++;
            v31[7] &= 0xFFFFFFFE;
            v31[7] |= v38 & 1;
            LOBYTE(v38) = *(*v4)++;
            v31[7] &= 0xFFFFFFFD;
            v31[7] |= 2 * (v38 & 1);
          }
          ++v10;
        }
        while ( v10 < v8 );
      }
      return 1i64;
    }
LABEL_31:
    result = 2i64;
  }
  return result;
}

// File Line: 128
// RVA: 0xAB4BF0
AkMusicTransitionRule *__fastcall CAkMusicTransAware::GetTransitionRule(CAkMusicTransAware *this, unsigned int in_srcID, unsigned int in_destID)
{
  unsigned int v3; // ebx
  unsigned int v4; // edi
  signed int v5; // eax
  CAkMusicTransAware *v6; // rbp
  __int64 v7; // rsi
  AkMusicTransitionRule *v8; // r11
  unsigned int *v9; // r9
  __int64 v10; // rax
  unsigned __int64 v11; // rcx
  signed __int64 v12; // r8
  unsigned __int64 v13; // r10
  signed __int64 v14; // kr00_8
  signed __int64 v15; // rdx
  unsigned int v16; // eax
  unsigned int *v17; // r9
  __int64 v18; // rax
  unsigned __int64 v19; // rcx
  signed __int64 v20; // r8
  unsigned __int64 v21; // r10
  signed __int64 v22; // kr08_8
  signed __int64 v23; // rdx
  unsigned int v24; // eax

  v3 = in_destID;
  v4 = in_srcID;
  v5 = this->m_arTrRules.m_uLength - 1;
  v6 = this;
  v7 = v5;
  if ( v5 < 0 )
    return v6->m_arTrRules.m_pItems;
  v8 = &this->m_arTrRules.m_pItems[v5];
  while ( 1 )
  {
    v9 = v8->srcIDs.m_pItems;
    if ( *v8->srcIDs.m_pItems == -1 )
      goto LABEL_31;
    v10 = v8->srcIDs.m_uLength;
    v11 = (unsigned __int64)&v9[v10];
    v12 = (signed __int64)&v9[v10];
    if ( v9 )
    {
      v13 = (unsigned __int64)&v9[v10];
      if ( (unsigned __int64)v9 <= v11 )
      {
        do
        {
          v14 = (signed __int64)(v13 - (_QWORD)v9) >> 2;
          v15 = (signed __int64)&v9[v14 / 2];
          v16 = v9[v14 / 2];
          if ( v4 >= v16 )
          {
            if ( v4 <= v16 )
            {
              v12 = (signed __int64)&v9[v14 / 2];
              break;
            }
            v9 = (unsigned int *)(v15 + 4);
          }
          else
          {
            v13 = v15 - 4;
          }
        }
        while ( (unsigned __int64)v9 <= v13 );
      }
    }
    if ( v12 != v11 )
    {
LABEL_31:
      v17 = v8->destIDs.m_pItems;
      if ( *v17 == -1 )
        return v8;
      v18 = v8->destIDs.m_uLength;
      v19 = (unsigned __int64)&v17[v18];
      v20 = (signed __int64)&v17[v18];
      if ( v17 )
      {
        v21 = (unsigned __int64)&v17[v18];
        if ( (unsigned __int64)v17 <= v19 )
        {
          do
          {
            v22 = (signed __int64)(v21 - (_QWORD)v17) >> 2;
            v23 = (signed __int64)&v17[v22 / 2];
            v24 = v17[v22 / 2];
            if ( v3 >= v24 )
            {
              if ( v3 <= v24 )
              {
                v20 = (signed __int64)&v17[v22 / 2];
                break;
              }
              v17 = (unsigned int *)(v23 + 4);
            }
            else
            {
              v21 = v23 - 4;
            }
          }
          while ( (unsigned __int64)v17 <= v21 );
        }
      }
      if ( v20 != v19 )
        return v8;
    }
    --v8;
    if ( --v7 < 0 )
      return v6->m_arTrRules.m_pItems;
  }
}

// File Line: 157
// RVA: 0xAB4D20
AkMusicTransitionRule *__fastcall CAkMusicTransAware::GetTransitionRule(CAkMusicTransAware *this, CAkParameterNodeBase *in_pOwnerNode, unsigned int in_srcID, CAkParameterNodeBase *in_pSrcParentNode, unsigned int in_destID, CAkParameterNodeBase *in_pDestParentNode, bool *out_bIsDestSequenceSpecific)
{
  CAkParameterNodeBase *v7; // r11
  unsigned int v8; // ebp
  signed int v9; // eax
  CAkParameterNodeBase *v10; // r15
  CAkMusicTransAware *v11; // r10
  __int64 v12; // r12
  AkMusicTransitionRule *v13; // rsi
  __int64 v14; // rax
  __int64 v15; // rbx
  unsigned int *v16; // r9
  unsigned __int64 v17; // rcx
  signed __int64 v18; // r8
  unsigned __int64 v19; // r10
  signed __int64 v20; // kr00_8
  signed __int64 v21; // rdx
  unsigned int v22; // eax
  unsigned int *v23; // rdi
  unsigned __int64 v24; // r8
  signed __int64 v25; // rcx
  unsigned __int64 v26; // r9
  unsigned __int64 v27; // r10
  signed __int64 v28; // kr08_8
  signed __int64 v29; // rdx
  unsigned int v30; // eax
  CAkParameterNodeBase *v31; // rbx
  unsigned int v32; // er11
  signed __int64 v33; // rcx
  unsigned __int64 v34; // r9
  unsigned __int64 v35; // r10
  signed __int64 v36; // kr10_8
  signed __int64 v37; // rdx
  unsigned int v38; // eax
  AkMusicTransitionRule *result; // rax
  CAkMusicTransAware *v40; // [rsp+60h] [rbp+8h]
  CAkParameterNodeBase *v41; // [rsp+78h] [rbp+20h]

  v41 = in_pSrcParentNode;
  v40 = this;
  v7 = in_pSrcParentNode;
  v8 = in_srcID;
  v9 = this->m_arTrRules.m_uLength - 1;
  v10 = in_pOwnerNode;
  v11 = this;
  v12 = v9;
  if ( v9 < 0 )
    return v11->m_arTrRules.m_pItems;
  v13 = &this->m_arTrRules.m_pItems[v9];
  while ( 1 )
  {
    v14 = v13->srcIDs.m_uLength;
    if ( (_DWORD)v14 )
    {
      v15 = v13->destIDs.m_uLength;
      if ( (_DWORD)v15 )
        break;
    }
LABEL_43:
    --v13;
    if ( --v12 < 0 )
      return v11->m_arTrRules.m_pItems;
    v7 = v41;
  }
  v16 = v13->srcIDs.m_pItems;
  if ( *v13->srcIDs.m_pItems == -1 )
    goto LABEL_18;
  v17 = (unsigned __int64)&v16[v14];
  v18 = (signed __int64)&v16[v14];
  if ( !v16 )
    goto LABEL_16;
  v19 = (unsigned __int64)&v16[v14];
  if ( (unsigned __int64)v16 > v17 )
    goto LABEL_15;
  while ( 1 )
  {
    v20 = (signed __int64)(v19 - (_QWORD)v16) >> 2;
    v21 = (signed __int64)&v16[v20 / 2];
    v22 = v16[v20 / 2];
    if ( v8 >= v22 )
      break;
    v19 = v21 - 4;
LABEL_12:
    if ( (unsigned __int64)v16 > v19 )
      goto LABEL_15;
  }
  if ( v8 > v22 )
  {
    v16 = (unsigned int *)(v21 + 4);
    goto LABEL_12;
  }
  v18 = (signed __int64)&v16[v20 / 2];
LABEL_15:
  v11 = v40;
LABEL_16:
  if ( v18 == v17 && !CAkMusicTransAware::AscendentMatch(v11, v10, &v13->srcIDs, v7) )
  {
LABEL_42:
    v11 = v40;
    goto LABEL_43;
  }
LABEL_18:
  v23 = v13->destIDs.m_pItems;
  if ( *v23 != -1 )
  {
    v24 = (unsigned __int64)&v23[v15];
    v25 = (signed __int64)&v23[v15];
    if ( v23 )
    {
      v26 = (unsigned __int64)v13->destIDs.m_pItems;
      v27 = (unsigned __int64)&v23[v15];
      if ( (unsigned __int64)v23 <= v24 )
      {
        do
        {
          v28 = (signed __int64)(v27 - v26) >> 2;
          v29 = v26 + 4 * (v28 / 2);
          v30 = *(_DWORD *)(v26 + 4 * (v28 / 2));
          if ( in_destID >= v30 )
          {
            if ( in_destID <= v30 )
            {
              v25 = v26 + 4 * (v28 / 2);
              break;
            }
            v26 = v29 + 4;
          }
          else
          {
            v27 = v29 - 4;
          }
        }
        while ( v26 <= v27 );
      }
    }
    if ( v25 == v24 )
    {
      v31 = in_pDestParentNode;
      if ( in_pDestParentNode )
      {
        while ( v31 != v10 )
        {
          v32 = v31->key;
          v33 = v24;
          if ( v23 )
          {
            v34 = (unsigned __int64)v13->destIDs.m_pItems;
            v35 = v24;
            if ( (unsigned __int64)v23 <= v24 )
            {
              do
              {
                v36 = (signed __int64)(v35 - v34) >> 2;
                v37 = v34 + 4 * (v36 / 2);
                v38 = *(_DWORD *)(v34 + 4 * (v36 / 2));
                if ( v32 >= v38 )
                {
                  if ( v32 <= v38 )
                  {
                    v33 = v34 + 4 * (v36 / 2);
                    break;
                  }
                  v34 = v37 + 4;
                }
                else
                {
                  v35 = v37 - 4;
                }
              }
              while ( v34 <= v35 );
            }
          }
          if ( v33 != v24 )
          {
            if ( v31->vfptr[3].Release((CAkIndexable *)&v31->vfptr) != 8 )
              goto LABEL_47;
            *out_bIsDestSequenceSpecific = 1;
            return v13;
          }
          v31 = v31->m_pParentNode;
          if ( !v31 )
            goto LABEL_42;
        }
      }
      goto LABEL_42;
    }
  }
LABEL_47:
  result = v13;
  *out_bIsDestSequenceSpecific = 0;
  return result;
}

// File Line: 192
// RVA: 0xAB4B10
AkMusicTransitionRule *__fastcall CAkMusicTransAware::GetPanicTransitionRule()
{
  unsigned int *v0; // rax
  unsigned int *v1; // rax

  if ( !(_S1_37 & 1) )
  {
    panicRule.srcIDs.m_pItems = 0i64;
    unk_14249F658 = 0i64;
    stru_14249F660.m_pItems = 0i64;
    *(_QWORD *)&stru_14249F660.m_uLength = 0i64;
    _S1_37 |= 1u;
    in_pvMemAddress = 0i64;
    atexit(CAkMusicTransAware::GetPanicTransitionRule_::_2_::_dynamic_atexit_destructor_for__panicRule__);
  }
  v0 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast(&panicRule.srcIDs);
  if ( v0 )
    *v0 = -1;
  unk_14249F670 = 0;
  unk_14249F678 = 0i64;
  unk_14249F680 = unk_14249F680 & 0xFFFFFFE7 | 0x27;
  v1 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast(&stru_14249F660);
  if ( v1 )
    *v1 = -1;
  unk_14249F684 = 0;
  unk_14249F68C = 0i64;
  unk_14249F694 = 0;
  in_pvMemAddress = 0i64;
  unk_14249F698 &= 0xFFE0u;
  return &panicRule;
}

// File Line: 222
// RVA: 0xAB4A50
CAkParameterNodeBase *__fastcall CAkMusicTransAware::AscendentMatch(CAkMusicTransAware *this, CAkParameterNodeBase *in_pOwnerNode, AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault> *in_ruleIDs, CAkParameterNodeBase *in_pNode)
{
  CAkParameterNodeBase *v4; // r11
  AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault> *v5; // rdi
  CAkParameterNodeBase *v6; // rsi
  unsigned __int64 v7; // r10
  __int64 v8; // rax
  unsigned int v9; // ebx
  unsigned __int64 v10; // rcx
  signed __int64 v11; // r8
  unsigned __int64 v12; // r9
  signed __int64 v13; // kr00_8
  signed __int64 v14; // rdx
  unsigned int v15; // eax

  v4 = in_pNode;
  v5 = in_ruleIDs;
  v6 = in_pOwnerNode;
  if ( in_pNode )
  {
    while ( v4 != v6 )
    {
      v7 = (unsigned __int64)v5->m_pItems;
      v8 = v5->m_uLength;
      v9 = v4->key;
      v10 = (unsigned __int64)&v5->m_pItems[v8];
      v11 = (signed __int64)&v5->m_pItems[v8];
      if ( v5->m_pItems )
      {
        v12 = (unsigned __int64)&v5->m_pItems[v8];
        if ( v7 <= v10 )
        {
          do
          {
            v13 = (signed __int64)(v12 - v7) >> 2;
            v14 = v7 + 4 * (v13 / 2);
            v15 = *(_DWORD *)(v7 + 4 * (v13 / 2));
            if ( v9 >= v15 )
            {
              if ( v9 <= v15 )
              {
                v11 = v7 + 4 * (v13 / 2);
                break;
              }
              v7 = v14 + 4;
            }
            else
            {
              v12 = v14 - 4;
            }
          }
          while ( v7 <= v12 );
        }
      }
      if ( v11 != v10 )
        return v4;
      v4 = v4->m_pParentNode;
      if ( !v4 )
        return 0i64;
    }
  }
  return 0i64;
}

// File Line: 322
// RVA: 0xAB4F60
__int64 __fastcall CAkMusicTransAware::PrepareMusicalDependencies(CAkMusicTransAware *this)
{
  CAkMusicTransAware *v1; // rdi
  __int64 result; // rax
  unsigned int v3; // ebp
  __int64 v4; // rsi
  __int64 v5; // rbx
  unsigned int *v6; // rdx
  unsigned int *v7; // rcx

  v1 = this;
  result = CAkMusicNode::PrepareMusicalDependencies((CAkMusicNode *)&this->vfptr);
  v3 = result;
  if ( (_DWORD)result == 1 )
  {
    v4 = 0i64;
    v5 = 0i64;
    if ( v1->m_arTrRules.m_uLength )
    {
      while ( 1 )
      {
        v6 = &v1->m_arTrRules.m_pItems[(unsigned int)v5].pTransObj->segmentID;
        if ( v6 )
        {
          v3 = CAkParameterNodeBase::PrepareNodeData(*v6);
          if ( v3 != 1 )
            break;
        }
        v5 = (unsigned int)(v5 + 1);
        if ( (unsigned int)v5 >= v1->m_arTrRules.m_uLength )
          goto LABEL_12;
      }
      if ( (_DWORD)v5 )
      {
        do
        {
          v7 = &v1->m_arTrRules.m_pItems[v4].pTransObj->segmentID;
          if ( v7 )
            CAkParameterNodeBase::UnPrepareNodeData(*v7);
          ++v4;
          --v5;
        }
        while ( v5 );
      }
      CAkMusicNode::UnPrepareMusicalDependencies((CAkMusicNode *)&v1->vfptr);
LABEL_12:
      result = v3;
    }
  }
  return result;
}

// File Line: 358
// RVA: 0xAB54F0
void __fastcall CAkMusicTransAware::UnPrepareMusicalDependencies(CAkMusicTransAware *this)
{
  unsigned int v1; // ebx
  CAkMusicTransAware *v2; // rdi
  unsigned int *v3; // rcx

  v1 = 0;
  v2 = this;
  if ( this->m_arTrRules.m_uLength )
  {
    do
    {
      v3 = &v2->m_arTrRules.m_pItems[v1].pTransObj->segmentID;
      if ( v3 )
        CAkParameterNodeBase::UnPrepareNodeData(*v3);
      ++v1;
    }
    while ( v1 < v2->m_arTrRules.m_uLength );
  }
  CAkMusicNode::UnPrepareMusicalDependencies((CAkMusicNode *)&v2->vfptr);
}

