// File Line: 65
// RVA: 0x94EF30
void __fastcall Scaleform::Render::Text::SGMLCharIter<wchar_t>::operator++(
        Scaleform::Render::Text::SGMLCharIter<wchar_t> *this)
{
  bool v1; // zf
  const wchar_t *pNextChar; // rdx

  v1 = !this->DoContentParsing;
  pNextChar = this->pNextChar;
  this->pCurChar = pNextChar;
  if ( !v1 && *pNextChar == 38 )
  {
    Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(this);
  }
  else if ( pNextChar < this->pEnd )
  {
    this->CurChar = *pNextChar;
    this->pNextChar = pNextChar + 1;
  }
}

// File Line: 88
// RVA: 0x997DD0
bool __fastcall Scaleform::Render::Text::SGMLCharIter<wchar_t>::IsSpace(unsigned __int16 c)
{
  unsigned __int64 v1; // rax
  int v2; // edx
  int v4; // edx

  v1 = (unsigned __int64)c >> 8;
  v2 = Scaleform::UnicodeSpaceBits[v1];
  if ( !Scaleform::UnicodeSpaceBits[v1] )
    return 0;
  if ( v2 == 1 )
    return 1;
  v4 = Scaleform::UnicodeSpaceBits[v2 + ((c >> 4) & 0xF)];
  return _bittest(&v4, c & 0xF) != 0;
}

