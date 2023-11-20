// File Line: 208
// RVA: 0x12B5090
signed __int64 __fastcall _RTDynamicCast(void *inptr, int VfDelta, void *SrcType, void *TargetType, int isReference)
{
  TypeDescriptor *pTargetTypeID; // r15
  TypeDescriptor *v6; // r12
  __int64 v7; // r13
  char *v8; // r14
  signed __int64 v9; // rbx
  _s_RTTICompleteObjectLocator *v11; // rsi
  char *v12; // rdi
  char *_ImageBase; // rcx
  __int64 v14; // r14
  int v15; // edx
  _s_RTTIBaseClassDescriptor *v16; // rax
  std::bad_cast pExceptionObject; // [rsp+40h] [rbp-48h]
  PVOID BaseOfImage; // [rsp+90h] [rbp+8h]

  pTargetTypeID = (TypeDescriptor *)TargetType;
  v6 = (TypeDescriptor *)SrcType;
  v7 = VfDelta;
  v8 = (char *)inptr;
  v9 = 0i64;
  if ( !inptr )
    return 0i64;
  v11 = *(_s_RTTICompleteObjectLocator **)(*(_QWORD *)inptr - 8i64);
  v12 = (char *)inptr - v11->offset;
  if ( v11->cdOffset )
    v12 -= *(signed int *)((char *)inptr - v11->cdOffset);
  if ( v11->signature )
  {
    _ImageBase = (char *)v11 - v11->pSelf;
  }
  else
  {
    _ImageBase = (char *)RtlPcToFileHeader(v11, &BaseOfImage);
    BaseOfImage = _ImageBase;
  }
  v14 = &v8[-v7] - v12;
  v15 = *(_DWORD *)&_ImageBase[v11->pClassDescriptor + 4];
  if ( v15 & 1 )
  {
    if ( v15 & 2 )
      v16 = FindVITargetTypeInstance(v12, v11, v6, v14, pTargetTypeID, (unsigned __int64)_ImageBase);
    else
      v16 = FindMITargetTypeInstance(v12, v11, v6, v14, pTargetTypeID, (unsigned __int64)_ImageBase);
  }
  else
  {
    v16 = FindSITargetTypeInstance(v11, v6, pTargetTypeID, (unsigned __int64)_ImageBase);
  }
  if ( v16 )
  {
    if ( v16->where.pdisp >= 0 )
      v9 = *(signed int *)(*(_QWORD *)&v12[v16->where.pdisp] + v16->where.vdisp) + (signed __int64)v16->where.pdisp;
    v9 += (signed __int64)&v12[v16->where.mdisp];
  }
  else if ( isReference )
  {
    std::bad_cast::bad_cast(&pExceptionObject, "Bad dynamic_cast!");
    CxxThrowException(&pExceptionObject, &TI2_AVbad_cast_std__);
  }
  return v9;
}

// File Line: 291
// RVA: 0x1451DD1
__RTDynamicCast$filt$0

