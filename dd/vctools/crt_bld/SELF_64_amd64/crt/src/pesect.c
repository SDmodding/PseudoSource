// File Line: 38
// RVA: 0x12CCB00
bool __fastcall ValidateImageBase(char *pImageBase)
{
  bool result; // al
  char *v2; // rcx

  if ( *(_WORD *)pImageBase != 23117 )
    return 0;
  v2 = &pImageBase[*((signed int *)pImageBase + 15)];
  result = 0;
  if ( *(_DWORD *)v2 == 17744 )
    result = *((_WORD *)v2 + 12) == 523;
  return result;
}

// File Line: 86
// RVA: 0x12CCA60
_IMAGE_SECTION_HEADER *__fastcall FindPESection(char *pImageBase, unsigned __int64 rva)
{
  unsigned int v2; // er9
  unsigned __int64 v3; // r10
  char *v4; // r8
  _IMAGE_SECTION_HEADER *result; // rax
  unsigned __int64 v6; // rdx

  v2 = 0;
  v3 = rva;
  v4 = &pImageBase[*((signed int *)pImageBase + 15)];
  result = (_IMAGE_SECTION_HEADER *)&v4[*((unsigned __int16 *)v4 + 10) + 24];
  if ( !*((_WORD *)v4 + 3) )
    return 0i64;
  while ( 1 )
  {
    v6 = result->VirtualAddress;
    if ( v3 >= v6 && v3 < (unsigned int)(v6 + result->Misc.PhysicalAddress) )
      break;
    ++v2;
    ++result;
    if ( v2 >= *((unsigned __int16 *)v4 + 3) )
      return 0i64;
  }
  return result;
}

// File Line: 143
// RVA: 0x12CCAB0
int __fastcall IsNonwritableInCurrentImage(char *pTarget)
{
  char *v1; // rbx
  _IMAGE_SECTION_HEADER *v2; // rax

  v1 = pTarget;
  LODWORD(v2) = ValidateImageBase((char *)0x140000000i64);
  if ( (_DWORD)v2 )
  {
    v2 = FindPESection((char *)0x140000000i64, (unsigned __int64)(v1 - 5368709120i64));
    if ( v2 )
      LODWORD(v2) = (v2->Characteristics & 0x80000000) == 0;
  }
  return (signed int)v2;
}

// File Line: 181
// RVA: 0x1452260
_IsNonwritableInCurrentImage$filt$0

