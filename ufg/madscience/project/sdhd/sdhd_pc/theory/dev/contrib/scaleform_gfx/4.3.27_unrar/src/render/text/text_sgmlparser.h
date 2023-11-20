// File Line: 65
// RVA: 0x94EF30
void __fastcall Scaleform::Render::Text::SGMLCharIter<wchar_t>::operator++(Scaleform::Render::Text::SGMLCharIter<wchar_t> *this)
{
  bool v1; // zf
  const wchar_t *v2; // rdx

  v1 = this->DoContentParsing == 0;
  v2 = this->pNextChar;
  this->pCurChar = v2;
  if ( !v1 )
    JUMPOUT(*v2, 38, Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar);
  if ( v2 < this->pEnd )
  {
    this->CurChar = *v2;
    this->pNextChar = v2 + 1;
  }
}

// File Line: 88
// RVA: 0x997DD0
bool __fastcall Scaleform::Render::Text::SGMLCharIter<wchar_t>::IsSpace(unsigned int c)
{
  unsigned __int64 v1; // rax
  int v2; // edx
  int v4; // edx

  v1 = (unsigned __int64)(unsigned __int16)c >> 8;
  v2 = Scaleform::UnicodeSpaceBits[v1];
  if ( !Scaleform::UnicodeSpaceBits[v1] )
    return 0;
  if ( v2 == 1 )
    return 1;
  v4 = Scaleform::UnicodeSpaceBits[v2 + (((unsigned int)(unsigned __int16)c >> 4) & 0xF)];
  return _bittest(&v4, c & 0xF) != 0;
}

// File Line: 117
// RVA: 0x96C110
__int64 __fastcall Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(Scaleform::Render::Text::SGMLCharIter<wchar_t> *this)
{
  const wchar_t *v1; // rax
  const wchar_t *v2; // r14
  Scaleform::Render::Text::SGMLCharIter<wchar_t> *v3; // rbx
  _WORD *v4; // r13
  signed __int64 v5; // r12
  signed __int64 v6; // r15
  const char *v7; // rsi
  wchar_t *v8; // rbp
  signed __int64 v9; // r14
  int v10; // eax
  int v11; // edi
  int v12; // eax
  signed __int64 v13; // r14
  const char *v14; // rsi
  wchar_t *v15; // rbp
  int v16; // eax
  int v17; // edi
  int v18; // eax
  const char *v19; // rsi
  wchar_t *v20; // rbp
  int v21; // eax
  int v22; // edi
  int v23; // eax
  signed __int64 v24; // r14
  const char *v25; // rsi
  wchar_t *v26; // rbp
  int v27; // eax
  int v28; // edi
  int v29; // eax
  signed __int64 v30; // r12
  signed __int64 v31; // r15
  const char *v32; // rsi
  wchar_t *v33; // rbp
  signed __int64 v34; // r14
  int v35; // eax
  int v36; // edi
  int v37; // eax
  const char *v38; // rsi
  wchar_t *v39; // rbp
  int v40; // eax
  int v41; // edi
  int v42; // eax
  int v43; // edi
  unsigned __int16 v44; // bp
  wchar_t v45; // cx
  wchar_t *v46; // rsi
  __int16 v47; // ax
  int v48; // eax
  wchar_t v49; // cx
  const wchar_t *v50; // rdx
  int v51; // ecx
  int v52; // edi
  const wchar_t *v53; // rax

  v1 = this->pCurChar;
  v2 = this->pEnd;
  v3 = this;
  if ( this->pCurChar < v2 )
  {
    this->pNextChar = v1;
    if ( *v1 != 38 )
      return v3->CurChar;
    v4 = v1 + 1;
    v5 = (signed __int64)(v1 + 6);
    this->CurChar = 38;
    this->pNextChar = v1 + 1;
    if ( v1 + 6 <= v2 )
    {
      v6 = 5i64;
      v7 = "quot;";
      v8 = (wchar_t *)(v1 + 1);
      v9 = 5i64;
      do
      {
        v10 = Scaleform::SFtowlower(*v8);
        ++v8;
        v11 = v10;
        v12 = Scaleform::SFtowlower(*v7++);
        if ( !--v9 || !v11 )
          break;
        if ( v11 != v12 )
          goto LABEL_12;
      }
      while ( *v7 );
      if ( v11 == v12 && (v9 || *v7) )
        goto LABEL_13;
LABEL_12:
      if ( v11 == v12 )
      {
LABEL_13:
        v3->CurChar = 34;
        v3->pNextChar = (const wchar_t *)v5;
        return v3->CurChar;
      }
      v13 = 5i64;
      v14 = "apos;";
      v15 = v4;
      do
      {
        v16 = Scaleform::SFtowlower(*v15);
        ++v15;
        v17 = v16;
        v18 = Scaleform::SFtowlower(*v14++);
        if ( !--v13 || !v17 )
          break;
        if ( v17 != v18 )
          goto LABEL_22;
      }
      while ( *v14 );
      if ( v17 == v18 && (v13 || *v14) )
      {
LABEL_23:
        v3->CurChar = 39;
        v3->pNextChar = (const wchar_t *)v5;
        return v3->CurChar;
      }
LABEL_22:
      if ( v17 == v18 )
        goto LABEL_23;
      v19 = "nbsp;";
      v20 = v4;
      do
      {
        v21 = Scaleform::SFtowlower(*v20);
        ++v20;
        v22 = v21;
        v23 = Scaleform::SFtowlower(*v19++);
        if ( !--v6 || !v22 )
          break;
        if ( v22 != v23 )
          goto LABEL_32;
      }
      while ( *v19 );
      if ( v22 == v23 && (v6 || *v19) )
      {
LABEL_33:
        v3->CurChar = 160;
        v3->pNextChar = (const wchar_t *)v5;
        return v3->CurChar;
      }
LABEL_32:
      if ( v22 == v23 )
        goto LABEL_33;
      v2 = v3->pEnd;
    }
    if ( v4 + 4 <= v2 )
    {
      v24 = 4i64;
      v25 = "amp;";
      v26 = v4;
      do
      {
        v27 = Scaleform::SFtowlower(*v26);
        ++v26;
        v28 = v27;
        v29 = Scaleform::SFtowlower(*v25++);
        if ( !--v24 || !v28 )
          break;
        if ( v28 != v29 )
          goto LABEL_44;
      }
      while ( *v25 );
      if ( v28 == v29 && (v24 || *v25) )
        goto LABEL_45;
LABEL_44:
      if ( v28 == v29 )
      {
LABEL_45:
        v3->CurChar = 38;
        v3->pNextChar = v4 + 4;
        return v3->CurChar;
      }
      v2 = v3->pEnd;
    }
    v30 = (signed __int64)(v4 + 3);
    if ( v4 + 3 <= v2 )
    {
      v31 = 3i64;
      v32 = "lt;";
      v33 = v4;
      v34 = 3i64;
      do
      {
        v35 = Scaleform::SFtowlower(*v33);
        ++v33;
        v36 = v35;
        v37 = Scaleform::SFtowlower(*v32++);
        if ( !--v34 || !v36 )
          break;
        if ( v36 != v37 )
          goto LABEL_56;
      }
      while ( *v32 );
      if ( v36 == v37 && (v34 || *v32) )
        goto LABEL_57;
LABEL_56:
      if ( v36 == v37 )
      {
LABEL_57:
        v3->CurChar = 60;
        v3->pNextChar = (const wchar_t *)v30;
        return v3->CurChar;
      }
      v38 = "gt;";
      v39 = v4;
      do
      {
        v40 = Scaleform::SFtowlower(*v39);
        ++v39;
        v41 = v40;
        v42 = Scaleform::SFtowlower(*v38++);
        if ( !--v31 || !v41 )
          break;
        if ( v41 != v42 )
          goto LABEL_66;
      }
      while ( *v38 );
      if ( v41 == v42 && (v31 || *v38) )
      {
LABEL_67:
        v3->CurChar = 62;
        v3->pNextChar = (const wchar_t *)v30;
        return v3->CurChar;
      }
LABEL_66:
      if ( v41 == v42 )
        goto LABEL_67;
      v2 = v3->pEnd;
    }
    if ( v4 + 2 > v2 || *v4 != 35 )
      return v3->CurChar;
    v43 = 0;
    v3->pNextChar = v4 + 1;
    v44 = v4[1];
    if ( Scaleform::SFtowlower(v44 == 120) )
    {
      v3->pNextChar = v4 + 2;
      if ( v4 + 2 < v2 )
      {
        while ( 1 )
        {
          v45 = *v3->pNextChar;
          if ( v45 == 59 )
            goto LABEL_87;
          if ( !isxdigit(v45) )
            goto LABEL_91;
          v46 = (wchar_t *)v3->pNextChar;
          v43 *= 16;
          v47 = Scaleform::SFtowlower(*v46);
          if ( (unsigned __int16)(v47 - 48) <= 9u )
            break;
          if ( (unsigned __int16)(v47 - 97) <= 5u )
          {
            v48 = (((_BYTE)v47 - 1) & 0xF) + 10;
            goto LABEL_79;
          }
LABEL_80:
          v3->pNextChar = v46 + 1;
          if ( v46 + 1 >= v3->pEnd )
            goto LABEL_87;
        }
        v48 = v47 & 0xF;
LABEL_79:
        v43 |= v48;
        goto LABEL_80;
      }
    }
    else
    {
      if ( !isdigit(v44) )
        goto LABEL_91;
      if ( v3->pNextChar < v3->pEnd )
      {
        do
        {
          v49 = *v3->pNextChar;
          if ( v49 == 59 )
            break;
          if ( !isdigit(v49) )
            goto LABEL_91;
          v50 = v3->pNextChar;
          v51 = 5 * v43;
          v52 = *v50 - 48;
          v3->pNextChar = v50 + 1;
          v43 = v52 + 2 * v51;
        }
        while ( v50 + 1 < v3->pEnd );
LABEL_87:
        if ( v43 == -1 )
        {
LABEL_91:
          v3->pNextChar = v4;
          return v3->CurChar;
        }
      }
    }
    v53 = v3->pNextChar;
    if ( *v53 == 59 )
      v3->pNextChar = v53 + 1;
    v3->CurChar = v43;
    return v3->CurChar;
  }
  return 0i64;
}

