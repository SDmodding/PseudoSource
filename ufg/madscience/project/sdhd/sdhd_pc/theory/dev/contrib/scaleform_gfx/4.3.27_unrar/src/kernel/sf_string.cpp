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
  const char *v2; // rdi
  Scaleform::String *v3; // r14
  size_t v4; // rbx
  Scaleform::String::DataDesc *v5; // rsi

  v2 = pdata;
  v3 = this;
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
  memmove(v5->Data, v2, v4);
  v3->HeapTypeBits = (unsigned __int64)v5;
}

// File Line: 49
// RVA: 0x944B80
void __fastcall Scaleform::String::String(Scaleform::String *this, const char *pdata1, const char *pdata2, const char *pdata3)
{
  size_t v4; // rdi
  const char *v5; // r14
  Scaleform::String *v6; // r15
  unsigned __int64 copySize1; // rsi
  unsigned __int64 copySize2; // rbp
  Scaleform::String::DataDesc *v9; // rbx

  v4 = -1i64;
  v5 = pdata3;
  v6 = this;
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
  memmove(&v9->Data[copySize2 + copySize1], v5, v4);
  v6->HeapTypeBits = (unsigned __int64)v9;
}

// File Line: 63
// RVA: 0x944CF0
void __fastcall Scaleform::String::String(Scaleform::String *this, const char *pdata, unsigned __int64 size)
{
  unsigned __int64 v3; // rdi
  const char *v4; // rbp
  Scaleform::String *v5; // rsi
  Scaleform::String::DataDesc *v6; // rbx

  v3 = size;
  v4 = pdata;
  v5 = this;
  if ( size )
  {
    v6 = (Scaleform::String::DataDesc *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          size + 16,
                                          0i64);
    v6->Data[v3] = 0;
    v6->RefCount = 1;
    v6->Size = v3;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v6 = &Scaleform::String::NullData;
  }
  memmove(v6->Data, v4, v3);
  v5->HeapTypeBits = (unsigned __int64)v6;
}

// File Line: 76
// RVA: 0x944A30
void __fastcall Scaleform::String::String(Scaleform::String *this, Scaleform::String *src)
{
  Scaleform::MemoryHeap *v2; // r9
  Scaleform::String *v3; // rdi
  unsigned __int64 v4; // rbx
  __int64 v5; // r8

  v2 = 0i64;
  v3 = this;
  v4 = src->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !(src->HeapTypeBits & 3) )
    goto LABEL_11;
  v5 = ((_QWORD)src->pData & 3) - 1;
  if ( ((_QWORD)src->pData & 3) == 1 )
  {
    v2 = (Scaleform::MemoryHeap *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::String *, __int64, _QWORD))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(
                                    Scaleform::Memory::pGlobalHeap,
                                    src,
                                    v5,
                                    0i64);
  }
  else if ( (_DWORD)v5 == 1 )
  {
    v2 = (Scaleform::MemoryHeap *)src[1].pData;
  }
  if ( v2 != Scaleform::Memory::pGlobalHeap )
  {
    v3->HeapTypeBits = (unsigned __int64)Scaleform::String::AllocDataCopy1(
                                           v3,
                                           Scaleform::Memory::pGlobalHeap,
                                           *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64,
                                           *(_QWORD *)v4 & 0x8000000000000000ui64,
                                           (const char *)(v4 + 12),
                                           *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64);
  }
  else
  {
LABEL_11:
    v3->HeapTypeBits = v4;
    _InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 8), 1u);
  }
}

// File Line: 100
// RVA: 0x944AE0
void __fastcall Scaleform::String::String(Scaleform::String *this, Scaleform::StringBuffer *src)
{
  unsigned __int64 v2; // rdi
  char *v3; // rsi
  Scaleform::String *v4; // r14
  Scaleform::String::DataDesc *v5; // rbx

  v2 = src->Size;
  v3 = &customWorldMapCaption;
  v4 = this;
  if ( src->pData )
    v3 = src->pData;
  if ( v2 )
  {
    v5 = (Scaleform::String::DataDesc *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                          Scaleform::Memory::pGlobalHeap,
                                          v2 + 16,
                                          0i64);
    v5->Data[v2] = 0;
    v5->RefCount = 1;
    v5->Size = v2;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v5 = &Scaleform::String::NullData;
  }
  memmove(v5->Data, v3, v2);
  v4->HeapTypeBits = (unsigned __int64)v5;
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
Scaleform::String::DataDesc *__fastcall Scaleform::String::AllocDataCopy1(Scaleform::String *this, Scaleform::MemoryHeap *pheap, unsigned __int64 size, unsigned __int64 lengthIsSize, const char *pdata, unsigned __int64 copySize)
{
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // rdi
  Scaleform::String::DataDesc *v8; // rbx

  v6 = lengthIsSize;
  v7 = size;
  if ( size )
  {
    v8 = (Scaleform::String::DataDesc *)pheap->vfptr->Alloc(pheap, size + 16, 0i64);
    v8->Data[v7] = 0;
    v8->RefCount = 1;
    v8->Size = v6 | v7;
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
Scaleform::String::DataDesc *__fastcall Scaleform::String::AllocDataCopy2(Scaleform::String *this, Scaleform::MemoryHeap *pheap, unsigned __int64 size, unsigned __int64 lengthIsSize, const char *pdata1, unsigned __int64 copySize1, const char *pdata2, unsigned __int64 copySize2)
{
  unsigned __int64 v8; // rsi
  unsigned __int64 v9; // rbx
  Scaleform::String::DataDesc *v10; // rdi

  v8 = lengthIsSize;
  v9 = size;
  if ( size )
  {
    v10 = (Scaleform::String::DataDesc *)pheap->vfptr->Alloc(pheap, size + 16, 0i64);
    v10->Data[v9] = 0;
    v10->RefCount = 1;
    v10->Size = v8 | v9;
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
signed __int64 __fastcall Scaleform::String::GetLength(Scaleform::String *this)
{
  unsigned __int64 v1; // rbx
  signed __int64 v2; // rdi
  signed __int64 result; // rax

  v1 = this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v2 = *(_QWORD *)v1 & 0x7FFFFFFFFFFFFFFFi64;
  if ( *(_QWORD *)v1 < 0i64 )
    return *(_QWORD *)v1 & 0x7FFFFFFFFFFFFFFFi64;
  result = Scaleform::UTF8Util::GetLength((const char *)(v1 + 12), *(_QWORD *)v1 & 0x7FFFFFFFFFFFFFFFi64);
  if ( result == v2 )
    *(_QWORD *)v1 |= 0x8000000000000000ui64;
  return result;
}

// File Line: 198
// RVA: 0x980C10
unsigned int __fastcall Scaleform::String::GetCharAt(Scaleform::String *this, unsigned __int64 index)
{
  __int64 v2; // r9
  _QWORD *v3; // rax
  const char *v4; // rdx
  char *putf8Buffer; // [rsp+30h] [rbp+8h]

  v2 = index;
  v3 = (_QWORD *)(this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v4 = (char *)v3 + 12;
  if ( *v3 >= 0i64 )
    return Scaleform::UTF8Util::GetCharAt(v2, v4, *v3 & 0x7FFFFFFFFFFFFFFFi64);
  putf8Buffer = (char *)&v4[v2];
  return Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
}

// File Line: 216
// RVA: 0x9843F0
signed __int64 __fastcall Scaleform::String::GetFirstCharAt(Scaleform::String *this, unsigned __int64 index, const char **offset)
{
  signed __int64 v3; // r10
  _QWORD *v4; // rax
  const char *v5; // r9
  unsigned __int64 v6; // r11
  char v7; // cl
  signed __int64 result; // rax
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

  v3 = index;
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
    if ( (v7 & 0xE0) == -64 )
    {
      v9 = *v5;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v9 & 0xC0) != -128 )
        goto LABEL_71;
      ++v5;
      result = v9 & 0x3F | ((v7 & 0x1Fu) << 6);
      if ( (unsigned int)result < 0x80 )
        result = 65533i64;
    }
    else if ( (v7 & 0xF0) == -32 )
    {
      v10 = *v5;
      v11 = (v7 & 0xF) << 12;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v10 & 0xC0) != -128 )
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
      if ( (v13 & 0xC0) != -128 )
        goto LABEL_71;
      ++v5;
      result = v13 & 0x3F | (unsigned int)v14;
      if ( (unsigned int)result < 0x800 )
        result = 65533i64;
    }
    else if ( (v7 & 0xF8) == -16 )
    {
      v15 = *v5;
      v16 = (v7 & 7) << 18;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v15 & 0xC0) != -128 )
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
      if ( (v18 & 0xC0) != -128 )
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
      if ( (v21 & 0xC0) != -128 )
        goto LABEL_71;
      ++v5;
      result = v21 & 0x3F | (unsigned int)v22;
      if ( (unsigned int)result < 0x10000 )
        result = 65533i64;
    }
    else if ( (v7 & 0xFC) == -8 )
    {
      v23 = *v5;
      v24 = (v7 & 3) << 24;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v23 & 0xC0) != -128 )
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
      if ( (v26 & 0xC0) != -128 )
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
      if ( (v29 & 0xC0) != -128 )
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
      if ( (v32 & 0xC0) != -128 )
        goto LABEL_71;
      ++v5;
      result = v32 & 0x3F | (unsigned int)v33;
      if ( (unsigned int)result < 0x200000 )
        result = 65533i64;
    }
    else
    {
      if ( (v7 & 0xFE) != -4 )
        goto LABEL_71;
      v34 = *v5;
      v35 = (v7 & 1) << 30;
      if ( !*v5 )
      {
        result = 0i64;
        goto LABEL_72;
      }
      if ( (v34 & 0xC0) != -128 )
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
      if ( (v37 & 0xC0) != -128 )
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
      if ( (v40 & 0xC0) != -128 )
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
      if ( (v43 & 0xC0) != -128 )
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
      if ( (v46 & 0xC0) != -128 )
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
    --v3;
    if ( (unsigned __int64)v5 >= v6 )
      return result;
  }
  while ( v3 >= 0 );
  *offset = v5;
  return result;
}

