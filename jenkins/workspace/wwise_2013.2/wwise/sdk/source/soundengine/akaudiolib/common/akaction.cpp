// File Line: 36
// RVA: 0xA76F40
void __fastcall CAkAction::CAkAction(CAkAction *this, AkActionType in_eActionType, unsigned int in_ulID)
{
  unsigned __int16 v3; // bx
  CAkAction *v4; // rdi
  char v5; // al

  v3 = in_eActionType;
  v4 = this;
  CAkIndexable::CAkIndexable((CAkIndexable *)&this->vfptr, in_ulID);
  v4->vfptr = (CAkIndexableVtbl *)&CAkAction::`vftable';
  v4->pNextLightItem = 0i64;
  v4->m_props.m_pProps = 0i64;
  v4->m_ranges.m_pProps = 0i64;
  v4->m_ulElementID = 0;
  v5 = *((_BYTE *)v4 + 54);
  v4->m_eActionType = v3;
  *((_BYTE *)v4 + 54) = v5 & 0x84 | 4;
}

// File Line: 41
// RVA: 0xA76F90
void __fastcall CAkAction::~CAkAction(CAkAction *this)
{
  CAkAction *v1; // rbx
  char *v2; // rdx
  char *v3; // rdx

  v1 = this;
  this->vfptr = (CAkIndexableVtbl *)&CAkAction::`vftable';
  v2 = this->m_ranges.m_pProps;
  if ( v2 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v2);
  v1->m_ranges.m_pProps = 0i64;
  v3 = v1->m_props.m_pProps;
  if ( v3 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v3);
  v1->m_props.m_pProps = 0i64;
  CAkIndexable::~CAkIndexable((CAkIndexable *)&v1->vfptr);
}

// File Line: 45
// RVA: 0xA77130
CAkActionSetAkProp *__fastcall CAkAction::Create(AkActionType in_eActionType, unsigned int in_ulID)
{
  __int32 v2; // er8

  v2 = in_eActionType & 0xFF00;
  if ( v2 <= 3584 )
  {
    if ( v2 != 3584 )
    {
      if ( v2 > 2048 )
      {
        if ( v2 != 2304 )
        {
          if ( !((v2 - 2560) & 0xFFFFFEFF) )
            return CAkActionSetAkProp::Create(in_eActionType, in_ulID, 0);
          if ( !((v2 - 3072) & 0xFFFFFEFF) )
            return CAkActionSetAkProp::Create(in_eActionType, in_ulID, AkPropID_BusVolume);
          return 0i64;
        }
      }
      else if ( v2 != 2048 )
      {
        if ( v2 > 1024 )
        {
          if ( !((v2 - 1536) & 0xFFFFFEFF) )
            return (CAkActionSetAkProp *)CAkActionMute::Create(in_eActionType, in_ulID);
        }
        else
        {
          switch ( v2 )
          {
            case 1024:
              return (CAkActionSetAkProp *)CAkActionPlay::Create(in_eActionType, in_ulID);
            case 256:
              return (CAkActionSetAkProp *)CAkActionStop::Create(in_eActionType, in_ulID);
            case 512:
              return (CAkActionSetAkProp *)CAkActionPause::Create(in_eActionType, in_ulID);
            case 768:
              return (CAkActionSetAkProp *)CAkActionResume::Create(in_eActionType, in_ulID);
          }
        }
        return 0i64;
      }
      return CAkActionSetAkProp::Create(in_eActionType, in_ulID, AkPropID_Pitch);
    }
    return CAkActionSetAkProp::Create(in_eActionType, in_ulID, AkPropID_LPF);
  }
  if ( v2 <= 6400 )
  {
    if ( v2 == 6400 )
      return (CAkActionSetAkProp *)CAkActionSetSwitch::Create(in_eActionType, in_ulID);
    if ( v2 > 4608 )
    {
      if ( !((v2 - 4864) & 0xFFFFFEFF) )
        return (CAkActionSetAkProp *)CAkActionSetGameParameter::Create(in_eActionType, in_ulID);
      return 0i64;
    }
    if ( v2 == 4608 )
      return (CAkActionSetAkProp *)CAkActionSetState::Create(in_eActionType, in_ulID);
    if ( v2 != 3840 )
    {
      if ( !((v2 - 4096) & 0xFFFFFEFF) )
        return (CAkActionSetAkProp *)CAkActionUseState::Create(in_eActionType, in_ulID);
      return 0i64;
    }
    return CAkActionSetAkProp::Create(in_eActionType, in_ulID, AkPropID_LPF);
  }
  if ( !((v2 - 6656) & 0xFFFFFEFF) )
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
  CAkAction *v1; // rdi
  CAkIndexItem<CAkAction *> *v2; // rbx
  signed __int64 v3; // rdx

  v1 = this;
  if ( this->key )
  {
    v2 = &g_pIndex->m_idxActions;
    EnterCriticalSection(&g_pIndex->m_idxActions.m_IndexLock.m_csLock);
    v3 = (signed __int64)v2 + 8 * (v1->key % 0xC1);
    v1->pNextItem = *(CAkIndexable **)(v3 + 40);
    *(_QWORD *)(v3 + 40) = v1;
    ++v2->m_mapIDToPtr.m_uiSize;
    LeaveCriticalSection(&v2->m_IndexLock.m_csLock);
  }
}

