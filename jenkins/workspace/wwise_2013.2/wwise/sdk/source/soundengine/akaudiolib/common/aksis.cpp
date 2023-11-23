// File Line: 28
// RVA: 0xA92AC0
void __fastcall CAkSIS::~CAkSIS(CAkSIS *this)
{
  char *m_pProps; // rcx
  char *v3; // rdx
  char *v4; // rbx
  __int64 v5; // rdi
  CAkTransition **v6; // rbx
  __int64 v7; // rdi
  char *v8; // rdx

  this->vfptr = (ITransitionableVtbl *)&CAkSIS::`vftable;
  m_pProps = this->m_values.m_pProps;
  if ( m_pProps )
  {
    v3 = m_pProps + 1;
    v4 = &m_pProps[((unsigned __int8)*m_pProps + 4) & 0xFFFFFFFC];
  }
  else
  {
    v3 = 0i64;
    v4 = 0i64;
  }
  if ( m_pProps )
    v5 = (__int64)&m_pProps[(unsigned __int8)*m_pProps + 1];
  else
    v5 = 0i64;
  if ( v3 != (char *)v5 )
  {
    v6 = (CAkTransition **)(v4 + 8);
    v7 = v5 - (_QWORD)v3;
    do
    {
      if ( *v6 )
        CAkTransitionManager::RemoveTransitionUser(g_pTransitionManager, *v6, this);
      v6 += 2;
      --v7;
    }
    while ( v7 );
  }
  v8 = this->m_values.m_pProps;
  if ( v8 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v8);
  this->m_values.m_pProps = 0i64;
}

// File Line: 37
// RVA: 0xA92B70
void __fastcall CAkSIS::TransUpdateValue(CAkSIS *this, __int64 in_eTarget, float in_fValue, bool in_bIsTerminated)
{
  char *m_pProps; // r10
  int v6; // r11d
  unsigned int v7; // ebx
  int v8; // r8d
  __int64 v9; // rbx
  CAkRegisteredObj *m_pGameObj; // r8
  CAkParameterNodeBase *m_pParamNode; // rcx
  CAkIndexableVtbl *vfptr; // rax
  CAkParameterNodeBase *v13; // [rsp+30h] [rbp-28h] BYREF
  unsigned int v14; // [rsp+38h] [rbp-20h]

  m_pProps = this->m_values.m_pProps;
  v6 = in_eTarget;
  if ( m_pProps )
  {
    v7 = (unsigned __int8)*m_pProps;
    v8 = 0;
    while ( 1 )
    {
      in_eTarget = (unsigned int)(v8 + 1);
      if ( m_pProps[in_eTarget] == (_BYTE)v6 )
        break;
      ++v8;
      if ( (unsigned int)in_eTarget >= v7 )
        goto LABEL_5;
    }
    v9 = (__int64)&m_pProps[16 * v8 + ((v7 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v9 = 0i64;
  }
  if ( v6 == 10 )
  {
    m_pGameObj = this->m_pGameObj;
    v14 = v14 & 0xFFFFFFFC | (m_pGameObj == 0i64);
    m_pParamNode = this->m_pParamNode;
    v13 = m_pParamNode;
    vfptr = m_pParamNode->vfptr;
    if ( m_pGameObj )
      ((void (__fastcall *)(CAkParameterNodeBase *, __int64, CAkRegisteredObj *, CAkParameterNodeBase **, _BYTE))vfptr[5].Category)(
        m_pParamNode,
        in_eTarget,
        m_pGameObj,
        &v13,
        0);
    else
      ((void (__fastcall *)(CAkParameterNodeBase *, __int64, CAkParameterNodeBase **, _QWORD))vfptr[6].__vecDelDtor)(
        m_pParamNode,
        in_eTarget,
        &v13,
        0i64);
  }
  else
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, CAkIndexableVtbl *, CAkRegisteredObj *, _QWORD))this->m_pParamNode->vfptr[5].Release)(
      this->m_pParamNode,
      (unsigned int)g_AkPropRTPCID[v6],
      this->m_pParamNode->vfptr,
      this->m_pGameObj,
      0i64);
  }
  *(float *)v9 = in_fValue;
  if ( in_bIsTerminated )
    *(_QWORD *)(v9 + 8) = 0i64;
}

