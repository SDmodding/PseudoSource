// File Line: 44
// RVA: 0x3EC800
void __fastcall UFG::OSuiteDBLogger::AddValue(UFG::OSuiteDBLogger *this, const char *name, float value)
{
  UFG::OSuiteDBLogger *v3; // rbx
  char dest; // [rsp+20h] [rbp-98h]

  v3 = this;
  UFG::qSPrintf(&dest, 128, "f_%s", name);
  OSuite::ZMetric::SetProperty(v3->m_pMetric, &dest, value);
}

// File Line: 45
// RVA: 0x493CB0
void __fastcall UFG::OSuiteDBLogger::AddValue(UFG::OSuiteDBLogger *this, const char *name, bool value)
{
  bool v3; // bl
  UFG::OSuiteDBLogger *v4; // rdi
  char dest; // [rsp+20h] [rbp-88h]

  v3 = value;
  v4 = this;
  UFG::qSPrintf(&dest, 128, "i32_%s", name);
  OSuite::ZMetric::SetProperty(v4->m_pMetric, &dest, v3 == 1);
}

// File Line: 69
// RVA: 0x42AAB0
void __fastcall UFG::OSuiteDBLogger::AddValue(UFG::OSuiteDBLogger *this, const char *name, const char *value)
{
  const char *v3; // rbx
  UFG::OSuiteDBLogger *v4; // rdi
  char dest; // [rsp+20h] [rbp-88h]

  v3 = value;
  v4 = this;
  UFG::qSPrintf(&dest, 128, "s_%s", name);
  OSuite::ZMetric::SetProperty(v4->m_pMetric, &dest, v3);
}