// File Line: 117
// RVA: 0x96C110
__int64 __fastcall Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(
        Scaleform::Render::Text::SGMLCharIter<wchar_t> *this)
{
  const wchar_t *pCurChar; // rax
  const wchar_t *pEnd; // r14
  const wchar_t *v4; // r13
  const wchar_t *v5; // r12
  __int64 v6; // r15
  const char *v7; // rsi
  wchar_t *v8; // rbp
  __int64 v9; // r14
  int v10; // eax
  int v11; // edi
  int v12; // eax
  __int64 v13; // r14
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
  __int64 v24; // r14
  const char *v25; // rsi
  wchar_t *v26; // rbp
  int v27; // eax
  int v28; // edi
  int v29; // eax
  const wchar_t *v30; // r12
  __int64 v31; // r15
  const char *v32; // rsi
  wchar_t *v33; // rbp
  __int64 v34; // r14
  int v35; // eax
  int v36; // edi
  int v37; // eax
  const char *v38; // rsi
  wchar_t *v39; // rbp
  int v40; // eax
  int v41; // edi
  int v42; // eax
  unsigned int v43; // edi
  wchar_t v44; // bp
  wchar_t v45; // cx
  const wchar_t *pNextChar; // rsi
  __int16 v47; // ax
  int v48; // eax
  wchar_t v49; // cx
  const wchar_t *v50; // rdx
  int v51; // ecx
  int v52; // edi
  const wchar_t *v53; // rax

  pCurChar = this->pCurChar;
  pEnd = this->pEnd;
  if ( this->pCurChar < pEnd )
  {
    this->pNextChar = pCurChar;
    if ( *pCurChar != 38 )
      return this->CurChar;
    v4 = pCurChar + 1;
    v5 = pCurChar + 6;
    this->CurChar = 38;
    this->pNextChar = pCurChar + 1;
    if ( pCurChar + 6 <= pEnd )
    {
      v6 = 5i64;
      v7 = "quot;";
      v8 = (wchar_t *)(pCurChar + 1);
      v9 = 5i64;
      do
      {
        v10 = Scaleform::SFtowlower(*v8++);
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
        this->CurChar = 34;
        this->pNextChar = v5;
        return this->CurChar;
      }
      v13 = 5i64;
      v14 = "apos;";
      v15 = (wchar_t *)v4;
      do
      {
        v16 = Scaleform::SFtowlower(*v15++);
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
        this->CurChar = 39;
        this->pNextChar = v5;
        return this->CurChar;
      }
LABEL_22:
      if ( v17 == v18 )
        goto LABEL_23;
      v19 = "nbsp;";
      v20 = (wchar_t *)v4;
      do
      {
        v21 = Scaleform::SFtowlower(*v20++);
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
        this->CurChar = 160;
        this->pNextChar = v5;
        return this->CurChar;
      }
LABEL_32:
      if ( v22 == v23 )
        goto LABEL_33;
      pEnd = this->pEnd;
    }
    if ( v4 + 4 <= pEnd )
    {
      v24 = 4i64;
      v25 = "amp;";
      v26 = (wchar_t *)v4;
      do
      {
        v27 = Scaleform::SFtowlower(*v26++);
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
        this->CurChar = 38;
        this->pNextChar = v4 + 4;
        return this->CurChar;
      }
      pEnd = this->pEnd;
    }
    v30 = v4 + 3;
    if ( v4 + 3 <= pEnd )
    {
      v31 = 3i64;
      v32 = "lt;";
      v33 = (wchar_t *)v4;
      v34 = 3i64;
      do
      {
        v35 = Scaleform::SFtowlower(*v33++);
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
        this->CurChar = 60;
        this->pNextChar = v30;
        return this->CurChar;
      }
      v38 = "gt;";
      v39 = (wchar_t *)v4;
      do
      {
        v40 = Scaleform::SFtowlower(*v39++);
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
        this->CurChar = 62;
        this->pNextChar = v30;
        return this->CurChar;
      }
LABEL_66:
      if ( v41 == v42 )
        goto LABEL_67;
      pEnd = this->pEnd;
    }
    if ( v4 + 2 > pEnd || *v4 != 35 )
      return this->CurChar;
    v43 = 0;
    this->pNextChar = v4 + 1;
    v44 = v4[1];
    if ( Scaleform::SFtowlower(v44 == 120) )
    {
      this->pNextChar = v4 + 2;
      if ( v4 + 2 < pEnd )
      {
        while ( 1 )
        {
          v45 = *this->pNextChar;
          if ( v45 == 59 )
            goto LABEL_87;
          if ( !isxdigit(v45) )
            goto LABEL_91;
          pNextChar = this->pNextChar;
          v43 *= 16;
          v47 = Scaleform::SFtowlower(*pNextChar);
          if ( (unsigned __int16)(v47 - 48) <= 9u )
            break;
          if ( (unsigned __int16)(v47 - 97) <= 5u )
          {
            v48 = (((_BYTE)v47 - 1) & 0xF) + 10;
            goto LABEL_79;
          }
LABEL_80:
          this->pNextChar = pNextChar + 1;
          if ( pNextChar + 1 >= this->pEnd )
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
      if ( this->pNextChar < this->pEnd )
      {
        do
        {
          v49 = *this->pNextChar;
          if ( v49 == 59 )
            break;
          if ( !isdigit(v49) )
            goto LABEL_91;
          v50 = this->pNextChar;
          v51 = 5 * v43;
          v52 = *v50 - 48;
          this->pNextChar = v50 + 1;
          v43 = v52 + 2 * v51;
        }
        while ( v50 + 1 < this->pEnd );
LABEL_87:
        if ( v43 == -1 )
        {
LABEL_91:
          this->pNextChar = v4;
          return this->CurChar;
        }
      }
    }
    v53 = this->pNextChar;
    if ( *v53 == 59 )
      this->pNextChar = v53 + 1;
    this->CurChar = v43;
    return this->CurChar;
  }
  return 0i64;
}

// File Line: 240
// RVA: 0x9B7B10
__int64 __fastcall Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(
        wchar_t *wstr,
        const char *str,
        unsigned __int64 len)
{
  unsigned __int64 v3; // rsi
  const char *v4; // rbx
  int v6; // r15d
  int v8; // eax
  int v9; // edi
  int v10; // eax
  __int64 v11; // rax
  __int64 v13; // rax

  v3 = len;
  v4 = str;
  if ( len )
  {
    v6 = len;
    do
    {
      v8 = Scaleform::SFtowlower(*wstr++);
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
    while ( str[v11] );
    return (unsigned int)(v6 - v11);
  }
  else
  {
    v13 = -1i64;
    do
      ++v13;
    while ( str[v13] );
    return (unsigned int)-(int)v13;
  }
}

// File Line: 266
// RVA: 0x9B7BD0
__int64 __fastcall Scaleform::Render::Text::SGMLCharIter<wchar_t>::StrCompare(
        const wchar_t *dst,
        unsigned __int64 dstlen,
        wchar_t *src,
        unsigned __int64 srclen)
{
  unsigned __int64 v4; // rdi
  wchar_t *v5; // rsi
  unsigned __int64 v6; // rbp
  int v7; // r15d
  int v8; // r12d
  signed __int64 v9; // r14
  int v10; // ebx
  int v11; // eax

  v4 = srclen;
  v5 = src;
  v6 = dstlen;
  if ( !dstlen )
    return (unsigned int)-(int)srclen;
  v7 = dstlen;
  v8 = srclen;
  v9 = (char *)dst - (char *)src;
  do
  {
    v10 = Scaleform::SFtowlower(*(wchar_t *)((char *)v5 + v9));
    v11 = Scaleform::SFtowlower(*v5++);
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
void __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::~SGMLParser<wchar_t>(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pBuffer);
}

// File Line: 388
// RVA: 0x959DD0
void __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this,
        const wchar_t *pstr,
        unsigned __int64 sz)
{
  unsigned __int64 BufSize; // rcx
  wchar_t *pBuffer; // rdx
  unsigned __int64 v8; // r8
  wchar_t *v9; // rax

  BufSize = this->BufSize;
  if ( sz + this->BufPos > BufSize )
  {
    pBuffer = this->pBuffer;
    v8 = BufSize + sz;
    this->BufSize = v8;
    if ( pBuffer )
      v9 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, pBuffer, 2 * v8);
    else
      v9 = (wchar_t *)this->pHeap->vfptr->Alloc(this->pHeap, 2 * v8, 0i64);
    this->pBuffer = v9;
  }
  memmove(&this->pBuffer[this->BufPos], pstr, 2 * sz);
  this->BufPos += sz;
}

// File Line: 417
// RVA: 0x989A80
__int64 __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::GetNext(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  __int64 result; // rax
  bool v3; // zf
  const wchar_t *pNextChar; // rcx
  const wchar_t *v5; // rcx
  unsigned int v6; // esi
  unsigned int CurChar; // eax
  const wchar_t *v8; // rcx
  unsigned int v9; // eax
  int CurState; // eax
  const wchar_t *v11; // rcx
  const wchar_t *v12; // rcx

  result = (unsigned int)this->CurState;
  if ( (_DWORD)result != 1 )
  {
    if ( (result & 0x8000) == 0 )
    {
      switch ( (int)result )
      {
        case 2:
          Scaleform::Render::Text::SGMLParser<wchar_t>::SkipName(this);
          goto $LL34;
        case 3:
          while ( this->Iter.pCurChar < this->Iter.pEnd )
          {
            if ( this->Iter.CurChar == 60 )
              break;
            v3 = !this->Iter.DoContentParsing;
            pNextChar = this->Iter.pNextChar;
            this->Iter.pCurChar = pNextChar;
            if ( v3 || *pNextChar != 38 )
            {
              if ( pNextChar < this->Iter.pEnd )
              {
                this->Iter.CurChar = *pNextChar;
                this->Iter.pNextChar = pNextChar + 1;
              }
            }
            else
            {
              Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
            }
          }
          this->CurState = 32771;
          goto LABEL_29;
        case 4:
          if ( this->Iter.pCurChar >= this->Iter.pEnd )
            goto LABEL_26;
          break;
        case 7:
        case 8:
$LL34:
          while ( (unsigned int)(this->CurState - 7) <= 1 )
            Scaleform::Render::Text::SGMLParser<wchar_t>::SkipAttribute(this);
          goto $LN165_0;
        case 9:
$LN165_0:
          if ( this->Iter.CurChar == 62 )
          {
            Scaleform::Render::Text::SGMLCharIter<wchar_t>::operator++(&this->Iter);
            this->CurState = 32770;
          }
          goto LABEL_29;
        default:
          goto LABEL_29;
      }
      do
      {
        if ( this->Iter.CurChar == 62 )
          goto LABEL_27;
        v3 = !this->Iter.DoContentParsing;
        v5 = this->Iter.pNextChar;
        this->Iter.pCurChar = v5;
        if ( v3 || *v5 != 38 )
        {
          if ( v5 < this->Iter.pEnd )
          {
            this->Iter.CurChar = *v5;
            this->Iter.pNextChar = v5 + 1;
          }
        }
        else
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
        }
      }
      while ( this->Iter.pCurChar < this->Iter.pEnd );
LABEL_26:
      if ( this->Iter.CurChar == 62 )
      {
LABEL_27:
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::operator++(&this->Iter);
        this->CurState = 32772;
        goto LABEL_29;
      }
      this->CurState = 1;
    }
LABEL_29:
    if ( this->CurState == 1 )
      return 1i64;
    v6 = 0;
    if ( this->Iter.pCurChar < this->Iter.pEnd )
    {
      while ( 1 )
      {
        if ( v6 )
        {
LABEL_65:
          this->CurState = v6;
          return v6;
        }
        CurChar = this->Iter.CurChar;
        if ( !CurChar )
          goto LABEL_62;
        if ( CurChar != 47 )
        {
          if ( CurChar == 60 )
          {
            v3 = !this->Iter.DoContentParsing;
            v8 = this->Iter.pNextChar;
            this->Iter.pCurChar = v8;
            if ( v3 || *v8 != 38 )
            {
              if ( v8 < this->Iter.pEnd )
              {
                this->Iter.CurChar = *v8;
                this->Iter.pNextChar = v8 + 1;
              }
            }
            else
            {
              Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
            }
            v9 = this->Iter.CurChar;
            if ( v9 == 33 )
            {
              Scaleform::Render::Text::SGMLParser<wchar_t>::SkipComment(this);
            }
            else if ( v9 == 47 )
            {
              Scaleform::Render::Text::SGMLCharIter<wchar_t>::operator++(&this->Iter);
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
        CurState = this->CurState;
        if ( CurState == 9 || CurState == 6 )
          break;
        v6 = 3;
LABEL_63:
        if ( this->Iter.pCurChar >= this->Iter.pEnd )
        {
          if ( !v6 )
            goto LABEL_66;
          goto LABEL_65;
        }
      }
      v3 = !this->Iter.DoContentParsing;
      v11 = this->Iter.pNextChar;
      this->Iter.pCurChar = v11;
      if ( v3 || *v11 != 38 )
      {
        if ( v11 < this->Iter.pEnd )
        {
          this->Iter.CurChar = *v11;
          this->Iter.pNextChar = v11 + 1;
        }
      }
      else
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
      }
      if ( this->Iter.CurChar == 62 )
      {
        v3 = !this->Iter.DoContentParsing;
        v12 = this->Iter.pNextChar;
        this->Iter.pCurChar = v12;
        if ( v3 || *v12 != 38 )
        {
          if ( v12 < this->Iter.pEnd )
          {
            this->Iter.CurChar = *v12;
            this->Iter.pNextChar = v12 + 1;
          }
          v6 = 32773;
        }
        else
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
          v6 = 32773;
        }
        goto LABEL_63;
      }
LABEL_62:
      v6 = 1;
      goto LABEL_63;
    }
LABEL_66:
    this->CurState = 0x8000;
    return (unsigned int)this->CurState;
  }
  return result;
}

// File Line: 533
// RVA: 0x989D80
char __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttribute(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this,
        const wchar_t **ppattrName,
        unsigned __int64 *pattrNameSz)
{
  int CurState; // eax
  char v8; // si
  unsigned int CurChar; // ecx
  unsigned __int64 v10; // rax
  int v11; // r8d
  int v12; // ecx
  bool v13; // zf
  const wchar_t *pNextChar; // rcx
  const wchar_t *v15; // rax

  CurState = this->CurState;
  if ( CurState == 1 )
    return 0;
  if ( CurState == 8 )
    Scaleform::Render::Text::SGMLParser<wchar_t>::SkipAttribute(this);
  v8 = 0;
  while ( this->CurState == 7 )
  {
    if ( this->Iter.pCurChar >= this->Iter.pEnd )
      break;
    Scaleform::Render::Text::SGMLParser<wchar_t>::ParseName(this, ppattrName, pattrNameSz);
    while ( this->Iter.pCurChar < this->Iter.pEnd )
    {
      CurChar = this->Iter.CurChar;
      v10 = (unsigned __int64)(unsigned __int16)CurChar >> 8;
      v11 = Scaleform::UnicodeSpaceBits[v10];
      if ( !Scaleform::UnicodeSpaceBits[v10] )
        break;
      if ( v11 != 1 )
      {
        v12 = Scaleform::UnicodeSpaceBits[v11 + (((unsigned __int16)CurChar >> 4) & 0xF)];
        if ( !_bittest(&v12, this->Iter.CurChar & 0xF) )
          break;
      }
      v13 = !this->Iter.DoContentParsing;
      pNextChar = this->Iter.pNextChar;
      this->Iter.pCurChar = pNextChar;
      if ( v13 || *pNextChar != 38 )
      {
        if ( pNextChar < this->Iter.pEnd )
        {
          this->Iter.CurChar = *pNextChar;
          this->Iter.pNextChar = pNextChar + 1;
        }
      }
      else
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
      }
    }
    if ( this->Iter.pCurChar < this->Iter.pEnd )
    {
      if ( this->Iter.CurChar == 61 )
      {
        v15 = this->Iter.pNextChar;
        this->Iter.pCurChar = v15;
        if ( this->Iter.DoContentParsing && *v15 == 38 )
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
        }
        else if ( v15 < this->Iter.pEnd )
        {
          this->Iter.CurChar = *v15;
          this->Iter.pNextChar = this->Iter.pCurChar + 1;
        }
        Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
        this->CurState = 8;
        v8 = 1;
      }
      else
      {
        Scaleform::Render::Text::SGMLParser<wchar_t>::SkipAttribute(this);
      }
    }
  }
  if ( this->Iter.pCurChar >= this->Iter.pEnd )
    this->CurState = 1;
  return v8;
}

