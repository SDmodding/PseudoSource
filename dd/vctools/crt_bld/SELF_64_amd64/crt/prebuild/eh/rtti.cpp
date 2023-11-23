// File Line: 208
// RVA: 0x12B5090
__int64 __fastcall _RTDynamicCast(
        char *inptr,
        int VfDelta,
        TypeDescriptor *SrcType,
        TypeDescriptor *TargetType,
        int isReference)
{
  __int64 v7; // r13
  __int64 v9; // rbx
  _s_RTTICompleteObjectLocator *v11; // rsi
  char *v12; // rdi
  char *_ImageBase; // rcx
  char *v14; // r14
  int v15; // edx
  _s_RTTIBaseClassDescriptor *VITargetTypeInstance; // rax
  std::bad_cast pExceptionObject; // [rsp+40h] [rbp-48h] BYREF
  PVOID BaseOfImage; // [rsp+90h] [rbp+8h] BYREF

  v7 = VfDelta;
  v9 = 0i64;
  if ( !inptr )
    return 0i64;
  v11 = *(_s_RTTICompleteObjectLocator **)(*(_QWORD *)inptr - 8i64);
  v12 = &inptr[-v11->offset];
  if ( v11->cdOffset )
    v12 -= *(int *)&inptr[-v11->cdOffset];
  if ( v11->signature )
  {
    _ImageBase = (char *)v11 - v11->pSelf;
  }
  else
  {
    _ImageBase = (char *)RtlPcToFileHeader(v11, &BaseOfImage);
    BaseOfImage = _ImageBase;
  }
  v14 = (char *)(&inptr[-v7] - v12);
  v15 = *(_DWORD *)&_ImageBase[v11->pClassDescriptor + 4];
  if ( (v15 & 1) != 0 )
  {
    if ( (v15 & 2) != 0 )
      VITargetTypeInstance = FindVITargetTypeInstance(
                               v12,
                               v11,
                               SrcType,
                               (__int64)v14,
                               TargetType,
                               (unsigned __int64)_ImageBase);
    else
      VITargetTypeInstance = FindMITargetTypeInstance(
                               v12,
                               v11,
                               SrcType,
                               (__int64)v14,
                               TargetType,
                               (unsigned __int64)_ImageBase);
  }
  else
  {
    VITargetTypeInstance = FindSITargetTypeInstance(v11, SrcType, TargetType, (unsigned __int64)_ImageBase);
  }
  if ( VITargetTypeInstance )
  {
    if ( VITargetTypeInstance->where.pdisp >= 0 )
      v9 = *(int *)(*(_QWORD *)&v12[VITargetTypeInstance->where.pdisp] + VITargetTypeInstance->where.vdisp)
         + (__int64)VITargetTypeInstance->where.pdisp;
    v9 += (__int64)&v12[VITargetTypeInstance->where.mdisp];
  }
  else if ( isReference )
  {
    std::bad_cast::bad_cast(&pExceptionObject, "Bad dynamic_cast!");
    CxxThrowException(&pExceptionObject, (_s_ThrowInfo *)&TI2_AVbad_cast_std__);
  }
  return v9;
}

// File Line: 291
// RVA: 0x1451DD1
__RTDynamicCast$filt$0

// File Line: 374
// RVA: 0x12B4D78
_s_RTTIBaseClassDescriptor *__fastcall FindSITargetTypeInstance(
        _s_RTTICompleteObjectLocator *pCOLocator,
        TypeDescriptor *pSrcTypeID,
        TypeDescriptor *pTargetTypeID,
        unsigned __int64 _ImageBase)
{
  __int64 pClassDescriptor; // rax
  int v5; // ebx
  unsigned int v7; // r14d
  __int64 v9; // r15
  int *i; // rsi
  int *v12; // rbp
  __int64 v13; // rcx
  __int64 v15; // rbx
  int *v16; // rsi
  __int64 v17; // rax
  __int64 v18; // rcx

  pClassDescriptor = pCOLocator->pClassDescriptor;
  v5 = 0;
  v7 = *(_DWORD *)(pClassDescriptor + _ImageBase + 8);
  v9 = _ImageBase + *(int *)(pClassDescriptor + _ImageBase + 12);
  if ( v7 )
  {
    for ( i = (int *)(_ImageBase + *(int *)(pClassDescriptor + _ImageBase + 12)); ; ++i )
    {
      v12 = (int *)(_ImageBase + *i);
      v13 = _ImageBase + *v12;
      if ( (TypeDescriptor *)v13 == pTargetTypeID || !strcmp((const char *)(v13 + 16), pTargetTypeID->name) )
        break;
      if ( ++v5 >= v7 )
        return 0i64;
    }
    v15 = (unsigned int)(v5 + 1);
    if ( (unsigned int)v15 < v7 )
    {
      v16 = (int *)(v9 + 4 * v15);
      do
      {
        v17 = *v16;
        if ( (*(_BYTE *)(v17 + _ImageBase + 20) & 4) != 0 )
          break;
        v18 = _ImageBase + *(int *)(v17 + _ImageBase);
        if ( (TypeDescriptor *)v18 == pSrcTypeID || !strcmp((const char *)(v18 + 16), pSrcTypeID->name) )
          return (_s_RTTIBaseClassDescriptor *)v12;
        LODWORD(v15) = v15 + 1;
        ++v16;
      }
      while ( (unsigned int)v15 < v7 );
    }
  }
  return 0i64;
}

