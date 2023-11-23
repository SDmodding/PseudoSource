// File Line: 55
// RVA: 0xEDFD64
__int64 __fastcall OSuite::ZHttpParser::skipwhitespace<char>(
        OSuite::ZHttpParser *this,
        const char *pszString,
        int iIndex)
{
  unsigned int v3; // ebx
  unsigned __int8 *i; // rdi

  v3 = (unsigned int)pszString;
  for ( i = (unsigned __int8 *)this + (int)pszString; isspace(*i); ++i )
    ++v3;
  return v3;
}

// File Line: 66
// RVA: 0xEDFCCC
__int64 __fastcall OSuite::ZHttpParser::parsebase<char>(
        OSuite::ZHttpParser *this,
        char *pszString,
        int *iIndex,
        int base)
{
  int v5; // ebp
  int v7; // eax
  unsigned int v8; // ebx
  __int64 v9; // rcx
  int v10; // edx
  int v11; // ecx

  v5 = (int)iIndex;
  v7 = OSuite::ZHttpParser::skipwhitespace<char>(this, (const char *)*(unsigned int *)pszString, (int)iIndex);
  v8 = 0;
  *(_DWORD *)pszString = v7;
  if ( *((_BYTE *)&this->vfptr + v7) )
  {
    do
    {
      if ( !isalnum(*((unsigned __int8 *)&this->vfptr + *(int *)pszString)) )
        break;
      v9 = *(int *)pszString;
      v8 *= v5;
      v10 = *((char *)&this->vfptr + v9);
      v11 = v9 + 1;
      *(_DWORD *)pszString = v11;
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
    while ( *((_BYTE *)&this->vfptr + v11) );
  }
  return v8;
}