// File Line: 242
// RVA: 0x98A1C0
signed __int64 __fastcall Scaleform::String::GetNextChar(Scaleform::String *this, const char **offset)
{
  const char **v2; // rbx
  signed __int64 result; // rax

  v2 = offset;
  result = Scaleform::UTF8Util::DecodeNextChar_Advance0(offset);
  if ( !(_DWORD)result )
    --*v2;
  return result;
}

// File Line: 249
// RVA: 0x958980
void __fastcall Scaleform::String::AppendChar(Scaleform::String *this, unsigned int ch)
{
  unsigned __int64 v2; // r8
  Scaleform::String *v3; // r15
  Scaleform::MemoryHeap *v4; // rcx
  size_t v5; // rdi
  volatile signed __int32 *v6; // rsi
  signed __int64 v7; // r12
  int v8; // er8
  int v9; // er8
  unsigned __int64 v10; // rbp
  __int64 v11; // rbx
  char Src; // [rsp+50h] [rbp+8h]
  char v13; // [rsp+51h] [rbp+9h]
  char v14; // [rsp+52h] [rbp+Ah]
  char v15; // [rsp+53h] [rbp+Bh]
  char v16; // [rsp+54h] [rbp+Ch]
  char v17; // [rsp+55h] [rbp+Dh]

  v2 = this->HeapTypeBits;
  v3 = this;
  v4 = 0i64;
  v5 = 0i64;
  v6 = (volatile signed __int32 *)(v2 & 0xFFFFFFFFFFFFFFFCui64);
  v7 = *(_QWORD *)(v2 & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64;
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
  v8 = v2 & 3;
  if ( v8 )
  {
    v9 = v8 - 1;
    if ( v9 )
    {
      if ( v9 == 1 )
        v4 = (Scaleform::MemoryHeap *)v3[1].pData;
    }
    else
    {
      v4 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v3);
    }
  }
  else
  {
    v4 = Scaleform::Memory::pGlobalHeap;
  }
  v10 = v5 + v7;
  if ( v5 + v7 )
  {
    v11 = (__int64)v4->vfptr->Alloc(v4, v10 + 16, 0i64);
    *(_BYTE *)(v11 + v10 + 12) = 0;
    *(_DWORD *)(v11 + 8) = 1;
    *(_QWORD *)v11 = v10;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v11 = (__int64)&Scaleform::String::NullData;
  }
  memmove((void *)(v11 + 12), (const void *)(v6 + 3), v7);
  memmove((void *)(v11 + v7 + 12), &Src, v5);
  v3->HeapTypeBits = v11 | (_QWORD)v3->pData & 3;
  if ( !_InterlockedDecrement(v6 + 2) )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
}

// File Line: 266
// RVA: 0x959300
void __fastcall Scaleform::String::AppendString(Scaleform::String *this, const wchar_t *pstr, __int64 len)
{
  unsigned __int64 v3; // rbx
  const wchar_t *v4; // rbp
  Scaleform::String *v5; // rsi
  volatile signed __int32 *v6; // r14
  __int64 v7; // r12
  signed __int64 copySize; // r15
  __int64 v9; // rax
  Scaleform::MemoryHeap *v10; // rdx
  __int64 v11; // rdi
  int v12; // ebx
  int v13; // ebx
  signed __int64 v14; // rbx
  unsigned __int64 v15; // rdi

  if ( pstr )
  {
    v3 = this->HeapTypeBits;
    v4 = pstr;
    v5 = this;
    v6 = (volatile signed __int32 *)(this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
    v7 = len;
    copySize = *(_QWORD *)v6 & 0x7FFFFFFFFFFFFFFFi64;
    v9 = Scaleform::UTF8Util::GetEncodeStringSize(pstr, len);
    v10 = 0i64;
    v11 = v9;
    v12 = v3 & 3;
    if ( v12 )
    {
      v13 = v12 - 1;
      if ( v13 )
      {
        if ( v13 == 1 )
          v10 = (Scaleform::MemoryHeap *)v5[1].pData;
      }
      else
      {
        v10 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v5);
      }
    }
    else
    {
      v10 = Scaleform::Memory::pGlobalHeap;
    }
    v14 = v11 + copySize;
    v15 = (unsigned __int64)Scaleform::String::AllocDataCopy1(
                              v5,
                              v10,
                              v11 + copySize,
                              0i64,
                              (const char *)v6 + 12,
                              copySize);
    Scaleform::UTF8Util::EncodeStringSafe((char *)(v15 + copySize + 12), v14 + 1, v4, v7);
    v5->HeapTypeBits = v15 | (_QWORD)v5->pData & 3;
    if ( !_InterlockedDecrement(v6 + 2) )
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
  }
}

// File Line: 285
// RVA: 0x959200
void __fastcall Scaleform::String::AppendString(Scaleform::String *this, const char *putf8str, __int64 utf8StrSz)
{
  __int64 copySize2; // rbx
  const char *pdata2; // rdi
  Scaleform::String *v5; // r14
  unsigned __int64 v6; // rcx
  Scaleform::MemoryHeap *v7; // rdx
  unsigned __int64 v8; // rsi
  signed __int64 copySize1; // r15
  int v10; // ecx
  int v11; // ecx

  if ( putf8str )
  {
    copySize2 = utf8StrSz;
    pdata2 = putf8str;
    v5 = this;
    if ( utf8StrSz )
    {
      if ( utf8StrSz == -1 )
      {
        copySize2 = -1i64;
        do
          ++copySize2;
        while ( putf8str[copySize2] );
      }
      v6 = this->HeapTypeBits;
      v7 = 0i64;
      v8 = v6 & 0xFFFFFFFFFFFFFFFCui64;
      copySize1 = *(_QWORD *)(v6 & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64;
      v10 = v6 & 3;
      if ( v10 )
      {
        v11 = v10 - 1;
        if ( v11 )
        {
          if ( v11 == 1 )
            v7 = (Scaleform::MemoryHeap *)v5[1].pData;
        }
        else
        {
          v7 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v5);
        }
      }
      else
      {
        v7 = Scaleform::Memory::pGlobalHeap;
      }
      v5->HeapTypeBits = (unsigned __int64)Scaleform::String::AllocDataCopy2(
                                             v5,
                                             v7,
                                             copySize1 + copySize2,
                                             0i64,
                                             (const char *)(v8 + 12),
                                             copySize1,
                                             pdata2,
                                             copySize2) | (_QWORD)v5->pData & 3;
      if ( !_InterlockedDecrement((volatile signed __int32 *)(v8 + 8)) )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v8);
    }
  }
}