// File Line: 240
// RVA: 0x9B7B10
__int64 __fastcall Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(const wchar_t *wstr, const char *str, unsigned __int64 len)
{
  unsigned __int64 v3; // rsi
  const char *v4; // rbx
  wchar_t *v5; // rbp
  int v6; // er15
  const char *v7; // r14
  int v8; // eax
  int v9; // edi
  int v10; // eax
  signed __int64 v11; // rax
  __int64 result; // rax
  signed __int64 v13; // rax

  v3 = len;
  v4 = str;
  v5 = (wchar_t *)wstr;
  if ( len )
  {
    v6 = len;
    v7 = str;
    do
    {
      v8 = Scaleform::SFtowlower(*v5);
      ++v5;
      v9 = v8;
      v10 = Scaleform::SFtowlower(*v4++);
      if ( !--v3 || !v9 )
        break;
      if ( v9 != v10 )
        return (unsigned int)(v9 - v10);
    }
    while ( *v4 );
    if ( v9 != v10 || !v3 && !*v4 )
      return (unsigned int)(v9 - v10);
    v11 = -1i64;
    do
      ++v11;
    while ( v7[v11] );
    result = (unsigned int)(v6 - v11);
  }
  else
  {
    v13 = -1i64;
    do
      ++v13;
    while ( str[v13] );
    result = (unsigned int)-(signed int)v13;
  }
  return result;
}

// File Line: 266
// RVA: 0x9B7BD0
__int64 __fastcall Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(const wchar_t *dst, unsigned __int64 dstlen, const wchar_t *src, unsigned __int64 srclen)
{
  unsigned __int64 v4; // rdi
  wchar_t *v5; // rsi
  unsigned __int64 v6; // rbp
  int v7; // er15
  int v8; // er12
  signed __int64 v9; // r14
  int v10; // ebx
  int v11; // eax

  v4 = srclen;
  v5 = (wchar_t *)src;
  v6 = dstlen;
  if ( !dstlen )
    return (unsigned int)-(signed int)srclen;
  v7 = dstlen;
  v8 = srclen;
  v9 = (char *)dst - (char *)src;
  do
  {
    v10 = Scaleform::SFtowlower(*(wchar_t *)((char *)v5 + v9));
    v11 = Scaleform::SFtowlower(*v5);
    ++v5;
    if ( !--v6 || !v10 )
      break;
    if ( v10 != v11 )
      return (unsigned int)(v10 - v11);
    --v4;
  }
  while ( v4 );
  if ( v10 == v11 && (v6 || v4) )
    return (unsigned int)(v7 - v8);
  return (unsigned int)(v10 - v11);
}