// File Line: 136
// RVA: 0xA77070
__int64 __fastcall CAkAction::AddRef(CAkAction *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkAction *v2; // rsi
  unsigned int v3; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxActions.m_IndexLock.m_csLock);
  v3 = v2->m_lRef + 1;
  v2->m_lRef = v3;
  LeaveCriticalSection(&v1->m_idxActions.m_IndexLock.m_csLock);
  return v3;
}

// File Line: 142
// RVA: 0xA774D0
__int64 __fastcall CAkAction::Release(CAkAction *this)
{
  CAkAudioLibIndex *v1; // rbx
  CAkAction *v2; // rsi
  bool v3; // zf
  unsigned int v4; // ebp
  unsigned int v5; // edx
  int v6; // edi

  v1 = g_pIndex;
  v2 = this;
  EnterCriticalSection(&g_pIndex->m_idxActions.m_IndexLock.m_csLock);
  v3 = v2->m_lRef-- == 1;
  v4 = v2->m_lRef;
  if ( v3 )
  {
    v5 = v2->key;
    if ( v5 )
      CAkIndexItem<CAkEvent *>::RemoveID((CAkIndexItem<CAkParameterNodeBase *> *)&g_pIndex->m_idxActions, v5);
    v6 = g_DefaultPoolId;
    v2->vfptr->__vecDelDtor((CAkIndexable *)&v2->vfptr, 0);
    AK::MemoryMgr::Free(v6, v2);
  }
  LeaveCriticalSection(&v1->m_idxActions.m_IndexLock.m_csLock);
  return v4;
}

// File Line: 161
// RVA: 0xA777B0
void __fastcall CAkAction::SetElementID(CAkAction *this, WwiseObjectIDext in_Id)
{
  *((_BYTE *)this + 54) &= 0xBFu;
  this->m_ulElementID = in_Id.id;
  *((_BYTE *)this + 54) |= in_Id.bIsBus << 6;
}

