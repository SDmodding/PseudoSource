// File Line: 36
// RVA: 0xA76F40
void __fastcall CAkAction::CAkAction(CAkAction *this, AkActionType in_eActionType, unsigned int in_ulID)
{
  unsigned __int16 v3; // bx
  char v5; // al

  v3 = in_eActionType;
  CAkIndexable::CAkIndexable(this, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkAction::`vftable;
  this->pNextLightItem = 0i64;
  this->m_props.m_pProps = 0i64;
  this->m_ranges.m_pProps = 0i64;
  this->m_ulElementID = 0;
  v5 = *((_BYTE *)this + 54);
  this->m_eActionType = v3;
  *((_BYTE *)this + 54) = v5 & 0x80 | 4;
}

// File Line: 41
// RVA: 0xA76F90
void __fastcall CAkAction::~CAkAction(CAkAction *this)
{
  char *m_pProps; // rdx
  char *v3; // rdx

  this->vfptr = (CAkIndexableVtbl *)&CAkAction::`vftable;
  m_pProps = this->m_ranges.m_pProps;
  if ( m_pProps )
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pProps);
  this->m_ranges.m_pProps = 0i64;
  v3 = this->m_props.m_pProps;
  if ( v3 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v3);
  this->m_props.m_pProps = 0i64;
  CAkIndexable::~CAkIndexable(this);
}

// File Line: 45
// RVA: 0xA77130
CAkActionSetAkProp *__fastcall CAkAction::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  unsigned __int32 v2; // r8d

  v2 = in_eActionType & 0xFF00;
  if ( v2 <= 0xE00 )
  {
    if ( v2 != 3584 )
    {
      if ( (in_eActionType & 0xFF00u) > 0x800 )
      {
        if ( v2 != 2304 )
        {
          if ( ((v2 - 2560) & 0xFFFFFEFF) == 0 )
            return CAkActionSetAkProp::Create(in_eActionType, in_ulID, AkPropID_Volume);
          if ( ((v2 - 3072) & 0xFFFFFEFF) == 0 )
            return CAkActionSetAkProp::Create(in_eActionType, in_ulID, AkPropID_BusVolume);
          return 0i64;
        }
      }
      else if ( v2 != 2048 )
      {
        if ( (in_eActionType & 0xFF00u) > 0x400 )
        {
          if ( ((v2 - 1536) & 0xFFFFFEFF) == 0 )
            return (CAkActionSetAkProp *)CAkActionMute::Create(in_eActionType, in_ulID);
        }
        else
        {
          switch ( v2 )
          {
            case 0x400u:
              return (CAkActionSetAkProp *)CAkActionPlay::Create(in_eActionType, in_ulID);
            case 0x100u:
              return (CAkActionSetAkProp *)CAkActionStop::Create(in_eActionType, in_ulID);
            case 0x200u:
              return (CAkActionSetAkProp *)CAkActionPause::Create(in_eActionType, in_ulID);
            case 0x300u:
              return (CAkActionSetAkProp *)CAkActionResume::Create(in_eActionType, in_ulID);
          }
        }
        return 0i64;
      }
      return CAkActionSetAkProp::Create(in_eActionType, in_ulID, AkPropID_Pitch);
    }
    return CAkActionSetAkProp::Create(in_eActionType, in_ulID, AkPropID_LPF);
  }
  if ( (in_eActionType & 0xFF00u) <= 0x1900 )
  {
    if ( v2 == 6400 )
      return (CAkActionSetAkProp *)CAkActionSetSwitch::Create(in_eActionType, in_ulID);
    if ( (in_eActionType & 0xFF00u) > 0x1200 )
    {
      if ( ((v2 - 4864) & 0xFFFFFEFF) == 0 )
        return (CAkActionSetAkProp *)CAkActionSetGameParameter::Create(in_eActionType, in_ulID);
      return 0i64;
    }
    if ( v2 == 4608 )
      return (CAkActionSetAkProp *)CAkActionSetState::Create(in_eActionType, in_ulID);
    if ( v2 != 3840 )
    {
      if ( ((v2 - 4096) & 0xFFFFFEFF) == 0 )
        return (CAkActionSetAkProp *)CAkActionUseState::Create(in_eActionType, in_ulID);
      return 0i64;
    }
    return CAkActionSetAkProp::Create(in_eActionType, in_ulID, AkPropID_LPF);
  }
  if ( ((v2 - 6656) & 0xFFFFFEFF) == 0 )
    return (CAkActionSetAkProp *)CAkActionBypassFX::Create(in_eActionType, in_ulID);
  if ( v2 == 7168 )
    return (CAkActionSetAkProp *)CAkActionBreak::Create(in_eActionType, in_ulID);
  if ( v2 == 7424 )
    return (CAkActionSetAkProp *)CAkActionTrigger::Create(in_eActionType, in_ulID);
  if ( v2 != 7680 )
    return 0i64;
  return (CAkActionSetAkProp *)CAkActionSeek::Create(in_eActionType, in_ulID);
}