// File Line: 353
// RVA: 0x948AF0
void __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::~SGMLParser<wchar_t>(Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pBuffer);
}

// File Line: 388
// RVA: 0x959DD0
void __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(Scaleform::Render::Text::SGMLParser<wchar_t> *this, const wchar_t *pstr, unsigned __int64 sz)
{
  Scaleform::Render::Text::SGMLParser<wchar_t> *v3; // rbx
  unsigned __int64 v4; // rcx
  unsigned __int64 v5; // rdi
  const wchar_t *v6; // rsi
  wchar_t *v7; // rdx
  unsigned __int64 v8; // r8
  wchar_t *v9; // rax

  v3 = this;
  v4 = this->BufSize;
  v5 = sz;
  v6 = pstr;
  if ( sz + v3->BufPos > v4 )
  {
    v7 = v3->pBuffer;
    v8 = v4 + sz;
    v3->BufSize = v8;
    if ( v7 )
      v9 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v7, 2 * v8);
    else
      v9 = (wchar_t *)v3->pHeap->vfptr->Alloc(v3->pHeap, 2 * v8, 0i64);
    v3->pBuffer = v9;
  }
  memmove(&v3->pBuffer[v3->BufPos], v6, 2 * v5);
  v3->BufPos += v5;
}

// File Line: 417
// RVA: 0x989A80
signed __int64 __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::GetNext(Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  signed __int64 result; // rax
  Scaleform::Render::Text::SGMLParser<wchar_t> *v2; // rdi
  bool v3; // zf
  const wchar_t *v4; // rcx
  const wchar_t *v5; // rcx
  unsigned int v6; // esi
  unsigned int v7; // eax
  const wchar_t *v8; // rcx
  unsigned int v9; // eax
  int v10; // eax
  const wchar_t *v11; // rcx
  const wchar_t *v12; // rcx

  result = (unsigned int)this->CurState;
  v2 = this;
  if ( (_DWORD)result != 1 )
  {
    if ( !_bittest((const signed int *)&result, 0xFu) )
    {
      switch ( (_DWORD)result )
      {
        case 2:
          Scaleform::Render::Text::SGMLParser<wchar_t>::SkipName(this);
          goto $LL34;
        case 3:
          if ( this->Iter.pCurChar < this->Iter.pEnd )
          {
            do
            {
              if ( v2->Iter.CurChar == 60 )
                break;
              v3 = v2->Iter.DoContentParsing == 0;
              v4 = v2->Iter.pNextChar;
              v2->Iter.pCurChar = v4;
              if ( v3 || *v4 != 38 )
              {
                if ( v4 < v2->Iter.pEnd )
                {
                  v2->Iter.CurChar = *v4;
                  v2->Iter.pNextChar = v4 + 1;
                }
              }
              else
              {
                Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v2->Iter);
              }
            }
            while ( v2->Iter.pCurChar < v2->Iter.pEnd );
          }
          v2->CurState = 32771;
          goto LABEL_29;
        case 4:
          if ( this->Iter.pCurChar >= this->Iter.pEnd )
            goto LABEL_26;
          break;
        case 7:
        case 8:
$LL34:
          while ( (unsigned int)(v2->CurState - 7) <= 1 )
            Scaleform::Render::Text::SGMLParser<wchar_t>::SkipAttribute(v2);
          goto $LN165_0;
        case 9:
$LN165_0:
          if ( v2->Iter.CurChar == 62 )
          {
            Scaleform::Render::Text::SGMLCharIter<wchar_t>::operator++(&v2->Iter);
            v2->CurState = 32770;
          }
          goto LABEL_29;
        default:
          goto LABEL_29;
      }
      do
      {
        if ( v2->Iter.CurChar == 62 )
          goto LABEL_27;
        v3 = v2->Iter.DoContentParsing == 0;
        v5 = v2->Iter.pNextChar;
        v2->Iter.pCurChar = v5;
        if ( v3 || *v5 != 38 )
        {
          if ( v5 < v2->Iter.pEnd )
          {
            v2->Iter.CurChar = *v5;
            v2->Iter.pNextChar = v5 + 1;
          }
        }
        else
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v2->Iter);
        }
      }
      while ( v2->Iter.pCurChar < v2->Iter.pEnd );
LABEL_26:
      if ( v2->Iter.CurChar == 62 )
      {
LABEL_27:
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::operator++(&v2->Iter);
        v2->CurState = 32772;
        goto LABEL_29;
      }
      v2->CurState = 1;
    }
LABEL_29:
    if ( v2->CurState == 1 )
      return 1i64;
    v6 = 0;
    if ( v2->Iter.pCurChar < v2->Iter.pEnd )
    {
      while ( 1 )
      {
        if ( v6 )
        {
LABEL_65:
          v2->CurState = v6;
          return v6;
        }
        v7 = v2->Iter.CurChar;
        if ( !v7 )
          goto LABEL_62;
        if ( v7 != 47 )
        {
          if ( v7 == 60 )
          {
            v3 = v2->Iter.DoContentParsing == 0;
            v8 = v2->Iter.pNextChar;
            v2->Iter.pCurChar = v8;
            if ( v3 || *v8 != 38 )
            {
              if ( v8 < v2->Iter.pEnd )
              {
                v2->Iter.CurChar = *v8;
                v2->Iter.pNextChar = v8 + 1;
              }
            }
            else
            {
              Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v2->Iter);
            }
            v9 = v2->Iter.CurChar;
            if ( v9 == 33 )
            {
              Scaleform::Render::Text::SGMLParser<wchar_t>::SkipComment(v2);
            }
            else if ( v9 == 47 )
            {
              Scaleform::Render::Text::SGMLCharIter<wchar_t>::operator++(&v2->Iter);
              v6 = 4;
            }
            else
            {
              v6 = 2;
            }
          }
          else
          {
            v6 = 3;
          }
          goto LABEL_63;
        }
        v10 = v2->CurState;
        if ( v10 == 9 || v10 == 6 )
          break;
        v6 = 3;
LABEL_63:
        if ( v2->Iter.pCurChar >= v2->Iter.pEnd )
        {
          if ( !v6 )
            goto LABEL_66;
          goto LABEL_65;
        }
      }
      v3 = v2->Iter.DoContentParsing == 0;
      v11 = v2->Iter.pNextChar;
      v2->Iter.pCurChar = v11;
      if ( v3 || *v11 != 38 )
      {
        if ( v11 < v2->Iter.pEnd )
        {
          v2->Iter.CurChar = *v11;
          v2->Iter.pNextChar = v11 + 1;
        }
      }
      else
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v2->Iter);
      }
      if ( v2->Iter.CurChar == 62 )
      {
        v3 = v2->Iter.DoContentParsing == 0;
        v12 = v2->Iter.pNextChar;
        v2->Iter.pCurChar = v12;
        if ( v3 || *v12 != 38 )
        {
          if ( v12 < v2->Iter.pEnd )
          {
            v2->Iter.CurChar = *v12;
            v2->Iter.pNextChar = v12 + 1;
          }
          v6 = 32773;
        }
        else
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v2->Iter);
          v6 = 32773;
        }
        goto LABEL_63;
      }
