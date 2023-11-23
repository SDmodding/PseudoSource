// File Line: 36
// RVA: 0x944DC0
void __fastcall Scaleform::String::String(Scaleform::String *this)
{
  this->HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
}

// File Line: 42
// RVA: 0x944C50
void __fastcall Scaleform::String::String(Scaleform::String *this, const char *pdata)
{
  size_t v4; // rbx
  Scaleform::String::DataDesc *v5; // rsi

  if ( !pdata )
  {
    v4 = 0i64;
LABEL_7:
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v5 = &Scaleform::String::NullData;
    goto LABEL_8;
  }
  v4 = -1i64;
  do
    ++v4;
  while ( pdata[v4] );
  if ( !v4 )
    goto LABEL_7;
  v5 = (Scaleform::String::DataDesc *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                        Scaleform::Memory::pGlobalHeap,
                                        v4 + 16,
                                        0i64);
  v5->Data[v4] = 0;
  v5->RefCount = 1;
  v5->Size = v4;
LABEL_8:
  memmove(v5->Data, pdata, v4);
  this->HeapTypeBits = (unsigned __int64)v5;
}

// File Line: 49
// RVA: 0x944B80
void __fastcall Scaleform::String::String(
        Scaleform::String *this,
        const char *pdata1,
        const char *pdata2,
        const char *pdata3)
{
  size_t v4; // rdi
  unsigned __int64 copySize1; // rsi
  unsigned __int64 copySize2; // rbp
  Scaleform::String::DataDesc *v9; // rbx

  v4 = -1i64;
  if ( pdata1 )
  {
    copySize1 = -1i64;
    do
      ++copySize1;
    while ( pdata1[copySize1] );
  }
  else
  {
    copySize1 = 0i64;
  }
  if ( pdata2 )
  {
    copySize2 = -1i64;
    do
      ++copySize2;
    while ( pdata2[copySize2] );
  }
  else
  {
    copySize2 = 0i64;
  }
  if ( pdata3 )
  {
    do
      ++v4;
    while ( pdata3[v4] );
  }
  else
  {
    v4 = 0i64;
  }
  v9 = Scaleform::String::AllocDataCopy2(
         this,
         Scaleform::Memory::pGlobalHeap,
         copySize1 + v4 + copySize2,
         0i64,
         pdata1,
         copySize1,
         pdata2,
         copySize2);
  memmove(&v9->Data[copySize2 + copySize1], pdata3, v4);
  this->HeapTypeBits = (unsigned __int64)v9;
}

// File Line: 63
// RVA: 0x944CF0
void __fastcall Scaleform::String::String(Scaleform::String *this, const char *pdata, size_t size)
{
  Scaleform::String::DataDesc *v6; // rbx

  if ( size )
  {
    v6 = (Scaleform::String::DataDesc *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          size + 16,
                                          0i64);
    v6->Data[size] = 0;
    v6->RefCount = 1;
    v6->Size = size;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v6 = &Scaleform::String::NullData;
  }
  memmove(v6->Data, pdata, size);
  this->HeapTypeBits = (unsigned __int64)v6;
}

// File Line: 76
// RVA: 0x944A30
void __fastcall Scaleform::String::String(Scaleform::String *this, Scaleform::String *src)
{
  Scaleform::MemoryHeap *pData; // r9
  unsigned __int64 v4; // rbx

  pData = 0i64;
  v4 = src->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( (src->HeapTypeBits & 3) == 0 )
    goto LABEL_8;
  if ( ((__int64)src->pData & 3) == 1 )
  {
    pData = (Scaleform::MemoryHeap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::String *, _QWORD, _QWORD))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(
                                       Scaleform::Memory::pGlobalHeap,
                                       src,
                                       ((__int64)src->pData & 3) - 1,
                                       0i64);
  }
  else if ( ((__int64)src->pData & 3) == 2 )
  {
    pData = (Scaleform::MemoryHeap *)src[1].pData;
  }
  if ( pData == Scaleform::Memory::pGlobalHeap )
  {
LABEL_8:
    this->HeapTypeBits = v4;
    _InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 8), 1u);
  }
  else
  {
    this->HeapTypeBits = (unsigned __int64)Scaleform::String::AllocDataCopy1(
                                             this,
                                             Scaleform::Memory::pGlobalHeap,
                                             *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64,
                                             *(_QWORD *)v4 & 0x8000000000000000ui64,
                                             (const char *)(v4 + 12),
                                             *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64);
  }
}

// File Line: 100
// RVA: 0x944AE0
void __fastcall Scaleform::String::String(Scaleform::String *this, Scaleform::StringBuffer *src)
{
  unsigned __int64 Size; // rdi
  char *pData; // rsi
  Scaleform::String::DataDesc *v5; // rbx

  Size = src->Size;
  pData = &customCaption;
  if ( src->pData )
    pData = src->pData;
  if ( Size )
  {
    v5 = (Scaleform::String::DataDesc *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          Size + 16,
                                          0i64);
    v5->Data[Size] = 0;
    v5->RefCount = 1;
    v5->Size = Size;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v5 = &Scaleform::String::NullData;
  }
  memmove(v5->Data, pData, Size);
  this->HeapTypeBits = (unsigned __int64)v5;
}

// File Line: 105
// RVA: 0x944D80
void __fastcall Scaleform::String::String(Scaleform::String *this, const wchar_t *data)
{
  this->HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  if ( data )
    Scaleform::String::operator=(this, data);
}

// File Line: 135
// RVA: 0x957990
Scaleform::String::DataDesc *__fastcall Scaleform::String::AllocDataCopy1(
        Scaleform::String *this,
        Scaleform::MemoryHeap *pheap,
        unsigned __int64 size,
        unsigned __int64 lengthIsSize,
        const char *pdata,
        unsigned __int64 copySize)
{
  Scaleform::String::DataDesc *v8; // rbx

  if ( size )
  {
    v8 = (Scaleform::String::DataDesc *)pheap->vfptr->Alloc(pheap, size + 16, 0i64);
    v8->Data[size] = 0;
    v8->RefCount = 1;
    v8->Size = lengthIsSize | size;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v8 = &Scaleform::String::NullData;
  }
  memmove(v8->Data, pdata, copySize);
  return v8;
}

// File Line: 144
// RVA: 0x957A10
Scaleform::String::DataDesc *__fastcall Scaleform::String::AllocDataCopy2(
        Scaleform::String *this,
        Scaleform::MemoryHeap *pheap,
        unsigned __int64 size,
        unsigned __int64 lengthIsSize,
        const char *pdata1,
        unsigned __int64 copySize1,
        const char *pdata2,
        unsigned __int64 copySize2)
{
  Scaleform::String::DataDesc *v10; // rdi

  if ( size )
  {
    v10 = (Scaleform::String::DataDesc *)pheap->vfptr->Alloc(pheap, size + 16, 0i64);
    v10->Data[size] = 0;
    v10->RefCount = 1;
    v10->Size = lengthIsSize | size;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v10 = &Scaleform::String::NullData;
  }
  memmove(v10->Data, pdata1, copySize1);
  memmove(&v10->Data[copySize1], pdata2, copySize2);
  return v10;
}

// File Line: 177
// RVA: 0x988380
__int64 __fastcall Scaleform::String::GetLength(Scaleform::String *this)
{
  unsigned __int64 v1; // rbx
  __int64 v2; // rdi
  __int64 result; // rax

  v1 = this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v2 = *(_QWORD *)v1 & 0x7FFFFFFFFFFFFFFFi64;
  if ( *(__int64 *)v1 < 0 )
    return *(_QWORD *)v1 & 0x7FFFFFFFFFFFFFFFi64;
  result = Scaleform::UTF8Util::GetLength((const char *)(v1 + 12), *(_QWORD *)v1 & 0x7FFFFFFFFFFFFFFFi64);
  if ( result == v2 )
    *(_QWORD *)v1 |= 0x8000000000000000ui64;
  return result;
}

// File Line: 198
// RVA: 0x980C10
unsigned int __fastcall Scaleform::String::GetCharAt(Scaleform::String *this, __int64 index)
{
  _QWORD *v3; // rax
  const char *v4; // rdx
  char *putf8Buffer; // [rsp+30h] [rbp+8h] BYREF

  v3 = (_QWORD *)(this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v4 = (char *)v3 + 12;
  if ( (__int64)*v3 >= 0 )
    return Scaleform::UTF8Util::GetCharAt(index, v4, *v3 & 0x7FFFFFFFFFFFFFFFi64);
  putf8Buffer = (char *)&v4[index];
  return Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer);
}

