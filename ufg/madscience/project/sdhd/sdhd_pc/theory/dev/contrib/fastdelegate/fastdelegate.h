// File Line: 929
// RVA: 0x24E7C0
UEL::Value *__fastcall fastdelegate::FastDelegate0<UEL::Value>::operator()(
        fastdelegate::FastDelegate1<UFG::qSymbol const &,UEL::Value> *this,
        UEL::Value *result,
        UFG::qSymbol *p1)
{
  __int64 v4; // rax
  char v6[40]; // [rsp+20h] [rbp-28h] BYREF

  v4 = ((__int64 (__fastcall *)(fastdelegate::detail::GenericClass *, char *, UFG::qSymbol *))this->m_Closure.m_pFunction)(
         this->m_Closure.m_pthis,
         v6,
         p1);
  result->integer = *(_QWORD *)v4;
  result->qSymbol_mUID = *(_DWORD *)v4;
  result->integer = *(_QWORD *)v4;
  result->qSymbol_mUID = *(_DWORD *)v4;
  result->boolean = *(_BYTE *)v4;
  result->qSymbol_mUID = *(_DWORD *)v4;
  result->integer = *(_QWORD *)v4;
  result->integer = *(_QWORD *)v4;
  result->integer = *(_QWORD *)v4;
  result->qSymbol_mUID = *(_DWORD *)v4;
  result->qVector_y = *(float *)(v4 + 8);
  result->qVector_z = *(float *)(v4 + 12);
  result->qVector_w = *(float *)(v4 + 16);
  result->type.mBaseType.mValue = *(_WORD *)(v4 + 20);
  result->type.mDetailedType.mUID = *(_DWORD *)(v4 + 24);
  return result;
}

// File Line: 1049
// RVA: 0x4E2170
void __fastcall fastdelegate::FastDelegate1<char const *,void>::InvokeStaticFunction(
        fastdelegate::FastDelegate1<char const *,void> *this,
        const char *p1)
{
  ((void (__fastcall *)(const char *))this)(p1);
}

// File Line: 1390
// RVA: 0x5395F0
void __fastcall fastdelegate::FastDelegate5<UFG::DebugTextGrid &,int,int,UFG::DebugTextGrid::ElementData &,char const *,void>::InvokeStaticFunction(
        fastdelegate::FastDelegate5<UFG::DebugTextGrid &,int,int,UFG::DebugTextGrid::ElementData &,char const *,void> *this,
        UFG::DebugTextGrid *p1,
        unsigned int p2,
        unsigned int p3,
        UFG::DebugTextGrid::ElementData *p4,
        const char *p5)
{
  ((void (__fastcall *)(UFG::DebugTextGrid *, _QWORD, _QWORD, UFG::DebugTextGrid::ElementData *, const char *))this)(
    p1,
    p2,
    p3,
    p4,
    p5);
}