// File Line: 300
// RVA: 0x95A150
void __fastcall Scaleform::String::AssignString(Scaleform::String *this, Scaleform::String::InitStruct *src, unsigned __int64 size)
{
  unsigned __int64 v3; // r9
  Scaleform::String *v4; // rsi
  Scaleform::MemoryHeap *v5; // rcx
  unsigned __int64 v6; // rdi
  Scaleform::String::InitStruct *v7; // r14
  volatile signed __int32 *v8; // rbp
  int v9; // er9
  int v10; // er9
  __int64 v11; // rbx

  v3 = this->HeapTypeBits;
  v4 = this;
  v5 = 0i64;
  v6 = size;
  v7 = src;
  v8 = (volatile signed __int32 *)(v3 & 0xFFFFFFFFFFFFFFFCui64);
  v9 = v3 & 3;
  if ( v9 )
  {
    v10 = v9 - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
        v5 = (Scaleform::MemoryHeap *)v4[1].pData;
    }
    else
    {
      v5 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  else
  {
    v5 = Scaleform::Memory::pGlobalHeap;
  }
  if ( v6 )
  {
    v11 = (__int64)v5->vfptr->Alloc(v5, v6 + 16, 0i64);
    *(_BYTE *)(v11 + v6 + 12) = 0;
    *(_DWORD *)(v11 + 8) = 1;
    *(_QWORD *)v11 = v6;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v11 = (__int64)&Scaleform::String::NullData;
  }
  v7->vfptr->InitString(v7, (char *)(v11 + 12), v6);
  v4->HeapTypeBits = v11 | (_QWORD)v4->pData & 3;
  if ( !_InterlockedDecrement(v8 + 2) )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v8);
}

// File Line: 309
// RVA: 0x95A240
void __fastcall Scaleform::String::AssignString(Scaleform::String *this, const char *putf8str, unsigned __int64 size)
{
  unsigned __int64 v3; // r9
  Scaleform::String *v4; // rdi
  Scaleform::MemoryHeap *v5; // rcx
  unsigned __int64 v6; // rsi
  const char *v7; // r14
  volatile signed __int32 *v8; // rbp
  int v9; // er9
  int v10; // er9
  __int64 v11; // rbx

  v3 = this->HeapTypeBits;
  v4 = this;
  v5 = 0i64;
  v6 = size;
  v7 = putf8str;
  v8 = (volatile signed __int32 *)(v3 & 0xFFFFFFFFFFFFFFFCui64);
  v9 = v3 & 3;
  if ( v9 )
  {
    v10 = v9 - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
        v5 = (Scaleform::MemoryHeap *)v4[1].pData;
    }
    else
    {
      v5 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  else
  {
    v5 = Scaleform::Memory::pGlobalHeap;
  }
  if ( v6 )
  {
    v11 = (__int64)v5->vfptr->Alloc(v5, v6 + 16, 0i64);
    *(_BYTE *)(v11 + v6 + 12) = 0;
    *(_DWORD *)(v11 + 8) = 1;
    *(_QWORD *)v11 = v6;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v11 = (__int64)&Scaleform::String::NullData;
  }
  memmove((void *)(v11 + 12), v7, v6);
  v4->HeapTypeBits = v11 | (_QWORD)v4->pData & 3;
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
    Scaleform::String::AssignString(this, pstr, v2);
  }
  else
  {
    Scaleform::String::AssignString(this, 0i64, 0i64);
  }
}

// File Line: 321
// RVA: 0x94E540
void __fastcall Scaleform::String::operator=(Scaleform::String *this, const wchar_t *pwstr)
{
  const wchar_t *v2; // rsi
  unsigned __int64 v3; // rdx
  __int64 v4; // rbx
  Scaleform::String *v5; // r13
  volatile signed __int32 *v6; // r12
  unsigned __int64 v7; // rdi
  wchar_t v8; // ax
  __int64 i; // r8
  unsigned int v10; // ecx
  signed int v11; // eax
  Scaleform::MemoryHeap *v12; // rcx
  int v13; // edx
  int v14; // edx
  __int64 v15; // r14
  __int64 v16; // rdi
  __int64 pindex; // [rsp+50h] [rbp+8h]

  v2 = pwstr;
  v3 = this->HeapTypeBits;
  v4 = 0i64;
  v5 = this;
  v6 = (volatile signed __int32 *)(this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v7 = 0i64;
  if ( v2 )
  {
    v8 = *v2;
    for ( i = 0i64; v8; v8 = v2[i] )
    {
      v10 = v8;
      if ( v8 > 0x7Fu )
      {
        if ( v8 > 0x7FFu )
        {
          if ( v8 > 0xFFFFu )
          {
            if ( v8 > 0x1FFFFFu )
            {
              if ( v8 > 0x3FFFFFFu )
              {
                v11 = 0;
                if ( v10 <= 0x7FFFFFFF )
                  v11 = 6;
              }
              else
              {
                v11 = 5;
              }
            }
            else
            {
              v11 = 4;
            }
          }
          else
          {
            v11 = 3;
          }
        }
        else
        {
          v11 = 2;
        }
      }
      else
      {
        v11 = 1;
      }
      ++i;
      v7 += v11;
    }
  }
  v12 = 0i64;
  v13 = v3 & 3;
  if ( v13 )
  {
    v14 = v13 - 1;
    if ( v14 )
    {
      if ( v14 == 1 )
        v12 = (Scaleform::MemoryHeap *)v5[1].pData;
    }
    else
    {
      v12 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v5);
    }
  }
  else
  {
    v12 = Scaleform::Memory::pGlobalHeap;
  }
  if ( v7 )
  {
    v15 = (__int64)v12->vfptr->Alloc(v12, v7 + 16, 0i64);
    *(_BYTE *)(v15 + v7 + 12) = 0;
    *(_DWORD *)(v15 + 8) = 1;
    *(_QWORD *)v15 = v7;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v15 = (__int64)&Scaleform::String::NullData;
  }
  v16 = v7 + 1;
  if ( v16 )
  {
    for ( pindex = 0i64; pindex < v16; ++v2 )
    {
      if ( !*v2 )
        break;
      Scaleform::UTF8Util::EncodeCharSafe((char *)(v15 + 12), v16 - v4, &pindex, *v2);
      v4 = pindex;
    }
    *(_BYTE *)(v15 + v4 + 12) = 0;
  }
  v5->HeapTypeBits = v15 | (_QWORD)v5->pData & 3;
  if ( !_InterlockedDecrement(v6 + 2) )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
}