// File Line: 216
// RVA: 0x9843F0
__int64 __fastcall Scaleform::String::GetFirstCharAt(Scaleform::String *this, __int64 index, const char **offset)
{
  _QWORD *v4; // rax
  const char *v5; // r9
  unsigned __int64 v6; // r11
  char v7; // cl
  __int64 result; // rax
  char v9; // dl
  char v10; // dl
  int v11; // eax
  char v12; // cl
  char v13; // dl
  int v14; // eax
  char v15; // dl
  int v16; // eax
  char v17; // cl
  char v18; // dl
  int v19; // eax
  char v20; // cl
  char v21; // dl
  int v22; // eax
  char v23; // dl
  int v24; // eax
  char v25; // cl
  char v26; // dl
  int v27; // eax
  char v28; // cl
  char v29; // dl
  int v30; // eax
  char v31; // cl
  char v32; // dl
  int v33; // eax
  char v34; // dl
  int v35; // eax
  char v36; // cl
  char v37; // dl
  int v38; // eax
  char v39; // cl
  char v40; // dl
  int v41; // eax
  char v42; // cl
  char v43; // dl
  int v44; // eax
  char v45; // cl
  char v46; // dl
  int v47; // eax

  v4 = (_QWORD *)(this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v5 = (char *)v4 + 12;
  v6 = (unsigned __int64)v4 + (*v4 & 0x7FFFFFFFFFFFFFFFi64) + 12;
  do
  {
    v7 = *v5++;
    if ( !v7 )
    {
      result = 0i64;
      goto LABEL_72;
    }
    if ( v7 >= 0 )
    {
      result = (unsigned int)v7;
      goto LABEL_72;
    }
    if ( (v7 & 0xE0) == 0xC0 )
    {
      v9 = *v5;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v9 & 0xC0) != 0x80 )
        goto LABEL_71;
      ++v5;
      result = v9 & 0x3F | ((unsigned __int8)(v7 & 0x1F) << 6);
      if ( (unsigned int)result < 0x80 )
        result = 65533i64;
    }
    else if ( (v7 & 0xF0) == 0xE0 )
    {
      v10 = *v5;
      v11 = (v7 & 0xF) << 12;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v10 & 0xC0) != 0x80 )
        goto LABEL_71;
      ++v5;
      v12 = v10;
      v13 = *v5;
      v14 = ((v12 & 0x3F) << 6) | v11;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v13 & 0xC0) != 0x80 )
        goto LABEL_71;
      ++v5;
      result = v13 & 0x3F | (unsigned int)v14;
      if ( (unsigned int)result < 0x800 )
        result = 65533i64;
    }
    else if ( (v7 & 0xF8) == 0xF0 )
    {
      v15 = *v5;
      v16 = (v7 & 7) << 18;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v15 & 0xC0) != 0x80 )
        goto LABEL_71;
      ++v5;
      v17 = v15;
      v18 = *v5;
      v19 = ((v17 & 0x3F) << 12) | v16;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v18 & 0xC0) != 0x80 )
        goto LABEL_71;
      ++v5;
      v20 = v18;
      v21 = *v5;
      v22 = ((v20 & 0x3F) << 6) | v19;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v21 & 0xC0) != 0x80 )
        goto LABEL_71;
      ++v5;
      result = v21 & 0x3F | (unsigned int)v22;
      if ( (unsigned int)result < 0x10000 )
        result = 65533i64;
    }
    else if ( (v7 & 0xFC) == 0xF8 )
    {
      v23 = *v5;
      v24 = (v7 & 3) << 24;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v23 & 0xC0) != 0x80 )
        goto LABEL_71;
      ++v5;
      v25 = v23;
      v26 = *v5;
      v27 = ((v25 & 0x3F) << 18) | v24;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v26 & 0xC0) != 0x80 )
        goto LABEL_71;
      ++v5;
      v28 = v26;
      v29 = *v5;
      v30 = ((v28 & 0x3F) << 12) | v27;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v29 & 0xC0) != 0x80 )
        goto LABEL_71;
      ++v5;
      v31 = v29;
      v32 = *v5;
      v33 = ((v31 & 0x3F) << 6) | v30;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v32 & 0xC0) != 0x80 )
        goto LABEL_71;
      ++v5;
      result = v32 & 0x3F | (unsigned int)v33;
      if ( (unsigned int)result < 0x200000 )
        result = 65533i64;
    }
    else
    {
      if ( (v7 & 0xFE) != 0xFC )
        goto LABEL_71;
      v34 = *v5;
      v35 = (v7 & 1) << 30;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v34 & 0xC0) != 0x80 )
        goto LABEL_71;
      ++v5;
      v36 = v34;
      v37 = *v5;
      v38 = ((v36 & 0x3F) << 24) | v35;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v37 & 0xC0) != 0x80 )
        goto LABEL_71;
      ++v5;
      v39 = v37;
      v40 = *v5;
      v41 = ((v39 & 0x3F) << 18) | v38;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v40 & 0xC0) != 0x80 )
        goto LABEL_71;
      ++v5;
      v42 = v40;
      v43 = *v5;
      v44 = ((v42 & 0x3F) << 12) | v41;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v43 & 0xC0) != 0x80 )
        goto LABEL_71;
      ++v5;
      v45 = v43;
      v46 = *v5;
      v47 = ((v45 & 0x3F) << 6) | v44;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v46 & 0xC0) != 0x80 )
      {
LABEL_71:
        result = 65533i64;
        goto LABEL_72;
      }
      ++v5;
      result = v46 & 0x3F | (unsigned int)v47;
      if ( (unsigned int)result < 0x4000000 )
        result = 65533i64;
    }
LABEL_72:
    --index;
    if ( (unsigned __int64)v5 >= v6 )
      return result;
  }
  while ( index >= 0 );
  *offset = v5;
  return result;
}

// File Line: 242
// RVA: 0x98A1C0
__int64 __fastcall Scaleform::String::GetNextChar(Scaleform::String *this, char **offset)
{
  __int64 result; // rax

  result = Scaleform::UTF8Util::DecodeNextChar_Advance0(offset);
  if ( !(_DWORD)result )
    --*offset;
  return result;
}

