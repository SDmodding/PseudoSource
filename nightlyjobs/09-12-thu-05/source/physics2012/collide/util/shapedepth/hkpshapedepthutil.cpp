// File Line: 17
// RVA: 0xCF2EB0
__int64 __fastcall hkpShapeDepthUtil::getShapeDepth(hkpShape *shape)
{
  __int64 v1; // rax
  __int64 v2; // rbx
  unsigned __int8 v3; // di
  unsigned int i; // esi
  hkpShape *v5; // rax
  unsigned __int8 v6; // al
  unsigned __int8 v7; // dl
  __int64 result; // rax
  char v9; // [rsp+20h] [rbp-208h]

  v1 = ((__int64 (*)(void))shape->vfptr[7].__vecDelDtor)();
  v2 = v1;
  if ( !v1 )
    return (unsigned __int8)hkpShapeDepthUtil::s_defaultMinimumChildDepth[0];
  v3 = 0;
  for ( i = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v1 + 16i64))(v1);
        i != -1;
        i = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v2 + 24i64))(v2, i) )
  {
    v5 = (hkpShape *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v2 + 40i64))(v2, i, &v9);
    v6 = hkpShapeDepthUtil::getShapeDepth(v5);
    v7 = v3;
    if ( v6 > v3 )
      v7 = v6;
    v3 = v7;
  }
  result = (unsigned __int8)hkpShapeDepthUtil::s_defaultMinimumChildDepth[0];
  if ( (unsigned __int8)(v3 + 1) > hkpShapeDepthUtil::s_defaultMinimumChildDepth[0] )
    result = (unsigned __int8)(v3 + 1);
  return result;
}