LABEL_62:
      v6 = 1;
      goto LABEL_63;
    }
LABEL_66:
    v2->CurState = 0x8000;
    result = (unsigned int)v2->CurState;
  }
  return result;
}

// File Line: 533
// RVA: 0x989D80
char __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(Scaleform::Render::Text::SGMLParser<wchar_t> *this, const wchar_t **ppattrName, unsigned __int64 *pattrNameSz)
{
  int v3; // eax
  unsigned __int64 *v4; // rbp
  const wchar_t **v5; // r14
  Scaleform::Render::Text::SGMLParser<wchar_t> *v6; // rdi
  char v8; // si
  unsigned int v9; // ecx
  unsigned __int64 v10; // rax
  int v11; // er8
  int v12; // ecx
  bool v13; // zf
  const wchar_t *v14; // rcx
  const wchar_t *v15; // rax

  v3 = this->CurState;
  v4 = pattrNameSz;
  v5 = ppattrName;
  v6 = this;
  if ( v3 == 1 )
    return 0;
  if ( v3 == 8 )
    Scaleform::Render::Text::SGMLParser<wchar_t>::SkipAttribute(this);
  v8 = 0;
  while ( v6->CurState == 7 )
  {
    if ( v6->Iter.pCurChar >= v6->Iter.pEnd )
      break;
    Scaleform::Render::Text::SGMLParser<wchar_t>::ParseName(v6, v5, v4);
    while ( v6->Iter.pCurChar < v6->Iter.pEnd )
    {
      v9 = v6->Iter.CurChar;
      v10 = (unsigned __int64)(unsigned __int16)v9 >> 8;
      v11 = Scaleform::UnicodeSpaceBits[v10];
      if ( !Scaleform::UnicodeSpaceBits[v10] )
        break;
      if ( v11 != 1 )
      {
        v12 = Scaleform::UnicodeSpaceBits[v11 + (((unsigned int)(unsigned __int16)v9 >> 4) & 0xF)];
        if ( !_bittest(&v12, v6->Iter.CurChar & 0xF) )
          break;
      }
      v13 = v6->Iter.DoContentParsing == 0;
      v14 = v6->Iter.pNextChar;
      v6->Iter.pCurChar = v14;
      if ( v13 || *v14 != 38 )
      {
        if ( v14 < v6->Iter.pEnd )
        {
          v6->Iter.CurChar = *v14;
          v6->Iter.pNextChar = v14 + 1;
        }
      }
      else
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v6->Iter);
      }
    }
    if ( v6->Iter.pCurChar < v6->Iter.pEnd )
    {
      if ( v6->Iter.CurChar == 61 )
      {
        v15 = v6->Iter.pNextChar;
        v6->Iter.pCurChar = v15;
        if ( v6->Iter.DoContentParsing && *v15 == 38 )
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v6->Iter);
        }
        else if ( v15 < v6->Iter.pEnd )
        {
          v6->Iter.CurChar = *v15;
          v6->Iter.pNextChar = v6->Iter.pCurChar + 1;
        }
        Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(v6);
        v6->CurState = 8;
        v8 = 1;
      }
      else
      {
        Scaleform::Render::Text::SGMLParser<wchar_t>::SkipAttribute(v6);
      }
    }
  }
  if ( v6->Iter.pCurChar >= v6->Iter.pEnd )
    v6->CurState = 1;
  return v8;
}