// File Line: 572
// RVA: 0x989F20
__int64 __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::GetNextAttributeValue(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this,
        const wchar_t **ppattrValue,
        unsigned __int64 *pattrValueSz)
{
  unsigned __int8 v3; // r13
  unsigned int CurChar; // r15d
  bool v8; // zf
  const wchar_t *pNextChar; // rcx
  char v10; // si
  bool DoContentParsing; // al
  const wchar_t *i; // rcx
  unsigned __int64 BufSize; // rcx
  unsigned int v14; // ebp
  wchar_t *pBuffer; // rdx
  unsigned __int64 v16; // r8
  wchar_t *v17; // rax
  const wchar_t *v18; // rcx
  const wchar_t *v19; // rax
  unsigned int v20; // eax
  __int64 result; // rax

  v3 = 0;
  if ( this->CurState == 8 )
  {
    CurChar = this->Iter.CurChar;
    if ( CurChar == 34 || CurChar == 39 )
    {
      v8 = !this->Iter.DoContentParsing;
      pNextChar = this->Iter.pNextChar;
      this->Iter.pCurChar = pNextChar;
      if ( v8 || *pNextChar != 38 )
      {
        if ( pNextChar < this->Iter.pEnd )
        {
          this->Iter.CurChar = *pNextChar;
          this->Iter.pNextChar = pNextChar + 1;
        }
      }
      else
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
      }
      v10 = 0;
      *ppattrValue = this->Iter.pCurChar;
      *pattrValueSz = 0i64;
      DoContentParsing = this->Iter.DoContentParsing;
      this->Iter.DoContentParsing = 1;
      if ( !DoContentParsing && *this->Iter.pCurChar == 38 )
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
      for ( i = this->Iter.pCurChar; i < this->Iter.pEnd; i = this->Iter.pCurChar )
      {
        if ( this->Iter.CurChar == CurChar )
          break;
        if ( this->Iter.DoContentParsing && *i == 38 )
        {
          if ( !v10 )
          {
            this->BufPos = 0i64;
            Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(this, *ppattrValue, *pattrValueSz);
            v10 = 1;
          }
          BufSize = this->BufSize;
          v14 = this->Iter.CurChar;
          if ( this->BufPos + 6 > BufSize )
          {
            pBuffer = this->pBuffer;
            v16 = BufSize + 6;
            this->BufSize = BufSize + 6;
            if ( pBuffer )
              v17 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                 Scaleform::Memory::pGlobalHeap,
                                 pBuffer,
                                 2 * v16);
            else
              v17 = (wchar_t *)this->pHeap->vfptr->Alloc(this->pHeap, 2 * v16, 0i64);
            this->pBuffer = v17;
          }
          this->pBuffer[this->BufPos++] = v14;
        }
        else if ( v10 )
        {
          Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(
            this,
            this->Iter.pCurChar,
            (unsigned int)(this->Iter.pNextChar - i));
        }
        else
        {
          *pattrValueSz += (unsigned int)(this->Iter.pNextChar - i);
        }
        v8 = !this->Iter.DoContentParsing;
        v18 = this->Iter.pNextChar;
        this->Iter.pCurChar = v18;
        if ( v8 || *v18 != 38 )
        {
          if ( v18 < this->Iter.pEnd )
          {
            this->Iter.CurChar = *v18;
            this->Iter.pNextChar = v18 + 1;
          }
        }
        else
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
        }
      }
      this->Iter.DoContentParsing = 0;
      if ( v10 )
      {
        *ppattrValue = this->pBuffer;
        *pattrValueSz = this->BufPos;
      }
      if ( this->Iter.pCurChar < this->Iter.pEnd )
      {
        v19 = this->Iter.pNextChar;
        v3 = 1;
        this->Iter.pCurChar = v19;
        if ( this->Iter.DoContentParsing && *v19 == 38 )
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
        }
        else if ( v19 < this->Iter.pEnd )
        {
          this->Iter.CurChar = *v19;
          this->Iter.pNextChar = this->Iter.pCurChar + 1;
        }
        Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
        v20 = this->Iter.CurChar;
        if ( v20 == 62 || v20 == 47 )
          this->CurState = 9;
        else
          this->CurState = 7;
      }
      else
      {
        this->CurState = 1;
      }
    }
    else
    {
      this->CurState = 1;
    }
  }
  result = v3;
  if ( this->Iter.pCurChar >= this->Iter.pEnd )
    this->CurState = 1;
  return result;
}

