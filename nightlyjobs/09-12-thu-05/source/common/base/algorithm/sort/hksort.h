// File Line: 105
// RVA: 0xE1B890
__int64 __fastcall hkAlgorithm::binarySearch_hkpRigidBody_____ptr64_hkpRigidBody_____ptr64_hkBool____cdecl___hkpRigidBody_const_____ptr64_hkpRigidBody_const_____ptr64__(
        hkpRigidBody **key,
        hkpRigidBody *const *items,
        int numItems,
        hkBool *(__fastcall *cmpLess)(hkBool *result, hkpRigidBody *, hkpRigidBody *))
{
  int v4; // esi
  int v5; // edi
  int v9; // ebx
  char v11; // [rsp+50h] [rbp+18h] BYREF

  v4 = numItems - 1;
  v5 = 0;
  while ( v4 > v5 )
  {
    v9 = (v4 + v5) >> 1;
    if ( cmpLess((hkBool *)&v11, items[v9], *key)->m_bool )
      v5 = v9 + 1;
    else
      v4 = (v4 + v5) >> 1;
  }
  if ( v5 != v4 || cmpLess((hkBool *)&v11, items[v5], *key)->m_bool || cmpLess((hkBool *)&v11, *key, items[v5])->m_bool )
    return 0xFFFFFFFFi64;
  else
    return (unsigned int)v5;
}

// File Line: 174
// RVA: 0xB3F4F0
void __fastcall hkAlgorithm::insertionSort<short>(__int16 *pArr, int size)
{
  int v2; // r10d
  __int64 i; // rbx
  __int16 v5; // r11
  int v6; // r8d
  __int64 j; // rax
  __int16 v8; // cx

  v2 = 0;
  for ( i = 0i64; v2 < size; pArr[j] = v5 )
  {
    v5 = pArr[i];
    v6 = v2;
    for ( j = i; v6 > 0; pArr[j--] = v8 )
    {
      v8 = pArr[j - 1];
      if ( v5 >= v8 )
        break;
      --v6;
    }
    ++v2;
    ++i;
  }
}

// File Line: 243
// RVA: 0xC706A0
// attributes: thunk
hkAlgorithm::ListElement *__fastcall hkAlgorithm::sortList<hkFreeList::Element>(hkAlgorithm::ListElement *head)
{
  return hkAlgorithm::_sortList(head);
}