// File Line: 572
// RVA: 0x989F20
__int64 __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttributeValue(Scaleform::Render::Text::SGMLParser<wchar_t> *this, const wchar_t **ppattrValue, unsigned __int64 *pattrValueSz)
{
  unsigned __int8 v3; // r13
  const wchar_t **v4; // r12
  Scaleform::Render::Text::SGMLParser<wchar_t> *v5; // rdi
  unsigned __int64 *v6; // r14
  unsigned int v7; // er15
  bool v8; // zf
  const wchar_t *v9; // rcx
  char v10; // si
  bool v11; // al
  char *i; // rcx
  unsigned __int64 v13; // rcx
  unsigned int v14; // ebp
  wchar_t *v15; // rdx
  signed __int64 v16; // r8
  wchar_t *v17; // rax
  const wchar_t *v18; // rcx
  const wchar_t *v19; // rax
  unsigned int v20; // eax
  __int64 result; // rax

  v3 = 0;
  v4 = ppattrValue;
  v5 = this;
  v6 = pattrValueSz;
  if ( this->CurState == 8 )
  {
    v7 = this->Iter.CurChar;
    if ( v7 == 34 || v7 == 39 )
    {
      v8 = this->Iter.DoContentParsing == 0;
      v9 = this->Iter.pNextChar;
      v5->Iter.pCurChar = v9;
      if ( v8 || *v9 != 38 )
      {
        if ( v9 < v5->Iter.pEnd )
        {
          v5->Iter.CurChar = *v9;
          v5->Iter.pNextChar = v9 + 1;
        }
      }
      else
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v5->Iter);
      }
      v10 = 0;
      *v4 = v5->Iter.pCurChar;
      *v6 = 0i64;
      v11 = v5->Iter.DoContentParsing;
      v5->Iter.DoContentParsing = 1;
      if ( !v11 && *v5->Iter.pCurChar == 38 )
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v5->Iter);
      for ( i = (char *)v5->Iter.pCurChar; (const wchar_t *)i < v5->Iter.pEnd; i = (char *)v5->Iter.pCurChar )
      {
        if ( v5->Iter.CurChar == v7 )
          break;
        if ( v5->Iter.DoContentParsing && *(_WORD *)i == 38 )
        {
          if ( !v10 )
          {
            v5->BufPos = 0i64;
            Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(v5, *v4, *v6);
            v10 = 1;
          }
          v13 = v5->BufSize;
          v14 = v5->Iter.CurChar;
          if ( v5->BufPos + 6 > v13 )
          {
            v15 = v5->pBuffer;
            v16 = v13 + 6;
            v5->BufSize = v13 + 6;
            if ( v15 )
              v17 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                 Scaleform::Memory::pGlobalHeap,
                                 v15,
                                 2 * v16);
            else
              v17 = (wchar_t *)v5->pHeap->vfptr->Alloc(v5->pHeap, 2 * v16, 0i64);
            v5->pBuffer = v17;
          }
          v5->pBuffer[v5->BufPos++] = v14;
        }
        else if ( v10 )
        {
          Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(
            v5,
            v5->Iter.pCurChar,
            (unsigned int)((_QWORD)((char *)v5->Iter.pNextChar - i) >> 1));
        }
        else
        {
          *v6 += (unsigned int)((_QWORD)((char *)v5->Iter.pNextChar - i) >> 1);
        }
        v8 = v5->Iter.DoContentParsing == 0;
        v18 = v5->Iter.pNextChar;
        v5->Iter.pCurChar = v18;
        if ( v8 || *v18 != 38 )
        {
          if ( v18 < v5->Iter.pEnd )
          {
            v5->Iter.CurChar = *v18;
            v5->Iter.pNextChar = v18 + 1;
          }
        }
        else
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v5->Iter);
        }
      }
      v5->Iter.DoContentParsing = 0;
      if ( v10 )
      {
        *v4 = v5->pBuffer;
        *v6 = v5->BufPos;
      }
      if ( v5->Iter.pCurChar < v5->Iter.pEnd )
      {
        v19 = v5->Iter.pNextChar;
        v3 = 1;
        v5->Iter.pCurChar = v19;
        if ( v5->Iter.DoContentParsing && *v19 == 38 )
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v5->Iter);
        }
        else if ( v19 < v5->Iter.pEnd )
        {
          v5->Iter.CurChar = *v19;
          v5->Iter.pNextChar = v5->Iter.pCurChar + 1;
        }
        Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(v5);
        v20 = v5->Iter.CurChar;
        if ( v20 == 62 || v20 == 47 )
          v5->CurState = 9;
        else
          v5->CurState = 7;
      }
      else
      {
        v5->CurState = 1;
      }
    }
    else
    {
      this->CurState = 1;
    }
  }
  result = v3;
  if ( v5->Iter.pCurChar >= v5->Iter.pEnd )
    v5->CurState = 1;
  return result;
}

// File Line: 644
// RVA: 0x99E8A0
void __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::ParseName(Scaleform::Render::Text::SGMLParser<wchar_t> *this, const wchar_t **ppname, unsigned __int64 *plen)
{
  char v3; // si
  const wchar_t *v4; // r9
  unsigned __int64 *v5; // r14
  const wchar_t **v6; // r15
  Scaleform::Render::Text::SGMLParser<wchar_t> *v7; // rdi
  unsigned int v8; // ecx
  unsigned __int64 v9; // rax
  int v10; // er8
  int v11; // ecx
  unsigned __int64 v12; // rcx
  unsigned int v13; // ebp
  wchar_t *v14; // rdx
  signed __int64 v15; // r8
  wchar_t *v16; // rax
  const wchar_t *v17; // rcx

  v3 = 0;
  *ppname = this->Iter.pCurChar;
  *plen = 0i64;
  v4 = this->Iter.pCurChar;
  v5 = plen;
  v6 = ppname;
  v7 = this;
  if ( v4 < this->Iter.pEnd )
  {
    do
    {
      v8 = v7->Iter.CurChar;
      if ( v8 - 60 <= 2 )
        break;
      if ( v8 == 47 )
        break;
      v9 = (unsigned __int64)(unsigned __int16)v8 >> 8;
      v10 = Scaleform::UnicodeSpaceBits[v9];
      if ( Scaleform::UnicodeSpaceBits[v9] )
      {
        if ( v10 == 1 )
          break;
        v11 = Scaleform::UnicodeSpaceBits[v10 + (((unsigned int)(unsigned __int16)v8 >> 4) & 0xF)];
        if ( _bittest(&v11, v7->Iter.CurChar & 0xF) )
          break;
      }
      if ( v7->Iter.DoContentParsing && *v4 == 38 )
      {
        if ( !v3 )
        {
          v7->BufPos = 0i64;
          Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(v7, *v6, *v5);
          v3 = 1;
        }
        v12 = v7->BufSize;
        v13 = v7->Iter.CurChar;
        if ( v7->BufPos + 6 > v12 )
        {
          v14 = v7->pBuffer;
          v15 = v12 + 6;
          v7->BufSize = v12 + 6;
          if ( v14 )
            v16 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                               Scaleform::Memory::pGlobalHeap,
                               v14,
                               2 * v15);
          else
            v16 = (wchar_t *)v7->pHeap->vfptr->Alloc(v7->pHeap, 2 * v15, 0i64);
          v7->pBuffer = v16;
        }
        v7->pBuffer[v7->BufPos++] = v13;
      }
      else if ( v3 )
      {
        Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(
          v7,
          v7->Iter.pCurChar,
          (unsigned int)((_QWORD)((char *)v7->Iter.pNextChar - (char *)v4) >> 1));
      }
      else
      {
        *v5 += (unsigned int)((_QWORD)((char *)v7->Iter.pNextChar - (char *)v4) >> 1);
      }
      v17 = v7->Iter.pNextChar;
      v7->Iter.pCurChar = v17;
      if ( v7->Iter.DoContentParsing && *v17 == 38 )
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v7->Iter);
      }
      else if ( v17 < v7->Iter.pEnd )
      {
        v7->Iter.CurChar = *v17;
        v7->Iter.pNextChar = v17 + 1;
      }
      v4 = v7->Iter.pCurChar;
    }
    while ( v4 < v7->Iter.pEnd );
    if ( v3 )
    {
      *v6 = v7->pBuffer;
      *v5 = v7->BufPos;
    }
  }
}