// File Line: 644
// RVA: 0x99E8A0
void __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::ParseName(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this,
        const wchar_t **ppname,
        unsigned __int64 *plen)
{
  char v3; // si
  const wchar_t *pCurChar; // r9
  unsigned int CurChar; // ecx
  unsigned __int64 v9; // rax
  int v10; // r8d
  int v11; // ecx
  unsigned __int64 BufSize; // rcx
  unsigned int v13; // ebp
  wchar_t *pBuffer; // rdx
  unsigned __int64 v15; // r8
  wchar_t *v16; // rax
  const wchar_t *pNextChar; // rcx

  v3 = 0;
  *ppname = this->Iter.pCurChar;
  *plen = 0i64;
  pCurChar = this->Iter.pCurChar;
  if ( pCurChar < this->Iter.pEnd )
  {
    do
    {
      CurChar = this->Iter.CurChar;
      if ( CurChar - 60 <= 2 )
        break;
      if ( CurChar == 47 )
        break;
      v9 = (unsigned __int64)(unsigned __int16)CurChar >> 8;
      v10 = Scaleform::UnicodeSpaceBits[v9];
      if ( Scaleform::UnicodeSpaceBits[v9] )
      {
        if ( v10 == 1 )
          break;
        v11 = Scaleform::UnicodeSpaceBits[v10 + (((unsigned __int16)CurChar >> 4) & 0xF)];
        if ( _bittest(&v11, this->Iter.CurChar & 0xF) )
          break;
      }
      if ( this->Iter.DoContentParsing && *pCurChar == 38 )
      {
        if ( !v3 )
        {
          this->BufPos = 0i64;
          Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(this, *ppname, *plen);
          v3 = 1;
        }
        BufSize = this->BufSize;
        v13 = this->Iter.CurChar;
        if ( this->BufPos + 6 > BufSize )
        {
          pBuffer = this->pBuffer;
          v15 = BufSize + 6;
          this->BufSize = BufSize + 6;
          if ( pBuffer )
            v16 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                               Scaleform::Memory::pGlobalHeap,
                               pBuffer,
                               2 * v15);
          else
            v16 = (wchar_t *)this->pHeap->vfptr->Alloc(this->pHeap, 2 * v15, 0i64);
          this->pBuffer = v16;
        }
        this->pBuffer[this->BufPos++] = v13;
      }
      else if ( v3 )
      {
        Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(
          this,
          this->Iter.pCurChar,
          (unsigned int)(this->Iter.pNextChar - pCurChar));
      }
      else
      {
        *plen += (unsigned int)(this->Iter.pNextChar - pCurChar);
      }
      pNextChar = this->Iter.pNextChar;
      this->Iter.pCurChar = pNextChar;
      if ( this->Iter.DoContentParsing && *pNextChar == 38 )
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
      }
      else if ( pNextChar < this->Iter.pEnd )
      {
        this->Iter.CurChar = *pNextChar;
        this->Iter.pNextChar = pNextChar + 1;
      }
      pCurChar = this->Iter.pCurChar;
    }
    while ( pCurChar < this->Iter.pEnd );
    if ( v3 )
    {
      *ppname = this->pBuffer;
      *plen = this->BufPos;
    }
  }
}