// File Line: 374
// RVA: 0x12B4D78
_s_RTTIBaseClassDescriptor *__fastcall FindSITargetTypeInstance(_s_RTTICompleteObjectLocator *pCOLocator, TypeDescriptor *pSrcTypeID, TypeDescriptor *pTargetTypeID, unsigned __int64 _ImageBase)
{
  __int64 v4; // rax
  unsigned int v5; // ebx
  unsigned __int64 v6; // rdi
  unsigned int v7; // er14
  TypeDescriptor *v8; // r13
  unsigned __int64 v9; // r15
  TypeDescriptor *v10; // r12
  signed int *v11; // rsi
  signed int *v12; // rbp
  unsigned __int64 v13; // rcx
  __int64 v15; // rbx
  signed int *v16; // rsi
  __int64 v17; // rax
  unsigned __int64 v18; // rcx

  v4 = pCOLocator->pClassDescriptor;
  v5 = 0;
  v6 = _ImageBase;
  v7 = *(_DWORD *)(v4 + _ImageBase + 8);
  v8 = pTargetTypeID;
  v9 = _ImageBase + *(signed int *)(v4 + _ImageBase + 12);
  v10 = pSrcTypeID;
  if ( v7 )
  {
    v11 = (signed int *)(_ImageBase + *(signed int *)(v4 + _ImageBase + 12));
    while ( 1 )
    {
      v12 = (signed int *)(v6 + *v11);
      v13 = v6 + *v12;
      if ( (TypeDescriptor *)v13 == v8 || !strcmp((const char *)(v13 + 16), (const char *)&v8[1]) )
        break;
      ++v5;
      ++v11;
      if ( v5 >= v7 )
        return 0i64;
    }
    v15 = v5 + 1;
    if ( (unsigned int)v15 < v7 )
    {
      v16 = (signed int *)(v9 + 4 * v15);
      do
      {
        v17 = *v16;
        if ( *(_BYTE *)(v17 + v6 + 20) & 4 )
          break;
        v18 = v6 + *(signed int *)(v17 + v6);
        if ( (TypeDescriptor *)v18 == v10 || !strcmp((const char *)(v18 + 16), (const char *)&v10[1]) )
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
_s_RTTIBaseClassDescriptor *__fastcall FindMITargetTypeInstance(void *pCompleteObject, _s_RTTICompleteObjectLocator *pCOLocator, TypeDescriptor *pSrcTypeID, __int64 SrcOffset, TypeDescriptor *pTargetTypeID, unsigned __int64 _ImageBase)
{
  unsigned __int64 v6; // r14
  __int64 v7; // rax
  signed int v8; // ebp
  signed int *v9; // r12
  signed int *v10; // rdi
  signed int *v11; // r15
  unsigned int v12; // er13
  unsigned int v13; // esi
  signed int *v14; // rbx
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rcx
  signed __int64 v17; // rdx
  __int64 v19; // rsi
  char *v20; // [rsp+60h] [rbp+8h]
  TypeDescriptor *v21; // [rsp+70h] [rbp+18h]
  __int64 v22; // [rsp+78h] [rbp+20h]
  unsigned int _ImageBasea; // [rsp+88h] [rbp+30h]

  v22 = SrcOffset;
  v21 = pSrcTypeID;
  v20 = (char *)pCompleteObject;
  v6 = _ImageBase;
  v7 = pCOLocator->pClassDescriptor;
  v8 = -1;
  v9 = (signed int *)(_ImageBase + *(signed int *)(v7 + _ImageBase + 12));
  v10 = 0i64;
  v11 = 0i64;
  _ImageBasea = *(_DWORD *)(v7 + _ImageBase + 8);
  v12 = 0;
  v13 = 0;
  if ( !_ImageBasea )
    return 0i64;
  while ( 1 )
  {
    v14 = (signed int *)(v6 + *v9);
    if ( v13 - v8 > v12 )
    {
      v15 = v6 + *v14;
      if ( (TypeDescriptor *)v15 == pTargetTypeID || !strcmp((const char *)(v15 + 16), (const char *)&pTargetTypeID[1]) )
      {
        if ( v11 )
        {
          if ( !(v14[5] & 3) && !(v11[5] & 1) )
            return (_s_RTTIBaseClassDescriptor *)v14;
          return 0i64;
        }
        v12 = v14[1];
        v10 = v14;
        v8 = v13;
      }
    }
    v16 = v6 + *v14;
    if ( (TypeDescriptor *)v16 == v21 || !strcmp((const char *)(v16 + 16), (const char *)&v21[1]) )
    {
      v17 = 0i64;
      if ( v14[3] >= 0 )
        v17 = *(signed int *)(v14[4] + *(_QWORD *)&v20[v14[3]]) + (signed __int64)v14[3];
      if ( v17 + v14[2] == v22 )
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
    if ( v10[5] & 0x40 )
    {
      if ( *(_BYTE *)(*(signed int *)(v6 + *(signed int *)(v10[6] + v6 + 12) + 4 * v19) + v6 + 20) & 1 )
        v10 = 0i64;
    }
    else if ( !v8 )
    {
LABEL_22:
      if ( v14[5] & 1 )
        return 0i64;
    }
    return (_s_RTTIBaseClassDescriptor *)v10;
  }
  if ( !(v10[5] & 3) )
    goto LABEL_22;
  return 0i64;
}

// File Line: 686
// RVA: 0x12B4E4C
_s_RTTIBaseClassDescriptor *__fastcall FindVITargetTypeInstance(void *pCompleteObject, _s_RTTICompleteObjectLocator *pCOLocator, TypeDescriptor *pSrcTypeID, __int64 SrcOffset, TypeDescriptor *pTargetTypeID, unsigned __int64 _ImageBase)
{
  unsigned __int64 v6; // r15
  __int64 v7; // rax
  signed int v8; // er8
  signed int *v9; // rcx
  unsigned int v10; // edx
  _s_RTTIBaseClassDescriptor *v11; // r12
  _s_RTTIBaseClassDescriptor *v12; // r13
  _s_RTTIBaseClassDescriptor *v13; // rsi
  _s_RTTIBaseClassDescriptor *v14; // rbp
  char v15; // di
  unsigned int v16; // er14
  _s_RTTIBaseClassDescriptor *v17; // rbx
  unsigned __int64 v18; // rcx
  unsigned __int64 v19; // rcx
  signed __int64 v20; // rdx
  __int64 v21; // rdx
  char v22; // cl
  unsigned int v23; // ecx
  signed __int64 v24; // rdx
  _s_RTTIBaseClassDescriptor *result; // rax
  unsigned int v26; // [rsp+20h] [rbp-68h]
  signed __int64 v27; // [rsp+28h] [rbp-60h]
  unsigned __int64 v28; // [rsp+30h] [rbp-58h]
  char *v29; // [rsp+90h] [rbp+8h]
  unsigned int v30; // [rsp+98h] [rbp+10h]
  TypeDescriptor *v31; // [rsp+A0h] [rbp+18h]
  __int64 v32; // [rsp+A8h] [rbp+20h]
  signed int _ImageBasea; // [rsp+B8h] [rbp+30h]

  v32 = SrcOffset;
  v31 = pSrcTypeID;
  v29 = (char *)pCompleteObject;
  v6 = _ImageBase;
  v7 = pCOLocator->pClassDescriptor;
  v27 = -1i64;
  v8 = -1;
  v9 = (signed int *)(_ImageBase + *(signed int *)(v7 + _ImageBase + 12));
  v10 = 0;
  v11 = 0i64;
  v12 = 0i64;
  v13 = 0i64;
  v28 = _ImageBase + *(signed int *)(v7 + _ImageBase + 12);
  v14 = 0i64;
  v26 = *(_DWORD *)(v7 + _ImageBase + 8);
  v30 = 0;
  _ImageBasea = -1;
  v15 = 1;
  v16 = 0;
  if ( !v26 )
    goto LABEL_42;
  while ( 1 )
  {
    v17 = (_s_RTTIBaseClassDescriptor *)(v6 + *v9);
    if ( v16 - v8 > v10 )
    {
      v18 = v6 + v17->pTypeDescriptor;
      if ( (TypeDescriptor *)v18 == pTargetTypeID || !strcmp((const char *)(v18 + 16), (const char *)&pTargetTypeID[1]) )
      {
        v14 = v17;
        if ( !(v17->attributes & 3) )
          v13 = v17;
        v30 = v17->numContainedBases;
        _ImageBasea = v16;
      }
    }
    v19 = v6 + v17->pTypeDescriptor;
    if ( (TypeDescriptor *)v19 == v31 || !strcmp((const char *)(v19 + 16), (const char *)&v31[1]) )
    {
      v20 = 0i64;
      if ( v17->where.pdisp >= 0 )
        v20 = *(signed int *)(v17->where.vdisp + *(_QWORD *)&v29[v17->where.pdisp]) + (signed __int64)v17->where.pdisp;
      v8 = _ImageBasea;
      if ( v20 + v17->where.mdisp == v32 )
      {
        v21 = v16++ - _ImageBasea;
        if ( (unsigned int)v21 > v30 )
        {
          if ( !(v17->attributes & 5) )
            v12 = v17;
        }
        else if ( v15 )
        {
          if ( v14->attributes & 0x40 )
          {
            v23 = *(_DWORD *)(*(signed int *)(v6 + *(signed int *)(v14->pClassDescriptor + v6 + 12) + 4 * v21) + v6 + 20);
            if ( v23 & 1 )
              v15 = 0;
            v22 = ~(unsigned __int8)(v23 >> 2) & 1;
          }
          else
          {
            if ( !_ImageBasea && v17->attributes & 1 )
              v15 = 0;
            v22 = 1;
          }
          if ( v15 && v22 )
          {
            v24 = 0i64;
            if ( v14->where.pdisp >= 0 )
              v24 = *(signed int *)(v14->where.vdisp + *(_QWORD *)&v29[v14->where.pdisp])
                  + (signed __int64)v14->where.pdisp;
            if ( v11 && v27 != v24 + v14->where.mdisp )
              goto LABEL_42;
            v11 = v14;
            v27 = v24 + v14->where.mdisp;
          }
        }
      }
    }
    else
    {
      v8 = _ImageBasea;
    }
    v9 = (signed int *)(v28 + 4);
    v28 += 4i64;
    if ( v16 >= v26 )
      break;
    v10 = v30;
  }
  if ( v15 && v11 )
    return v11;
  if ( v12 && v13 )
    result = v13;
  else
LABEL_42:
    result = 0i64;
  return result;
}