// File Line: 334
// RVA: 0x94E2D0
void __fastcall Scaleform::String::operator=(Scaleform::String *this, Scaleform::String *src)
{
  __int64 v2; // rdi
  Scaleform::String *v3; // r15
  Scaleform::String *v4; // rbx
  Scaleform::MemoryHeap *v5; // rbp
  Scaleform::MemoryHeap *v6; // r8
  Scaleform::MemoryHeap *v7; // rax
  unsigned __int64 v8; // r14
  unsigned __int64 v9; // rsi

  v2 = 0i64;
  v3 = src;
  v4 = this;
  v5 = 0i64;
  if ( (_QWORD)this->pData & 3 )
  {
    if ( ((_QWORD)this->pData & 3) == 1 )
    {
      v7 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      v6 = Scaleform::Memory::pGlobalHeap;
      v5 = v7;
    }
    else
    {
      v6 = Scaleform::Memory::pGlobalHeap;
      if ( ((_QWORD)this->pData & 3) == 2 )
        v5 = (Scaleform::MemoryHeap *)this[1].pData;
    }
  }
  else
  {
    v6 = Scaleform::Memory::pGlobalHeap;
    v5 = Scaleform::Memory::pGlobalHeap;
  }
  v8 = v4->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v9 = v3->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( v3->HeapTypeBits & 3 )
  {
    if ( ((_QWORD)v3->pData & 3) == 1 )
    {
      v2 = (__int64)v6->vfptr->GetAllocHeap(v6, v3);
    }
    else if ( ((_QWORD)v3->pData & 3) == 2 )
    {
      v2 = (__int64)v3[1].pData;
    }
  }
  else
  {
    v2 = (__int64)v6;
  }
  if ( v5 == (Scaleform::MemoryHeap *)v2 )
  {
    v4->HeapTypeBits = v9 | (_QWORD)v4->pData & 3;
    _InterlockedExchangeAdd((volatile signed __int32 *)(v9 + 8), 1u);
  }
  else
  {
    v4->HeapTypeBits = (unsigned __int64)Scaleform::String::AllocDataCopy1(
                                           v4,
                                           v5,
                                           *(_QWORD *)v9 & 0x7FFFFFFFFFFFFFFFi64,
                                           *(_QWORD *)v9 & 0x8000000000000000ui64,
                                           (const char *)(v9 + 12),
                                           *(_QWORD *)v9 & 0x7FFFFFFFFFFFFFFFi64) | (_QWORD)v4->pData & 3;
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
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rdi
  char *v4; // r14
  Scaleform::String *v5; // rsi
  volatile signed __int32 *v6; // rbp
  Scaleform::MemoryHeap *v7; // rcx
  int v8; // er8
  int v9; // er8
  __int64 v10; // rbx

  v2 = this->HeapTypeBits;
  v3 = src->Size;
  v4 = &customWorldMapCaption;
  v5 = this;
  v6 = (volatile signed __int32 *)(this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  if ( src->pData )
    v4 = src->pData;
  v7 = 0i64;
  v8 = v2 & 3;
  if ( v8 )
  {
    v9 = v8 - 1;
    if ( v9 )
    {
      if ( v9 == 1 )
        v7 = (Scaleform::MemoryHeap *)v5[1].pData;
    }
    else
    {
      v7 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v5);
    }
  }
  else
  {
    v7 = Scaleform::Memory::pGlobalHeap;
  }
  if ( v3 )
  {
    v10 = (__int64)v7->vfptr->Alloc(v7, v3 + 16, 0i64);
    *(_BYTE *)(v10 + v3 + 12) = 0;
    *(_DWORD *)(v10 + 8) = 1;
    *(_QWORD *)v10 = v3;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v10 = (__int64)&Scaleform::String::NullData;
  }
  memmove((void *)(v10 + 12), v4, v3);
  v5->HeapTypeBits = v10 | (_QWORD)v5->pData & 3;
  if ( !_InterlockedDecrement(v6 + 2) )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
}

// File Line: 362
// RVA: 0x94F2F0
void __fastcall Scaleform::String::operator+=(Scaleform::String *this, Scaleform::String *src)
{
  Scaleform::String *v2; // rbx
  unsigned __int64 v3; // r15
  volatile signed __int32 *v4; // rdi
  signed __int64 copySize2; // r14
  Scaleform::MemoryHeap *v6; // rdx
  unsigned __int64 v7; // rsi
  signed __int64 copySize1; // rbp
  int v9; // er8
  int v10; // er8

  v2 = this;
  v3 = src->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v4 = (volatile signed __int32 *)(this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  copySize2 = *(_QWORD *)v3 & 0x7FFFFFFFFFFFFFFFi64;
  v6 = 0i64;
  v7 = *(_QWORD *)v4 & *(_QWORD *)v3 & 0x8000000000000000ui64;
  copySize1 = *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64;
  v9 = this->HeapTypeBits & 3;
  if ( v9 )
  {
    v10 = v9 - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
        v6 = (Scaleform::MemoryHeap *)this[1].pData;
    }
    else
    {
      v6 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    }
  }
  else
  {
    v6 = Scaleform::Memory::pGlobalHeap;
  }
  v2->HeapTypeBits = (unsigned __int64)Scaleform::String::AllocDataCopy2(
                                         v2,
                                         v6,
                                         copySize2 + copySize1,
                                         v7,
                                         (const char *)v4 + 12,
                                         copySize1,
                                         (const char *)(v3 + 12),
                                         copySize2) | (_QWORD)v2->pData & 3;
  if ( !_InterlockedDecrement(v4 + 2) )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
}

// File Line: 376
// RVA: 0x94F170
Scaleform::String *__fastcall Scaleform::String::operator+(Scaleform::String *this, Scaleform::String *result, const char *str)
{
  const char *v3; // rbx
  Scaleform::String *v4; // rdi
  const char *v5; // rdx

  v3 = str;
  v4 = result;
  Scaleform::String::String(result, this);
  v5 = &customWorldMapCaption;
  if ( v3 )
    v5 = v3;
  Scaleform::String::AppendString(v4, v5, -1i64);
  return v4;
}

// File Line: 383
// RVA: 0x94F110
Scaleform::String *__fastcall Scaleform::String::operator+(Scaleform::String *this, Scaleform::String *result, Scaleform::String *src)
{
  Scaleform::String *v3; // rbx
  Scaleform::String *v4; // rdi

  v3 = src;
  v4 = result;
  Scaleform::String::String(result, this);
  Scaleform::String::operator+=(v4, v3);
  return v4;
}

// File Line: 390
// RVA: 0x9A8B70
void __fastcall Scaleform::String::Remove(Scaleform::String *this, unsigned __int64 posAt, __int64 removeLength)
{
  Scaleform::String *v3; // r15
  volatile signed __int32 *v4; // rdi
  __int64 v5; // rsi
  unsigned __int64 v6; // r14
  __int64 v7; // rbp
  unsigned __int64 v8; // rbx
  __int64 v9; // rax
  char *v10; // rax
  unsigned __int64 copySize1; // rbx
  char *v12; // rax
  Scaleform::MemoryHeap *v13; // r10
  unsigned __int64 v14; // rsi
  char *v15; // r14

  v3 = this;
  v4 = (volatile signed __int32 *)(this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v5 = removeLength;
  v6 = posAt;
  v7 = *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64;
  v8 = *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64;
  if ( *(_QWORD *)v4 >= 0i64 )
  {
    v9 = Scaleform::UTF8Util::GetLength((const char *)v4 + 12, *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64);
    if ( v9 == v8 )
      *(_QWORD *)v4 |= 0x8000000000000000ui64;
    v8 = v9;
  }
  if ( v6 < v8 )
  {
    if ( v6 + v5 > v8 )
      v5 = v8 - v6;
    v10 = Scaleform::UTF8Util::GetByteIndex(v6, (const char *)v4 + 12, v7);
    copySize1 = (unsigned __int64)v10;
    v12 = Scaleform::UTF8Util::GetByteIndex(v5, (const char *)v4 + (_QWORD)v10 + 12, v7 - (_QWORD)v10);
    v13 = 0i64;
    v14 = *(_QWORD *)v4 & 0x8000000000000000ui64;
    v15 = v12;
    if ( (_QWORD)v3->pData & 3 )
    {
      if ( ((_QWORD)v3->pData & 3) == 1 )
      {
        v13 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v3);
      }
      else if ( ((_QWORD)v3->pData & 3) == 2 )
      {
        v13 = (Scaleform::MemoryHeap *)v3[1].pData;
      }
    }
    else
    {
      v13 = Scaleform::Memory::pGlobalHeap;
    }
    v3->HeapTypeBits = (unsigned __int64)Scaleform::String::AllocDataCopy2(
                                           v3,
                                           v13,
                                           v7 - (_QWORD)v15,
                                           v14,
                                           (const char *)v4 + 12,
                                           copySize1,
                                           &v15[v3->HeapTypeBits + 12 + copySize1],
                                           v7 - (_QWORD)v15 - copySize1) | (_QWORD)v3->pData & 3;
    if ( !_InterlockedDecrement(v4 + 2) )
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  }
}

// File Line: 415
// RVA: 0x9B86D0
Scaleform::String *__fastcall Scaleform::String::Substring(Scaleform::String *this, Scaleform::String *result, unsigned __int64 start, unsigned __int64 end)
{
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // rbp
  Scaleform::String *v6; // rdi
  Scaleform::String *v7; // rbx
  unsigned __int64 v8; // rbx
  char *v9; // rax
  signed __int64 v10; // r8
  char *v11; // rbx
  char *v12; // rax

  v4 = end;
  v5 = start;
  v6 = result;
  v7 = this;
  if ( start >= Scaleform::String::GetLength(this) || v5 >= v4 )
  {
    v6->HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  }
  else
  {
    v8 = v7->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    if ( *(_QWORD *)v8 >= 0i64 )
    {
      v9 = Scaleform::UTF8Util::GetByteIndex(v5, (const char *)(v8 + 12), *(_QWORD *)v8 & 0x7FFFFFFFFFFFFFFFi64);
      v10 = *(_QWORD *)v8 & 0x7FFFFFFFFFFFFFFFi64;
      v11 = &v9[v8];
      v12 = Scaleform::UTF8Util::GetByteIndex(v4 - v5, v11 + 12, v10 - (_QWORD)v9);
      Scaleform::String::String(v6, v11 + 12, (unsigned __int64)v12);
    }
    else
    {
      Scaleform::String::String(v6, (const char *)(v8 + v5 + 12), v4 - v5);
    }
  }
  return v6;
}

// File Line: 433
// RVA: 0x95F950
void __fastcall Scaleform::String::Clear(Scaleform::String *this)
{
  Scaleform::String *v1; // rbx

  v1 = this;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v1->HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (_QWORD)v1->pData & 3;
}

// File Line: 441
// RVA: 0x9BA1F0
Scaleform::String *__fastcall Scaleform::String::ToUpper(Scaleform::String *this, Scaleform::String *result)
{
  Scaleform::String *v2; // r14
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rsi
  __int64 v5; // rbx
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // r9
  unsigned __int64 v8; // rcx
  int v9; // eax
  int v10; // eax
  signed __int64 v11; // r8
  signed __int64 v12; // rdx
  signed __int64 v13; // rax
  unsigned int v14; // eax
  char *v15; // rdi
  char putf8str; // [rsp+30h] [rbp-D0h]
  char v18; // [rsp+31h] [rbp-CFh]
  char v19; // [rsp+32h] [rbp-CEh]
  char v20; // [rsp+33h] [rbp-CDh]
  char v21; // [rsp+34h] [rbp-CCh]
  char v22[235]; // [rsp+35h] [rbp-CBh]
  char *putf8Buffer; // [rsp+260h] [rbp+160h]
  Scaleform::String *v24; // [rsp+268h] [rbp+168h]

  v24 = result;
  v2 = result;
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
    v6 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    v7 = v6;
    v8 = (unsigned __int64)v6 >> 8;
    v9 = UnicodeToUpperBits[v8];
    if ( UnicodeToUpperBits[v8]
      && (v9 == 1 || (v10 = UnicodeToUpperBits[v9 + (((unsigned int)v7 >> 4) & 0xF)], _bittest(&v10, v7 & 0xF))) )
    {
      v11 = 0i64;
      v12 = 640i64;
      do
      {
        v13 = (v12 >> 1) + v11;
        if ( UnicodeToUpperTable[v13].Key >= v7 )
        {
          v12 >>= 1;
        }
        else
        {
          v11 = v13 + 1;
          v12 += -1 - (v12 >> 1);
        }
      }
      while ( v12 > 0 );
      v14 = (unsigned __int16)word_1418AC562[2 * v11];
    }
    else
    {
      v14 = v7;
    }
    if ( v14 > 0x7F )
    {
      if ( v14 > 0x7FF )
      {
        if ( v14 > 0xFFFF )
        {
          if ( v14 > 0x1FFFFF )
          {
            if ( v14 > 0x3FFFFFF )
            {
              if ( v14 <= 0x7FFFFFFF )
              {
                *(&putf8str + v5) = (v14 >> 30) | 0xFC;
                *(&v18 + v5) = HIBYTE(v14) & 0x3F | 0x80;
                *(&v19 + v5) = (v14 >> 18) & 0x3F | 0x80;
                *(&v20 + v5) = (v14 >> 12) & 0x3F | 0x80;
                *(&v21 + v5) = (v14 >> 6) & 0x3F | 0x80;
                v22[v5] = v14 & 0x3F | 0x80;
                v5 += 6i64;
              }
            }
            else
            {
              *(&putf8str + v5) = HIBYTE(v14) | 0xF8;
              *(&v18 + v5) = (v14 >> 18) & 0x3F | 0x80;
              *(&v19 + v5) = (v14 >> 12) & 0x3F | 0x80;
              *(&v20 + v5) = (v14 >> 6) & 0x3F | 0x80;
              *(&v21 + v5) = v14 & 0x3F | 0x80;
              v5 += 5i64;
            }
          }
          else
          {
            *(&putf8str + v5) = (v14 >> 18) | 0xF0;
            *(&v18 + v5) = (v14 >> 12) & 0x3F | 0x80;
            *(&v19 + v5) = (v14 >> 6) & 0x3F | 0x80;
            *(&v20 + v5) = v14 & 0x3F | 0x80;
            v5 += 4i64;
          }
        }
        else
        {
          *(&putf8str + v5) = (v14 >> 12) | 0xE0;
          *(&v18 + v5) = (v14 >> 6) & 0x3F | 0x80;
          *(&v19 + v5) = v14 & 0x3F | 0x80;
          v5 += 3i64;
        }
      }
      else
      {
        *(&putf8str + v5) = (v14 >> 6) | 0xC0;
        *(&v18 + v5) = v14 & 0x3F | 0x80;
        v5 += 2i64;
      }
    }
    else
    {
      *(&putf8str + v5++) = v14;
    }
    v15 = putf8Buffer;
    if ( (unsigned __int64)putf8Buffer >= v4 || v5 >= 504 )
    {
      Scaleform::String::AppendString(v2, &putf8str, v5);
      v5 = 0i64;
      if ( (unsigned __int64)v15 >= v4 )
        break;
    }
  }
  return v2;
}