// File Line: 249
// RVA: 0x958980
void __fastcall Scaleform::String::AppendChar(Scaleform::String *this, unsigned int ch)
{
  unsigned __int64 HeapTypeBits; // r8
  Scaleform::MemoryHeap *pData; // rcx
  size_t v5; // rdi
  volatile signed __int32 *v6; // rsi
  __int64 v7; // r12
  int v8; // r8d
  int v9; // r8d
  unsigned __int64 v10; // rbp
  unsigned __int64 v11; // rbx
  char Src; // [rsp+50h] [rbp+8h] BYREF
  char v13; // [rsp+51h] [rbp+9h]
  char v14; // [rsp+52h] [rbp+Ah]
  char v15; // [rsp+53h] [rbp+Bh]
  char v16; // [rsp+54h] [rbp+Ch]
  char v17; // [rsp+55h] [rbp+Dh]

  HeapTypeBits = this->HeapTypeBits;
  pData = 0i64;
  v5 = 0i64;
  v6 = (volatile signed __int32 *)(HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v7 = *(_QWORD *)(HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64;
  if ( ch > 0x7F )
  {
    if ( ch > 0x7FF )
    {
      if ( ch > 0xFFFF )
      {
        if ( ch > 0x1FFFFF )
        {
          if ( ch > 0x3FFFFFF )
          {
            if ( ch <= 0x7FFFFFFF )
            {
              v5 = 6i64;
              Src = (ch >> 30) | 0xFC;
              v13 = HIBYTE(ch) & 0x3F | 0x80;
              v14 = (ch >> 18) & 0x3F | 0x80;
              v15 = (ch >> 12) & 0x3F | 0x80;
              v17 = ch & 0x3F | 0x80;
              v16 = (ch >> 6) & 0x3F | 0x80;
            }
          }
          else
          {
            v5 = 5i64;
            Src = HIBYTE(ch) | 0xF8;
            v13 = (ch >> 18) & 0x3F | 0x80;
            v14 = (ch >> 12) & 0x3F | 0x80;
            v16 = ch & 0x3F | 0x80;
            v15 = (ch >> 6) & 0x3F | 0x80;
          }
        }
        else
        {
          v5 = 4i64;
          Src = (ch >> 18) | 0xF0;
          v13 = (ch >> 12) & 0x3F | 0x80;
          v15 = ch & 0x3F | 0x80;
          v14 = (ch >> 6) & 0x3F | 0x80;
        }
      }
      else
      {
        v5 = 3i64;
        Src = (ch >> 12) | 0xE0;
        v14 = ch & 0x3F | 0x80;
        v13 = (ch >> 6) & 0x3F | 0x80;
      }
    }
    else
    {
      v5 = 2i64;
      v13 = ch & 0x3F | 0x80;
      Src = (ch >> 6) | 0xC0;
    }
  }
  else
  {
    Src = ch;
    v5 = 1i64;
  }
  v8 = HeapTypeBits & 3;
  if ( v8 )
  {
    v9 = v8 - 1;
    if ( v9 )
    {
      if ( v9 == 1 )
        pData = (Scaleform::MemoryHeap *)this[1].pData;
    }
    else
    {
      pData = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    }
  }
  else
  {
    pData = Scaleform::Memory::pGlobalHeap;
  }
  v10 = v5 + v7;
  if ( v5 + v7 )
  {
    v11 = (unsigned __int64)pData->vfptr->Alloc(pData, v10 + 16, 0i64);
    *(_BYTE *)(v11 + v10 + 12) = 0;
    *(_DWORD *)(v11 + 8) = 1;
    *(_QWORD *)v11 = v10;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v11 = (unsigned __int64)&Scaleform::String::NullData;
  }
  memmove((void *)(v11 + 12), (const void *)(v6 + 3), v7);
  memmove((void *)(v11 + v7 + 12), &Src, v5);
  this->HeapTypeBits = v11 | (__int64)this->pData & 3;
  if ( !_InterlockedDecrement(v6 + 2) )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
}

// File Line: 266
// RVA: 0x959300
void __fastcall Scaleform::String::AppendString(Scaleform::String *this, const wchar_t *pstr, __int64 len)
{
  unsigned __int64 HeapTypeBits; // rbx
  volatile signed __int32 *v6; // r14
  __int64 copySize; // r15
  __int64 EncodeStringSize; // rax
  Scaleform::MemoryHeap *pData; // rdx
  __int64 v11; // rdi
  int v12; // ebx
  int v13; // ebx
  __int64 v14; // rbx
  unsigned __int64 v15; // rdi

  if ( pstr )
  {
    HeapTypeBits = this->HeapTypeBits;
    v6 = (volatile signed __int32 *)(this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
    copySize = *(_QWORD *)v6 & 0x7FFFFFFFFFFFFFFFi64;
    EncodeStringSize = Scaleform::UTF8Util::GetEncodeStringSize(pstr, len);
    pData = 0i64;
    v11 = EncodeStringSize;
    v12 = HeapTypeBits & 3;
    if ( v12 )
    {
      v13 = v12 - 1;
      if ( v13 )
      {
        if ( v13 == 1 )
          pData = (Scaleform::MemoryHeap *)this[1].pData;
      }
      else
      {
        pData = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      }
    }
    else
    {
      pData = Scaleform::Memory::pGlobalHeap;
    }
    v14 = v11 + copySize;
    v15 = (unsigned __int64)Scaleform::String::AllocDataCopy1(
                              this,
                              pData,
                              v11 + copySize,
                              0i64,
                              (const char *)v6 + 12,
                              copySize);
    Scaleform::UTF8Util::EncodeStringSafe((char *)(v15 + copySize + 12), v14 + 1, pstr, len);
    this->HeapTypeBits = v15 | (__int64)this->pData & 3;
    if ( !_InterlockedDecrement(v6 + 2) )
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
  }
}

// File Line: 285
// RVA: 0x959200
void __fastcall Scaleform::String::AppendString(
        Scaleform::String *this,
        const char *putf8str,
        unsigned __int64 utf8StrSz)
{
  unsigned __int64 copySize2; // rbx
  unsigned __int64 HeapTypeBits; // rcx
  Scaleform::MemoryHeap *pData; // rdx
  unsigned __int64 v8; // rsi
  __int64 copySize1; // r15
  int v10; // ecx
  int v11; // ecx

  if ( putf8str )
  {
    copySize2 = utf8StrSz;
    if ( utf8StrSz )
    {
      if ( utf8StrSz == -1i64 )
      {
        copySize2 = -1i64;
        do
          ++copySize2;
        while ( putf8str[copySize2] );
      }
      HeapTypeBits = this->HeapTypeBits;
      pData = 0i64;
      v8 = HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      copySize1 = *(_QWORD *)(HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64;
      v10 = HeapTypeBits & 3;
      if ( v10 )
      {
        v11 = v10 - 1;
        if ( v11 )
        {
          if ( v11 == 1 )
            pData = (Scaleform::MemoryHeap *)this[1].pData;
        }
        else
        {
          pData = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
        }
      }
      else
      {
        pData = Scaleform::Memory::pGlobalHeap;
      }
      this->HeapTypeBits = (unsigned __int64)Scaleform::String::AllocDataCopy2(
                                               this,
                                               pData,
                                               copySize1 + copySize2,
                                               0i64,
                                               (const char *)(v8 + 12),
                                               copySize1,
                                               putf8str,
                                               copySize2) | (__int64)this->pData & 3;
      if ( !_InterlockedDecrement((volatile signed __int32 *)(v8 + 8)) )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v8);
    }
  }
}

// File Line: 300
// RVA: 0x95A150
void __fastcall Scaleform::String::AssignString(
        Scaleform::String *this,
        Scaleform::String::InitStruct *src,
        unsigned __int64 size)
{
  unsigned __int64 HeapTypeBits; // r9
  Scaleform::MemoryHeap *pData; // rcx
  volatile signed __int32 *v8; // rbp
  int v9; // r9d
  int v10; // r9d
  unsigned __int64 v11; // rbx

  HeapTypeBits = this->HeapTypeBits;
  pData = 0i64;
  v8 = (volatile signed __int32 *)(HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v9 = HeapTypeBits & 3;
  if ( v9 )
  {
    v10 = v9 - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
        pData = (Scaleform::MemoryHeap *)this[1].pData;
    }
    else
    {
      pData = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    }
  }
  else
  {
    pData = Scaleform::Memory::pGlobalHeap;
  }
  if ( size )
  {
    v11 = (unsigned __int64)pData->vfptr->Alloc(pData, size + 16, 0i64);
    *(_BYTE *)(v11 + size + 12) = 0;
    *(_DWORD *)(v11 + 8) = 1;
    *(_QWORD *)v11 = size;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v11 = (unsigned __int64)&Scaleform::String::NullData;
  }
  src->vfptr->InitString(src, (char *)(v11 + 12), size);
  this->HeapTypeBits = v11 | (__int64)this->pData & 3;
  if ( !_InterlockedDecrement(v8 + 2) )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v8);
}

// File Line: 309
// RVA: 0x95A240
void __fastcall Scaleform::String::AssignString(Scaleform::String *this, const char *putf8str, size_t size)
{
  unsigned __int64 HeapTypeBits; // r9
  Scaleform::MemoryHeap *pData; // rcx
  volatile signed __int32 *v8; // rbp
  int v9; // r9d
  int v10; // r9d
  unsigned __int64 v11; // rbx

  HeapTypeBits = this->HeapTypeBits;
  pData = 0i64;
  v8 = (volatile signed __int32 *)(HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v9 = HeapTypeBits & 3;
  if ( v9 )
  {
    v10 = v9 - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
        pData = (Scaleform::MemoryHeap *)this[1].pData;
    }
    else
    {
      pData = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    }
  }
  else
  {
    pData = Scaleform::Memory::pGlobalHeap;
  }
  if ( size )
  {
    v11 = (unsigned __int64)pData->vfptr->Alloc(pData, size + 16, 0i64);
    *(_BYTE *)(v11 + size + 12) = 0;
    *(_DWORD *)(v11 + 8) = 1;
    *(_QWORD *)v11 = size;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v11 = (unsigned __int64)&Scaleform::String::NullData;
  }
  memmove((void *)(v11 + 12), putf8str, size);
  this->HeapTypeBits = v11 | (__int64)this->pData & 3;
  if ( !_InterlockedDecrement(v8 + 2) )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v8);
}

// File Line: 316
// RVA: 0x94E510
void __fastcall Scaleform::String::operator=(Scaleform::String *this, const char *pstr)
{
  unsigned __int64 v2; // r8

  if ( pstr )
  {
    v2 = -1i64;
    do
      ++v2;
    while ( pstr[v2] );
  }
  else
  {
    v2 = 0i64;
  }
  Scaleform::String::AssignString(this, pstr, v2);
}

// File Line: 321
// RVA: 0x94E540
void __fastcall Scaleform::String::operator=(Scaleform::String *this, wchar_t *pwstr)
{
  unsigned __int64 HeapTypeBits; // rdx
  __int64 v4; // rbx
  volatile signed __int32 *v6; // r12
  unsigned __int64 v7; // rdi
  wchar_t v8; // ax
  __int64 i; // r8
  int v10; // eax
  Scaleform::MemoryHeap *pData; // rcx
  int v12; // edx
  int v13; // edx
  unsigned __int64 v14; // r14
  __int64 v15; // rdi
  __int64 pindex; // [rsp+50h] [rbp+8h] BYREF

  HeapTypeBits = this->HeapTypeBits;
  v4 = 0i64;
  v6 = (volatile signed __int32 *)(this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v7 = 0i64;
  if ( pwstr )
  {
    v8 = *pwstr;
    for ( i = 0i64; v8; v8 = pwstr[i] )
    {
      if ( v8 > 0x7Fu )
      {
        if ( v8 > 0x7FFu )
          v10 = 3;
        else
          v10 = 2;
      }
      else
      {
        v10 = 1;
      }
      ++i;
      v7 += v10;
    }
  }
  pData = 0i64;
  v12 = HeapTypeBits & 3;
  if ( v12 )
  {
    v13 = v12 - 1;
    if ( v13 )
    {
      if ( v13 == 1 )
        pData = (Scaleform::MemoryHeap *)this[1].pData;
    }
    else
    {
      pData = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    }
  }
  else
  {
    pData = Scaleform::Memory::pGlobalHeap;
  }
  if ( v7 )
  {
    v14 = (unsigned __int64)pData->vfptr->Alloc(pData, v7 + 16, 0i64);
    *(_BYTE *)(v14 + v7 + 12) = 0;
    *(_DWORD *)(v14 + 8) = 1;
    *(_QWORD *)v14 = v7;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v14 = (unsigned __int64)&Scaleform::String::NullData;
  }
  v15 = v7 + 1;
  if ( v15 )
  {
    for ( pindex = 0i64; pindex < v15; ++pwstr )
    {
      if ( !*pwstr )
        break;
      Scaleform::UTF8Util::EncodeCharSafe((char *)(v14 + 12), v15 - v4, &pindex, *pwstr);
      v4 = pindex;
    }
    *(_BYTE *)(v14 + v4 + 12) = 0;
  }
  this->HeapTypeBits = v14 | (__int64)this->pData & 3;
  if ( !_InterlockedDecrement(v6 + 2) )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
}

// File Line: 334
// RVA: 0x94E2D0
void __fastcall Scaleform::String::operator=(Scaleform::String *this, Scaleform::String *src)
{
  Scaleform::String::DataDesc *v2; // rdi
  Scaleform::MemoryHeap *pData; // rbp
  Scaleform::MemoryHeap *v6; // r8
  Scaleform::MemoryHeap *v7; // rax
  unsigned __int64 v8; // r14
  unsigned __int64 v9; // rsi

  v2 = 0i64;
  pData = 0i64;
  if ( ((__int64)this->pData & 3) != 0 )
  {
    if ( ((__int64)this->pData & 3) == 1 )
    {
      v7 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      v6 = Scaleform::Memory::pGlobalHeap;
      pData = v7;
    }
    else
    {
      v6 = Scaleform::Memory::pGlobalHeap;
      if ( ((__int64)this->pData & 3) == 2 )
        pData = (Scaleform::MemoryHeap *)this[1].pData;
    }
  }
  else
  {
    v6 = Scaleform::Memory::pGlobalHeap;
    pData = Scaleform::Memory::pGlobalHeap;
  }
  v8 = this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v9 = src->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( (src->HeapTypeBits & 3) != 0 )
  {
    if ( ((__int64)src->pData & 3) == 1 )
    {
      v2 = (Scaleform::String::DataDesc *)v6->vfptr->GetAllocHeap(v6, src);
    }
    else if ( ((__int64)src->pData & 3) == 2 )
    {
      v2 = src[1].pData;
    }
  }
  else
  {
    v2 = (Scaleform::String::DataDesc *)v6;
  }
  if ( pData == (Scaleform::MemoryHeap *)v2 )
  {
    this->HeapTypeBits = v9 | (__int64)this->pData & 3;
    _InterlockedExchangeAdd((volatile signed __int32 *)(v9 + 8), 1u);
  }
  else
  {
    this->HeapTypeBits = (unsigned __int64)Scaleform::String::AllocDataCopy1(
                                             this,
                                             pData,
                                             *(_QWORD *)v9 & 0x7FFFFFFFFFFFFFFFi64,
                                             *(_QWORD *)v9 & 0x8000000000000000ui64,
                                             (const char *)(v9 + 12),
                                             *(_QWORD *)v9 & 0x7FFFFFFFFFFFFFFFi64) | (__int64)this->pData & 3;
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)(v8 + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *, unsigned __int64, Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v8,
      v6);
}

// File Line: 355
// RVA: 0x94E410
void __fastcall Scaleform::String::operator=(Scaleform::String *this, Scaleform::StringBuffer *src)
{
  unsigned __int64 HeapTypeBits; // r8
  unsigned __int64 Size; // rdi
  char *pData; // r14
  volatile signed __int32 *v6; // rbp
  Scaleform::MemoryHeap *v7; // rcx
  int v8; // r8d
  int v9; // r8d
  unsigned __int64 v10; // rbx

  HeapTypeBits = this->HeapTypeBits;
  Size = src->Size;
  pData = &customCaption;
  v6 = (volatile signed __int32 *)(this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  if ( src->pData )
    pData = src->pData;
  v7 = 0i64;
  v8 = HeapTypeBits & 3;
  if ( v8 )
  {
    v9 = v8 - 1;
    if ( v9 )
    {
      if ( v9 == 1 )
        v7 = (Scaleform::MemoryHeap *)this[1].pData;
    }
    else
    {
      v7 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    }
  }
  else
  {
    v7 = Scaleform::Memory::pGlobalHeap;
  }
  if ( Size )
  {
    v10 = (unsigned __int64)v7->vfptr->Alloc(v7, Size + 16, 0i64);
    *(_BYTE *)(v10 + Size + 12) = 0;
    *(_DWORD *)(v10 + 8) = 1;
    *(_QWORD *)v10 = Size;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v10 = (unsigned __int64)&Scaleform::String::NullData;
  }
  memmove((void *)(v10 + 12), pData, Size);
  this->HeapTypeBits = v10 | (__int64)this->pData & 3;
  if ( !_InterlockedDecrement(v6 + 2) )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
}

// File Line: 362
// RVA: 0x94F2F0
void __fastcall Scaleform::String::operator+=(Scaleform::String *this, Scaleform::String *src)
{
  unsigned __int64 v3; // r15
  volatile signed __int32 *v4; // rdi
  __int64 copySize2; // r14
  Scaleform::MemoryHeap *pData; // rdx
  unsigned __int64 v7; // rsi
  __int64 copySize1; // rbp
  int v9; // r8d
  int v10; // r8d

  v3 = src->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v4 = (volatile signed __int32 *)(this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  copySize2 = *(_QWORD *)v3 & 0x7FFFFFFFFFFFFFFFi64;
  pData = 0i64;
  v7 = *(_QWORD *)v4 & *(_QWORD *)v3 & 0x8000000000000000ui64;
  copySize1 = *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64;
  v9 = this->HeapTypeBits & 3;
  if ( v9 )
  {
    v10 = v9 - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
        pData = (Scaleform::MemoryHeap *)this[1].pData;
    }
    else
    {
      pData = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    }
  }
  else
  {
    pData = Scaleform::Memory::pGlobalHeap;
  }
  this->HeapTypeBits = (unsigned __int64)Scaleform::String::AllocDataCopy2(
                                           this,
                                           pData,
                                           copySize2 + copySize1,
                                           v7,
                                           (const char *)v4 + 12,
                                           copySize1,
                                           (const char *)(v3 + 12),
                                           copySize2) | (__int64)this->pData & 3;
  if ( !_InterlockedDecrement(v4 + 2) )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
}

// File Line: 376
// RVA: 0x94F170
Scaleform::String *__fastcall Scaleform::String::operator+(
        Scaleform::String *this,
        Scaleform::String *result,
        const char *str)
{
  const char *v5; // rdx

  Scaleform::String::String(result, this);
  v5 = &customCaption;
  if ( str )
    v5 = str;
  Scaleform::String::AppendString(result, v5, -1i64);
  return result;
}

// File Line: 383
// RVA: 0x94F110
Scaleform::String *__fastcall Scaleform::String::operator+(
        Scaleform::String *this,
        Scaleform::String *result,
        Scaleform::String *src)
{
  Scaleform::String::String(result, this);
  Scaleform::String::operator+=(result, src);
  return result;
}

// File Line: 390
// RVA: 0x9A8B70
void __fastcall Scaleform::String::Remove(Scaleform::String *this, unsigned __int64 posAt, __int64 removeLength)
{
  volatile signed __int32 *v4; // rdi
  __int64 v7; // rbp
  unsigned __int64 v8; // rbx
  __int64 Length; // rax
  __int64 copySize1; // rbx
  __int64 ByteIndex; // rax
  Scaleform::MemoryHeap *pData; // r10
  unsigned __int64 v13; // rsi
  __int64 v14; // r14

  v4 = (volatile signed __int32 *)(this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v7 = *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64;
  v8 = v7;
  if ( *(__int64 *)v4 >= 0 )
  {
    Length = Scaleform::UTF8Util::GetLength((char *)v4 + 12, *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64);
    if ( Length == v7 )
      *(_QWORD *)v4 |= 0x8000000000000000ui64;
    v8 = Length;
  }
  if ( posAt < v8 )
  {
    if ( posAt + removeLength > v8 )
      removeLength = v8 - posAt;
    copySize1 = Scaleform::UTF8Util::GetByteIndex(posAt, (char *)v4 + 12, v7);
    ByteIndex = Scaleform::UTF8Util::GetByteIndex(removeLength, (char *)v4 + copySize1 + 12, v7 - copySize1);
    pData = 0i64;
    v13 = *(_QWORD *)v4 & 0x8000000000000000ui64;
    v14 = ByteIndex;
    if ( ((__int64)this->pData & 3) != 0 )
    {
      if ( ((__int64)this->pData & 3) == 1 )
      {
        pData = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      }
      else if ( ((__int64)this->pData & 3) == 2 )
      {
        pData = (Scaleform::MemoryHeap *)this[1].pData;
      }
    }
    else
    {
      pData = Scaleform::Memory::pGlobalHeap;
    }
    this->HeapTypeBits = (unsigned __int64)Scaleform::String::AllocDataCopy2(
                                             this,
                                             pData,
                                             v7 - v14,
                                             v13,
                                             (const char *)v4 + 12,
                                             copySize1,
                                             (const char *)(v14 + this->HeapTypeBits + copySize1 + 12),
                                             v7 - v14 - copySize1) | (__int64)this->pData & 3;
    if ( !_InterlockedDecrement(v4 + 2) )
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  }
}

// File Line: 415
// RVA: 0x9B86D0
Scaleform::String *__fastcall Scaleform::String::Substring(
        Scaleform::String *this,
        Scaleform::String *result,
        unsigned __int64 start,
        unsigned __int64 end)
{
  unsigned __int64 v8; // rbx
  __int64 ByteIndex; // rax
  __int64 v10; // r8
  unsigned __int64 v11; // rbx
  __int64 v12; // rax

  if ( start >= Scaleform::String::GetLength(this) || start >= end )
  {
    result->HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  }
  else
  {
    v8 = this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    if ( *(__int64 *)v8 >= 0 )
    {
      ByteIndex = Scaleform::UTF8Util::GetByteIndex(start, (char *)(v8 + 12), *(_QWORD *)v8 & 0x7FFFFFFFFFFFFFFFi64);
      v10 = *(_QWORD *)v8 & 0x7FFFFFFFFFFFFFFFi64;
      v11 = ByteIndex + v8;
      v12 = Scaleform::UTF8Util::GetByteIndex(end - start, (char *)(v11 + 12), v10 - ByteIndex);
      Scaleform::String::String(result, (const char *)(v11 + 12), v12);
    }
    else
    {
      Scaleform::String::String(result, (const char *)(v8 + start + 12), end - start);
    }
  }
  return result;
}

// File Line: 433
// RVA: 0x95F950
void __fastcall Scaleform::String::Clear(Scaleform::String *this)
{
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (__int64)this->pData & 3;
}

// File Line: 441
// RVA: 0x9BA1F0
Scaleform::String *__fastcall Scaleform::String::ToUpper(Scaleform::String *this, Scaleform::String *result)
{
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rsi
  signed __int64 v5; // rbx
  unsigned __int16 v6; // r9
  unsigned __int64 v7; // rcx
  int v8; // eax
  int v9; // eax
  __int64 v10; // r8
  __int64 v11; // rdx
  __int64 v12; // rax
  unsigned int v13; // eax
  char *v14; // rdi
  char putf8str[3]; // [rsp+30h] [rbp-D0h] BYREF
  char *putf8Buffer; // [rsp+260h] [rbp+160h] BYREF
  Scaleform::String *v18; // [rsp+268h] [rbp+168h]

  v18 = result;
  v3 = this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  putf8Buffer = (char *)(v3 + 12);
  v4 = v3 + 12 + (*(_QWORD *)v3 & 0x7FFFFFFFFFFFFFFFi64);
  result->HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  v5 = 0i64;
  if ( (unsigned __int64)putf8Buffer >= v4 )
    return result;
  while ( 1 )
  {
    v6 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer);
    v7 = (unsigned __int64)v6 >> 8;
    v8 = UnicodeToUpperBits[v7];
    if ( UnicodeToUpperBits[v7]
      && (v8 == 1 || (v9 = UnicodeToUpperBits[v8 + ((v6 >> 4) & 0xF)], _bittest(&v9, v6 & 0xF))) )
    {
      v10 = 0i64;
      v11 = 640i64;
      do
      {
        v12 = (v11 >> 1) + v10;
        if ( UnicodeToUpperTable[v12].Key >= v6 )
        {
          v11 >>= 1;
        }
        else
        {
          v10 = v12 + 1;
          v11 += -1 - (v11 >> 1);
        }
      }
      while ( v11 > 0 );
      v13 = (unsigned __int16)word_1418AC562[2 * v10];
    }
    else
    {
      v13 = v6;
    }
    if ( v13 > 0x7F )
    {
      if ( v13 > 0x7FF )
      {
        putf8str[v5] = (v13 >> 12) | 0xE0;
        putf8str[v5 + 1] = (v13 >> 6) & 0x3F | 0x80;
        putf8str[v5 + 2] = v13 & 0x3F | 0x80;
        v5 += 3i64;
      }
      else
      {
        putf8str[v5] = (v13 >> 6) | 0xC0;
        putf8str[v5 + 1] = v13 & 0x3F | 0x80;
        v5 += 2i64;
      }
    }
    else
    {
      putf8str[v5++] = v13;
    }
    v14 = putf8Buffer;
    if ( (unsigned __int64)putf8Buffer >= v4 || v5 >= 504 )
    {
      Scaleform::String::AppendString(result, putf8str, v5);
      v5 = 0i64;
      if ( (unsigned __int64)v14 >= v4 )
        break;
    }
  }
  return result;
}

// File Line: 465
// RVA: 0x9B9F10
Scaleform::String *__fastcall Scaleform::String::ToLower(Scaleform::String *this, Scaleform::String *result)
{
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rsi
  signed __int64 v5; // rbx
  unsigned __int16 v6; // r9
  unsigned __int64 v7; // rcx
  int v8; // eax
  int v9; // eax
  __int64 v10; // r8
  __int64 v11; // rdx
  __int64 v12; // rax
  unsigned int v13; // eax
  char *v14; // rdi
  char putf8str[3]; // [rsp+30h] [rbp-D0h] BYREF
  char *putf8Buffer; // [rsp+260h] [rbp+160h] BYREF
  Scaleform::String *v18; // [rsp+268h] [rbp+168h]

  v18 = result;
  v3 = this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  putf8Buffer = (char *)(v3 + 12);
  v4 = v3 + 12 + (*(_QWORD *)v3 & 0x7FFFFFFFFFFFFFFFi64);
  result->HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  v5 = 0i64;
  if ( (unsigned __int64)putf8Buffer >= v4 )
    return result;
  while ( 1 )
  {
    v6 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer);
    v7 = (unsigned __int64)v6 >> 8;
    v8 = UnicodeToLowerBits[v7];
    if ( UnicodeToLowerBits[v7]
      && (v8 == 1 || (v9 = UnicodeToLowerBits[v8 + ((v6 >> 4) & 0xF)], _bittest(&v9, v6 & 0xF))) )
    {
      v10 = 0i64;
      v11 = 676i64;
      do
      {
        v12 = (v11 >> 1) + v10;
        if ( UnicodeToLowerTable[v12].Key >= v6 )
        {
          v11 >>= 1;
        }
        else
        {
          v10 = v12 + 1;
          v11 += -1 - (v11 >> 1);
        }
      }
      while ( v11 > 0 );
      v13 = (unsigned __int16)word_1418ACF72[2 * v10];
    }
    else
    {
      v13 = v6;
    }
    if ( v13 > 0x7F )
    {
      if ( v13 > 0x7FF )
      {
        putf8str[v5] = (v13 >> 12) | 0xE0;
        putf8str[v5 + 1] = (v13 >> 6) & 0x3F | 0x80;
        putf8str[v5 + 2] = v13 & 0x3F | 0x80;
        v5 += 3i64;
      }
      else
      {
        putf8str[v5] = (v13 >> 6) | 0xC0;
        putf8str[v5 + 1] = v13 & 0x3F | 0x80;
        v5 += 2i64;
      }
    }
    else
    {
      putf8str[v5++] = v13;
    }
    v14 = putf8Buffer;
    if ( (unsigned __int64)putf8Buffer >= v4 || v5 >= 504 )
    {
      Scaleform::String::AppendString(result, putf8str, v5);
      v5 = 0i64;
      if ( (unsigned __int64)v14 >= v4 )
        break;
    }
  }
  return result;
}

// File Line: 535
// RVA: 0x961930
// attributes: thunk
int __fastcall Scaleform::String::CompareNoCase(const char *a, const char *b)
{
  return stricmp(a, b);
}

// File Line: 540
// RVA: 0x961940
__int64 __fastcall Scaleform::String::CompareNoCase(const char *a, const char *b, __int64 len)
{
  __int64 v3; // r10
  const char *v5; // rbx
  int v6; // r9d
  int v7; // ecx
  __int64 v8; // rax
  __int64 v10; // rax

  v3 = len;
  if ( len )
  {
    v5 = b;
    do
    {
      v6 = *a;
      if ( (unsigned int)(v6 - 65) <= 0x19 )
        v6 += 32;
      v7 = *b;
      ++a;
      if ( (unsigned int)(v7 - 65) <= 0x19 )
        v7 += 32;
      ++b;
      if ( !--v3 || !v6 )
        break;
      if ( v6 != (__int64)v7 )
        return (unsigned int)(v6 - v7);
    }
    while ( *b );
    if ( v6 != (__int64)v7 || !v3 && !*b )
      return (unsigned int)(v6 - v7);
    v8 = -1i64;
    do
      ++v8;
    while ( v5[v8] );
    return (unsigned int)(len - v8);
  }
  else
  {
    v10 = -1i64;
    do
      ++v10;
    while ( b[v10] );
    return (unsigned int)-(int)v10;
  }
}

// File Line: 568
// RVA: 0x95AC20
unsigned __int64 __fastcall Scaleform::String::BernsteinHashFunction(
        char *pdataIn,
        unsigned __int64 size,
        unsigned __int64 seed)
{
  __int64 v3; // rax
  unsigned __int64 result; // rax

  if ( !size )
    return seed;
  do
  {
    v3 = (unsigned __int8)pdataIn[--size];
    result = (33 * seed) ^ v3;
    seed = result;
  }
  while ( size );
  return result;
}

// File Line: 582
// RVA: 0x95AC50
unsigned __int64 __fastcall Scaleform::String::BernsteinHashFunctionCIS(
        char *pdataIn,
        unsigned __int64 size,
        unsigned __int64 seed)
{
  int v4; // eax

  for ( ; size; seed = v4 ^ (33 * seed) )
  {
    v4 = (unsigned __int8)pdataIn[--size];
    if ( (unsigned int)(v4 - 65) <= 0x19 )
      v4 += 32;
  }
  return seed;
}

// File Line: 599
// RVA: 0x971140
void __fastcall Scaleform::String::EscapeSpecialHTML(
        char *psrc,
        unsigned __int64 length,
        Scaleform::String *pescapedStr)
{
  char *pData; // rdi
  unsigned __int64 Size; // rbx
  unsigned __int64 BufferSize; // rsi
  unsigned __int64 GrowSize; // r14
  Scaleform::MemoryHeap *pHeap; // r15
  const char *v8; // r13
  unsigned int i; // eax
  unsigned __int64 v10; // r12
  char *v11; // rax
  unsigned __int64 v12; // r12
  char *v13; // rax
  unsigned __int64 v14; // r12
  char *v15; // rax
  unsigned __int64 v16; // r12
  char *v17; // rax
  unsigned __int64 v18; // r12
  char *v19; // rax
  Scaleform::StringBuffer src; // [rsp+28h] [rbp-38h] BYREF
  char *putf8Buffer; // [rsp+A0h] [rbp+40h] BYREF
  Scaleform::String *v22; // [rsp+B0h] [rbp+50h]

  v22 = pescapedStr;
  putf8Buffer = psrc;
  pData = 0i64;
  memset(&src, 0, 24);
  Size = 0i64;
  BufferSize = 0i64;
  GrowSize = 512i64;
  src.GrowSize = 512i64;
  src.LengthIsSize = 0;
  pHeap = Scaleform::Memory::pGlobalHeap;
  src.pHeap = Scaleform::Memory::pGlobalHeap;
  v8 = &psrc[length];
  for ( i = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer);
        putf8Buffer < v8;
        i = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer) )
  {
    switch ( i )
    {
      case <:
        v10 = Size;
        Size += 4i64;
        if ( Size >= BufferSize )
        {
          BufferSize = ~(GrowSize - 1) & (GrowSize + Size);
          src.BufferSize = BufferSize;
          if ( pData )
            v11 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                            Scaleform::Memory::pGlobalHeap,
                            pData,
                            BufferSize);
          else
            v11 = (char *)pHeap->vfptr->Alloc(pHeap, BufferSize, 0i64);
          src.pData = v11;
          pData = v11;
        }
        src.LengthIsSize = 0;
        src.Size = Size;
        if ( pData )
          pData[Size] = 0;
        *(_DWORD *)&pData[v10] = *(_DWORD *)"&lt;";
        break;
      case >:
        v12 = Size;
        Size += 4i64;
        if ( Size >= BufferSize )
        {
          BufferSize = ~(GrowSize - 1) & (GrowSize + Size);
          src.BufferSize = BufferSize;
          if ( pData )
            v13 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                            Scaleform::Memory::pGlobalHeap,
                            pData,
                            BufferSize);
          else
            v13 = (char *)pHeap->vfptr->Alloc(pHeap, BufferSize, 0i64);
          src.pData = v13;
          pData = v13;
        }
        src.LengthIsSize = 0;
        src.Size = Size;
        if ( pData )
          pData[Size] = 0;
        *(_DWORD *)&pData[v12] = *(_DWORD *)"&gt;";
        break;
      case ":
        v14 = Size;
        Size += 6i64;
        if ( Size >= BufferSize )
        {
          BufferSize = ~(GrowSize - 1) & (GrowSize + Size);
          src.BufferSize = BufferSize;
          if ( pData )
            v15 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                            Scaleform::Memory::pGlobalHeap,
                            pData,
                            BufferSize);
          else
            v15 = (char *)pHeap->vfptr->Alloc(pHeap, BufferSize, 0i64);
          src.pData = v15;
          pData = v15;
        }
        src.LengthIsSize = 0;
        src.Size = Size;
        if ( pData )
          pData[Size] = 0;
        qmemcpy(&pData[v14], "&quot;", 6);
        break;
      case \:
        v16 = Size;
        Size += 6i64;
        if ( Size >= BufferSize )
        {
          BufferSize = ~(GrowSize - 1) & (GrowSize + Size);
          src.BufferSize = BufferSize;
          if ( pData )
            v17 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                            Scaleform::Memory::pGlobalHeap,
                            pData,
                            BufferSize);
          else
            v17 = (char *)pHeap->vfptr->Alloc(pHeap, BufferSize, 0i64);
          src.pData = v17;
          pData = v17;
        }
        src.LengthIsSize = 0;
        src.Size = Size;
        if ( pData )
          pData[Size] = 0;
        qmemcpy(&pData[v16], "&apos;", 6);
        break;
      case &:
        v18 = Size;
        Size += 5i64;
        if ( Size >= BufferSize )
        {
          BufferSize = ~(GrowSize - 1) & (GrowSize + Size);
          src.BufferSize = BufferSize;
          if ( pData )
            v19 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                            Scaleform::Memory::pGlobalHeap,
                            pData,
                            BufferSize);
          else
            v19 = (char *)pHeap->vfptr->Alloc(pHeap, BufferSize, 0i64);
          src.pData = v19;
          pData = v19;
        }
        src.LengthIsSize = 0;
        src.Size = Size;
        if ( pData )
          pData[Size] = 0;
        qmemcpy(&pData[v18], "&amp;", 5);
        break;
      default:
        Scaleform::StringBuffer::AppendChar(&src, i);
        pHeap = src.pHeap;
        GrowSize = src.GrowSize;
        BufferSize = src.BufferSize;
        Size = src.Size;
        pData = src.pData;
        break;
    }
  }
  Scaleform::String::operator=(v22, &src);
  if ( pData )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pData);
}