// File Line: 489
// RVA: 0x12B4C00
_s_RTTIBaseClassDescriptor *__fastcall FindMITargetTypeInstance(
        char *pCompleteObject,
        _s_RTTICompleteObjectLocator *pCOLocator,
        TypeDescriptor *pSrcTypeID,
        __int64 SrcOffset,
        TypeDescriptor *pTargetTypeID,
        unsigned __int64 _ImageBase)
{
  __int64 pClassDescriptor; // rax
  int v8; // ebp
  int *v9; // r12
  int *v10; // rdi
  int *v11; // r15
  unsigned int v12; // r13d
  unsigned int v13; // esi
  int *v14; // rbx
  __int64 v15; // rcx
  __int64 v16; // rcx
  __int64 v17; // rdx
  __int64 v19; // rsi
  unsigned int _ImageBasea; // [rsp+88h] [rbp+30h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  v8 = -1;
  v9 = (int *)(_ImageBase + *(int *)(pClassDescriptor + _ImageBase + 12));
  v10 = 0i64;
  v11 = 0i64;
  _ImageBasea = *(_DWORD *)(pClassDescriptor + _ImageBase + 8);
  v12 = 0;
  v13 = 0;
  if ( !_ImageBasea )
    return 0i64;
  while ( 1 )
  {
    v14 = (int *)(_ImageBase + *v9);
    if ( v13 - v8 > v12 )
    {
      v15 = _ImageBase + *v14;
      if ( (TypeDescriptor *)v15 == pTargetTypeID || !strcmp((const char *)(v15 + 16), pTargetTypeID->name) )
      {
        if ( v11 )
        {
          if ( (v14[5] & 3) == 0 && (v11[5] & 1) == 0 )
            return (_s_RTTIBaseClassDescriptor *)v14;
          return 0i64;
        }
        v12 = v14[1];
        v10 = v14;
        v8 = v13;
      }
    }
    v16 = _ImageBase + *v14;
    if ( (TypeDescriptor *)v16 == pSrcTypeID || !strcmp((const char *)(v16 + 16), pSrcTypeID->name) )
    {
      v17 = 0i64;
      if ( v14[3] >= 0 )
        v17 = *(int *)(v14[4] + *(_QWORD *)&pCompleteObject[v14[3]]) + (__int64)v14[3];
      if ( v17 + v14[2] == SrcOffset )
        break;
    }
LABEL_14:
    ++v13;
    ++v9;
    if ( v13 >= _ImageBasea )
      return 0i64;
  }
  if ( !v10 )
  {
    v11 = v14;
    goto LABEL_14;
  }
  v19 = v13 - v8;
  if ( (unsigned int)v19 <= v12 )
  {
    if ( (v10[5] & 0x40) != 0 )
    {
      if ( (*(_BYTE *)(*(int *)(_ImageBase + *(int *)(v10[6] + _ImageBase + 12) + 4 * v19) + _ImageBase + 20) & 1) != 0 )
        return 0i64;
    }
    else if ( !v8 )
    {
LABEL_22:
      if ( (v14[5] & 1) != 0 )
        return 0i64;
    }
    return (_s_RTTIBaseClassDescriptor *)v10;
  }
  if ( (v10[5] & 3) == 0 )
    goto LABEL_22;
  return 0i64;
}