// File Line: 737
// RVA: 0x99E090
bool __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::ParseContent(Scaleform::Render::Text::SGMLParser<wchar_t> *this, const wchar_t **ppContent, unsigned __int64 *pcontentSize)
{
  unsigned __int64 *v3; // r14
  const wchar_t **v4; // r12
  Scaleform::Render::Text::SGMLParser<wchar_t> *v5; // rbx
  char v6; // si
  bool v7; // al
  char *v8; // r8
  unsigned int v9; // ecx
  unsigned __int64 v10; // rax
  int v11; // er9
  int v12; // ecx
  unsigned __int64 v13; // rcx
  wchar_t *v14; // rdx
  signed __int64 v15; // r8
  wchar_t *v16; // rax
  unsigned __int64 v17; // rcx
  unsigned int v18; // ebp
  wchar_t *v19; // rdx
  signed __int64 v20; // r8
  wchar_t *v21; // rax
  __int64 v22; // rax
  const wchar_t *v23; // rcx
  const wchar_t *v24; // rax

  v3 = pcontentSize;
  v4 = ppContent;
  v5 = this;
  if ( this->CurState == 3 )
  {
    v6 = 0;
    *ppContent = this->Iter.pCurChar;
    *pcontentSize = 0i64;
    v7 = this->Iter.DoContentParsing;
    this->Iter.DoContentParsing = 1;
    if ( !v7 && *this->Iter.pCurChar == 38 )
      Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
    v8 = (char *)v5->Iter.pCurChar;
    if ( (const wchar_t *)v8 < v5->Iter.pEnd )
    {
      do
      {
        v9 = v5->Iter.CurChar;
        if ( v9 == 60 && (!v5->Iter.DoContentParsing || *(_WORD *)v8 != 38) )
          break;
        if ( (v10 = (unsigned __int64)(unsigned __int16)v9 >> 8, (v11 = Scaleform::UnicodeSpaceBits[v10]) != 0)
          && (v11 == 1
           || (v12 = Scaleform::UnicodeSpaceBits[v11 + (((unsigned int)(unsigned __int16)v9 >> 4) & 0xF)],
               _bittest(&v12, v5->Iter.CurChar & 0xF)))
          && v5->CondenseWhite )
        {
          if ( !v6 )
          {
            v5->BufPos = 0i64;
            Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(v5, *v4, *v3);
            v6 = 1;
          }
          v13 = v5->BufSize;
          if ( v5->BufPos + 6 > v13 )
          {
            v14 = v5->pBuffer;
            v15 = v13 + 6;
            v5->BufSize = v13 + 6;
            if ( v14 )
              v16 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                 Scaleform::Memory::pGlobalHeap,
                                 v14,
                                 2 * v15);
            else
              v16 = (wchar_t *)v5->pHeap->vfptr->Alloc(v5->pHeap, 2 * v15, 0i64);
            v5->pBuffer = v16;
          }
          v5->pBuffer[v5->BufPos++] = 32;
          Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(v5);
        }
        else
        {
          if ( v5->Iter.DoContentParsing && *(_WORD *)v8 == 38 )
          {
            if ( !v6 )
            {
              v5->BufPos = 0i64;
              Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(v5, *v4, *v3);
              v6 = 1;
            }
            v17 = v5->BufSize;
            v18 = v5->Iter.CurChar;
            if ( v5->BufPos + 6 > v17 )
            {
              v19 = v5->pBuffer;
              v20 = v17 + 6;
              v5->BufSize = v17 + 6;
              if ( v19 )
                v21 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                   Scaleform::Memory::pGlobalHeap,
                                   v19,
                                   2 * v20);
              else
                v21 = (wchar_t *)v5->pHeap->vfptr->Alloc(v5->pHeap, 2 * v20, 0i64);
              v5->pBuffer = v21;
            }
            v5->pBuffer[v5->BufPos++] = v18;
          }
          else
          {
            v22 = (_QWORD)((char *)v5->Iter.pNextChar - v8) >> 1;
            if ( v6 )
              Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(v5, v5->Iter.pCurChar, (unsigned int)v22);
            else
              *v3 += (unsigned int)v22;
          }
          v23 = v5->Iter.pNextChar;
          v5->Iter.pCurChar = v23;
          if ( v5->Iter.DoContentParsing && *v23 == 38 )
          {
            Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v5->Iter);
          }
          else if ( v23 < v5->Iter.pEnd )
          {
            v5->Iter.CurChar = *v23;
            v5->Iter.pNextChar = v23 + 1;
          }
        }
        v8 = (char *)v5->Iter.pCurChar;
      }
      while ( (const wchar_t *)v8 < v5->Iter.pEnd );
      if ( v6 )
      {
        *v4 = v5->pBuffer;
        *v3 = v5->BufPos;
      }
    }
    v24 = v5->Iter.pCurChar;
    if ( v24 < v5->Iter.pEnd && (v5->Iter.CurChar != 60 || v5->Iter.DoContentParsing && *v24 == 38) )
      v5->CurState = 1;
    else
      v5->CurState |= 0x8000u;
    v5->Iter.DoContentParsing = 0;
  }
  return v5->CurState != 1;
}

// File Line: 801
// RVA: 0x9B6790
void __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::SkipName(Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  Scaleform::Render::Text::SGMLParser<wchar_t> *v1; // rdi
  unsigned int v2; // ecx
  unsigned __int64 v3; // rax
  int v4; // er8
  int v5; // edx
  int v6; // ecx
  bool v7; // zf
  const wchar_t *v8; // rcx

  v1 = this;
  if ( this->CurState == 2 && this->Iter.pCurChar < this->Iter.pEnd )
  {
    do
    {
      v2 = v1->Iter.CurChar;
      if ( v2 - 60 <= 2 )
        break;
      if ( v2 == 47 )
        break;
      v3 = (unsigned __int64)(unsigned __int16)v2 >> 8;
      v4 = Scaleform::UnicodeSpaceBits[v3];
      if ( Scaleform::UnicodeSpaceBits[v3] )
      {
        if ( v4 == 1 )
          break;
        v5 = v2 & 0xF;
        v6 = Scaleform::UnicodeSpaceBits[v4 + (((unsigned int)(unsigned __int16)v2 >> 4) & 0xF)];
        if ( _bittest(&v6, v5) )
          break;
      }
      v7 = v1->Iter.DoContentParsing == 0;
      v8 = v1->Iter.pNextChar;
      v1->Iter.pCurChar = v8;
      if ( v7 || *v8 != 38 )
      {
        if ( v8 < v1->Iter.pEnd )
        {
          v1->Iter.CurChar = *v8;
          v1->Iter.pNextChar = v8 + 1;
        }
      }
      else
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v1->Iter);
      }
    }
    while ( v1->Iter.pCurChar < v1->Iter.pEnd );
  }
}