// File Line: 737
// RVA: 0x99E090
bool __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::ParseContent(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this,
        const wchar_t **ppContent,
        unsigned __int64 *pcontentSize)
{
  char v6; // si
  bool DoContentParsing; // al
  const wchar_t *pCurChar; // r8
  unsigned int CurChar; // ecx
  unsigned __int64 v10; // rax
  int v11; // r9d
  int v12; // ecx
  unsigned __int64 BufSize; // rcx
  wchar_t *pBuffer; // rdx
  unsigned __int64 v15; // r8
  wchar_t *v16; // rax
  unsigned __int64 v17; // rcx
  unsigned int v18; // ebp
  wchar_t *v19; // rdx
  unsigned __int64 v20; // r8
  wchar_t *v21; // rax
  __int64 v22; // rax
  const wchar_t *pNextChar; // rcx
  const wchar_t *v24; // rax

  if ( this->CurState == 3 )
  {
    v6 = 0;
    *ppContent = this->Iter.pCurChar;
    *pcontentSize = 0i64;
    DoContentParsing = this->Iter.DoContentParsing;
    this->Iter.DoContentParsing = 1;
    if ( !DoContentParsing && *this->Iter.pCurChar == 38 )
      Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
    pCurChar = this->Iter.pCurChar;
    if ( pCurChar < this->Iter.pEnd )
    {
      do
      {
        CurChar = this->Iter.CurChar;
        if ( CurChar == 60 && (!this->Iter.DoContentParsing || *pCurChar != 38) )
          break;
        if ( (v10 = (unsigned __int64)(unsigned __int16)CurChar >> 8, (v11 = Scaleform::UnicodeSpaceBits[v10]) != 0)
          && (v11 == 1
           || (v12 = Scaleform::UnicodeSpaceBits[v11 + (((unsigned __int16)CurChar >> 4) & 0xF)],
               _bittest(&v12, this->Iter.CurChar & 0xF)))
          && this->CondenseWhite )
        {
          if ( !v6 )
          {
            this->BufPos = 0i64;
            Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(this, *ppContent, *pcontentSize);
            v6 = 1;
          }
          BufSize = this->BufSize;
          if ( this->BufPos + 6 > BufSize )
          {
            pBuffer = this->pBuffer;
            v15 = BufSize + 6;
            this->BufSize = BufSize + 6;
            if ( pBuffer )
              v16 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                 Scaleform::Memory::pGlobalHeap,
                                 pBuffer,
                                 2 * v15);
            else
              v16 = (wchar_t *)this->pHeap->vfptr->Alloc(this->pHeap, 2 * v15, 0i64);
            this->pBuffer = v16;
          }
          this->pBuffer[this->BufPos++] = 32;
          Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
        }
        else
        {
          if ( this->Iter.DoContentParsing && *pCurChar == 38 )
          {
            if ( !v6 )
            {
              this->BufPos = 0i64;
              Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(this, *ppContent, *pcontentSize);
              v6 = 1;
            }
            v17 = this->BufSize;
            v18 = this->Iter.CurChar;
            if ( this->BufPos + 6 > v17 )
            {
              v19 = this->pBuffer;
              v20 = v17 + 6;
              this->BufSize = v17 + 6;
              if ( v19 )
                v21 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                   Scaleform::Memory::pGlobalHeap,
                                   v19,
                                   2 * v20);
              else
                v21 = (wchar_t *)this->pHeap->vfptr->Alloc(this->pHeap, 2 * v20, 0i64);
              this->pBuffer = v21;
            }
            this->pBuffer[this->BufPos++] = v18;
          }
          else
          {
            v22 = this->Iter.pNextChar - pCurChar;
            if ( v6 )
              Scaleform::Render::Text::SGMLParser<wchar_t>::AppendToBuf(this, this->Iter.pCurChar, (unsigned int)v22);
            else
              *pcontentSize += (unsigned int)v22;
          }
          pNextChar = this->Iter.pNextChar;
          this->Iter.pCurChar = pNextChar;
          if ( this->Iter.DoContentParsing && *pNextChar == 38 )
          {
            Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
          }
          else if ( pNextChar < this->Iter.pEnd )
          {
            this->Iter.CurChar = *pNextChar;
            this->Iter.pNextChar = pNextChar + 1;
          }
        }
        pCurChar = this->Iter.pCurChar;
      }
      while ( pCurChar < this->Iter.pEnd );
      if ( v6 )
      {
        *ppContent = this->pBuffer;
        *pcontentSize = this->BufPos;
      }
    }
    v24 = this->Iter.pCurChar;
    if ( v24 < this->Iter.pEnd && (this->Iter.CurChar != 60 || this->Iter.DoContentParsing && *v24 == 38) )
      this->CurState = 1;
    else
      this->CurState |= 0x8000u;
    this->Iter.DoContentParsing = 0;
  }
  return this->CurState != 1;
}

