// File Line: 105
// RVA: 0xE1B890
signed __int64 __fastcall hkAlgorithm::binarySearch_hkpRigidBody_____ptr64_hkpRigidBody_____ptr64_hkBool____cdecl___hkpRigidBody_const_____ptr64_hkpRigidBody_const_____ptr64__(hkpRigidBody *const *key, hkpRigidBody *const *items, int numItems, hkBool *(__fastcall *cmpLess)(hkBool *result, hkpRigidBody *, hkpRigidBody *))
{
  int v4; // esi
  int v5; // edi
  hkBool *(__fastcall *v6)(hkBool *, hkpRigidBody *, hkpRigidBody *); // rbp
  hkpRigidBody *const *v7; // r15
  hkpRigidBody *const *v8; // r14
  int v9; // ebx
  signed __int64 result; // rax
  char v11; // [rsp+50h] [rbp+18h]

  v4 = numItems - 1;
  v5 = 0;
  v6 = cmpLess;
  v7 = items;
  v8 = key;
  while ( v4 > v5 )
  {
    v9 = (v4 + v5) >> 1;
    if ( v6((hkBool *)&v11, v7[v9], *v8)->m_bool )
      v5 = v9 + 1;
    else
      v4 = (v4 + v5) >> 1;
  }
  if ( v5 != v4 || v6((hkBool *)&v11, v7[v5], *v8)->m_bool || v6((hkBool *)&v11, *v8, v7[v5])->m_bool )
    result = 0xFFFFFFFFi64;
  else
    result = (unsigned int)v5;
  return result;
}

// File Line: 174
// RVA: 0xB3F4F0
void __fastcall hkAlgorithm::insertionSort<short>(__int16 *pArr, int size)
{
  int v2; // er10
  __int16 *v3; // r9
  __int64 i; // rbx
  __int16 v5; // r11
  int v6; // er8
  __int64 j; // rax
  __int16 v8; // cx

  v2 = 0;
  v3 = pArr;
  for ( i = 0i64; v2 < size; v3[j] = v5 )
  {
    v5 = v3[i];
    v6 = v2;
    for ( j = i; v6 > 0; v3[j--] = v8 )
    {
      v8 = v3[j - 1];
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
hkAlgorithm::ListElement *__fastcall hkAlgorithm::sortList<hkFreeList::Element>(hkFreeList::Element *head)
{
  return hkAlgorithm::_sortList((hkAlgorithm::ListElement *)head);
}

