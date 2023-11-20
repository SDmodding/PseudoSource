// File Line: 77
// RVA: 0x3E1590
void __fastcall UFG::OSuiteDBLogger::AddValue(UFG::OSuiteDBLogger *this, const char *name, int value)
{
  int v3; // ebx
  UFG::OSuiteDBLogger *v4; // rdi
  char dest; // [rsp+20h] [rbp-88h]

  v3 = value;
  v4 = this;
  UFG::qSPrintf(&dest, 128, "i32_%s", name);
  OSuite::ZMetric::SetProperty(v4->m_pMetric, &dest, v3);
}