// File Line: 465
// RVA: 0x9B9F10
Scaleform::String *__fastcall Scaleform::String::ToLower(Scaleform::String *this, Scaleform::String *result)
{
  Scaleform::String *v2; // r14
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rsi
  __int64 v5; // rbx
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // r9
  unsigned __int64 v8; // rcx
  int v9; // eax
  int v10; // eax
  signed __int64 v11; // r8
  signed __int64 v12; // rdx
  signed __int64 v13; // rax
  unsigned int v14; // eax
  char *v15; // rdi
  char putf8str; // [rsp+30h] [rbp-D0h]
  char v18; // [rsp+31h] [rbp-CFh]
  char v19; // [rsp+32h] [rbp-CEh]
  char v20; // [rsp+33h] [rbp-CDh]
  char v21; // [rsp+34h] [rbp-CCh]
  char v22[539]; // [rsp+35h] [rbp-CBh]
  char *putf8Buffer; // [rsp+260h] [rbp+160h]
  Scaleform::String *v24; // [rsp+268h] [rbp+168h]

  v24 = result;
  v2 = result;
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
    v6 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    v7 = v6;
    v8 = (unsigned __int64)v6 >> 8;
    v9 = UnicodeToLowerBits[v8];
    if ( UnicodeToLowerBits[v8]
      && (v9 == 1 || (v10 = UnicodeToLowerBits[v9 + (((unsigned int)v7 >> 4) & 0xF)], _bittest(&v10, v7 & 0xF))) )
    {
      v11 = 0i64;
      v12 = 676i64;
      do
      {
        v13 = (v12 >> 1) + v11;
        if ( UnicodeToLowerTable[v13].Key >= v7 )
        {
          v12 >>= 1;
        }
        else
        {
          v11 = v13 + 1;
          v12 += -1 - (v12 >> 1);
        }
      }
      while ( v12 > 0 );
      v14 = (unsigned __int16)word_1418ACF72[2 * v11];
    }
    else
    {
      v14 = v7;
    }
    if ( v14 > 0x7F )
    {
      if ( v14 > 0x7FF )
      {
        if ( v14 > 0xFFFF )
        {
          if ( v14 > 0x1FFFFF )
          {
            if ( v14 > 0x3FFFFFF )
            {
              if ( v14 <= 0x7FFFFFFF )
              {
                *(&putf8str + v5) = (v14 >> 30) | 0xFC;
                *(&v18 + v5) = HIBYTE(v14) & 0x3F | 0x80;
                *(&v19 + v5) = (v14 >> 18) & 0x3F | 0x80;
                *(&v20 + v5) = (v14 >> 12) & 0x3F | 0x80;
                *(&v21 + v5) = (v14 >> 6) & 0x3F | 0x80;
                v22[v5] = v14 & 0x3F | 0x80;
                v5 += 6i64;
              }
            }
            else
            {
              *(&putf8str + v5) = HIBYTE(v14) | 0xF8;
              *(&v18 + v5) = (v14 >> 18) & 0x3F | 0x80;
              *(&v19 + v5) = (v14 >> 12) & 0x3F | 0x80;
              *(&v20 + v5) = (v14 >> 6) & 0x3F | 0x80;
              *(&v21 + v5) = v14 & 0x3F | 0x80;
              v5 += 5i64;
            }
          }
          else
          {
            *(&putf8str + v5) = (v14 >> 18) | 0xF0;
            *(&v18 + v5) = (v14 >> 12) & 0x3F | 0x80;
            *(&v19 + v5) = (v14 >> 6) & 0x3F | 0x80;
            *(&v20 + v5) = v14 & 0x3F | 0x80;
            v5 += 4i64;
          }
        }
        else
        {
          *(&putf8str + v5) = (v14 >> 12) | 0xE0;
          *(&v18 + v5) = (v14 >> 6) & 0x3F | 0x80;
          *(&v19 + v5) = v14 & 0x3F | 0x80;
          v5 += 3i64;
        }
      }
      else
      {
        *(&putf8str + v5) = (v14 >> 6) | 0xC0;
        *(&v18 + v5) = v14 & 0x3F | 0x80;
        v5 += 2i64;
      }
    }
    else
    {
      *(&putf8str + v5++) = v14;
    }
    v15 = putf8Buffer;
    if ( (unsigned __int64)putf8Buffer >= v4 || v5 >= 504 )
    {
      Scaleform::String::AppendString(v2, &putf8str, v5);
      v5 = 0i64;
      if ( (unsigned __int64)v15 >= v4 )
        break;
    }
  }
  return v2;
}

// File Line: 535
// RVA: 0x961930
int __fastcall Scaleform::String::CompareNoCase(const char *a, const char *b)
{
  return stricmp(a, b);
}