// File Line: 686
// RVA: 0x12B4E4C
_s_RTTIBaseClassDescriptor *__fastcall FindVITargetTypeInstance(
        char *pCompleteObject,
        _s_RTTICompleteObjectLocator *pCOLocator,
        TypeDescriptor *pSrcTypeID,
        __int64 SrcOffset,
        TypeDescriptor *pTargetTypeID,
        unsigned __int64 _ImageBase)
{
  __int64 pClassDescriptor; // rax
  int v8; // r8d
  int *v9; // rcx
  unsigned int v10; // edx
  int *v11; // r12
  int *v12; // r13
  int *v13; // rsi
  int *v14; // rbp
  char v15; // di
  unsigned int v16; // r14d
  int *v17; // rbx
  __int64 v18; // rcx
  __int64 v19; // rcx
  __int64 v20; // rdx
  __int64 v21; // rdx
  bool v22; // cl
  __int64 v23; // rdx
  unsigned int v25; // [rsp+20h] [rbp-68h]
  __int64 v26; // [rsp+28h] [rbp-60h]
  int *v27; // [rsp+30h] [rbp-58h]
  unsigned int v29; // [rsp+98h] [rbp+10h]
  int _ImageBasea; // [rsp+B8h] [rbp+30h]

  pClassDescriptor = pCOLocator->pClassDescriptor;
  v26 = -1i64;
  v8 = -1;
  v9 = (int *)(_ImageBase + *(int *)(pClassDescriptor + _ImageBase + 12));
  v10 = 0;
  v11 = 0i64;
  v12 = 0i64;
  v13 = 0i64;
  v27 = v9;
  v14 = 0i64;
  v25 = *(_DWORD *)(pClassDescriptor + _ImageBase + 8);
  v29 = 0;
  _ImageBasea = -1;
  v15 = 1;
  v16 = 0;
  if ( !v25 )
    return 0i64;
  while ( 1 )
  {
    v17 = (int *)(_ImageBase + *v9);
    if ( v16 - v8 > v10 )
    {
      v18 = _ImageBase + *v17;
      if ( (TypeDescriptor *)v18 == pTargetTypeID || !strcmp((const char *)(v18 + 16), pTargetTypeID->name) )
      {
        v14 = v17;
        if ( (v17[5] & 3) == 0 )
          v13 = v17;
        v29 = v17[1];
        _ImageBasea = v16;
      }
    }
    v19 = _ImageBase + *v17;
    if ( (TypeDescriptor *)v19 == pSrcTypeID || !strcmp((const char *)(v19 + 16), pSrcTypeID->name) )
    {
      v20 = 0i64;
      if ( v17[3] >= 0 )
        v20 = *(int *)(v17[4] + *(_QWORD *)&pCompleteObject[v17[3]]) + (__int64)v17[3];
      v8 = _ImageBasea;
      if ( v20 + v17[2] == SrcOffset )
      {
        v21 = v16 - _ImageBasea;
        if ( (unsigned int)v21 > v29 )
        {
          if ( (v17[5] & 5) == 0 )
            v12 = v17;
        }
        else if ( v15 )
        {
          if ( (v14[5] & 0x40) != 0 )
          {
            if ( (*(_DWORD *)(*(int *)(_ImageBase + *(int *)(v14[6] + _ImageBase + 12) + 4 * v21) + _ImageBase + 20) & 1) != 0 )
              v15 = 0;
            v22 = (*(_DWORD *)(*(int *)(_ImageBase + *(int *)(v14[6] + _ImageBase + 12) + 4 * v21) + _ImageBase + 20) & 4) == 0;
          }
          else
          {
            if ( !_ImageBasea && (v17[5] & 1) != 0 )
              v15 = 0;
            v22 = 1;
          }
          if ( v15 && v22 )
          {
            v23 = 0i64;
            if ( v14[3] >= 0 )
              v23 = *(int *)(v14[4] + *(_QWORD *)&pCompleteObject[v14[3]]) + (__int64)v14[3];
            if ( v11 && v26 != v23 + v14[2] )
              return 0i64;
            v11 = v14;
            v26 = v23 + v14[2];
          }
        }
      }
    }
    else
    {
      v8 = _ImageBasea;
    }
    ++v16;
    v9 = ++v27;
    if ( v16 >= v25 )
      break;
    v10 = v29;
  }
  if ( v15 && v11 )
    return (_s_RTTIBaseClassDescriptor *)v11;
  if ( v12 && v13 )
    return (_s_RTTIBaseClassDescriptor *)v13;
  else
    return 0i64;
}