// File Line: 801
// RVA: 0x9B6790
void __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::SkipName(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  unsigned int CurChar; // ecx
  unsigned __int64 v3; // rax
  int v4; // r8d
  int v5; // ecx
  bool v6; // zf
  const wchar_t *pNextChar; // rcx

  if ( this->CurState == 2 && this->Iter.pCurChar < this->Iter.pEnd )
  {
    do
    {
      CurChar = this->Iter.CurChar;
      if ( CurChar - 60 <= 2 )
        break;
      if ( CurChar == 47 )
        break;
      v3 = (unsigned __int64)(unsigned __int16)CurChar >> 8;
      v4 = Scaleform::UnicodeSpaceBits[v3];
      if ( Scaleform::UnicodeSpaceBits[v3] )
      {
        if ( v4 == 1 )
          break;
        v5 = Scaleform::UnicodeSpaceBits[v4 + (((unsigned __int16)CurChar >> 4) & 0xF)];
        if ( _bittest(&v5, this->Iter.CurChar & 0xF) )
          break;
      }
      v6 = !this->Iter.DoContentParsing;
      pNextChar = this->Iter.pNextChar;
      this->Iter.pCurChar = pNextChar;
      if ( v6 || *pNextChar != 38 )
      {
        if ( pNextChar < this->Iter.pEnd )
        {
          this->Iter.CurChar = *pNextChar;
          this->Iter.pNextChar = pNextChar + 1;
        }
      }
      else
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
      }
    }
    while ( this->Iter.pCurChar < this->Iter.pEnd );
  }
}