// File Line: 122
// RVA: 0xA770C0
void __fastcall CAkAction::AddToIndex(CAkAction *this)
{
  CAkIndexItem<CAkAction *> *p_m_idxActions; // rbx
  _RTL_CRITICAL_SECTION_DEBUG **v3; // rdx

  if ( this->key )
  {
    p_m_idxActions = &g_pIndex->m_idxActions;
    EnterCriticalSection(&g_pIndex->m_idxActions.m_IndexLock.m_csLock);
    v3 = &p_m_idxActions->m_IndexLock.m_csLock.DebugInfo + this->key % 0xC1;
    this->pNextItem = (CAkIndexable *)v3[5];
    v3[5] = (_RTL_CRITICAL_SECTION_DEBUG *)this;
    ++p_m_idxActions->m_mapIDToPtr.m_uiSize;
    LeaveCriticalSection(&p_m_idxActions->m_IndexLock.m_csLock);
  }
}

// File Line: 136
// RVA: 0xA77070
__int64 __fastcall CAkAction::AddRef(CAkAction *this)
{
  CAkAudioLibIndex *v1; // rbx
  unsigned int v3; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxActions.m_IndexLock.m_csLock);
  v3 = this->m_lRef + 1;
  this->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxActions.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 142
// RVA: 0xA774D0
__int64 __fastcall CAkAction::Release(CAkAction *this)
{
  CAkAudioLibIndex *v1; // rbx
  bool v3; // zf
  unsigned int m_lRef; // ebp
  unsigned int key; // edx
  int v6; // edi

  v1 = g_pIndex;
  EnterCriticalSection(&g_pIndex->m_idxActions.m_IndexLock.m_csLock);
  v3 = this->m_lRef-- == 1;
  m_lRef = this->m_lRef;
  if ( v3 )
  {
    key = this->key;
    if ( key )
      CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxActions, key);
    v6 = g_DefaultPoolId;
    this->vfptr->__vecDelDtor(this, 0i64);
    AK::MemoryMgr::Free(v6, this);
  }
  LeaveCriticalSection(&v1->m_idxActions.m_IndexLock.m_csLock);
  return m_lRef;
}

// File Line: 161
// RVA: 0xA777B0
void __fastcall CAkAction::SetElementID(CAkAction *this, WwiseObjectIDext in_Id)
{
  *((_BYTE *)this + 54) &= ~0x40u;
  this->m_ulElementID = in_Id.id;
  *((_BYTE *)this + 54) |= in_Id.bIsBus << 6;
}