// File Line: 167
// RVA: 0xA77680
signed __int64 __fastcall CAkAction::SetAkProp(CAkAction *this, AkPropID in_eProp, float in_fValue, float in_fMin, float in_fMax)
{
  CAkAction *v5; // rsi
  char v6; // di
  char *v7; // r9
  int v8; // ebx
  unsigned int v9; // er8
  unsigned int v10; // er10
  int v11; // edx
  __int64 v12; // rcx
  signed __int64 v13; // rdx
  AkPropValue *v14; // rax
  signed __int64 result; // rax
  char *v16; // rdx
  unsigned int v17; // er9
  __int64 v18; // rcx
  AkPropValue in_Value; // [rsp+58h] [rbp+10h]

  v5 = this;
  v6 = in_eProp;
  v7 = this->m_props.m_pProps;
  v8 = 0;
  v9 = 1;
  LODWORD(in_Value.fValue) = g_AkPropDefault[in_eProp];
  if ( v7 )
  {
    v10 = (unsigned __int8)*v7;
    v11 = 0;
    while ( 1 )
    {
      v12 = (unsigned int)(v11 + 1);
      if ( v7[v12] == v6 )
        break;
      ++v11;
      if ( (unsigned int)v12 >= v10 )
        goto LABEL_5;
    }
    v13 = (signed __int64)&v7[4 * v11 + ((v10 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v13 = 0i64;
  }
  v14 = &in_Value;
  if ( v13 )
    v14 = (AkPropValue *)v13;
  in_Value.fValue = v14->fValue;
  if ( in_Value.fValue == in_fValue
    || (in_Value.fValue = in_fValue,
        result = AkPropBundle<AkPropValue>::SetAkProp(&v5->m_props, v6, LODWORD(in_fValue)),
        v9 = result,
        (_DWORD)result == 1) )
  {
    if ( in_fMin != 0.0 || in_fMax != 0.0 )
      goto LABEL_22;
    v16 = v5->m_ranges.m_pProps;
    if ( !v16 )
      goto LABEL_16;
    v17 = (unsigned __int8)*v16;
    while ( 1 )
    {
      v18 = (unsigned int)(v8 + 1);
      if ( v16[v18] == v6 )
        break;
      ++v8;
      if ( (unsigned int)v18 >= v17 )
        goto LABEL_16;
    }
    if ( &v16[8 * v8 + ((v17 + 4) & 0xFFFFFFFC)] )
LABEL_22:
      result = AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetAkProp(
                 &v5->m_ranges,
                 v6,
                 (RANGED_MODIFIERS<AkPropValue>)__PAIR__(LODWORD(in_fMax), LODWORD(in_fMin)));
    else
LABEL_16:
      result = v9;
  }
  return result;
}

// File Line: 186
// RVA: 0xA77560
signed __int64 __fastcall CAkAction::SetAkProp(CAkAction *this, AkPropID in_eProp, int in_iValue, int in_iMin, int in_iMax)
{
  CAkAction *v5; // rbp
  char v6; // di
  char *v7; // r11
  int v8; // ebx
  int v9; // er15
  int v10; // esi
  unsigned int v11; // er10
  unsigned int v12; // er8
  int v13; // edx
  __int64 v14; // rcx
  signed __int64 v15; // rdx
  int *v16; // rax
  signed __int64 result; // rax
  char *v18; // rdx
  unsigned int v19; // er8
  __int64 v20; // rcx
  int v21; // [rsp+58h] [rbp+10h]

  v5 = this;
  v6 = in_eProp;
  v7 = this->m_props.m_pProps;
  v8 = 0;
  v9 = in_iMin;
  v10 = in_iValue;
  v11 = 1;
  v21 = g_AkPropDefault[in_eProp].iValue;
  if ( v7 )
  {
    v12 = (unsigned __int8)*v7;
    v13 = 0;
    while ( 1 )
    {
      v14 = (unsigned int)(v13 + 1);
      if ( v7[v14] == v6 )
        break;
      ++v13;
      if ( (unsigned int)v14 >= v12 )
        goto LABEL_5;
    }
    v15 = (signed __int64)&v7[4 * v13 + ((v12 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v15 = 0i64;
  }
  v16 = &v21;
  if ( v15 )
    v16 = (int *)v15;
  if ( *v16 == v10
    || (result = AkPropBundle<AkPropValue>::SetAkProp(&v5->m_props, v6, (AkPropValue)v10),
        v11 = result,
        (_DWORD)result == 1) )
  {
    if ( v9 || in_iMax )
      goto LABEL_22;
    v18 = v5->m_ranges.m_pProps;
    if ( !v18 )
      goto LABEL_16;
    v19 = (unsigned __int8)*v18;
    while ( 1 )
    {
      v20 = (unsigned int)(v8 + 1);
      if ( v18[v20] == v6 )
        break;
      ++v8;
      if ( (unsigned int)v20 >= v19 )
        goto LABEL_16;
    }
    if ( &v18[8 * v8 + ((v19 + 4) & 0xFFFFFFFC)] )
LABEL_22:
      result = AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetAkProp(
                 &v5->m_ranges,
                 v6,
                 (RANGED_MODIFIERS<AkPropValue>)__PAIR__(in_iMax, v9));
    else
LABEL_16:
      result = v11;
  }
  return result;
}

// File Line: 205
// RVA: 0xA773D0
__int64 __fastcall CAkAction::GetTransitionTime(CAkAction *this)
{
  char *v1; // r8
  signed int v2; // er10
  CAkAction *v3; // r11
  unsigned int v4; // er9
  int v5; // edx
  __int64 v6; // rcx
  signed __int64 v7; // rdx
  char *v8; // r9
  int *v9; // rax
  unsigned int v10; // ebx
  unsigned int v11; // eax
  int v12; // edx
  __int64 v13; // r8
  unsigned __int8 *v15; // rdi
  int v16; // esi
  int v17; // [rsp+30h] [rbp+8h]

  v1 = this->m_props.m_pProps;
  v2 = 0;
  v3 = this;
  v17 = g_AkPropDefault[15].iValue;
  if ( v1 )
  {
    v4 = (unsigned __int8)*v1;
    v5 = 0;
    while ( 1 )
    {
      v6 = (unsigned int)(v5 + 1);
      if ( v1[v6] == 15 )
        break;
      ++v5;
      if ( (unsigned int)v6 >= v4 )
        goto LABEL_5;
    }
    v7 = (signed __int64)&v1[4 * v5 + ((v4 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v7 = 0i64;
  }
  v8 = v3->m_ranges.m_pProps;
  v9 = &v17;
  if ( v7 )
    v9 = (int *)v7;
  v10 = *v9;
  if ( !v8 )
    return v10;
  v11 = (unsigned __int8)*v8;
  v12 = 0;
  while ( 1 )
  {
    v13 = (unsigned int)(v12 + 1);
    if ( v8[v13] == 15 )
      break;
    ++v12;
    if ( (unsigned int)v13 >= v11 )
      return v10;
  }
  v15 = (unsigned __int8 *)&v8[8 * v12 + ((v11 + 4) & 0xFFFFFFFC)];
  if ( !v15 )
    return v10;
  if ( *((_DWORD *)v15 + 1) != *(_DWORD *)v15 )
  {
    v16 = *((_DWORD *)v15 + 1) - *(_DWORD *)v15;
    v2 = (signed int)((double)rand() * 0.00003051850947599719 * (double)v16 + 0.5);
  }
  return v10 + v2 + *(_DWORD *)v15;
}

// File Line: 212
// RVA: 0xA772D0
__int64 __fastcall CAkAction::GetDelayTime(CAkAction *this)
{
  char *v1; // r8
  signed int v2; // er10
  CAkAction *v3; // r11
  unsigned int v4; // er9
  int v5; // edx
  __int64 v6; // rcx
  signed __int64 v7; // rdx
  char *v8; // r9
  int *v9; // rax
  unsigned int v10; // ebx
  unsigned int v11; // eax
  int v12; // edx
  __int64 v13; // r8
  unsigned __int8 *v15; // rdi
  int v16; // esi
  int v17; // [rsp+30h] [rbp+8h]

  v1 = this->m_props.m_pProps;
  v2 = 0;
  v3 = this;
  v17 = g_AkPropDefault[14].iValue;
  if ( v1 )
  {
    v4 = (unsigned __int8)*v1;
    v5 = 0;
    while ( 1 )
    {
      v6 = (unsigned int)(v5 + 1);
      if ( v1[v6] == 14 )
        break;
      ++v5;
      if ( (unsigned int)v6 >= v4 )
        goto LABEL_5;
    }
    v7 = (signed __int64)&v1[4 * v5 + ((v4 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v7 = 0i64;
  }
  v8 = v3->m_ranges.m_pProps;
  v9 = &v17;
  if ( v7 )
    v9 = (int *)v7;
  v10 = *v9;
  if ( !v8 )
    return v10;
  v11 = (unsigned __int8)*v8;
  v12 = 0;
  while ( 1 )
  {
    v13 = (unsigned int)(v12 + 1);
    if ( v8[v13] == 14 )
      break;
    ++v12;
    if ( (unsigned int)v13 >= v11 )
      return v10;
  }
  v15 = (unsigned __int8 *)&v8[8 * v12 + ((v11 + 4) & 0xFFFFFFFC)];
  if ( !v15 )
    return v10;
  if ( *((_DWORD *)v15 + 1) != *(_DWORD *)v15 )
  {
    v16 = *((_DWORD *)v15 + 1) - *(_DWORD *)v15;
    v2 = (signed int)((double)rand() * 0.00003051850947599719 * (double)v16 + 0.5);
  }
  return v10 + v2 + *(_DWORD *)v15;
}

// File Line: 219
// RVA: 0xA777D0
__int64 __fastcall CAkAction::SetInitialValues(CAkAction *this, char *in_pData, unsigned int in_ulDataSize)
{
  char *v3; // rdx
  int v4; // eax
  CAkIndexableVtbl *v5; // rax
  CAkAction *v6; // rsi
  char *v7; // rdx
  int v8; // edi
  AkPropBundle<RANGED_MODIFIERS<AkPropValue> > *v9; // r14
  char *v10; // rdx
  unsigned __int8 *v11; // rax
  unsigned __int8 v12; // bl
  unsigned int v13; // er15
  char *v14; // rax
  char *v15; // rbp
  unsigned int v16; // er9
  char *v17; // rdx
  size_t v18; // rbx
  char *v19; // r8
  unsigned int v20; // er10
  __int64 v21; // rcx
  __int64 v22; // rdx
  unsigned __int8 *v23; // r8
  char *v24; // r8
  unsigned int v25; // edx
  __int64 v26; // rcx
  unsigned __int8 *v28; // r8
  __int64 v29; // [rsp+60h] [rbp+8h]
  void *Src; // [rsp+68h] [rbp+10h]
  unsigned int io_rulDataSize; // [rsp+70h] [rbp+18h]

  io_rulDataSize = in_ulDataSize;
  v3 = in_pData + 6;
  Src = v3;
  v4 = *(_DWORD *)v3;
  Src = v3 + 4;
  LODWORD(v29) = v4;
  v5 = this->vfptr;
  BYTE4(v29) = v3[4] != 0;
  Src = v3 + 5;
  v6 = this;
  ((void (__fastcall *)(CAkAction *, __int64))v5[1].AddRef)(this, v29);
  v7 = v6->m_props.m_pProps;
  if ( v7 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v7);
  v8 = 0;
  v9 = &v6->m_ranges;
  v6->m_props.m_pProps = 0i64;
  v10 = v6->m_ranges.m_pProps;
  if ( v10 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v10);
  v11 = (unsigned __int8 *)Src;
  v9->m_pProps = 0i64;
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
    v6->m_props.m_pProps = v15;
  }
  v16 = AkPropBundle<RANGED_MODIFIERS<AkPropValue>>::SetInitialParams(&v6->m_ranges, (char **)&Src, &io_rulDataSize);
  if ( v16 == 1 )
    v16 = ((__int64 (__fastcall *)(CAkAction *, void **, unsigned int *, signed __int64))v6->vfptr[2].AddRef)(
            v6,
            &Src,
            &io_rulDataSize,
            1i64);
LABEL_11:
  v19 = v6->m_props.m_pProps;
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
    v23 = (unsigned __int8 *)&v19[4 * v21 + ((v20 + 4) & 0xFFFFFFFC)];
    if ( v23 )
      *(_DWORD *)v23 *= AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8;
  }
LABEL_18:
  v24 = v9->m_pProps;
  if ( v9->m_pProps )
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
CAkIndexable *__fastcall CAkAction::GetAndRefTarget(CAkAction *this)
{
  return CAkAudioLibIndex::GetNodePtrAndAddRef(
           g_pIndex,
           this->m_ulElementID,
           (AkNodeType)(((*((_BYTE *)this + 54) >> 6) & 1) != 0));
}

