// File Line: 56
// RVA: 0x9B5240
void __fastcall Scaleform::HeapPT::BitSet1::SetUsed(unsigned int *buf, unsigned __int64 start, unsigned __int64 num)
{
  unsigned __int64 v4; // r11
  unsigned int v5; // eax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // r8
  __int64 v8; // r11
  unsigned __int64 v9; // rax
  unsigned int *v10; // rdi
  unsigned __int64 i; // rcx

  v4 = start + num - 1;
  v5 = Scaleform::HeapPT::BitSet1::HeadUsedTable[start & 0x1F];
  v6 = start >> 5;
  v7 = v4 >> 5;
  v8 = v4 & 0x1F;
  if ( v7 <= start >> 5 )
  {
    buf[v6] |= Scaleform::HeapPT::BitSet1::TailUsedTable[v8] & v5;
  }
  else
  {
    buf[v6] |= v5;
    v9 = v6 + 1;
    if ( v6 + 1 < v7 )
    {
      v10 = &buf[v9];
      for ( i = v7 - v9; i; --i )
        *v10++ = -1;
    }
    buf[v7] |= Scaleform::HeapPT::BitSet1::TailUsedTable[v8];
  }
}

// File Line: 78
// RVA: 0x9B0600
void __fastcall Scaleform::HeapPT::BitSet1::SetFree(unsigned int *buf, unsigned __int64 start, unsigned __int64 num)
{
  unsigned __int64 v4; // r11
  unsigned int v5; // eax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // r8
  __int64 v8; // r11
  unsigned __int64 v9; // rax
  unsigned int *v10; // rdi
  unsigned __int64 i; // rcx

  v4 = start + num - 1;
  v5 = Scaleform::HeapPT::BitSet1::HeadFreeTable[start & 0x1F];
  v6 = start >> 5;
  v7 = v4 >> 5;
  v8 = v4 & 0x1F;
  if ( v7 <= start >> 5 )
  {
    buf[v6] &= Scaleform::HeapPT::BitSet1::TailFreeTable[v8] | v5;
  }
  else
  {
    buf[v6] &= v5;
    v9 = v6 + 1;
    if ( v6 + 1 < v7 )
    {
      v10 = &buf[v9];
      for ( i = v7 - v9; i; --i )
        *v10++ = 0;
    }
    buf[v7] &= Scaleform::HeapPT::BitSet1::TailFreeTable[v8];
  }
}

// File Line: 147
// RVA: 0x979C80
unsigned __int64 __fastcall Scaleform::HeapPT::BitSet1::FindFreeSize(const unsigned int *buf, unsigned __int64 start)
{
  unsigned __int64 v2; // r10
  unsigned int v3; // eax
  unsigned int v4; // r9d
  unsigned int v5; // r9d
  unsigned __int64 v9; // r8
  unsigned __int64 i; // rdx
  unsigned __int64 v11; // rcx
  __int64 v12; // rcx
  __int64 v13; // rcx

  v2 = start & 0x1F;
  v3 = Scaleform::HeapPT::BitSet1::HeadFreeTable[v2];
  v4 = v3 | buf[start >> 5];
  if ( v4 == v3 )
  {
    v9 = (start >> 5) + 1;
    for ( i = 32 - v2; !buf[v9]; i += 32i64 )
      ++v9;
    v11 = buf[v9];
    if ( (_WORD)v11 )
    {
      if ( (_BYTE)v11 )
        v12 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastFreeBlock[(unsigned __int8)v11];
      else
        v12 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastFreeBlock[BYTE1(v11)] + 8;
      return v12 + i;
    }
    else
    {
      if ( (v11 & 0xFF0000) != 0 )
        v13 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastFreeBlock[BYTE2(v11)] + 16;
      else
        v13 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastFreeBlock[v11 >> 24] + 24;
      return v13 + i;
    }
  }
  else
  {
    v5 = v4 >> v2;
    if ( (_WORD)v5 )
    {
      if ( (_BYTE)v5 )
        return (int)(unsigned __int8)Scaleform::HeapPT::BitSet1::LastFreeBlock[(unsigned __int8)v5];
      else
        return (unsigned __int8)Scaleform::HeapPT::BitSet1::LastFreeBlock[BYTE1(v5)] + 8;
    }
    else if ( (v5 & 0xFF0000) != 0 )
    {
      return (unsigned __int8)Scaleform::HeapPT::BitSet1::LastFreeBlock[BYTE2(v5)] + 16;
    }
    else
    {
      return (unsigned __int8)Scaleform::HeapPT::BitSet1::LastFreeBlock[(unsigned __int64)v5 >> 24] + 24;
    }
  }
}