// File Line: 167
// RVA: 0xA77680
__int64 __fastcall CAkAction::SetAkProp(
        CAkAction *this,
        AkPropID in_eProp,
        float in_fValue,
        float in_fMin,
        float in_fMax)
{
  char v6; // di
  char *m_pProps; // r9
  int v8; // ebx
  unsigned int v9; // r8d
  unsigned int v10; // r10d
  int v11; // edx
  __int64 v12; // rcx
  __int64 v13; // rdx
  AkPropValue *p_in_Value; // rax
  __int64 result; // rax
  char *v16; // rdx
  unsigned int v17; // r9d
  __int64 v18; // rcx
  AkPropValue in_Value; // [rsp+58h] [rbp+10h] BYREF

  v6 = in_eProp;
  m_pProps = this->m_props.m_pProps;
  v8 = 0;
  v9 = 1;
  LODWORD(in_Value.fValue) = g_AkPropDefault[in_eProp];
  if ( m_pProps )
  {
    v10 = (unsigned __int8)*m_pProps;
    v11 = 0;
    while ( 1 )
    {
      v12 = (unsigned int)(v11 + 1);
      if ( m_pProps[v12] == v6 )
        break;
      ++v11;
      if ( (unsigned int)v12 >= v10 )
        goto LABEL_5;
    }
    v13 = (__int64)&m_pProps[4 * v11 + ((v10 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v13 = 0i64;
  }
  p_in_Value = &in_Value;
  if ( v13 )
    p_in_Value = (AkPropValue *)v13;
  in_Value.fValue = p_in_Value->fValue;
  if ( in_Value.fValue == in_fValue
    || (in_Value.fValue = in_fValue,
        result = AkPropBundle<AkPropValue>::SetAkProp(&this->m_props, v6, LODWORD(in_fValue)),
        v9 = result,
        (_DWORD)result == 1) )
  {
    if ( in_fMin != 0.0 || in_fMax != 0.0 )
      return AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetAkProp(
               &this->m_ranges,
               v6,
               (RANGED_MODIFIERS<AkPropValue>)__PAIR64__(LODWORD(in_fMax), LODWORD(in_fMin)));
    v16 = this->m_ranges.m_pProps;
    if ( !v16 )
      return v9;
    v17 = (unsigned __int8)*v16;
    while ( 1 )
    {
      v18 = (unsigned int)(v8 + 1);
      if ( v16[v18] == v6 )
        break;
      ++v8;
      if ( (unsigned int)v18 >= v17 )
        return v9;
    }
    if ( !&v16[8 * v8 + ((v17 + 4) & 0xFFFFFFFC)] )
      return v9;
    else
      return AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetAkProp(
               &this->m_ranges,
               v6,
               (RANGED_MODIFIERS<AkPropValue>)__PAIR64__(LODWORD(in_fMax), LODWORD(in_fMin)));
  }
  return result;
}

// File Line: 186
// RVA: 0xA77560
__int64 __fastcall CAkAction::SetAkProp(
        CAkAction *this,
        AkPropID in_eProp,
        AkPropValue in_iValue,
        unsigned int in_iMin,
        int in_iMax)
{
  char v6; // di
  char *m_pProps; // r11
  int v8; // ebx
  unsigned int v11; // r10d
  unsigned int v12; // r8d
  int v13; // edx
  __int64 v14; // rcx
  __int64 v15; // rdx
  int *p_iValue; // rax
  __int64 result; // rax
  char *v18; // rdx
  unsigned int v19; // r8d
  __int64 v20; // rcx
  int iValue; // [rsp+58h] [rbp+10h] BYREF

  v6 = in_eProp;
  m_pProps = this->m_props.m_pProps;
  v8 = 0;
  v11 = 1;
  iValue = g_AkPropDefault[in_eProp].iValue;
  if ( m_pProps )
  {
    v12 = (unsigned __int8)*m_pProps;
    v13 = 0;
    while ( 1 )
    {
      v14 = (unsigned int)(v13 + 1);
      if ( m_pProps[v14] == v6 )
        break;
      ++v13;
      if ( (unsigned int)v14 >= v12 )
        goto LABEL_5;
    }
    v15 = (__int64)&m_pProps[4 * v13 + ((v12 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v15 = 0i64;
  }
  p_iValue = &iValue;
  if ( v15 )
    p_iValue = (int *)v15;
  if ( *p_iValue == LODWORD(in_iValue.fValue)
    || (result = AkPropBundle<AkPropValue>::SetAkProp(&this->m_props, v6, in_iValue), v11 = result, (_DWORD)result == 1) )
  {
    if ( in_iMin || in_iMax )
      return AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetAkProp(
               &this->m_ranges,
               v6,
               (RANGED_MODIFIERS<AkPropValue>)__PAIR64__(in_iMax, in_iMin));
    v18 = this->m_ranges.m_pProps;
    if ( !v18 )
      return v11;
    v19 = (unsigned __int8)*v18;
    while ( 1 )
    {
      v20 = (unsigned int)(v8 + 1);
      if ( v18[v20] == v6 )
        break;
      ++v8;
      if ( (unsigned int)v20 >= v19 )
        return v11;
    }
    if ( &v18[8 * v8 + ((v19 + 4) & 0xFFFFFFFC)] )
      return AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetAkProp(
               &this->m_ranges,
               v6,
               (RANGED_MODIFIERS<AkPropValue>)__PAIR64__(in_iMax, in_iMin));
    else
      return v11;
  }
  return result;
}

// File Line: 205
// RVA: 0xA773D0
__int64 __fastcall CAkAction::GetTransitionTime(CAkAction *this)
{
  char *m_pProps; // r8
  int v2; // r10d
  unsigned int v4; // r9d
  int v5; // edx
  __int64 v6; // rcx
  __int64 v7; // rdx
  char *v8; // r9
  int *p_iValue; // rax
  unsigned int v10; // ebx
  unsigned int v11; // eax
  int i; // edx
  __int64 v13; // r8
  char *v15; // rdi
  int v16; // esi
  int iValue; // [rsp+30h] [rbp+8h] BYREF

  m_pProps = this->m_props.m_pProps;
  v2 = 0;
  iValue = g_AkPropDefault[15].iValue;
  if ( m_pProps )
  {
    v4 = (unsigned __int8)*m_pProps;
    v5 = 0;
    while ( 1 )
    {
      v6 = (unsigned int)(v5 + 1);
      if ( m_pProps[v6] == 15 )
        break;
      ++v5;
      if ( (unsigned int)v6 >= v4 )
        goto LABEL_5;
    }
    v7 = (__int64)&m_pProps[4 * v5 + ((v4 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v7 = 0i64;
  }
  v8 = this->m_ranges.m_pProps;
  p_iValue = &iValue;
  if ( v7 )
    p_iValue = (int *)v7;
  v10 = *p_iValue;
  if ( !v8 )
    return v10;
  v11 = (unsigned __int8)*v8;
  for ( i = 0; ; ++i )
  {
    v13 = (unsigned int)(i + 1);
    if ( v8[v13] == 15 )
      break;
    if ( (unsigned int)v13 >= v11 )
      return v10;
  }
  v15 = &v8[8 * i + ((v11 + 4) & 0xFFFFFFFC)];
  if ( !v15 )
    return v10;
  v16 = *((_DWORD *)v15 + 1) - *(_DWORD *)v15;
  if ( v16 )
    v2 = (int)((double)rand() * 0.00003051850947599719 * (double)v16 + 0.5);
  return v10 + v2 + *(_DWORD *)v15;
}

// File Line: 212
// RVA: 0xA772D0
__int64 __fastcall CAkAction::GetDelayTime(CAkAction *this)
{
  char *m_pProps; // r8
  int v2; // r10d
  unsigned int v4; // r9d
  int v5; // edx
  __int64 v6; // rcx
  __int64 v7; // rdx
  char *v8; // r9
  int *p_iValue; // rax
  unsigned int v10; // ebx
  unsigned int v11; // eax
  int i; // edx
  __int64 v13; // r8
  char *v15; // rdi
  int v16; // esi
  int iValue; // [rsp+30h] [rbp+8h] BYREF

  m_pProps = this->m_props.m_pProps;
  v2 = 0;
  iValue = g_AkPropDefault[14].iValue;
  if ( m_pProps )
  {
    v4 = (unsigned __int8)*m_pProps;
    v5 = 0;
    while ( 1 )
    {
      v6 = (unsigned int)(v5 + 1);
      if ( m_pProps[v6] == 14 )
        break;
      ++v5;
      if ( (unsigned int)v6 >= v4 )
        goto LABEL_5;
    }
    v7 = (__int64)&m_pProps[4 * v5 + ((v4 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v7 = 0i64;
  }
  v8 = this->m_ranges.m_pProps;
  p_iValue = &iValue;
  if ( v7 )
    p_iValue = (int *)v7;
  v10 = *p_iValue;
  if ( !v8 )
    return v10;
  v11 = (unsigned __int8)*v8;
  for ( i = 0; ; ++i )
  {
    v13 = (unsigned int)(i + 1);
    if ( v8[v13] == 14 )
      break;
    if ( (unsigned int)v13 >= v11 )
      return v10;
  }
  v15 = &v8[8 * i + ((v11 + 4) & 0xFFFFFFFC)];
  if ( !v15 )
    return v10;
  v16 = *((_DWORD *)v15 + 1) - *(_DWORD *)v15;
  if ( v16 )
    v2 = (int)((double)rand() * 0.00003051850947599719 * (double)v16 + 0.5);
  return v10 + v2 + *(_DWORD *)v15;
}

// File Line: 219
// RVA: 0xA777D0
__int64 __fastcall CAkAction::SetInitialValues(CAkAction *this, char *in_pData, unsigned int in_ulDataSize)
{
  char *v3; // rdx
  int v4; // eax
  CAkIndexableVtbl *vfptr; // rax
  char *m_pProps; // rdx
  int v8; // edi
  AkPropBundle<RANGED_MODIFIERS<AkPropValue> > *p_m_ranges; // r14
  char *v10; // rdx
  unsigned __int8 *v11; // rax
  unsigned __int8 v12; // bl
  unsigned int v13; // r15d
  char *v14; // rax
  char *v15; // rbp
  unsigned int v16; // r9d
  char *v17; // rdx
  size_t v18; // rbx
  char *v19; // r8
  unsigned int v20; // r10d
  __int64 v21; // rcx
  __int64 v22; // rdx
  char *v23; // r8
  char *v24; // r8
  unsigned int v25; // edx
  __int64 v26; // rcx
  unsigned __int8 *v28; // r8
  __int64 v29; // [rsp+60h] [rbp+8h]
  void *Src; // [rsp+68h] [rbp+10h] BYREF
  unsigned int io_rulDataSize; // [rsp+70h] [rbp+18h] BYREF

  io_rulDataSize = in_ulDataSize;
  v3 = in_pData + 6;
  Src = v3;
  v4 = *(_DWORD *)v3;
  Src = v3 + 4;
  LODWORD(v29) = v4;
  vfptr = this->vfptr;
  BYTE4(v29) = v3[4] != 0;
  Src = v3 + 5;
  ((void (__fastcall *)(CAkAction *, __int64))vfptr[1].AddRef)(this, v29);
  m_pProps = this->m_props.m_pProps;
  if ( m_pProps )
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pProps);
  v8 = 0;
  p_m_ranges = &this->m_ranges;
  this->m_props.m_pProps = 0i64;
  v10 = this->m_ranges.m_pProps;
  if ( v10 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v10);
  v11 = (unsigned __int8 *)Src;
  p_m_ranges->m_pProps = 0i64;
  v12 = *v11;
  Src = v11 + 1;
  if ( v12 )
  {
    v13 = (v12 + 4) & 0xFFFFFFFC;
    v14 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v13 + 4 * v12);
    v15 = v14;
    if ( !v14 )
    {
      v16 = 52;
      goto LABEL_11;
    }
    *v14 = v12;
    memmove(v14 + 1, Src, v12);
    v17 = (char *)Src + v12;
    v18 = 4i64 * v12;
    Src = v17;
    memmove(&v15[v13], v17, v18);
    Src = (char *)Src + v18;
    this->m_props.m_pProps = v15;
  }
  v16 = AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetInitialParams(&this->m_ranges, (char **)&Src, &io_rulDataSize);
  if ( v16 == 1 )
    v16 = ((__int64 (__fastcall *)(CAkAction *, void **, unsigned int *, __int64))this->vfptr[2].AddRef)(
            this,
            &Src,
            &io_rulDataSize,
            1i64);
LABEL_11:
  v19 = this->m_props.m_pProps;
  if ( v19 )
  {
    v20 = (unsigned __int8)*v19;
    v21 = 0i64;
    while ( 1 )
    {
      v22 = (unsigned int)(v21 + 1);
      if ( v19[v22] == 14 )
        break;
      v21 = (unsigned int)v22;
      if ( (unsigned int)v22 >= v20 )
        goto LABEL_18;
    }
    v23 = &v19[4 * v21 + ((v20 + 4) & 0xFFFFFFFC)];
    if ( v23 )
      *(_DWORD *)v23 *= AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8;
  }
LABEL_18:
  v24 = p_m_ranges->m_pProps;
  if ( p_m_ranges->m_pProps )
  {
    v25 = (unsigned __int8)*v24;
    while ( 1 )
    {
      v26 = (unsigned int)(v8 + 1);
      if ( v24[v26] == 14 )
        break;
      ++v8;
      if ( (unsigned int)v26 >= v25 )
        return v16;
    }
    v28 = (unsigned __int8 *)&v24[8 * v8 + ((v25 + 4) & 0xFFFFFFFC)];
    if ( v28 )
    {
      *(_DWORD *)v28 *= AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8;
      *((_DWORD *)v28 + 1) *= AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8;
    }
  }
  return v16;
}

// File Line: 278
// RVA: 0xA772A0
CAkParameterNodeBase *__fastcall CAkAction::GetAndRefTarget(CAkAction *this)
{
  return CAkAudioLibIndex::GetNodePtrAndAddRef(
           g_pIndex,
           this->m_ulElementID,
           (AkNodeType)((*((_BYTE *)this + 54) & 0x40) != 0));
}

