// File Line: 929
// RVA: 0x24E7C0
UEL::Value *__fastcall fastdelegate::FastDelegate0<UEL::Value>::operator()(fastdelegate::FastDelegate1<UFG::qSymbol const &,UEL::Value> *this, UEL::Value *result, UFG::qSymbol *p1)
{
  UEL::Value *v3; // rbx
  __int64 v4; // rax
  char v6; // [rsp+20h] [rbp-28h]

  v3 = result;
  v4 = ((__int64 (__fastcall *)(fastdelegate::detail::GenericClass *, char *, UFG::qSymbol *))this->m_Closure.m_pFunction)(
         this->m_Closure.m_pthis,
         &v6,
         p1);
  v3->integer = *(_QWORD *)v4;
  v3->qSymbol_mUID = *(_DWORD *)v4;
  v3->integer = *(_QWORD *)v4;
  v3->qSymbol_mUID = *(_DWORD *)v4;
  v3->boolean = *(_BYTE *)v4;
  v3->qSymbol_mUID = *(_DWORD *)v4;
  v3->integer = *(_QWORD *)v4;
  v3->integer = *(_QWORD *)v4;
  v3->integer = *(_QWORD *)v4;
  v3->qSymbol_mUID = *(_DWORD *)v4;
  v3->qVector_y = *(float *)(v4 + 8);
  v3->qVector_z = *(float *)(v4 + 12);
  v3->qVector_w = *(float *)(v4 + 16);
  v3->type.mBaseType.mValue = *(_WORD *)(v4 + 20);
  v3->type.mDetailedType.mUID = *(_DWORD *)(v4 + 24);
  return v3;
}

// File Line: 1049
// RVA: 0x4E2170
void __fastcall fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction(fastdelegate::FastDelegate1<char const *,void> *this, const char *p1)
{
  ((void (__fastcall *)(const char *))this)(p1);
}

// File Line: 1390
// RVA: 0x5395F0
void __fastcall fastdelegate::FastDelegate5<UFG::DebugTextGrid &,int,int,UFG::DebugTextGrid::ElementData &,char const *,void>::InvokeStaticFunction(fastdelegate::FastDelegate5<UFG::DebugTextGrid &,int,int,UFG::DebugTextGrid::ElementData &,char const *,void> *this, UFG::DebugTextGrid *p1, int p2, int p3, UFG::DebugTextGrid::ElementData *p4, const char *p5)
{
  ((void (__fastcall *)(UFG::DebugTextGrid *, _QWORD, _QWORD, UFG::DebugTextGrid::ElementData *, const char *))this)(
    p1,
    (unsigned int)p2,
    (unsigned int)p3,
    p4,
    p5);
}