// File Line: 540
// RVA: 0x961940
__int64 __fastcall Scaleform::String::CompareNoCase(const char *a, const char *b, __int64 len)
{
  __int64 v3; // r10
  const char *v4; // r11
  const char *v5; // rbx
  int v6; // er9
  int v7; // ecx
  signed __int64 v8; // rax
  __int64 result; // rax
  signed __int64 v10; // rax

  v3 = len;
  v4 = a;
  if ( len )
  {
    v5 = b;
    do
    {
      v6 = *v4;
      if ( (unsigned int)(v6 - 65) <= 0x19 )
        v6 += 32;
      v7 = *b;
      ++v4;
      if ( (unsigned int)(v7 - 65) <= 0x19 )
        v7 += 32;
      ++b;
      if ( !--v3 || !v6 )
        break;
      if ( v6 != (signed __int64)v7 )
        return (unsigned int)(v6 - v7);
    }
    while ( *b );
    if ( v6 != (signed __int64)v7 || !v3 && !*b )
      return (unsigned int)(v6 - v7);
    v8 = -1i64;
    do
      ++v8;
    while ( v5[v8] );
    result = (unsigned int)(len - v8);
  }
  else
  {
    v10 = -1i64;
    do
      ++v10;
    while ( b[v10] );
    result = (unsigned int)-(signed int)v10;
  }
  return result;
}

// File Line: 568
// RVA: 0x95AC20
unsigned __int64 __fastcall Scaleform::String::BernsteinHashFunction(const void *pdataIn, unsigned __int64 size, unsigned __int64 seed)
{
  __int64 v3; // rax
  unsigned __int64 result; // rax

  if ( !size )
    return seed;
  do
  {
    v3 = (unsigned __int8)*((char *)pdataIn + size-- - 1);
    result = 33 * seed ^ v3;
    seed = result;
  }
  while ( size );
  return result;
}

// File Line: 582
// RVA: 0x95AC50
unsigned __int64 __fastcall Scaleform::String::BernsteinHashFunctionCIS(const void *pdataIn, unsigned __int64 size, unsigned __int64 seed)
{
  unsigned __int64 i; // r9
  int v4; // eax

  for ( i = seed; size; i = v4 ^ 33 * i )
  {
    v4 = (unsigned __int8)*((char *)pdataIn + size-- - 1);
    if ( (unsigned int)(v4 - 65) <= 0x19 )
      v4 += 32;
  }
  return i;
}

// File Line: 599
// RVA: 0x971140
void __fastcall Scaleform::String::EscapeSpecialHTML(const char *psrc, unsigned __int64 length, Scaleform::String *pescapedStr)
{
  char *v3; // rdi
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rsi
  unsigned __int64 v6; // r14
  Scaleform::MemoryHeap *v7; // r15
  const char *v8; // r13
  unsigned int i; // eax
  unsigned __int64 v10; // r12
  signed __int64 v11; // rax
  char *v12; // rax
  unsigned __int64 v13; // r12
  signed __int64 v14; // rax
  char *v15; // rax
  unsigned __int64 v16; // r12
  signed __int64 v17; // rax
  char *v18; // rax
  unsigned __int64 v19; // r12
  signed __int64 v20; // rax
  char *v21; // rax
  unsigned __int64 v22; // r12
  signed __int64 v23; // rax
  char *v24; // rax
  Scaleform::StringBuffer src; // [rsp+28h] [rbp-38h]
  char *putf8Buffer; // [rsp+A0h] [rbp+40h]
  Scaleform::String *v27; // [rsp+B0h] [rbp+50h]

  v27 = pescapedStr;
  putf8Buffer = (char *)psrc;
  v3 = 0i64;
  src.pData = 0i64;
  v4 = 0i64;
  src.Size = 0i64;
  v5 = 0i64;
  src.BufferSize = 0i64;
  v6 = 512i64;
  src.GrowSize = 512i64;
  src.LengthIsSize = 0;
  v7 = Scaleform::Memory::pGlobalHeap;
  src.pHeap = Scaleform::Memory::pGlobalHeap;
  v8 = &psrc[length];
  for ( i = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
        putf8Buffer < v8;
        i = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer) )
  {
    switch ( i )
    {
      case 0x3Cu:
        v10 = v4;
        v4 += 4i64;
        if ( v4 >= v5 )
        {
          v11 = ~(v6 - 1);
          v5 = v11 & (v6 + v4);
          src.BufferSize = v11 & (v6 + v4);
          if ( v3 )
            v12 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v3, v5);
          else
            v12 = (char *)v7->vfptr->Alloc(v7, v5, 0i64);
          src.pData = v12;
          v3 = v12;
        }
        src.LengthIsSize = 0;
        src.Size = v4;
        if ( v3 )
          v3[v4] = 0;
        *(_DWORD *)&v3[v10] = *(_DWORD *)"&lt;";
        break;
      case 0x3Eu:
        v13 = v4;
        v4 += 4i64;
        if ( v4 >= v5 )
        {
          v14 = ~(v6 - 1);
          v5 = v14 & (v6 + v4);
          src.BufferSize = v14 & (v6 + v4);
          if ( v3 )
            v15 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v3, v5);
          else
            v15 = (char *)v7->vfptr->Alloc(v7, v5, 0i64);
          src.pData = v15;
          v3 = v15;
        }
        src.LengthIsSize = 0;
        src.Size = v4;
        if ( v3 )
          v3[v4] = 0;
        *(_DWORD *)&v3[v13] = *(_DWORD *)"&gt;";
        break;
      case 0x22u:
        v16 = v4;
        v4 += 6i64;
        if ( v4 >= v5 )
        {
          v17 = ~(v6 - 1);
          v5 = v17 & (v6 + v4);
          src.BufferSize = v17 & (v6 + v4);
          if ( v3 )
            v18 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v3, v5);
          else
            v18 = (char *)v7->vfptr->Alloc(v7, v5, 0i64);
          src.pData = v18;
          v3 = v18;
        }
        src.LengthIsSize = 0;
        src.Size = v4;
        if ( v3 )
          v3[v4] = 0;
        *(_DWORD *)&v3[v16] = *(_DWORD *)"&quot;";
        *(_WORD *)&v3[v16 + 4] = *(_WORD *)"t;";
        break;
      case 0x27u:
        v19 = v4;
        v4 += 6i64;
        if ( v4 >= v5 )
        {
          v20 = ~(v6 - 1);
          v5 = v20 & (v6 + v4);
          src.BufferSize = v20 & (v6 + v4);
          if ( v3 )
            v21 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v3, v5);
          else
            v21 = (char *)v7->vfptr->Alloc(v7, v5, 0i64);
          src.pData = v21;
          v3 = v21;
        }
        src.LengthIsSize = 0;
        src.Size = v4;
        if ( v3 )
          v3[v4] = 0;
        *(_DWORD *)&v3[v19] = *(_DWORD *)"&apos;";
        *(_WORD *)&v3[v19 + 4] = *(_WORD *)"s;";
        break;
      case 0x26u:
        v22 = v4;
        v4 += 5i64;
        if ( v4 >= v5 )
        {
          v23 = ~(v6 - 1);
          v5 = v23 & (v6 + v4);
          src.BufferSize = v23 & (v6 + v4);
          if ( v3 )
            v24 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v3, v5);
          else
            v24 = (char *)v7->vfptr->Alloc(v7, v5, 0i64);
          src.pData = v24;
          v3 = v24;
        }
        src.LengthIsSize = 0;
        src.Size = v4;
        if ( v3 )
          v3[v4] = 0;
        *(_DWORD *)&v3[v22] = *(_DWORD *)"&amp;";
        v3[v22 + 4] = to[4];
        break;
      default:
        Scaleform::StringBuffer::AppendChar(&src, i);
        v7 = src.pHeap;
        v6 = src.GrowSize;
        v5 = src.BufferSize;
        v4 = src.Size;
        v3 = src.pData;
        break;
    }
  }
  Scaleform::String::operator=(v27, &src);
  if ( v3 )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
}