// File Line: 815
// RVA: 0x9B68C0
void __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  Scaleform::Render::Text::SGMLParser<wchar_t> *v1; // rdi
  unsigned int v2; // edx
  unsigned __int64 v3; // rax
  int v4; // er8
  int v5; // ecx
  bool v6; // zf
  const wchar_t *v7; // rcx

  v1 = this;
  while ( v1->Iter.pCurChar < v1->Iter.pEnd )
  {
    v2 = v1->Iter.CurChar;
    v3 = (unsigned __int64)(unsigned __int16)v2 >> 8;
    v4 = Scaleform::UnicodeSpaceBits[v3];
    if ( !Scaleform::UnicodeSpaceBits[v3] )
      break;
    if ( v4 != 1 )
    {
      v5 = Scaleform::UnicodeSpaceBits[v4 + (((unsigned int)(unsigned __int16)v2 >> 4) & 0xF)];
      if ( !_bittest(&v5, v1->Iter.CurChar & 0xF) )
        break;
    }
    v6 = v1->Iter.DoContentParsing == 0;
    v7 = v1->Iter.pNextChar;
    v1->Iter.pCurChar = v7;
    if ( v6 || *v7 != 38 )
    {
      if ( v7 < v1->Iter.pEnd )
      {
        v1->Iter.CurChar = *v7;
        v1->Iter.pNextChar = v7 + 1;
      }
    }
    else
    {
      Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v1->Iter);
    }
  }
}

// File Line: 824
// RVA: 0x9B6360
void __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::SkipAttribute(Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  Scaleform::Render::Text::SGMLParser<wchar_t> *v1; // rdi
  unsigned int v2; // er8
  unsigned __int64 v3; // rax
  int v4; // er9
  int v5; // ecx
  bool v6; // zf
  const wchar_t *v7; // rcx
  unsigned int v8; // eax
  const wchar_t *v9; // rax
  unsigned int v10; // esi
  const wchar_t *v11; // rcx
  const wchar_t *v12; // rax
  const wchar_t *v13; // rax
  unsigned int v14; // eax

  v1 = this;
  if ( this->CurState == 7 )
  {
    Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
    while ( v1->Iter.pCurChar < v1->Iter.pEnd )
    {
      v2 = v1->Iter.CurChar;
      v3 = (unsigned __int64)(unsigned __int16)v2 >> 8;
      v4 = Scaleform::UnicodeAlnumBits[v3];
      if ( !Scaleform::UnicodeAlnumBits[v3] )
        break;
      if ( v4 != 1 )
      {
        v5 = Scaleform::UnicodeAlnumBits[v4 + (((unsigned int)(unsigned __int16)v2 >> 4) & 0xF)];
        if ( !_bittest(&v5, v2 & 0xF) )
          break;
      }
      if ( v2 == 61 )
        break;
      v6 = v1->Iter.DoContentParsing == 0;
      v7 = v1->Iter.pNextChar;
      v1->Iter.pCurChar = v7;
      if ( v6 || *v7 != 38 )
      {
        if ( v7 < v1->Iter.pEnd )
        {
          v1->Iter.CurChar = *v7;
          v1->Iter.pNextChar = v7 + 1;
        }
      }
      else
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v1->Iter);
      }
    }
    if ( v1->Iter.pCurChar >= v1->Iter.pEnd )
    {
LABEL_14:
      v1->CurState = 1;
      return;
    }
    v8 = v1->Iter.CurChar;
    if ( v8 == 61 )
    {
      v9 = v1->Iter.pNextChar;
      v1->Iter.pCurChar = v9;
      if ( v1->Iter.DoContentParsing && *v9 == 38 )
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v1->Iter);
        Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(v1);
        v1->CurState = 8;
      }
      else
      {
        if ( v9 < v1->Iter.pEnd )
        {
          v1->Iter.CurChar = *v9;
          v1->Iter.pNextChar = v1->Iter.pCurChar + 1;
        }
        Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(v1);
        v1->CurState = 8;
      }
    }
    else if ( v8 == 47 || v8 == 62 )
    {
      v1->CurState = 9;
    }
    else
    {
      v1->CurState = 1;
    }
  }
  if ( v1->CurState == 8 )
  {
    v10 = v1->Iter.CurChar;
    if ( v10 == 34 || v10 == 39 )
    {
      while ( 1 )
      {
        v6 = v1->Iter.DoContentParsing == 0;
        v11 = v1->Iter.pNextChar;
        v1->Iter.pCurChar = v11;
        if ( v6 || *v11 != 38 )
        {
          if ( v11 < v1->Iter.pEnd )
          {
            v1->Iter.CurChar = *v11;
            v1->Iter.pNextChar = v11 + 1;
          }
        }
        else
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v1->Iter);
        }
        v12 = v1->Iter.pEnd;
        if ( v1->Iter.pCurChar >= v12 )
          break;
        if ( v1->Iter.CurChar == v10 )
        {
          if ( v1->Iter.pCurChar >= v12 )
            goto LABEL_14;
          v13 = v1->Iter.pNextChar;
          v1->Iter.pCurChar = v13;
          if ( v1->Iter.DoContentParsing && *v13 == 38 )
          {
            Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v1->Iter);
          }
          else if ( v13 < v1->Iter.pEnd )
          {
            v1->Iter.CurChar = *v13;
            v1->Iter.pNextChar = v1->Iter.pCurChar + 1;
          }
          Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(v1);
          v14 = v1->Iter.CurChar;
          if ( v14 == 62 || v14 == 47 )
            v1->CurState = 9;
          else
            v1->CurState = 7;
          return;
        }
      }
    }
    goto LABEL_14;
  }
}