// File Line: 635
// RVA: 0x9BB100
void __fastcall Scaleform::String::UnescapeSpecialHTML(
        char *psrc,
        unsigned __int64 length,
        Scaleform::String *punescapedStr)
{
  char *pData; // rbx
  const char *v5; // rsi
  unsigned int v6; // eax
  char *v7; // rdi
  unsigned int v8; // edx
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rdx
  unsigned __int64 v12; // rsi
  unsigned __int64 v13; // rdi
  unsigned __int64 v14; // rdx
  unsigned __int64 v15; // rsi
  unsigned __int64 v16; // rdi
  unsigned __int64 v17; // rdx
  unsigned __int64 Size; // rsi
  unsigned __int64 v19; // rdi
  unsigned __int64 v20; // rdx
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // rdi
  unsigned __int64 v23; // rdx
  Scaleform::StringBuffer src; // [rsp+28h] [rbp-38h] BYREF
  char *putf8Buffer; // [rsp+80h] [rbp+20h] BYREF

  putf8Buffer = psrc;
  pData = 0i64;
  memset(&src, 0, 24);
  src.GrowSize = 512i64;
  src.LengthIsSize = 0;
  src.pHeap = Scaleform::Memory::pGlobalHeap;
  v5 = &psrc[length];
  v6 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer);
  v7 = putf8Buffer;
  if ( putf8Buffer >= v5 )
    goto LABEL_58;
  while ( 1 )
  {
    if ( v6 != 38 )
    {
      v8 = v6;
      goto LABEL_10;
    }
    if ( !strncmp(v7, "quot;", 5ui64) )
      break;
    if ( !strncmp(v7, "apos;", 5ui64) )
    {
      Size = src.Size;
      v19 = src.Size + 1;
      if ( src.Size + 1 < src.BufferSize )
      {
        pData = src.pData;
      }
      else
      {
        v20 = ~(src.GrowSize - 1) & (src.GrowSize + v19);
        src.BufferSize = v20;
        if ( src.pData )
          pData = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, src.pData, v20);
        else
          pData = (char *)src.pHeap->vfptr->Alloc(src.pHeap, v20, 0i64);
        src.pData = pData;
      }
      src.LengthIsSize = 0;
      src.Size = v19;
      if ( pData )
        pData[v19] = 0;
      pData[Size] = 39;
      goto LABEL_58;
    }
    if ( !strncmp(v7, "amp;", 4ui64) )
    {
      v15 = src.Size;
      v16 = src.Size + 1;
      if ( src.Size + 1 < src.BufferSize )
      {
        pData = src.pData;
      }
      else
      {
        v17 = ~(src.GrowSize - 1) & (src.GrowSize + v16);
        src.BufferSize = v17;
        if ( src.pData )
          pData = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, src.pData, v17);
        else
          pData = (char *)src.pHeap->vfptr->Alloc(src.pHeap, v17, 0i64);
        src.pData = pData;
      }
      src.LengthIsSize = 0;
      src.Size = v16;
      if ( pData )
        pData[v16] = 0;
      pData[v15] = 38;
      goto LABEL_58;
    }
    if ( !strncmp(v7, "lt;", 3ui64) )
    {
      v12 = src.Size;
      v13 = src.Size + 1;
      if ( src.Size + 1 < src.BufferSize )
      {
        pData = src.pData;
      }
      else
      {
        v14 = ~(src.GrowSize - 1) & (src.GrowSize + v13);
        src.BufferSize = v14;
        if ( src.pData )
          pData = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, src.pData, v14);
        else
          pData = (char *)src.pHeap->vfptr->Alloc(src.pHeap, v14, 0i64);
        src.pData = pData;
      }
      src.LengthIsSize = 0;
      src.Size = v13;
      if ( pData )
        pData[v13] = 0;
      pData[v12] = 60;
      goto LABEL_58;
    }
    if ( !strncmp(v7, "gt;", 3ui64) )
    {
      v9 = src.Size;
      v10 = src.Size + 1;
      if ( src.Size + 1 < src.BufferSize )
      {
        pData = src.pData;
      }
      else
      {
        v11 = ~(src.GrowSize - 1) & (src.GrowSize + v10);
        src.BufferSize = v11;
        if ( src.pData )
          pData = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, src.pData, v11);
        else
          pData = (char *)src.pHeap->vfptr->Alloc(src.pHeap, v11, 0i64);
        src.pData = pData;
      }
      src.LengthIsSize = 0;
      src.Size = v10;
      if ( pData )
        pData[v10] = 0;
      pData[v9] = 62;
      goto LABEL_58;
    }
    v8 = 38;