// File Line: 815
// RVA: 0x9B68C0
void __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  unsigned int CurChar; // edx
  unsigned __int64 v3; // rax
  int v4; // r8d
  int v5; // ecx
  bool v6; // zf
  const wchar_t *pNextChar; // rcx

  while ( this->Iter.pCurChar < this->Iter.pEnd )
  {
    CurChar = this->Iter.CurChar;
    v3 = (unsigned __int64)(unsigned __int16)CurChar >> 8;
    v4 = Scaleform::UnicodeSpaceBits[v3];
    if ( !Scaleform::UnicodeSpaceBits[v3] )
      break;
    if ( v4 != 1 )
    {
      v5 = Scaleform::UnicodeSpaceBits[v4 + (((unsigned __int16)CurChar >> 4) & 0xF)];
      if ( !_bittest(&v5, this->Iter.CurChar & 0xF) )
        break;
    }
    v6 = !this->Iter.DoContentParsing;
    pNextChar = this->Iter.pNextChar;
    this->Iter.pCurChar = pNextChar;
    if ( v6 || *pNextChar != 38 )
    {
      if ( pNextChar < this->Iter.pEnd )
      {
        this->Iter.CurChar = *pNextChar;
        this->Iter.pNextChar = pNextChar + 1;
      }
    }
    else
    {
      Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
    }
  }
}

// File Line: 824
// RVA: 0x9B6360
void __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::SkipAttribute(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  unsigned int CurChar; // r8d
  unsigned __int64 v3; // rax
  int v4; // r9d
  int v5; // ecx
  bool v6; // zf
  const wchar_t *pNextChar; // rcx
  unsigned int v8; // eax
  const wchar_t *v9; // rax
  unsigned int v10; // esi
  const wchar_t *v11; // rcx
  const wchar_t *pEnd; // rax
  const wchar_t *v13; // rax
  unsigned int v14; // eax

  if ( this->CurState == 7 )
  {
    Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
    while ( this->Iter.pCurChar < this->Iter.pEnd )
    {
      CurChar = this->Iter.CurChar;
      v3 = (unsigned __int64)(unsigned __int16)CurChar >> 8;
      v4 = Scaleform::UnicodeAlnumBits[v3];
      if ( !Scaleform::UnicodeAlnumBits[v3] )
        break;
      if ( v4 != 1 )
      {
        v5 = Scaleform::UnicodeAlnumBits[v4 + (((unsigned __int16)CurChar >> 4) & 0xF)];
        if ( !_bittest(&v5, this->Iter.CurChar & 0xF) )
          break;
      }
      if ( CurChar == 61 )
        break;
      v6 = !this->Iter.DoContentParsing;
      pNextChar = this->Iter.pNextChar;
      this->Iter.pCurChar = pNextChar;
      if ( v6 || *pNextChar != 38 )
      {
        if ( pNextChar < this->Iter.pEnd )
        {
          this->Iter.CurChar = *pNextChar;
          this->Iter.pNextChar = pNextChar + 1;
        }
      }
      else
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
      }
    }
    if ( this->Iter.pCurChar >= this->Iter.pEnd )
    {
LABEL_14:
      this->CurState = 1;
      return;
    }
    v8 = this->Iter.CurChar;
    if ( v8 == 61 )
    {
      v9 = this->Iter.pNextChar;
      this->Iter.pCurChar = v9;
      if ( this->Iter.DoContentParsing && *v9 == 38 )
      {
        Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
        Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
        this->CurState = 8;
      }
      else
      {
        if ( v9 < this->Iter.pEnd )
        {
          this->Iter.CurChar = *v9;
          this->Iter.pNextChar = this->Iter.pCurChar + 1;
        }
        Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
        this->CurState = 8;
      }
    }
    else if ( v8 == 47 || v8 == 62 )
    {
      this->CurState = 9;
    }
    else
    {
      this->CurState = 1;
    }
  }
  if ( this->CurState == 8 )
  {
    v10 = this->Iter.CurChar;
    if ( v10 == 34 || v10 == 39 )
    {
      while ( 1 )
      {
        v6 = !this->Iter.DoContentParsing;
        v11 = this->Iter.pNextChar;
        this->Iter.pCurChar = v11;
        if ( v6 || *v11 != 38 )
        {
          if ( v11 < this->Iter.pEnd )
          {
            this->Iter.CurChar = *v11;
            this->Iter.pNextChar = v11 + 1;
          }
        }
        else
        {
          Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
        }
        pEnd = this->Iter.pEnd;
        if ( this->Iter.pCurChar >= pEnd )
          break;
        if ( this->Iter.CurChar == v10 )
        {
          if ( this->Iter.pCurChar >= pEnd )
            goto LABEL_14;
          v13 = this->Iter.pNextChar;
          this->Iter.pCurChar = v13;
          if ( this->Iter.DoContentParsing && *v13 == 38 )
          {
            Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
          }
          else if ( v13 < this->Iter.pEnd )
          {
            this->Iter.CurChar = *v13;
            this->Iter.pNextChar = this->Iter.pCurChar + 1;
          }
          Scaleform::Render::Text::SGMLParser<wchar_t>::SkipSpaces(this);
          v14 = this->Iter.CurChar;
          if ( v14 == 62 || v14 == 47 )
            this->CurState = 9;
          else
            this->CurState = 7;
          return;
        }
      }
    }
    goto LABEL_14;
  }
}