// File Line: 880
// RVA: 0x9B66A0
void __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::SkipComment(Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  signed int v1; // edi
  Scaleform::Render::Text::SGMLParser<wchar_t> *v2; // rsi
  bool v3; // zf
  const wchar_t *v4; // rcx
  unsigned int v5; // eax
  const wchar_t *v6; // rax

  v1 = 0;
  v2 = this;
  while ( v2->Iter.pCurChar < v2->Iter.pEnd )
  {
    if ( !v2->Iter.CurChar || v1 == 3 )
      break;
    v3 = v2->Iter.DoContentParsing == 0;
    v4 = v2->Iter.pNextChar;
    v2->Iter.pCurChar = v4;
    if ( v3 || *v4 != 38 )
    {
      if ( v4 < v2->Iter.pEnd )
      {
        v2->Iter.CurChar = *v4;
        v2->Iter.pNextChar = v4 + 1;
      }
    }
    else
    {
      Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v2->Iter);
    }
    v5 = v2->Iter.CurChar;
    if ( v5 == 45 )
    {
      if ( v1 < 2 )
        ++v1;
    }
    else if ( v5 == 62 )
    {
      if ( v1 == 2 )
        v1 = 3;
    }
    else
    {
      v1 = 0;
    }
  }
  if ( v2->Iter.pCurChar < v2->Iter.pEnd && v1 == 3 )
  {
    v6 = v2->Iter.pNextChar;
    v2->Iter.pCurChar = v6;
    if ( v2->Iter.DoContentParsing && *v6 == 38 )
    {
      Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&v2->Iter);
    }
    else if ( v6 < v2->Iter.pEnd )
    {
      v2->Iter.CurChar = *v6;
      v2->Iter.pNextChar = v2->Iter.pCurChar + 1;
    }
  }
}

// File Line: 904
// RVA: 0x99E7F0
char __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(int *pdestVal, const wchar_t *pstr, unsigned __int64 len)
{
  unsigned __int64 v3; // rdi
  const wchar_t *v4; // rbx
  int *v5; // r15
  char result; // al
  int v7; // esi
  signed int v8; // er14
  unsigned __int64 v9; // rbp
  int v10; // eax

  v3 = len;
  v4 = pstr;
  v5 = pdestVal;
  if ( !len )
    return 0;
  v7 = 0;
  v8 = 1;
  if ( *pstr == 45 )
  {
    v8 = -1;
  }
  else if ( *pstr != 43 )
  {
    goto LABEL_7;
  }
  v4 = pstr + 1;
  v3 = len - 1;
LABEL_7:
  v9 = 0i64;
  if ( v3 )
  {
    while ( isdigit(*v4) )
    {
      v10 = *v4;
      ++v9;
      ++v4;
      v7 = v10 + 2 * (5 * v7 - 24);
      if ( v9 >= v3 )
        goto LABEL_10;
    }
    result = 0;
  }
  else
  {
LABEL_10:
    result = 1;
    *v5 = v7 * v8;
  }
  return result;
}

// File Line: 931
// RVA: 0x99E4D0
char __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::ParseHexInt(unsigned int *pdestVal, const wchar_t *pstr, unsigned __int64 len)
{
  unsigned __int64 v3; // rbp
  wchar_t *v4; // rdi
  unsigned int *v5; // r14
  unsigned int v7; // ebx
  unsigned __int64 v8; // rsi
  __int16 v9; // ax
  int v10; // eax

  v3 = len;
  v4 = (wchar_t *)pstr;
  v5 = pdestVal;
  if ( !len )
    return 0;
  v7 = 0;
  v8 = 0i64;
  if ( !len )
  {
LABEL_11:
    *v5 = v7;
    return 1;
  }
  while ( isxdigit(*v4) )
  {
    v7 *= 16;
    v9 = Scaleform::SFtowlower(*v4);
    if ( (unsigned __int16)(v9 - 48) <= 9u )
    {
      v10 = v9 & 0xF;
LABEL_9:
      v7 |= v10;
      goto LABEL_10;
    }
    if ( (unsigned __int16)(v9 - 97) <= 5u )
    {
      v10 = (((_BYTE)v9 - 1) & 0xF) + 10;
      goto LABEL_9;
    }
LABEL_10:
    ++v8;
    ++v4;
    if ( v8 >= v3 )
      goto LABEL_11;
  }
  return 0;
}

// File Line: 953
// RVA: 0x99E360
char __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::ParseFloat(float *pdestVal, const wchar_t *pstr, unsigned __int64 len)
{
  const wchar_t *v3; // rbx
  float *v4; // rsi
  char result; // al
  const wchar_t *v6; // rdi
  double v7; // xmm9_8
  double v8; // xmm7_8
  double v9; // xmm6_8
  int v10; // eax
  const wchar_t *v11; // rbx
  int v12; // eax
  float v13; // xmm0_4

  v3 = pstr;
  v4 = pdestVal;
  if ( !len )
    return 0;
  v6 = &pstr[len];
  v7 = DOUBLE_1_0;
  v8 = 0.0;
  v9 = 0.0;
  if ( *pstr == 45 )
  {
    v7 = DOUBLE_N1_0;
LABEL_6:
    v3 = pstr + 1;
    goto LABEL_7;
  }
  if ( *pstr == 43 )
    goto LABEL_6;
LABEL_7:
  if ( v3 < v6 )
  {
    while ( (*v3 - 44) & 0xFFFD )
    {
      if ( !isdigit(*v3) )
        return 0;
      v10 = *v3;
      ++v3;
      v9 = (double)(v10 - 48) + v9 * 10.0;
      if ( v3 >= v6 )
        goto LABEL_18;
    }
    if ( v3 < v6 && !((*v3 - 44) & 0xFFFD) )
    {
      v11 = v3 + 1;
      if ( v11 >= v6 )
      {
LABEL_17:
        v9 = v9 + v8;
        goto LABEL_18;
      }
      while ( isdigit(*v11) )
      {
        v12 = *v11;
        ++v11;
        v8 = ((double)(v12 - 48) + v8) * 0.1;
        if ( v11 >= v6 )
          goto LABEL_17;
      }
      return 0;
    }
  }
LABEL_18:
  result = 1;
  v13 = v7 * v9;
  *v4 = v13;
  return result;
}