LABEL_10:
    Scaleform::StringBuffer::AppendChar(&src, v8);
    v6 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer);
    v7 = putf8Buffer;
    if ( putf8Buffer >= v5 )
    {
      pData = src.pData;
      goto LABEL_58;
    }
  }
  v21 = src.Size;
  v22 = src.Size + 1;
  if ( src.Size + 1 < src.BufferSize )
  {
    pData = src.pData;
  }
  else
  {
    v23 = ~(src.GrowSize - 1) & (src.GrowSize + v22);
    src.BufferSize = v23;
    if ( src.pData )
      pData = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, src.pData, v23);
    else
      pData = (char *)src.pHeap->vfptr->Alloc(src.pHeap, v23, 0i64);
    src.pData = pData;
  }
  src.LengthIsSize = 0;
  src.Size = v22;
  if ( pData )
    pData[v22] = 0;
  pData[v21] = 34;
LABEL_58:
  Scaleform::String::operator=(punescapedStr, &src);
  if ( pData )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pData);
}

// File Line: 688
// RVA: 0x944FC0
void __fastcall Scaleform::StringLH::StringLH(Scaleform::StringLH *this)
{
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  this->HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 1;
}

// File Line: 694
// RVA: 0x944F00
void __fastcall Scaleform::StringLH::StringLH(Scaleform::StringLH *this, const char *pdata)
{
  size_t v4; // rbx
  Scaleform::MemoryHeap *v5; // rax
  unsigned __int64 v6; // rsi

  if ( pdata )
  {
    v4 = -1i64;
    do
      ++v4;
    while ( pdata[v4] );
  }
  else
  {
    v4 = 0i64;
  }
  v5 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  if ( v4 )
  {
    v6 = (unsigned __int64)v5->vfptr->Alloc(v5, v4 + 16, 0i64);
    *(_BYTE *)(v6 + v4 + 12) = 0;
    *(_DWORD *)(v6 + 8) = 1;
    *(_QWORD *)v6 = v4;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v6 = (unsigned __int64)&Scaleform::String::NullData;
  }
  memmove((void *)(v6 + 12), pdata, v4);
  this->HeapTypeBits = v6 | 1;
}