// File Line: 880
// RVA: 0x9B66A0
void __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::SkipComment(
        Scaleform::Render::Text::SGMLParser<wchar_t> *this)
{
  int v1; // edi
  bool v3; // zf
  const wchar_t *pNextChar; // rcx
  unsigned int CurChar; // eax
  const wchar_t *v6; // rax

  v1 = 0;
  while ( this->Iter.pCurChar < this->Iter.pEnd )
  {
    if ( !this->Iter.CurChar || v1 == 3 )
      break;
    v3 = !this->Iter.DoContentParsing;
    pNextChar = this->Iter.pNextChar;
    this->Iter.pCurChar = pNextChar;
    if ( v3 || *pNextChar != 38 )
    {
      if ( pNextChar < this->Iter.pEnd )
      {
        this->Iter.CurChar = *pNextChar;
        this->Iter.pNextChar = pNextChar + 1;
      }
    }
    else
    {
      Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
    }
    CurChar = this->Iter.CurChar;
    if ( CurChar == 45 )
    {
      if ( v1 < 2 )
        ++v1;
    }
    else if ( CurChar == 62 )
    {
      if ( v1 == 2 )
        v1 = 3;
    }
    else
    {
      v1 = 0;
    }
  }
  if ( this->Iter.pCurChar < this->Iter.pEnd && v1 == 3 )
  {
    v6 = this->Iter.pNextChar;
    this->Iter.pCurChar = v6;
    if ( this->Iter.DoContentParsing && *v6 == 38 )
    {
      Scaleform::Render::Text::SGMLCharIter<wchar_t>::DecodeEscapedChar(&this->Iter);
    }
    else if ( v6 < this->Iter.pEnd )
    {
      this->Iter.CurChar = *v6;
      this->Iter.pNextChar = this->Iter.pCurChar + 1;
    }
  }
}

// File Line: 904
// RVA: 0x99E7F0
bool __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::ParseInt(
        int *pdestVal,
        const wchar_t *pstr,
        unsigned __int64 len)
{
  unsigned __int64 v3; // rdi
  const wchar_t *v4; // rbx
  bool result; // al
  int v7; // esi
  int v8; // r14d
  unsigned __int64 v9; // rbp
  int v10; // eax

  v3 = len;
  v4 = pstr;
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
    return 0;
  }
  else
  {
LABEL_10:
    result = 1;
    *pdestVal = v7 * v8;
  }
  return result;
}

// File Line: 931
// RVA: 0x99E4D0
char __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::ParseHexInt(
        unsigned int *pdestVal,
        wchar_t *pstr,
        unsigned __int64 len)
{
  unsigned int v7; // ebx
  unsigned __int64 v8; // rsi
  __int16 v9; // ax
  int v10; // eax

  if ( !len )
    return 0;
  v7 = 0;
  v8 = 0i64;
  while ( isxdigit(*pstr) )
  {
    v7 *= 16;
    v9 = Scaleform::SFtowlower(*pstr);
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
    ++pstr;
    if ( v8 >= len )
    {
      *pdestVal = v7;
      return 1;
    }
  }
  return 0;
}

// File Line: 953
// RVA: 0x99E360
bool __fastcall Scaleform::Render::Text::SGMLParser<wchar_t>::ParseFloat(
        float *pdestVal,
        const wchar_t *pstr,
        unsigned __int64 len)
{
  const wchar_t *v3; // rbx
  bool result; // al
  const wchar_t *v6; // rdi
  double v7; // xmm9_8
  double v8; // xmm7_8
  double v9; // xmm6_8
  int v10; // eax
  const wchar_t *v11; // rbx
  int v12; // eax
  float v13; // xmm0_4

  v3 = pstr;
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
    while ( ((*v3 - 44) & 0xFFFD) != 0 )
    {
      if ( !isdigit(*v3) )
        return 0;
      v10 = *v3++;
      v9 = (double)(v10 - 48) + v9 * 10.0;
      if ( v3 >= v6 )
        goto LABEL_18;
    }
    if ( v3 < v6 && ((*v3 - 44) & 0xFFFD) == 0 )
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
        v12 = *v11++;
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
  *pdestVal = v13;
  return result;
}

