// File Line: 55
// RVA: 0xEDFD64
__int64 __fastcall OSuite::ZHttpParser::skipwhitespace<char>(OSuite::ZHttpParser *this, const char *pszString, int iIndex)
{
  unsigned int v3; // ebx
  unsigned __int8 *i; // rdi

  v3 = (unsigned int)pszString;
  for ( i = (unsigned __int8 *)this + (signed int)pszString; isspace(*i); ++i )
    ++v3;
  return v3;
}

// File Line: 66
// RVA: 0xEDFCCC
__int64 __fastcall OSuite::ZHttpParser::parsebase<char>(OSuite::ZHttpParser *this, const char *pszString, int *iIndex, int base)
{
  char *v4; // rsi
  int v5; // ebp
  OSuite::ZHttpParser *v6; // rdi
  int v7; // eax
  unsigned int v8; // ebx
  __int64 v9; // rcx
  int v10; // edx
  int v11; // ecx

  v4 = (char *)pszString;
  v5 = (signed int)iIndex;
  v6 = this;
  v7 = OSuite::ZHttpParser::skipwhitespace<char>(this, (const char *)*(unsigned int *)pszString, (int)iIndex);
  v8 = 0;
  *(_DWORD *)v4 = v7;
  if ( *((_BYTE *)&v6->vfptr + v7) )
  {
    do
    {
      if ( !isalnum(*((unsigned __int8 *)&v6->vfptr + *(signed int *)v4)) )
        break;
      v9 = *(signed int *)v4;
      v8 *= v5;
      v10 = *((char *)&v6->vfptr + v9);
      v11 = v9 + 1;
      *(_DWORD *)v4 = v11;
      if ( (unsigned int)(v10 - 48) > 9 )
      {
        if ( (unsigned int)(v10 - 97) > 0x19 )
        {
          if ( (unsigned int)(v10 - 65) <= 0x19 )
            v10 -= 55;
        }
        else
        {
          v10 -= 87;
        }
      }
      else
      {
        v10 -= 48;
      }
      if ( v10 >= v5 )
        break;
      v8 += v10;
    }
    while ( *((_BYTE *)&v6->vfptr + v11) );
  }
  return v8;
}