// File Line: 714
// RVA: 0x964810
void __fastcall Scaleform::StringLH::CopyConstructHelper(Scaleform::StringLH *this, Scaleform::String *src)
{
  unsigned __int64 v4; // rbx
  Scaleform::MemoryHeap *v5; // rbp
  Scaleform::MemoryHeap *pData; // rax

  v4 = src->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v5 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  pData = 0i64;
  if ( ((__int64)src->pData & 3) != 0 )
  {
    if ( ((__int64)src->pData & 3) == 1 )
    {
      pData = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, src);
    }
    else if ( ((__int64)src->pData & 3) == 2 )
    {
      pData = (Scaleform::MemoryHeap *)src[1].pData;
    }
  }
  else
  {
    pData = Scaleform::Memory::pGlobalHeap;
  }
  if ( pData == v5 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 8), 1u);
    this->HeapTypeBits = v4 | 1;
  }
  else
  {
    this->HeapTypeBits = (unsigned __int64)Scaleform::String::AllocDataCopy1(
                                             this,
                                             v5,
                                             *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64,
                                             *(_QWORD *)v4 & 0x8000000000000000ui64,
                                             (const char *)(v4 + 12),
                                             *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64) | 1;
  }
}

// File Line: 746
// RVA: 0x944EC0
void __fastcall Scaleform::StringDH::StringDH(Scaleform::StringDH *this, Scaleform::MemoryHeap *pheap)
{
  this->pHeap = pheap;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  this->HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
}