// File Line: 635
// RVA: 0x9BB100
void __fastcall Scaleform::String::UnescapeSpecialHTML(const char *psrc, unsigned __int64 length, Scaleform::String *punescapedStr)
{
  Scaleform::String *v3; // r14
  char *v4; // rbx
  const char *v5; // rsi
  unsigned int v6; // eax
  char *v7; // rdi
  unsigned int v8; // edx
  unsigned __int64 v9; // rsi
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rdx
  unsigned __int64 v13; // rsi
  unsigned __int64 v14; // rdi
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // rdx
  unsigned __int64 v17; // rsi
  unsigned __int64 v18; // rdi
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rdx
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // rdi
  unsigned __int64 v23; // rax
  unsigned __int64 v24; // rdx
  unsigned __int64 v25; // rsi
  unsigned __int64 v26; // rdi
  unsigned __int64 v27; // rax
  unsigned __int64 v28; // rdx
  Scaleform::StringBuffer src; // [rsp+28h] [rbp-38h]
  char *putf8Buffer; // [rsp+80h] [rbp+20h]

  putf8Buffer = (char *)psrc;
  v3 = punescapedStr;
  v4 = 0i64;
  src.pData = 0i64;
  src.Size = 0i64;
  src.BufferSize = 0i64;
  src.GrowSize = 512i64;
  src.LengthIsSize = 0;
  src.pHeap = Scaleform::Memory::pGlobalHeap;
  v5 = &psrc[length];
  v6 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
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
      v21 = src.Size;
      v22 = src.Size + 1;
      if ( src.Size + 1 < src.BufferSize )
      {
        v4 = src.pData;
      }
      else
      {
        v23 = ~(src.GrowSize - 1);
        v24 = v23 & (src.GrowSize + v22);
        src.BufferSize = v23 & (src.GrowSize + v22);
        if ( src.pData )
          v4 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, src.pData, v24);
        else
          v4 = (char *)src.pHeap->vfptr->Alloc(src.pHeap, v24, 0i64);
        src.pData = v4;
      }
      src.LengthIsSize = 0;
      src.Size = v22;
      if ( v4 )
        v4[v22] = 0;
      v4[v21] = 39;
      goto LABEL_58;
    }
    if ( !strncmp(v7, "amp;", 4ui64) )
    {
      v17 = src.Size;
      v18 = src.Size + 1;
      if ( src.Size + 1 < src.BufferSize )
      {
        v4 = src.pData;
      }
      else
      {
        v19 = ~(src.GrowSize - 1);
        v20 = v19 & (src.GrowSize + v18);
        src.BufferSize = v19 & (src.GrowSize + v18);
        if ( src.pData )
          v4 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, src.pData, v20);
        else
          v4 = (char *)src.pHeap->vfptr->Alloc(src.pHeap, v20, 0i64);
        src.pData = v4;
      }
      src.LengthIsSize = 0;
      src.Size = v18;
      if ( v4 )
        v4[v18] = 0;
      v4[v17] = 38;
      goto LABEL_58;
    }
    if ( !strncmp(v7, "lt;", 3ui64) )
    {
      v13 = src.Size;
      v14 = src.Size + 1;
      if ( src.Size + 1 < src.BufferSize )
      {
        v4 = src.pData;
      }
      else
      {
        v15 = ~(src.GrowSize - 1);
        v16 = v15 & (src.GrowSize + v14);
        src.BufferSize = v15 & (src.GrowSize + v14);
        if ( src.pData )
          v4 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, src.pData, v16);
        else
          v4 = (char *)src.pHeap->vfptr->Alloc(src.pHeap, v16, 0i64);
        src.pData = v4;
      }
      src.LengthIsSize = 0;
      src.Size = v14;
      if ( v4 )
        v4[v14] = 0;
      v4[v13] = 60;
      goto LABEL_58;
    }
    if ( !strncmp(v7, "gt;", 3ui64) )
    {
      v9 = src.Size;
      v10 = src.Size + 1;
      if ( src.Size + 1 < src.BufferSize )
      {
        v4 = src.pData;
      }
      else
      {
        v11 = ~(src.GrowSize - 1);
        v12 = v11 & (src.GrowSize + v10);
        src.BufferSize = v11 & (src.GrowSize + v10);
        if ( src.pData )
          v4 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, src.pData, v12);
        else
          v4 = (char *)src.pHeap->vfptr->Alloc(src.pHeap, v12, 0i64);
        src.pData = v4;
      }
      src.LengthIsSize = 0;
      src.Size = v10;
      if ( v4 )
        v4[v10] = 0;
      v4[v9] = 62;
      goto LABEL_58;
    }
    v8 = 38;
LABEL_10:
    Scaleform::StringBuffer::AppendChar(&src, v8);
    v6 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    v7 = putf8Buffer;
    if ( putf8Buffer >= v5 )
    {
      v4 = src.pData;
      goto LABEL_58;
    }
  }
  v25 = src.Size;
  v26 = src.Size + 1;
  if ( src.Size + 1 < src.BufferSize )
  {
    v4 = src.pData;
  }
  else
  {
    v27 = ~(src.GrowSize - 1);
    v28 = v27 & (src.GrowSize + v26);
    src.BufferSize = v27 & (src.GrowSize + v26);
    if ( src.pData )
      v4 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, src.pData, v28);
    else
      v4 = (char *)src.pHeap->vfptr->Alloc(src.pHeap, v28, 0i64);
    src.pData = v4;
  }
  src.LengthIsSize = 0;
  src.Size = v26;
  if ( v4 )
    v4[v26] = 0;
  v4[v25] = 34;
LABEL_58:
  Scaleform::String::operator=(v3, &src);
  if ( v4 )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4);
}

// File Line: 688
// RVA: 0x944FC0
void __fastcall Scaleform::StringLH::StringLH(Scaleform::StringLH *this)
{
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  this->HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 1;
}

// File Line: 694
// RVA: 0x944F00
void __fastcall Scaleform::StringLH::StringLH(Scaleform::StringLH *this, const char *pdata)
{
  const char *v2; // rdi
  Scaleform::StringLH *v3; // r14
  size_t v4; // rbx
  Scaleform::MemoryHeap *v5; // rax
  __int64 v6; // rsi

  v2 = pdata;
  v3 = this;
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
    v6 = (__int64)v5->vfptr->Alloc(v5, v4 + 16, 0i64);
    *(_BYTE *)(v6 + v4 + 12) = 0;
    *(_DWORD *)(v6 + 8) = 1;
    *(_QWORD *)v6 = v4;
  }
  else
  {
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    v6 = (__int64)&Scaleform::String::NullData;
  }
  memmove((void *)(v6 + 12), v2, v4);
  v3->HeapTypeBits = v6 | 1;
}

