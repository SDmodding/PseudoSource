// File Line: 44
// RVA: 0x3EC800
void __fastcall UFG::OSuiteDBLogger::AddValue(UFG::OSuiteDBLogger *this, const char *name, float value)
{
  char dest[128]; // [rsp+20h] [rbp-98h] BYREF

  UFG::qSPrintf(dest, 128, "f_%s", name);
  OSuite::ZMetric::SetProperty(this->m_pMetric, dest, value);
}

// File Line: 45
// RVA: 0x493CB0
void __fastcall UFG::OSuiteDBLogger::AddValue(UFG::OSuiteDBLogger *this, const char *name, bool value)
{
  char dest[136]; // [rsp+20h] [rbp-88h] BYREF

  UFG::qSPrintf(dest, 128, "i32_%s", name);
  OSuite::ZMetric::SetProperty(this->m_pMetric, dest, value);
}

// File Line: 69
// RVA: 0x42AAB0
void __fastcall UFG::OSuiteDBLogger::AddValue(UFG::OSuiteDBLogger *this, const char *name, const char *value)
{
  char dest[136]; // [rsp+20h] [rbp-88h] BYREF

  UFG::qSPrintf(dest, 128, "s_%s", name);
  OSuite::ZMetric::SetProperty(this->m_pMetric, dest, value);
}

