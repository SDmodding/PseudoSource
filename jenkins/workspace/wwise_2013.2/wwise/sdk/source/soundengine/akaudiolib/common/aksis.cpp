// File Line: 28
// RVA: 0xA92AC0
void __fastcall CAkSIS::~CAkSIS(CAkSIS *this)
{
  CAkSIS *v1; // rsi
  char *v2; // rcx
  signed __int64 v3; // rdx
  char *v4; // rbx
  signed __int64 v5; // rdi
  CAkTransition **v6; // rbx
  signed __int64 v7; // rdi
  char *v8; // rdx

  v1 = this;
  this->vfptr = (ITransitionableVtbl *)&CAkSIS::`vftable';
  v2 = this->m_values.m_pProps;
  if ( v2 )
  {
    v3 = (signed __int64)(v2 + 1);
    v4 = &v2[((unsigned __int8)*v2 + 4) & 0xFFFFFFFC];
  }
  else
  {
    v3 = 0i64;
    v4 = 0i64;
  }
  if ( v2 )
    v5 = (signed __int64)&v2[(unsigned __int8)*v2 + 1];
  else
    v5 = 0i64;
  if ( v3 != v5 )
  {
    v6 = (CAkTransition **)(v4 + 8);
    v7 = v5 - v3;
    do
    {
      if ( *v6 )
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, *v6, (ITransitionable *)&v1->vfptr);
      v6 += 2;
      --v7;
    }
    while ( v7 );
  }
  v8 = v1->m_values.m_pProps;
  if ( v8 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v8);
  v1->m_values.m_pProps = 0i64;
}

// File Line: 37
// RVA: 0xA92B70
void __fastcall CAkSIS::TransUpdateValue(CAkSIS *this, __int64 in_eTarget, float in_fValue, bool in_bIsTerminated)
{
  char *v4; // r10
  bool v5; // si
  float v6; // xmm6_4
  int v7; // er11
  unsigned int v8; // ebx
  int v9; // er8
  signed __int64 v10; // rbx
  float v11; // xmm2_4
  CAkRegisteredObj *v12; // r8
  CAkParameterNodeBase *v13; // rcx
  CAkIndexableVtbl *v14; // rax
  CAkParameterNodeBase *v15; // [rsp+30h] [rbp-28h]
  unsigned int v16; // [rsp+38h] [rbp-20h]

  v4 = this->m_values.m_pProps;
  v5 = in_bIsTerminated;
  v6 = in_fValue;
  v7 = in_eTarget;
  if ( v4 )
  {
    v8 = (unsigned __int8)*v4;
    v9 = 0;
    while ( 1 )
    {
      in_eTarget = (unsigned int)(v9 + 1);
      if ( v4[in_eTarget] == (_BYTE)v7 )
        break;
      v9 = in_eTarget;
      if ( (unsigned int)in_eTarget >= v8 )
        goto LABEL_5;
    }
    v10 = (signed __int64)&v4[16 * v9 + ((v8 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v10 = 0i64;
  }
  if ( v7 == 10 )
  {
    v12 = this->m_pGameObj;
    v16 = v16 & 0xFFFFFFFC | (v12 == 0i64);
    v13 = this->m_pParamNode;
    v15 = v13;
    v14 = v13->vfptr;
    if ( v12 )
      ((void (__fastcall *)(CAkParameterNodeBase *, __int64, CAkRegisteredObj *, CAkParameterNodeBase **, _BYTE))v14[5].Category)(
        v13,
        in_eTarget,
        v12,
        &v15,
        0);
    else
      ((void (__fastcall *)(CAkParameterNodeBase *, __int64, CAkParameterNodeBase **, _QWORD))v14[6].__vecDelDtor)(
        v13,
        in_eTarget,
        &v15,
        0i64);
  }
  else
  {
    v11 = in_fValue - *(float *)v10;
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, CAkIndexableVtbl *, CAkRegisteredObj *, _QWORD))this->m_pParamNode->vfptr[5].Release)(
      this->m_pParamNode,
      (unsigned int)g_AkPropRTPCID[v7],
      this->m_pParamNode->vfptr,
      this->m_pGameObj,
      0i64);
  }
  *(float *)v10 = v6;
  if ( v5 )
    *(_QWORD *)(v10 + 8) = 0i64;
}

