// File Line: 77
// RVA: 0x3E1590
void __fastcall UFG::OSuiteDBLogger::AddValue(UFG::OSuiteDBLogger *this, const char *name, int value)
{
  char dest[136]; // [rsp+20h] [rbp-88h] BYREF

  UFG::qSPrintf(dest, 128, "i32_%s", name);
  OSuite::ZMetric::SetProperty(this->m_pMetric, dest, value);
}

