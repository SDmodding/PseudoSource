// File Line: 37
// RVA: 0x12D7A80
__int64 __fastcall CallSettingFrame(__int64 a1, __int64 *a2, __int64 a3)
{
  void (*v3)(void); // rax
  __int64 v4; // rax
  __int64 *v6; // [rsp+38h] [rbp+10h]

  v6 = a2;
  v3 = (void (*)(void))NLG_Notify(a1, *a2, a3);
  v3();
  v4 = _NLG_Return2();
  return NLG_Notify(v4, *v6, 2i64);
}

// File Line: 88
// RVA: 0x12D7AC0
void *__fastcall GetNextInstrOffset(_QWORD *a1)
{
  void *result; // rax
  void *retaddr; // [rsp+0h] [rbp+0h]

  result = retaddr;
  *a1 = retaddr;
  return result;
}