// File Line: 795
// RVA: 0x964730
void __fastcall Scaleform::StringDH::CopyConstructHelper(
        Scaleform::StringDH *this,
        Scaleform::String *src,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::MemoryHeap *pData; // r9
  unsigned __int64 v6; // rbx

  pData = 0i64;
  v6 = src->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( (src->HeapTypeBits & 3) != 0 )
  {
    if ( ((__int64)src->pData & 3) == 1 )
    {
      pData = (Scaleform::MemoryHeap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::String *, _QWORD, _QWORD))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(
                                         Scaleform::Memory::pGlobalHeap,
                                         src,
                                         ((__int64)src->pData & 3) - 1,
                                         0i64);
    }
    else if ( ((__int64)src->pData & 3) == 2 )
    {
      pData = (Scaleform::MemoryHeap *)src[1].pData;
    }
  }
  else
  {
    pData = Scaleform::Memory::pGlobalHeap;
  }
  if ( !pheap )
    pheap = pData;
  this->pHeap = pheap;
  if ( pData == pheap )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 8), 1u);
    this->HeapTypeBits = v6 | 2;
  }
  else
  {
    this->HeapTypeBits = (unsigned __int64)Scaleform::String::AllocDataCopy1(
                                             this,
                                             pheap,
                                             *(_QWORD *)v6 & 0x7FFFFFFFFFFFFFFFi64,
                                             *(_QWORD *)v6 & 0x8000000000000000ui64,
                                             (const char *)(v6 + 12),
                                             *(_QWORD *)v6 & 0x7FFFFFFFFFFFFFFFi64) | 2;
  }
}

// File Line: 837
// RVA: 0x944DE0
void __fastcall Scaleform::StringBuffer::StringBuffer(Scaleform::StringBuffer *this, Scaleform::MemoryHeap *pheap)
{
  this->GrowSize = 512i64;
  this->pHeap = pheap;
  this->pData = 0i64;
  this->Size = 0i64;
  this->BufferSize = 0i64;
  this->LengthIsSize = 0;
}

// File Line: 848
// RVA: 0x944E00
void __fastcall Scaleform::StringBuffer::StringBuffer(
        Scaleform::StringBuffer *this,
        char *data,
        Scaleform::MemoryHeap *pheap)
{
  char *v3; // rdi
  unsigned __int64 v5; // rbx

  v3 = &customCaption;
  if ( data )
    v3 = data;
  this->GrowSize = 512i64;
  this->pData = 0i64;
  this->Size = 0i64;
  this->BufferSize = 0i64;
  v5 = -1i64;
  this->LengthIsSize = 0;
  this->pHeap = pheap;
  do
    ++v5;
  while ( v3[v5] );
  Scaleform::StringBuffer::Resize(this, v5);
  memmove(this->pData, v3, v5);
}

// File Line: 854
// RVA: 0x944E80
void __fastcall Scaleform::StringBuffer::StringBuffer(
        Scaleform::StringBuffer *this,
        const char *data,
        __int64 dataSize,
        Scaleform::MemoryHeap *pheap)
{
  this->GrowSize = 512i64;
  this->pData = 0i64;
  this->Size = 0i64;
  this->BufferSize = 0i64;
  this->LengthIsSize = 0;
  this->pHeap = pheap;
  Scaleform::StringBuffer::AppendString(this, data, dataSize);
}

// File Line: 895
// RVA: 0x9883F0
unsigned __int64 __fastcall Scaleform::StringBuffer::GetLength(Scaleform::StringBuffer *this)
{
  unsigned __int64 result; // rax

  if ( this->LengthIsSize )
    return this->Size;
  result = Scaleform::UTF8Util::GetLength(this->pData, this->Size);
  if ( result == this->Size )
    this->LengthIsSize = 1;
  return result;
}

