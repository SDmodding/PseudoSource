// File Line: 35
// RVA: 0xEE4BE8
__int64 __fastcall OSuite::FComputeHashAdd(unsigned int nHash, unsigned int nKey)
{
  return 1025 * (nKey + nHash) ^ (1025 * (nKey + nHash) >> 6);
}

// File Line: 101
// RVA: 0xEE4BF8
__int64 __fastcall OSuite::FComputeHashAdd(unsigned int nHash, const void *pData, unsigned __int64 nByteCount)
{
  while ( --nByteCount )
  {
    nHash = 1025 * (nHash + *(unsigned __int8 *)pData) ^ (1025 * (nHash + *(unsigned __int8 *)pData) >> 6);
    pData = (char *)pData + 1;
  }
  return nHash;
}

// File Line: 118
// RVA: 0xEE4C18
__int64 __fastcall OSuite::FComputeHashEnd(unsigned int nHash)
{
  return 32769 * ((9 * nHash >> 11) ^ 9 * nHash);
}

// File Line: 133
// RVA: 0xEE4BB0
__int64 __fastcall OSuite::FComputeHash<char const *>(const char *const *pszString)
{
  const char *v1; // r8
  unsigned int v2; // edx

  v1 = *pszString;
  v2 = 0;
  while ( *v1 )
  {
    v2 = 1025 * (*v1 + v2) ^ (1025 * (*v1 + v2) >> 6);
    ++v1;
  }
  return 32769 * (9 * v2 ^ (9 * v2 >> 11));
}

// File Line: 144
// RVA: 0xEE4BAC
__int64 __fastcall OSuite::FComputeHash<void *>(void *const *pPointer)
{
  return *(unsigned int *)pPointer;
}