// File Line: 714
// RVA: 0x964810
void __fastcall Scaleform::StringLH::CopyConstructHelper(Scaleform::StringLH *this, Scaleform::String *src)
{
  Scaleform::StringLH *v2; // rsi
  Scaleform::String *v3; // rdi
  unsigned __int64 v4; // rbx
  Scaleform::MemoryHeap *v5; // rbp
  Scaleform::MemoryHeap *v6; // rax

  v2 = this;
  v3 = src;
  v4 = src->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v5 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  v6 = 0i64;
  if ( (_QWORD)v3->pData & 3 )
  {
    if ( ((_QWORD)v3->pData & 3) == 1 )
    {
      v6 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v3);
    }
    else if ( ((_QWORD)v3->pData & 3) == 2 )
    {
      v6 = (Scaleform::MemoryHeap *)v3[1].pData;
    }
  }
  else
  {
    v6 = Scaleform::Memory::pGlobalHeap;
  }
  if ( v6 == v5 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 8), 1u);
    v2->HeapTypeBits = v4 | 1;
  }
  else
  {
    v2->HeapTypeBits = (unsigned __int64)Scaleform::String::AllocDataCopy1(
                                           (Scaleform::String *)&v2->0,
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
  this->HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
}

// File Line: 795
// RVA: 0x964730
void __fastcall Scaleform::StringDH::CopyConstructHelper(Scaleform::StringDH *this, Scaleform::String *src, Scaleform::MemoryHeap *pheap)
{
  Scaleform::MemoryHeap *v3; // rdi
  Scaleform::String::DataDesc *v4; // r9
  Scaleform::StringDH *v5; // rsi
  unsigned __int64 v6; // rbx
  __int64 v7; // r8

  v3 = pheap;
  v4 = 0i64;
  v5 = this;
  v6 = src->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( src->HeapTypeBits & 3 )
  {
    v7 = ((_QWORD)src->pData & 3) - 1;
    if ( ((_QWORD)src->pData & 3) == 1 )
    {
      v4 = (Scaleform::String::DataDesc *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::String *, __int64, _QWORD))Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap)(
                                            Scaleform::Memory::pGlobalHeap,
                                            src,
                                            v7,
                                            0i64);
    }
    else if ( (_DWORD)v7 == 1 )
    {
      v4 = src[1].pData;
    }
  }
  else
  {
    v4 = (Scaleform::String::DataDesc *)Scaleform::Memory::pGlobalHeap;
  }
  if ( !v3 )
    v3 = (Scaleform::MemoryHeap *)v4;
  v5->pHeap = v3;
  if ( v4 == (Scaleform::String::DataDesc *)v3 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 8), 1u);
    v5->HeapTypeBits = v6 | 2;
  }
  else
  {
    v5->HeapTypeBits = (unsigned __int64)Scaleform::String::AllocDataCopy1(
                                           (Scaleform::String *)&v5->0,
                                           v3,
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
void __fastcall Scaleform::StringBuffer::StringBuffer(Scaleform::StringBuffer *this, const char *data, Scaleform::MemoryHeap *pheap)
{
  const char *v3; // rdi
  Scaleform::StringBuffer *v4; // rsi
  unsigned __int64 v5; // rbx

  v3 = &customWorldMapCaption;
  if ( data )
    v3 = data;
  v4 = this;
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
  memmove(v4->pData, v3, v5);
}

// File Line: 854
// RVA: 0x944E80
void __fastcall Scaleform::StringBuffer::StringBuffer(Scaleform::StringBuffer *this, const char *data, unsigned __int64 dataSize, Scaleform::MemoryHeap *pheap)
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
  Scaleform::StringBuffer *v1; // rbx
  unsigned __int64 result; // rax

  v1 = this;
  if ( this->LengthIsSize )
    return this->Size;
  result = Scaleform::UTF8Util::GetLength(this->pData, this->Size);
  if ( result == v1->Size )
    v1->LengthIsSize = 1;
  return result;
}

// File Line: 919
// RVA: 0x9AC770
void __fastcall Scaleform::StringBuffer::Resize(Scaleform::StringBuffer *this, unsigned __int64 _size)
{
  unsigned __int64 v2; // rdi
  Scaleform::StringBuffer *v3; // rbx
  char *v4; // r9
  unsigned __int64 v5; // rdx
  char *v6; // rax
  char *v7; // rax

  v2 = _size;
  v3 = this;
  if ( _size >= this->BufferSize )
  {
    v4 = this->pData;
    v5 = ~(this->GrowSize - 1) & (this->GrowSize + _size);
    this->BufferSize = v5;
    if ( v4 )
      v6 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v4, v5);
    else
      v6 = (char *)this->pHeap->vfptr->Alloc(this->pHeap, v5, 0i64);
    v3->pData = v6;
  }
  v7 = v3->pData;
  v3->LengthIsSize = 0;
  v3->Size = v2;
  if ( v7 )
    v7[v2] = 0;
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
  unsigned __int64 v2; // rsi
  size_t v3; // rbx
  Scaleform::StringBuffer *v4; // rdi
  char Src; // [rsp+30h] [rbp+8h]
  char v6; // [rsp+31h] [rbp+9h]
  char v7; // [rsp+32h] [rbp+Ah]
  char v8; // [rsp+33h] [rbp+Bh]
  char v9; // [rsp+34h] [rbp+Ch]
  char v10; // [rsp+35h] [rbp+Dh]

  v2 = this->Size;
  v3 = 0i64;
  v4 = this;
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
  Scaleform::StringBuffer::Resize(this, v3 + v2);
  memmove(&v4->pData[v2], &Src, v3);
}

// File Line: 972
// RVA: 0x959410
void __fastcall Scaleform::StringBuffer::AppendString(Scaleform::StringBuffer *this, const char *putf8str, __int64 utf8StrSz)
{
  __int64 v3; // rbx
  const char *v4; // rsi
  Scaleform::StringBuffer *v5; // r14
  unsigned __int64 v6; // rdi

  if ( putf8str )
  {
    v3 = utf8StrSz;
    v4 = putf8str;
    v5 = this;
    if ( utf8StrSz )
    {
      if ( utf8StrSz == -1 )
      {
        v3 = -1i64;
        do
          ++v3;
        while ( putf8str[v3] );
      }
      v6 = this->Size;
      Scaleform::StringBuffer::Resize(this, v6 + v3);
      memmove(&v5->pData[v6], v4, v3);
    }
  }
}

// File Line: 1020
// RVA: 0x994720
void __fastcall Scaleform::StringBuffer::Insert(Scaleform::StringBuffer *this, const char *substr, unsigned __int64 posAt, __int64 len)
{
  unsigned __int64 v4; // rbp
  __int64 v5; // rbx
  unsigned __int64 v6; // r15
  const char *v7; // rsi
  Scaleform::StringBuffer *v8; // rdi
  unsigned __int64 v9; // r14
  char *v10; // r9
  signed __int64 v11; // rdx
  char *v12; // rax
  char *v13; // rax

  v4 = this->Size;
  v5 = len;
  v6 = posAt;
  v7 = substr;
  v8 = this;
  if ( len < 0 )
  {
    v5 = -1i64;
    do
      ++v5;
    while ( substr[v5] );
  }
  if ( !this->LengthIsSize )
    v6 = (unsigned __int64)Scaleform::UTF8Util::GetByteIndex(posAt, this->pData, this->Size);
  v9 = v5 + v4;
  if ( v5 + v4 >= v8->BufferSize )
  {
    v10 = v8->pData;
    v11 = ~(v8->GrowSize - 1) & (v8->GrowSize + v9);
    v8->BufferSize = v11;
    if ( v10 )
      v12 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v10, v11);
    else
      v12 = (char *)v8->pHeap->vfptr->Alloc(v8->pHeap, v11, 0i64);
    v8->pData = v12;
  }
  memmove(&v8->pData[v6 + v5], &v8->pData[v6], v4 - v6 + 1);
  memmove(&v8->pData[v6], v7, v5);
  v13 = v8->pData;
  v8->LengthIsSize = 0;
  v8->Size = v9;
  v13[v9] = 0;
}

// File Line: 1059
// RVA: 0x98E180
Scaleform::StringDataPtr *__fastcall Scaleform::StringDataPtr::GetTruncateWhitespace(Scaleform::StringDataPtr *this, Scaleform::StringDataPtr *result)
{
  const char *v2; // r15
  unsigned __int64 v3; // r12
  char v4; // r14
  const char *v5; // rsi
  char *v6; // rbx
  Scaleform::StringDataPtr *v7; // rdi
  const char *v8; // rbp
  signed __int64 v9; // r13
  int v10; // eax
  unsigned __int64 v11; // rcx
  int v12; // eax
  int v13; // edx
  unsigned int v14; // eax
  char *putf8Buffer; // [rsp+50h] [rbp+8h]

  v2 = this->pStr;
  v3 = this->Size;
  v4 = 0;
  v5 = &this->pStr[v3];
  v6 = (char *)v2;
  v7 = result;
  v8 = this->pStr;
  v9 = 3298534887423i64;
  putf8Buffer = (char *)this->pStr;
  if ( v2 < v5 )
  {
    while ( 1 )
    {
      v8 = v6;
      v10 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
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
      v12 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      v13 = v12;
      if ( v12 != 8287 )
      {
        v14 = v12 - 0x2000;
        if ( (v14 > 0x29 || !_bittest64(&v9, v14)) && v13 != 32 && (unsigned int)(v13 - 9) > 4 && v13 != 12288 )
          v6 = putf8Buffer;
      }
    }
    if ( v8 != v2 || v6 != v5 )
    {
      v7->pStr = v8;
      v7->Size = v6 - v8;
    }
    else
    {
      v7->pStr = v2;
      v7->Size = v3;
    }
  }
  else
  {
    v7->pStr = 0i64;
    v7->Size = 0i64;
  }
  return v7;
}

// File Line: 1101
// RVA: 0x97A3A0
unsigned __int64 __fastcall Scaleform::StringDataPtr::FindLastChar(Scaleform::StringDataPtr *this, char c, unsigned __int64 init_ind)
{
  unsigned __int64 v3; // r8

  if ( init_ind == -1i64 || init_ind > this->Size )
    v3 = this->Size;
  else
    v3 = init_ind + 1;
  if ( !v3 )
    return -1i64;
  while ( this->pStr[v3 - 1] != c )
  {
    if ( !--v3 )
      return -1i64;
  }
  return v3 - 1;
}

// File Line: 1142
// RVA: 0x98A1E0
Scaleform::StringDataPtr *__fastcall Scaleform::StringDataPtr::GetNextToken(Scaleform::StringDataPtr *this, Scaleform::StringDataPtr *result, char separator)
{
  unsigned __int64 v3; // r10
  const char *v4; // r9
  unsigned __int64 v5; // rax
  char v6; // cl

  v3 = this->Size;
  v4 = this->pStr;
  v5 = 0i64;
  if ( v3 )
  {
    do
    {
      v6 = v4[v5];
      if ( !v6 )
        break;
      if ( v6 == separator )
        break;
      ++v5;
    }
    while ( v5 < v3 );
  }
  result->Size = v5;
  result->pStr = v4;
  return result;
}