// File Line: 919
// RVA: 0x9AC770
void __fastcall Scaleform::StringBuffer::Resize(Scaleform::StringBuffer *this, unsigned __int64 _size)
{
  char *pData; // r9
  unsigned __int64 v5; // rdx
  char *v6; // rax
  char *v7; // rax

  if ( _size >= this->BufferSize )
  {
    pData = this->pData;
    v5 = ~(this->GrowSize - 1) & (this->GrowSize + _size);
    this->BufferSize = v5;
    if ( pData )
      v6 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, pData, v5);
    else
      v6 = (char *)this->pHeap->vfptr->Alloc(this->pHeap, v5, 0i64);
    this->pData = v6;
  }
  v7 = this->pData;
  this->LengthIsSize = 0;
  this->Size = _size;
  if ( v7 )
    v7[_size] = 0;
}

// File Line: 928
// RVA: 0x95F9A0
void __fastcall Scaleform::StringBuffer::Clear(Scaleform::StringBuffer *this)
{
  Scaleform::StringBuffer::Resize(this, 0i64);
}

// File Line: 942
// RVA: 0x958BE0
void __fastcall Scaleform::StringBuffer::AppendChar(Scaleform::StringBuffer *this, unsigned int ch)
{
  unsigned __int64 Size; // rsi
  size_t v3; // rbx
  char Src; // [rsp+30h] [rbp+8h] BYREF
  char v6; // [rsp+31h] [rbp+9h]
  char v7; // [rsp+32h] [rbp+Ah]
  char v8; // [rsp+33h] [rbp+Bh]
  char v9; // [rsp+34h] [rbp+Ch]
  char v10; // [rsp+35h] [rbp+Dh]

  Size = this->Size;
  v3 = 0i64;
  if ( ch > 0x7F )
  {
    if ( ch > 0x7FF )
    {
      if ( ch > 0xFFFF )
      {
        if ( ch > 0x1FFFFF )
        {
          if ( ch > 0x3FFFFFF )
          {
            if ( ch <= 0x7FFFFFFF )
            {
              v3 = 6i64;
              Src = (ch >> 30) | 0xFC;
              v6 = HIBYTE(ch) & 0x3F | 0x80;
              v7 = (ch >> 18) & 0x3F | 0x80;
              v8 = (ch >> 12) & 0x3F | 0x80;
              v10 = ch & 0x3F | 0x80;
              v9 = (ch >> 6) & 0x3F | 0x80;
            }
          }
          else
          {
            v3 = 5i64;
            Src = HIBYTE(ch) | 0xF8;
            v6 = (ch >> 18) & 0x3F | 0x80;
            v7 = (ch >> 12) & 0x3F | 0x80;
            v9 = ch & 0x3F | 0x80;
            v8 = (ch >> 6) & 0x3F | 0x80;
          }
        }
        else
        {
          v3 = 4i64;
          Src = (ch >> 18) | 0xF0;
          v6 = (ch >> 12) & 0x3F | 0x80;
          v8 = ch & 0x3F | 0x80;
          v7 = (ch >> 6) & 0x3F | 0x80;
        }
      }
      else
      {
        v3 = 3i64;
        Src = (ch >> 12) | 0xE0;
        v7 = ch & 0x3F | 0x80;
        v6 = (ch >> 6) & 0x3F | 0x80;
      }
    }
    else
    {
      v3 = 2i64;
      v6 = ch & 0x3F | 0x80;
      Src = (ch >> 6) | 0xC0;
    }
  }
  else
  {
    Src = ch;
    v3 = 1i64;
  }
  Scaleform::StringBuffer::Resize(this, v3 + Size);
  memmove(&this->pData[Size], &Src, v3);
}

// File Line: 972
// RVA: 0x959410
void __fastcall Scaleform::StringBuffer::AppendString(
        Scaleform::StringBuffer *this,
        const char *putf8str,
        size_t utf8StrSz)
{
  size_t v3; // rbx
  unsigned __int64 Size; // rdi

  if ( putf8str )
  {
    v3 = utf8StrSz;
    if ( utf8StrSz )
    {
      if ( utf8StrSz == -1i64 )
      {
        v3 = -1i64;
        do
          ++v3;
        while ( putf8str[v3] );
      }
      Size = this->Size;
      Scaleform::StringBuffer::Resize(this, Size + v3);
      memmove(&this->pData[Size], putf8str, v3);
    }
  }
}

// File Line: 1020
// RVA: 0x994720
void __fastcall Scaleform::StringBuffer::Insert(
        Scaleform::StringBuffer *this,
        const char *substr,
        __int64 posAt,
        __int64 len)
{
  unsigned __int64 Size; // rbp
  size_t v5; // rbx
  __int64 ByteIndex; // r15
  size_t v9; // r14
  char *pData; // r9
  unsigned __int64 v11; // rdx
  char *v12; // rax
  char *v13; // rax

  Size = this->Size;
  v5 = len;
  ByteIndex = posAt;
  if ( len < 0 )
  {
    v5 = -1i64;
    do
      ++v5;
    while ( substr[v5] );
  }
  if ( !this->LengthIsSize )
    ByteIndex = Scaleform::UTF8Util::GetByteIndex(posAt, this->pData, this->Size);
  v9 = v5 + Size;
  if ( v5 + Size >= this->BufferSize )
  {
    pData = this->pData;
    v11 = ~(this->GrowSize - 1) & (this->GrowSize + v9);
    this->BufferSize = v11;
    if ( pData )
      v12 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, pData, v11);
    else
      v12 = (char *)this->pHeap->vfptr->Alloc(this->pHeap, v11, 0i64);
    this->pData = v12;
  }
  memmove(&this->pData[ByteIndex + v5], &this->pData[ByteIndex], Size - ByteIndex + 1);
  memmove(&this->pData[ByteIndex], substr, v5);
  v13 = this->pData;
  this->LengthIsSize = 0;
  this->Size = v9;
  v13[v9] = 0;
}

// File Line: 1059
// RVA: 0x98E180
Scaleform::StringDataPtr *__fastcall Scaleform::StringDataPtr::GetTruncateWhitespace(
        Scaleform::StringDataPtr *this,
        Scaleform::StringDataPtr *result)
{
  const char *pStr; // r15
  unsigned __int64 Size; // r12
  char v4; // r14
  const char *v5; // rsi
  char *v6; // rbx
  const char *v8; // rbp
  __int64 v9; // r13
  int v10; // eax
  unsigned __int64 v11; // rcx
  int v12; // eax
  int v13; // edx
  unsigned int v14; // eax
  char *putf8Buffer; // [rsp+50h] [rbp+8h] BYREF

  pStr = this->pStr;
  Size = this->Size;
  v4 = 0;
  v5 = &this->pStr[Size];
  v6 = (char *)pStr;
  v8 = this->pStr;
  v9 = 0x30000000FFFi64;
  putf8Buffer = (char *)this->pStr;
  if ( pStr < v5 )
  {
    while ( 1 )
    {
      v8 = v6;
      v10 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer);
      if ( v10 != 32 && (unsigned int)(v10 - 9) > 4 )
      {
        v11 = (unsigned int)(v10 - 0x2000);
        if ( ((unsigned int)v11 > 0x29 || !_bittest64(&v9, v11)) && v10 != 8287 && v10 != 12288 )
          break;
      }
      v6 = putf8Buffer;
      if ( putf8Buffer >= v5 )
        goto LABEL_11;
    }
    v6 = putf8Buffer;
    v4 = 1;
  }
LABEL_11:
  if ( v6 != v5 || v4 )
  {
    putf8Buffer = v6;
    while ( putf8Buffer < v5 )
    {
      v12 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&putf8Buffer);
      v13 = v12;
      if ( v12 != 8287 )
      {
        v14 = v12 - 0x2000;
        if ( (v14 > 0x29 || !_bittest64(&v9, v14)) && v13 != 32 && (unsigned int)(v13 - 9) > 4 && v13 != 12288 )
          v6 = putf8Buffer;
      }
    }
    if ( v8 == pStr && v6 == v5 )
    {
      result->pStr = pStr;
      result->Size = Size;
    }
    else
    {
      result->pStr = v8;
      result->Size = v6 - v8;
    }
  }
  else
  {
    result->pStr = 0i64;
    result->Size = 0i64;
  }
  return result;
}

// File Line: 1101
// RVA: 0x97A3A0
unsigned __int64 __fastcall Scaleform::StringDataPtr::FindLastChar(
        Scaleform::StringDataPtr *this,
        char c,
        unsigned __int64 init_ind)
{
  unsigned __int64 Size; // r8

  if ( init_ind == -1i64 || init_ind > this->Size )
    Size = this->Size;
  else
    Size = init_ind + 1;
  if ( !Size )
    return -1i64;
  while ( this->pStr[Size - 1] != c )
  {
    if ( !--Size )
      return -1i64;
  }
  return Size - 1;
}

// File Line: 1142
// RVA: 0x98A1E0
Scaleform::StringDataPtr *__fastcall Scaleform::StringDataPtr::GetNextToken(
        Scaleform::StringDataPtr *this,
        Scaleform::StringDataPtr *result,
        char separator)
{
  unsigned __int64 Size; // r10
  const char *pStr; // r9
  unsigned __int64 i; // rax
  char v6; // cl

  Size = this->Size;
  pStr = this->pStr;
  for ( i = 0i64; i < Size; ++i )
  {
    v6 = pStr[i];
    if ( !v6 )
      break;
    if ( v6 == separator )
      break;
  }
  result->Size = i;
  result->pStr = pStr;
  return result;
}

